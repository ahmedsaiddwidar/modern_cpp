// #include<iostream>
// #include<algorithm>
// #include<memory>
// #include<string>
// #include<vector>


// //The "Subscriber" contract.
// class Iobserver{
//     public:
//     //When the destructor is virtual:The program calls Derived’s destructor first Then calls Base’s destructor(serve polymorphism)
//     // and default to tell the compiler that to Generate the normal, automatic version of this function for me.
//     virtual ~Iobserver() = default;

//     // The Subject calls this method on all observers when data changes.
//     // We pass the new data directly here (This is a "Push" model).
//     virtual void update(float tmep, float humidity) = 0;
// };

// //The "Publisher" contract.
// class Isubject{
//     public:

//     virtual ~Isubject() = default;


//     // Methods to manage the subscription list
//     // Notice we use raw pointers here. The Subject does not OWN the observers.
//     // It just knows their addresses so it can call them.
//     virtual void attach(Iobserver *observerPtr) = 0;
//     virtual void detach(Iobserver *observerPtr) = 0;
//     virtual void notify() = 0;

// };

// //THE CONCRETE SUBJECT (Weather Data)
// class weatherData :public Isubject{
//     private:

//     std::vector<Iobserver*>observersList;

//     float m_temp;
//     float m_humidity;

//     public:

//     // Add a subscriber to the list
//     void attach(Iobserver *observer) override{

//         observersList.push_back(observer);

//         std::cout << "[Subject] An observer has attached.\n";
//     }

//     // Remove a subscriber from the list (Modern C++ idiom)
//     void detach(Iobserver *observer) override{

//         // This is the standard "erase-remove" idiom to remove an item from a vector by value.
//         observersList.erase(
//             std::remove(observersList.begin(), observersList.end(), observer),
//             observersList.end()
//         );


//         std::cout << "[Subject] An observer has detached.\n";
//     }
//         // The core logic: Loop through the list and tell everyone.
//         void notify() override{
//             std::cout << "\n[Subject] Notifying all " << observersList.size() << " observers...\n";
            
//             // Range-based for loop over the raw pointers
//             for(Iobserver* obs : observersList){

//                 obs ->update(m_humidity, m_temp);
//             }
//         }

//         void setMeasurements(float hum, float tem){

//             m_humidity = hum;
//             m_temp = tem;

//             // Crucial step: Data changed, so notify observers!
//             notify();
//         }

// };

// class currentDisplay : public Iobserver{
//     private :

//     uint32_t id;

//     public:

//     currentDisplay(uint32_t ID):
//     id(ID){

//     }

//     void update(float temperature, float humidity) override {
//         std::cout << "  -> [Display ID " << id << "] shows: Temp "
//                   << temperature << "C, Humidity " << humidity << "%\n";
//     }

// };

// class heatAlertSystem : public Iobserver{
//     public:

//     void update(float temperature, float humidity) override {
//         if (temperature > 30.0f) {
//             std::cout << "  -> [ALERT SYSTEM] ***** RED ALERT! Extreme heat detected! *****\n";
//         }
//         // If temp is <= 30, this observer does nothing.
//     }
// };



// int main() {

//     // 1. Create the Subject (the weather station)
//     // We use unique_ptr for ownership in main.
//     auto weatherStation = std::make_unique<weatherData>();

//     // 2. Create the Observers (the displays)
//     auto display1 = std::make_unique<currentDisplay>(120);
//     auto display2 = std::make_unique<currentDisplay>(200);
//     auto heatAlert = std::make_unique<heatAlertSystem>();

//     std::cout << "--- System Starting up ---\n";


//     // 3. Register Observers with the Subject
//     // Note: .get() retrieves the raw pointer from the unique_ptr to pass to attach()
//     weatherStation ->attach(display1.get());
//     weatherStation ->attach(display2.get());

//     weatherStation ->attach(heatAlert.get());

//    // --- Scenario 1: Mild Weather ---
//     // The station gets new data. It automatically triggers notify().
//     weatherStation->setMeasurements(24.5f, 65.0f);

//     // --- Scenario 2: Heatwave ---
//     // The heat alert system should trigger this time.
//     weatherStation->setMeasurements(35.2f, 40.0f);

//     // --- Scenario 3: One display breaks (detaches) ---
//     std::cout << "\n--- Display 202 is going offline ---\n";
//     weatherStation->detach(display2.get());

//     // --- Scenario 4: New data comes in ---
//     // Only display 101 and the alert system should respond now.
//     weatherStation->setMeasurements(28.0f, 70.0f);

//     std::cout << "\n--- System Shutting Down ---\n";
//     // unique_ptrs clean up memory automatically.
//     return 0;

// }

Here are deterministic, simple summaries for your quick review or interview preparation.

I. The Three Main Categories of Design Patterns

These categories classify patterns based on their intent.

    Creational Patterns: Focus on object creation mechanisms. They abstract the instantiation process, helping to make a system independent of how its objects are created, composed, and represented (e.g., avoiding "hard-coded" new operators).

    Structural Patterns: Focus on how classes and objects are composed to form larger structures. They help ensure that if one part of a system changes, the entire structure doesn't need to change.

    Behavioral Patterns: Focus on communication between objects, how duties are assigned, and the algorithms used. They are concerned with the assignment of responsibilities between objects.

II. Specific Pattern Summaries

1. Observer Pattern (Behavioral)

    Intent: Defines a one-to-many dependency between objects so that when one object (the Subject) changes state, all its dependents (Observers) are notified and updated automatically.

    Mechanism:

        The Subject holds a list of pointers to an IObserver interface.

        The Subject doesn't know the concrete types of the observers.

        When the Subject's state changes, it iterates through the list and calls a virtual update() method on each observer pointer.

    Analogy: A newsletter subscription. The publisher sends new issues to everyone on the subscriber list; they don't need to know who the subscribers are personally.

2. Proxy Pattern (Structural)

    Intent: Provides a surrogate or placeholder for another object to control access to the original object. Both the proxy and the real object implement the same interface.

    Common Use Case (Virtual Proxy): Used for "Lazy Initialization." It delays the creation of an expensive resource (like loading a huge file) until it is absolutely needed.

    Mechanism: The Proxy holds a pointer to the Real Object (initially null). When the client calls a method on the Proxy, the Proxy checks if the Real Object exists. If not, it creates it, then delegates the call to the Real Object.

3. Singleton Pattern (Creational)

    Intent: Ensures a class has only one instance and provides a global point of access to that instance.

    Mechanism:

        Make the class constructor private so it cannot be instantiated from outside.

        Hold a static member variable containing the single instance of the class.

        Provide a public static method (often called getInstance()) that returns that sole instance.

