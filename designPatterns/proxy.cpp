#include<iostream>
#include<vector>
#include<memory> // Required for std::unique_ptr
#include<chrono> // Required for time duration
#include<string>
#include<thread> // Required to simulate delay


// ==========================================
// 1. THE INTERFACE (The Contract)
// ==========================================
// This is an abstract base class. It defines what both the
// real image and the proxy *must* be able to do.
// It ensures the rest of the application doesn't need to know
// if it's holding a proxy or the real thing.
class IGraphic{
    public:


    // a pure virtual function the obhects inheriting from this class wil have their implementation of it
    virtual void display() = 0;
    

    // a vityal destructor is crutial with inheritance so that the derived classes will be cleaned correctly
    virtual ~IGraphic() = default;


};


// ==========================================
// 2. THE REAL SUBJECT (The "Heavy" Object)
// ==========================================
// This is the object that actually does the hard work.
// It takes a long time to initialize.
class realHeavyImage : public IGraphic{

    private:

    std::string fileName;

    // A private helper method to simulate heavy work
    void loadFromDisk(){

        std::cout<<"[Real Image]  Loading..."<<fileName<<"from Disk, please wait 3s"<<std::endl;

        // We pause the program for 3 seconds to simulate loading a huge file.
        std::this_thread::sleep_for(std::chrono::seconds(3));

        std::cout << "   [RealImage] Loading complete.\n";
    }

    public:

    //constructor
    realHeavyImage(const std::string& f)
    : fileName(f){

        // AS SOON AS this object is created, it runs the expensive loading process.
        loadFromDisk();
    }

    void display() override{

        std::cout << "   [RealImage] Displaying image content for: " << fileName << "\n";
    }

};

// ==========================================
// 3. THE PROXY (The "Middleman")
// ==========================================
// This is lightweight. It inherits from the same interface,
// so it "looks" just like the real thing to the outside world.
class imageProxy : public IGraphic{

    private:

    std::string fileName;

    // The Proxy holds a pointer to the real object.
    // We use unique_ptr: it manages memory automatically. If the proxy dies,
    // it automatically deletes the real image it's holding.
    // Initially, it's empty (nullptr).
    std::unique_ptr<realHeavyImage>realImagePtr;

    public:

    // Constructor: Super fast. It just stores the filename string.
    imageProxy(const std::string& f)
    : fileName(f), realImagePtr(nullptr){

        std::cout << "[Proxy] Created lightweight proxy for: " << fileName << "\n";
    
    }

  
    
    void display() override{

        std::cout << "[Proxy] Display request received.\n";


        if(realImagePtr == nullptr){

            std::cout << "[Proxy] Real image not loaded yet. Initializing now...\n";

            // Lazy Initialization: Create the heavy object NOW.
            // make_unique creates a new RealHeavyImage and puts it in the pointer.
            realImagePtr = std::make_unique<realHeavyImage>(fileName);

        }
        else{

            std::cout << "[Proxy] Real image already loaded. Using existing one.\n";
        }

        // Delegate the actual work to the real object.
        realImagePtr->display();
    }
};

//client code
int main(){

    std::cout << "--- Program Starting ---\n\n";

    // We create a list (vector) of pointers to the Interface (IGraphic).
    // The main program doesn't care if they are proxies or real images.
    std::vector<std::unique_ptr<IGraphic>>gallery;

    std::cout << "1. Creating the image gallery list...\n";
    // Notice: We are creating ImageProxy objects here, NOT RealHeavyImage objects.
    // These lines will run instantly.

    gallery.push_back(std::make_unique<imageProxy>("photo A.raw"));
    gallery.push_back(std::make_unique<imageProxy>("photo b.raw"));

    std::cout << "\nGallery list created instantly. No heavy loading happened yet.\n";
    std::cout << "--------------------------------------------------------\n\n";

    // --- Scenario 1: User wants to see the first photo ---
    std::cout << "2. User clicks on 'Photo_A.raw' to view it.\n";
    // This is the first time calling display(). The proxy will detect
    // that the real image is missing and trigger the 3-second load.
    gallery[0]->display();
    std::cout << "\n--------------------------------------------------------\n\n";


    // --- Scenario 2: User wants to see the first photo AGAIN ---
    std::cout << "3. User clicks on 'Photo_A.raw' AGAIN.\n";
    // The proxy will detect that it already holds the real image.
    // It will skip the loading and display instantly.
    gallery[0]->display();
    std::cout << "\n--------------------------------------------------------\n\n";


    // --- Scenario 3: User clicks the second photo ---
    std::cout << "4. User clicks on 'Photo_B.raw'.\n";
    // This proxy hasn't loaded its real image yet. It will take 3 seconds.
    gallery[1]->display();

    std::cout << "\n--- Program Ending (Cleanup happens automatically) ---\n";
    return 0;
}