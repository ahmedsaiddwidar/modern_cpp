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
    std::unique_ptr<INotifier> baseEmail = std::make_unique<EmailNotifier>();
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

// Rule #1: The "Chain Link" Constructor Signature

// Every single decorator class in your system needs nearly the identical constructor. Memorize this one pattern.

// The Concept: "I am a link in a chain. To exist, I must be given the next link, and I must take total ownership of it."

// The Syntax Pattern to Memorize:
// C++

// // In the .h file or class definition:
// MyDecorator(std::unique_ptr<TheInterface> wrapped)
//     : TheBaseDecoratorClass(std::move(wrapped)) {}

// Why it works (The Mnemonic):

//     Input: I take a unique_ptr by value. (Give me the baton).

//     Initializer List: I immediately call my parent's constructor.

//     Action: I use std::move() to pass that baton up to my parent to hold onto.

// If you can write that constructor without looking, you are 80% of the way there.
// Rule #2: The "Inside-Out" Build Process (Client Code)

// When writing the client code (like in main), do not try to write it from left to right. Your brain will get tangled in parentheses.

// Write it backwards, from the inside out.

// The Exercise: Say to yourself: "I want an Email, wrapped in Important, wrapped in SMS."

//     Start at the center. Write the core object.
//     C++

// std::make_unique<EmailNotifier>()

// Wrap it with the next layer. Put parentheses around step 1, and write the next wrapper in front of it.
// C++

// std::make_unique<ImportantDecorator>( std::make_unique<EmailNotifier>() )

// Wrap it again. Put parentheses around step 2, and write the final wrapper in front of it.
// C++

// std::make_unique<SMSDecorator>( std::make_unique<ImportantDecorator>( std::make_unique<EmailNotifier>() ) )

// Assign it. Finally, assign that whole blob to a pointer of the Interface type.
// C++

//     std::unique_ptr<INotifier> service = ... the giant blob from step 3 ...;

// Don't memorize the final blob. Memorize the process of writing it inside-out.
// Rule #3: The "Relay Race" Execution Mental Model

// When you need to trace service->send(), don't look at the code block. Use a mental image of a relay race.

//     The variable held by the client (service) is the Starting Line.

//     Each object is a Runner.

//     The m_wrapped pointer is the Baton.

// How to trace:

//     Put your finger on the outermost layer (SMS). Say: "Do your specific job." (Print "SMS sending...").

//     Move your finger along the baton (pointer) to the next layer inside.

//     Repeat until you hit the core object that has no baton to pass.