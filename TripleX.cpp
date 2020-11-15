#include <iostream>
#include <ctime>;
using namespace std;

void ClearScreen(){
    cout << "\033[2J\033[1;1H";
    
}

void PrintIntroduction(int Difficulty){
// Print welcome messages to the terminal
    cout << "\n\n\n\nYou are a secret agent breaking into a level "<< Difficulty;
    cout << " secure server room...\nEnter the correct code to continue...\n";
    cout << "_/\\__/\\__0>";
}

bool PlayGame(int Difficulty){
    
    PrintIntroduction(Difficulty);

    // Declare 3 secret number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    cout << endl;
    cout << "+ There are 3 numbers in the code\n";
    cout << "+ The codes add up to: " << CodeSum << endl;   
    cout << "+ The code multiply to give: " << CodeProduct << endl;;

    int GuessA, GuessB, GuessC;

    // Have the user enter their guesses
    cout << endl;    
    cout << "***What is are you three guesses?" << endl;
    cin >> GuessA >> GuessB >> GuessC;
    

    // Initialize user guesses
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    

    // Check if the players guess is correct
    if (GuessSum == CodeSum && CodeProduct == GuessProduct){
        cout << "\nTHAT'S CORRECT! "; 
        return true;       
    } else {
        cout << "\nYou entered the wrong code!  Careful agent!  Try again! ***";
        return false;
    }
}

int main() 
{     
    srand(time(NULL)); // create a new random sequence based on time of day
    int const MaxLevel = 3;
    int LevelDifficulty = 1;
  
    while (LevelDifficulty <= MaxLevel) // Loop game until all levels are completed
    {
        
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();   // Clears any errors
        cin.ignore();  // Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty;            
        }
        
    }

    ClearScreen();
    cout<<"\nYou beat the game!!!!!";
    
    return 0; 
}