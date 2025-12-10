#include<iostream>
#include<string>
#include<optional>
#include<string_view>

1. Controls instance creation

It guarantees:

Only one object is created

You cannot create more by mistake

2. Provides a global access point

3. Ensures shared state

Since everyone uses the same instance, all clients share the same data/configuration.

4.When Singleton Is Useful

Use it when you need ONLY ONE:

Logger

Configuration manager

Database connection manager

Thread pool

Window manager in a GUI

Cache manager

class Singleton {
private:
    Singleton() { }                       // private constructor
    Singleton(const Singleton&) = delete; // disable copy
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton& getInstance() {
        static Singleton instance;        // created once, thread-safe in C++11+
        return instance;
    }

    void doSomething() {
        std::cout << "Singleton working!" << std::endl;
    }
};

// //-------------------------------------
// //define the game states using  enum
// //-------------------------------------

// enum class gameState{
//     mainMenue,
//     playing,
//     paused,
//     gameOver
// };

// //-------------------------------------
// //define the singelton class
// //-------------------------------------

// class gameWorld{
//     public:

//     // the core of the singelton logic

//     //the reference ti insure the singelton is passed by reference
//     //static function because we are able to call the function without reating an object which violated the singelton rule
//     static gameWorld& getInstance(){
        
//         static gameWorld instance;

//         return instance;
//     }

//     //we delete both the copy cinstructor and assignment operator
//     //this insures noone accidenatlly cloning the captain
//     gameWorld(const gameWorld&) = delete;
//     void operator=(const gameWorld&) = delete;


//     //-------------------------------------
//     //Game Logic
//     //-------------------------------------


//     //update the state
//     void setState(gameState newState){
//         m_state = newState;

//         std::cout<<"[Game world] state changed \n";
//     }

//     // [[nodiscard]] warns you if you call this function but ignore the result.
//     [[nodiscard]] gameState getSate(void){
//         return m_state;
//     }
    
//     //update the score
//     void addScore(uint32_t points){
//         m_points += points;

//         std::cout<<"the game is updated! the current score = "<< m_points<<std::endl;
//     }

//     // std::string_view avoids making a heavy copy of the string text.
//     void setPlayerNmae(std::string_view name){
//         m_playerName = name;
     
//         std::cout<<"[Game world] welcome,\t"<<m_playerName<<std::endl;
//     }


//     // std::optional handles cases where maybe there is no high score yet.
//     // It is much safer than returning -1 or 0.
//     [[nodiscard]] std::optional<int> getHighScore() const{

//         if(m_points > 1000){
//             return m_points;
//         }
//         return std::nullopt;
//     }

//     private:

//     // We make this private so nobody can type "GameWorld g;"
//     // They MUST use GameWorld::getInstance()
//     gameWorld(): m_points(0), m_state(gameState::mainMenue){
//         std::cout<<"----Game World is booting up (created)----\n";
//     }

//     // Private Destructor (Optional, but good for clarity)
//     ~gameWorld(){
//         std::cout<<"----Game World is shutting down----\n";
//     }


//     uint32_t m_points;
//     gameState m_state;
//     std::string m_playerName;


// };

// int main(){

//     std::cout<<"1- Program starts...\n";


//     // NOTICE: We don't create a GameWorld here. We just ask for it.
//     // The FIRST time we call this, the constructor triggers.
//     gameWorld& game = gameWorld::getInstance();

//     // Setup player using string_view (efficient)
//     game.setPlayerNmae("Ahmed Dewidar\n");

//     // Change state
//     game.setState(gameState::playing);

//     // Simulate gameplay
//     game.addScore(900);
//     game.addScore(500);
//     game.addScore(900);

//     // Check for high score using std::optional
//     std::cout << "2. Checking High Score...\n";

//     // We can use 'auto' to let the compiler deduce the type
//     auto highScore = game.getHighScore();

//     if(highScore.has_value()){
//         std::cout << "   WOW! New High Score: " << highScore.value() << "\n";
//     } 
//     else {
//         std::cout << "   Keep trying! No high score yet.\n";
//     }

//     std::cout << "3. Main Function Ending.\n";

//     return 0;
// }