#include<iostream>
#include<string>
#include<memory>


#define ahmed 10

class IPaymentsStrategies{

public:

    virtual ~IPaymentsStrategies() = default;
    

    virtual void pay(double amount) const = 0;
};

class CreditcardPayment : public IPaymentsStrategies{

private:

    std::string creditcardNumber;
    std::string cvv;

public:

    CreditcardPayment(std::string ccNum, std::string CvvNum):
    creditcardNumber(ccNum), cvv(CvvNum){}

    void pay(double amount)const override{

        std::cout<<"processing credit card payment of $"<<amount<<"using card ending with"
        <<creditcardNumber.substr(creditcardNumber.length() - 4)<<std::endl;
        // (Real implementation would contact a payment gateway here)
    }
};

class PayPalPayment : public IPaymentsStrategies{

private:
    std::string email;
public:
    PayPalPayment(std::string emailAddr) : email(std::move(emailAddr)) {}

    void pay(double amount) const override {
        std::cout << "Processing PayPal payment of $" << amount 
                  << " using email account: " << email << ".\n";
        // (Real implementation would redirect to PayPal login)
    }
};

class ShoppingCart{
    public:
        std::unique_ptr<IPaymentsStrategies> m_paymentMethod;
        double m_totalAmount;

    public:
        ShoppingCart():
        m_paymentMethod(nullptr), m_totalAmount(0.0){}

    void addItem(double price){
        m_totalAmount += price;
    }

    void setPaymentMethod(std::unique_ptr<IPaymentsStrategies> strategy){
        std::cout<<"switching payment method"<<std::endl;

        m_paymentMethod = std::move(strategy);
    }

    void checkout(void){
        if(! m_paymentMethod){
            std::cout << "Error: No payment method selected!\n";
            return;
        }
        std::cout << "[Cart] Starting checkout...\n";
        // Delegate the work to the current strategy.
        
        m_paymentMethod ->pay(m_totalAmount);
        
        std::cout << "[Cart] Checkout complete.\n\n";
    }
};


int main(){
    std::cout << "--- Online Store Opening ---\n";

    ShoppingCart cart;
    cart.addItem(50.00);
    cart.addItem(150.25);
    std::cout << "Items added to cart.\n\n";

    // --- Scenario 1: User chooses Credit Card ---
    std::cout << "User selects Credit Card option.\n";
    // Create the specific strategy and hand ownership to the cart.
    cart.setPaymentMethod(std::make_unique<CreditcardPayment>("1234567812345678", "999"));
    cart.checkout();

    std::cout << "--- Later that day (Runtime switching) ---\n";

    // --- Scenario 2: User changes mind, switches to PayPal ---
    cart.addItem(25.00); // Add another item
    std::cout << "User decides to switch payment method to PayPal.\n";
    // We just call the setter again with a different type of object.
    cart.setPaymentMethod(std::make_unique<PayPalPayment>("buyer@example.com"));
    
    // The cart doesn't care that the method changed. It just calls pay().
    cart.checkout();

    std::cout << "--- Store Closing ---\n";
    // ShoppingCart goes out of scope. Its unique_ptr member is destroyed.
    // The currently held strategy (PayPalPayment) is automatically deleted.

    return 0;
}
// 2. What the Assignment Line does

// When you write: m_paymentMethod = std::move(strategy);

// You are calling the move assignment operator of the std::unique_ptr. This operator performs three crucial steps in a specific order, invisible to you:

// Step 1: Clean up the old tenant (Very Important!) Before taking on new responsibility, m_paymentMethod checks: "Do I currently own something?"

//     If yes (e.g., it was holding the old Credit Card strategy), it immediately deletes that old object to prevent a memory leak.

//     If no (it was nullptr), it does nothing.

// Step 2: Steal the new resource It looks inside the strategy pointer, takes the raw memory address of the new PayPal object, and stores it inside m_paymentMethod.

// Step 3: Empty the source It sets the strategy pointer to nullptr. The source pointer is now empty and owns nothing.