#include <iostream>
#include <string>
#include <memory> // Required for std::unique_ptr

// ==========================================
// 1. THE COMPONENT INTERFACE
// ==========================================
// The common interface for both base objects and decorators.
// They must all be able to "send" a message.
class INotifier {
public:
    virtual ~INotifier() = default;
    virtual void send(const std::string& message) const = 0;
};


// ==========================================
// 2. CONCRETE COMPONENT (The Base Layer)
// ==========================================
// The basic implementation. This is like the plain coffee.
class EmailNotifier : public INotifier {
public:
    void send(const std::string& message) const override {
        std::cout << "[Email Service] Sending email: '" << message << "'\n";
    }
};


// ==========================================
// 3. THE BASE DECORATOR
// ==========================================
// This is the bridge. It's crucial.
// 1. It implements INotifier so it "looks" like a notifier.
// 2. It HOLDS a pointer to another INotifier (the thing it wraps).
class NotifierDecorator : public INotifier {
protected:
    // The wrapped object. Owned by this decorator.
    std::unique_ptr<INotifier> m_wrapped;

public:
    // Constructor: Takes ownership of the wrapped object via move semantics.
    NotifierDecorator(std::unique_ptr<INotifier> wrapped)
        : m_wrapped(std::move(wrapped)) {}

    // Default implementation: just delegate to the wrapped object.
    void send(const std::string& message) const override {
        m_wrapped->send(message);
    }
};


// ==========================================
// 4. CONCRETE DECORATORS (The Layers)
// ==========================================

// Layer A: Adds SMS functionality
class SMSDecorator : public NotifierDecorator {
public:
    // Pass the wrapped object up to the base constructor
    SMSDecorator(std::unique_ptr<INotifier> wrapped)
        : NotifierDecorator(std::move(wrapped)) {}

    void send(const std::string& message) const override {
        // Behavior added BEFORE the base behavior
        std::cout << "[SMS Service] Sending text alert indicating new notification.\n";

        // Delegate to the wrapped layer
        // Note: We call the base class's send, which calls m_wrapped->send()
        NotifierDecorator::send(message);
    }
};

// Layer B: Modifies the message itself
class ImportantDecorator : public NotifierDecorator {
public:
    ImportantDecorator(std::unique_ptr<INotifier> wrapped)
        : NotifierDecorator(std::move(wrapped)) {}

    void send(const std::string& message) const override {
        // Behavior that modifies data BEFORE delegating
        std::string markedMessage = "!!! IMPORTANT !!! " + message + " !!! IMPORTANT !!!";

        std::cout << "[Important Dec] Added urgency markers to message.\n";
        // Delegate the MODIFIED message to the inner layer
        NotifierDecorator::send(markedMessage);
    }
};


// ==========================================
// 5. CLIENT CODE
// ==========================================
int main() {
    std::cout << "--- Scenario 1: Basic Email Only ---\n";
    // 1. Create basic component
    std::unique_ptr<INotifier> service1 = std::make_unique<EmailNotifier>();
    service1->send("Server is down.");


    std::cout << "\n--- Scenario 2: Email wrapped with SMS ---\n";
    // 1. Create base
    auto baseEmail = std::make_unique<EmailNotifier>();
    // 2. Wrap it with SMS. The SMS decorator takes ownership of the email object.
    std::unique_ptr<INotifier> service2 = std::make_unique<SMSDecorator>(std::move(baseEmail));
    service2->send("Disk space low.");


    std::cout << "\n--- Scenario 3: The Full Stack (Russian Nesting Doll) ---\n";
    // We can build it in one go. Read it from inside out:
    // Create Email -> Wrap in Important -> Wrap that in SMS.
    std::unique_ptr<INotifier> fullStackService =
        std::make_unique<SMSDecorator>(
            std::make_unique<ImportantDecorator>(
                std::make_unique<EmailNotifier>()
            )
        );

    // When we call send(), it triggers a chain reaction down through the layers.
    fullStackService->send("Database breach detected!");

    std::cout << "\n--- Cleanup done automatically by unique_ptr ---\n";
    return 0;
}