#include<iostream>
#include<memory>
#include<string>

// This is the interface that all things created by the factory
// must adhere to. The client only ever talks to this interface.
class Itransport{

    public:

    virtual ~Itransport() = default;

    virtual void delivery () const = 0;
};


// The specific implementations of the product.
class truck : public Itransport{

    public:

    void delivery() const override{

        std::cout<<"[truck] Delivering cargo by truck in a container.\n";
    }
};

class ship : public Itransport{

    public:

    void delivery() const override{

        std::cout<<"[Ship] Delivering cargo by sea in a container.\n";
    }
};

//This class declares the "Factory Method".
class logisticCreator{

    public:

    virtual ~logisticCreator() = default;


    // This is the core of the pattern. It's pure virtual.
    // Subclasses *must* implement this to decide which object to create.
    // It returns a unique_ptr to the abstract ITransport interface.
    virtual std::unique_ptr<Itransport> createTransport() const = 0;


    // An example of a function that uses the factory method.
    // This shows that the base class doesn't know *what* transport it's using,
    // it just knows it has one.
    void planDelivery() const{

        std::cout << "Logistics App: Starting delivery plan...\n";

        std::unique_ptr<Itransport>transport = this ->createTransport();

        transport->delivery();

        std::cout << "Logistics App: Plan finished.\n\n";
    }
};

// These classes override the factory method to return a specific product type.
class roadLogistics : public logisticCreator{

    public:

    std::unique_ptr<Itransport> createTransport() const override{

        std::cout << "  -> (Factory creating a Truck)\n";

        return std::make_unique<truck>();
    }
};

class seaLogistics : public logisticCreator{

    public:

    std::unique_ptr<Itransport> createTransport() const override{

        std::cout << "  -> (Factory creating a ship)\n";

        return std::make_unique<ship>();
    }
};

// The client code works with the abstract Creator and abstract Product.
// It doesn't need to know about 'Truck' or 'Ship' classes directly.
void runBusinessLogic(logisticCreator& creator){

    std::cout << "Client: I'm not aware of the specific class, but I'm launching app.\n";

    creator.planDelivery();
}

int main() {
    std::cout << "--- App Launched ---\n\n";

    std::cout << "Scenario 1: The business needs road transport.\n";
    // We instantiate the specific factory we need.
    std::unique_ptr<logisticCreator> roadApp = std::make_unique<roadLogistics>();
    // The client code runs without knowing it's dealing with trucks.
    runBusinessLogic(*roadApp);


    std::cout << "Scenario 2: The business needs sea transport.\n";
    // We instantiate a different factory.
    std::unique_ptr<logisticCreator> seaApp = std::make_unique<seaLogistics>();
    runBusinessLogic(*seaApp);

    std::cout << "--- App Closing ---\n";
    // unique_ptrs clean up everything automatically.
    return 0;
}