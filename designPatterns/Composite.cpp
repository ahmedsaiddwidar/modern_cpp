#include<iostream>
#include<vector>
#include<memory>
#include<string>

// ==========================================
// 1. THE COMPONENT INTERFACE
// ==========================================
// The contract: Everyone in the company must be able to answer this question.
class IEmployee {
public:
    virtual ~IEmployee() = default;
    virtual int getSalaryCost() const = 0; // The crucial common method
    virtual std::string getName() const = 0; // Just for helpful output
};

// ==========================================
// 2. THE LEAF (Individual Worker)
// ==========================================
// A simple unit. They manage nobody.
// Their cost is just their own salary.

class IndividualWorker : public IEmployee{
private:
    std::string m_name;
    int m_salary;
public:
    IndividualWorker(const std::string& name, int salary)
    // we used std::move for efficiency as the compiler calls move constructor of std::string if we did not use it the compiler calls copy constructor of std::string
        : m_name(std::move(name)), m_salary(salary) {}

    int getSalaryCost() const override {
        std::cout << "   -> (Leaf) Getting salary for " << m_name << ": $" << m_salary << "\n";
        return m_salary;
    }

    std::string getName() const override {
        return m_name;
    }    
};
// ==========================================
// 3. THE COMPOSITE (Manager)
// ==========================================
// A complex unit. They have their own salary, PLUS they hold a list of subordinates.
class Manager : public IEmployee {
private:
    std::string m_name;
    int m_ownSalary;

    // === THE CORE MECHANISM ===
    // A list of pointers to the INTERFACE.
    // The Manager owns these subordinate objects.
    std::vector<std::unique_ptr<IEmployee> > m_subordinates;


public:
    Manager(const std::string& name, int ownSalary)
    : m_name(std::move(name)), m_ownSalary(ownSalary) {}

    // Helper to build the tree structure
    void addSubordinate(std::unique_ptr<IEmployee> emp) {
        m_subordinates.push_back(std::move(emp));
    }

    std::string getName() const override {
        return m_name + "(Manager)";
    }

    int getSalaryCost() const override {

        std::cout << "[Composite] " << m_name << " is calculating total department cost...\n";

        int totalCost = m_ownSalary; // Start with own salary

        // Loop through the vector of interface pointers.
        // We don't know if 'sub' is a Worker or another Manager. We just call the interface method.
        
        for(const auto& sub: m_subordinates) {
            totalCost += sub ->getSalaryCost();
        }
        std::cout << "[Composite] " << m_name << " department total finished: $" << totalCost << "\n";

        return totalCost;
    }

};

// ==========================================
// 4. CLIENT CODE
// ==========================================
int main() {
    std::cout << "--- Building Organization Chart ---\n";

    // 1. Create Leaves (Bottom level workers)
    auto dev1 = std::make_unique<IndividualWorker>("Alice Dev", 60000);
    auto dev2 = std::make_unique<IndividualWorker>("Bob Dev", 65000);
    auto designer1 = std::make_unique<IndividualWorker>("Charlie Design", 70000);

    // 2. Create Mid-level Composites (Managers)
    auto techLead = std::make_unique<Manager>("Dave TechLead", 90000);
    auto designLead = std::make_unique<Manager>("Eve DesignLead", 95000);

    // 3. Create Top-level Composite (CEO)
    auto ceo = std::make_unique<Manager>("Frank CEO", 200000);

    // 4. Assemble the structure (put people under managers)
    techLead->addSubordinate(std::move(dev1));
    techLead->addSubordinate(std::move(dev2));

    designLead->addSubordinate(std::move(designer1));

    // Put managers under the CEO
    ceo->addSubordinate(std::move(techLead));
    ceo->addSubordinate(std::move(designLead));

    std::cout << "Org chart built successfully.\n\n";


    // 5. The Client Action
    // We ask the SINGLE top object for the total.
    std::cout << "--- Requesting Total Company Salary Cost ---\n";
    int totalCompanyCost = ceo->getSalaryCost();

    std::cout << "\n=============================================\n";
    std::cout << "FINAL RESULT: Total Company Cost: $" << totalCompanyCost << "\n";
    std::cout << "=============================================\n";

    // Automatic cleanup happens here when 'ceo' goes out of scope.
    return 0;
}
