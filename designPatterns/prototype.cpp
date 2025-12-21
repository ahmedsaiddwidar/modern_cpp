#include <iostream>
#include <string>
#include <vector>
#include <memory>  // For std::unique_ptr
#include <thread>  // To simulate slow loading
#include <chrono>  // Time durations

// ==========================================
// 1. THE PROTOTYPE INTERFACE
// ==========================================
// The contract ensuring reports can copy themselves.
class IReportPrototype {
public:
    virtual ~IReportPrototype() = default;
    // The crucial clone method
    virtual std::unique_ptr<IReportPrototype> clone() const = 0;
    // Helper to view report contents
    virtual void preview() const = 0;
};


// ==========================================
// 2. CONCRETE PROTOTYPE (The Heavy Object)
// ==========================================
class CorporateReport : public IReportPrototype {
private:
    // --- "Heavy" Data (Shared/Copied to all clones) ---
    // Connecting to a DB and loading images takes time.
    std::string m_databaseConnectionToken;
    std::string m_companyLogoData;

    // --- "Light" Data (Unique to each clone) ---
    std::string m_departmentName;
    std::string m_reportContent;

    // Simulate the expensive initialization process
    void establishHeavyResources() {
        std::cout << "  [Report Constructor] Authenticating with DB Server & Loading Hi-Res Logo... (Wait 2s)\n";
        // Simulate network/disk delay
        std::this_thread::sleep_for(std::chrono::seconds(2));
        m_databaseConnectionToken = "AUTH_TOKEN_XYZ987";
        m_companyLogoData = "[Standard Header/Footer Image Binary Data]";
        std::cout << "  [Report Constructor] Heavy resources ready.\n";
    }

public:
    // --- Standard Constructor (SLOW) ---
    // Runs once for the master template.
    CorporateReport() {
        m_departmentName = "TEMPLATE_DEPT";
        m_reportContent = "TEMPLATE_CONTENT";
        establishHeavyResources();
    }

    // --- THE CLONE IMPLEMENTATION (FAST) ---
    std::unique_ptr<IReportPrototype> clone() const override {
        // The magic line again.
        // Invokes the default C++ copy constructor.
        // It performs a fast RAM-to-RAM copy of the heavy tokens and logo data.
        return std::make_unique<CorporateReport>(*this);
    }

    // --- Lightweight Modifiers ---
    // Used to customize the report AFTER cloning.
    void customizeReport(std::string dept, std::string content) {
        m_departmentName = std::move(dept);
        m_reportContent = std::move(content);
    }

    void preview() const override {
        std::cout << "---------------------------------\n";
        std::cout << "REPORT PREVIEW [Addr: " << this << "]\n";
        std::cout << "DB Connection: " << m_databaseConnectionToken << " | Logo Loaded: Yes\n";
        std::cout << "TO:   " << m_departmentName << " Department\n";
        std::cout << "BODY: " << m_reportContent << "\n";
        std::cout << "---------------------------------\n";
    }
};


// ==========================================
// 3. CLIENT CODE
// ==========================================
int main() {
    std::cout << "--- Report System Startup ---\n";

    // 1. Create the Master Template (The "Expensive" part)
    std::cout << "Initializing Master Report Template...\n";
    // This line will hang for 2 seconds.
    auto masterTemplate = std::make_unique<CorporateReport>();
    std::cout << "Master Template Initialized.\n\n";


    std::cout << "--- Monday Morning Reporting Batch Starting ---\n";

    // 2. Create Report for Sales Dept (FAST)
    std::cout << "Generating Sales Report via cloning...\n";
    // INSTANT copy. No 2-second wait.
    auto salesReportPtr = masterTemplate->clone();
    // Cast back to concrete type to customize
    //You cannot press the specific "customize" button yet, because the Universal Remote doesn't have it.
    //You need a way to trade the Universal Remote for the specific one. That is what dynamic_cast does.
    auto salesReport = dynamic_cast<CorporateReport*>(salesReportPtr.get());
    if (salesReport) {
        salesReport->customizeReport("SALES", "Q3 revenue is up 15%. Good job.");
    }

    // 3. Create Report for IT Dept (FAST)
    std::cout << "Generating IT Report via cloning...\n";
    // INSTANT copy.
    auto itReportPtr = masterTemplate->clone();
    auto itReport = dynamic_cast<CorporateReport*>(itReportPtr.get());
    if (itReport) {
        itReport->customizeReport("IT SECURITY", "Please remind staff to change passwords.");
    }


    std::cout << "\n--- Verifying Outputs ---\n";
    // Look closely at the output:
    // They have different memory addresses and different custom content.
    // But they ALL have the same heavy DB token and Logo data.
    std::cout << "Master Template State:\n";
    masterTemplate->preview();
    std::cout << "\nSales Report State:\n";
    salesReportPtr->preview();
    std::cout << "\nIT Report State:\n";
    itReportPtr->preview();

    std::cout << "\n--- System Shutdown ---\n";
    return 0;
}