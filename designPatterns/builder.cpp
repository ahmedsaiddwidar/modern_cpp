#include<iostream>
#include<string>
#include<vector>
#include<memory>


// ==========================================
// 1. THE PRODUCT (The Complex Object)
// ==========================================
// This is just a data holder. It has many parts.
class Computer {
public:
    std::string cpu;
    std::string gpu;
    std::string ram;
    std::string storageType;

    bool hasRGP = false;
    bool hasWaterCooling = false;

    void ShowSpecs() const{
        std::cout << "CPU: " << cpu << "\n";
        std::cout << "GPU: " << gpu << "\n";
        std::cout << "RAM: " << ram << "\n";
        std::cout << "Storage Type: " << storageType << "\n";

        if(gpu.empty()) std::cout << " GPU: " << gpu << "\n";
        if(storageType.empty()) std::cout << " Storage Type: " << storageType << "\n";

        std::cout << "Feautures: \n" << (hasRGP ? "[RGP Leighting]" : "")
                    << (hasWaterCooling ? "[Water Cooling]" : "");

        std::cout << "---------------------------------\n";
    }

};

// ==========================================
// 2. THE BUILDER INTERFACE
// ==========================================
// Defines the steps to build a computer.
// Crucial Modern C++ Idiom: Methods return a reference to the interface type.
class IComputerBuilder {
public:
    virtual ~IComputerBuilder() = default;

    // Build steps (returning reference for chaining)
    virtual IComputerBuilder& setCPU(const std::string& cpu) = 0;
    virtual IComputerBuilder& setGPU(const std::string& gpu) = 0;
    virtual IComputerBuilder& setRAM(const std::string& ram) = 0;
    virtual IComputerBuilder& setStorageType(const std::string& storageType) = 0;

    virtual IComputerBuilder& enableRGB(bool enable) = 0;
    virtual IComputerBuilder& enableWaterCooling(bool enable) = 0;

    // The final step: Get the result and transfer ownership.
    virtual std::unique_ptr<Computer> build() = 0;
};

// ==========================================
// 3. CONCRETE BUILDER
// ==========================================
// Implements the steps to build a specific kind of computer (e.g., a Gaming Rig).
class GamingPCBuilder : public IComputerBuilder {
private:
    // The builder holds the product instance while it's being built.
    std::unique_ptr<Computer> m_computer;

public:
    GamingPCBuilder() {

        reset();
    }

    void reset() {
        m_computer = std::make_unique<Computer>();
    }

    // --- Implementation of steps ---
    // Note the 'return *this;' pattern for method chaining.

    IComputerBuilder& setCPU(const std::string& cpu) override {
        
        m_computer->cpu = cpu;
        return *this;
    }

    IComputerBuilder& setGPU(const std::string& gpu) override {
        m_computer->gpu = gpu;
        return *this;
    }

    IComputerBuilder& setRAM(const std::string& ram) override {
        m_computer->ram = ram;
        return *this;
    }

    IComputerBuilder& setStorageType(const std::string& storageType) override {
        m_computer->storageType = storageType;
        return *this;
    }

    IComputerBuilder& enableRGB(bool enable) override {
        m_computer->hasRGP = enable;
        return *this;
    }

    IComputerBuilder& enableWaterCooling(bool enable) override {
        m_computer->hasWaterCooling = enable;
        return *this;
    }

    // The final step: Get the result and transfer ownership.
    std::unique_ptr<Computer> build() override {
        std::unique_ptr<Computer> result = std::move(m_computer);
        reset(); // Prepare for the next build
        return result;
    }

};

// ==========================================
// 4. THE DIRECTOR (Optional but useful)
// ==========================================
// Knowing the *order* of steps can sometimes be complex.
// A director defines common "recipes" using the builder interface.
class PCShopDirector {
public:
    // Recipe 1: A high-end gaming machine
    void constructUltimateGamingRig(IComputerBuilder& builder) {
        builder.setCPU("AMD Ryzen 9 7950X3D")
               .setRAM("64GB DDR5 6000MHz")
               .setGPU("Nvidia RTX 4090")
               .setStorageType("4TB NVMe SSD")
               .enableRGB(true)
               .enableWaterCooling(true);
    }

    // Recipe 2: A basic office machine
    void constructOfficeBudgetPC(IComputerBuilder& builder) {
        // Notice we skip GPU, RGB, and WaterCooling.
        builder.setCPU("Intel i5-13400")
               .setRAM("16GB DDR4")
               .setStorageType("512GB SSD");
    }
};


// ==========================================
// 5. CLIENT CODE
// ==========================================
int main() {
    // Create the builder and the optional director.
    GamingPCBuilder builder;
    PCShopDirector director;

    std::cout << "--- Scenario 1: Using a Director (Pre-set recipes) ---\n";

    std::cout << "Building Ultimate Gaming Rig...\n";
    // Tell director to run its recipe using our builder
    director.constructUltimateGamingRig(builder);
    // Get the finished product from the builder
    std::unique_ptr<Computer> myGamingPC = builder.build();
    myGamingPC->ShowSpecs();


    std::cout << "\nBuilding Budget Office PC...\n";
    director.constructOfficeBudgetPC(builder);
    std::unique_ptr<Computer> myOfficePC = builder.build();
    myOfficePC->ShowSpecs();


    std::cout << "\n--- Scenario 2: Custom Build (Manual chaining) ---\n";
    // We don't need the director. We can use the builder directly for a unique custom order.
    std::cout << "Building Customer Special Order...\n";

    // LOOK AT THIS READABLE SYNTAX (Fluent Interface):
    builder.setCPU("Intel i7-13700K")
           .setGPU("AMD Radeon RX 7900 XTX")
           .setRAM("32GB DDR5")
           .enableRGB(true);

    // Finalize
    std::unique_ptr<Computer> customPC = builder.build();
    customPC->ShowSpecs();

    std::cout << "\n--- Automatic cleanup via unique_ptr ---\n";
    return 0;
}