#include <iostream> // hash symbol is a way of including preprocessing directive
#include <ctime> // for seeding
// #iostream is the header file 
void printIntroduction(int levelDifficulty){
    std::cout << "You are a secret agent breaking into a level "<<levelDifficulty;
    std::cout << " \nsecure server room... Enter the correct code to continue...\n";
}
bool playGame(int levelDifficulty){
    //first we print an introduction to the game
    printIntroduction(levelDifficulty);
    //2nd we play game.

    //decleration statements
    //using varaibles, that can be changed at run time
    //int, double, char, string, float types
    int CodeA = rand() % levelDifficulty+ levelDifficulty; //returns 0-9, modulus value is our difficult level, increase the diffculty
    int CodeB = rand() % levelDifficulty + levelDifficulty;
    int CodeC = rand() % levelDifficulty+ levelDifficulty;

    //to indure complete randomness we use a seed. 
    int CodeSum =  CodeA + CodeB + CodeC; //operators include +, / ,*, c
    int CodeProduct = CodeA*CodeB*CodeC;
    //known as expression statements
    std::cout <<"\nThere are 3 numbers in the code" <<"\n";
    std::cout <<"The code add-up to: "<<CodeSum<<"\n";
    std::cout <<"The code multiply to give:  "<<CodeProduct<<"\n";
    // std::cout <<"The sum is " <<sum<< std::endl; //print the sum of a, b and c
    //std::cout <<"The product is " <<product<< std::endl; //print the sum of a, b and c
    //const varaibles, are varaibles that cannot be changed after being declared.
    
    //players input
    int GuessA,GuessB,GuessC; //players guess
    //cin is the way for taking input from the user.
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "you entered for guess A: "<< GuessA<<" for guess b: "<<GuessB<<" for Guess c: "<<GuessC<<"\n";
    // const int GuessSum, GuessProduct;
     const int GuessSum = GuessA+GuessB+ GuessC;
     const int GuessProduct = GuessA*GuessB*GuessC;
     std::cout << "The sum of your guess is: "<< GuessSum<<"\n";
     std::cout << "The product of your guess is: "<< GuessProduct<<"\n";

     //if statements

     if(GuessSum == CodeSum && GuessProduct == CodeProduct)
         return true;
     return false;
}
int main(){ //main returns a zero
    srand(time(NULL)); //creates a new seed at the start of the game.  seeding based on the time of day

    //call function

    int levelDifficulty = 1;
    int maxDifficulty = 5;

    while(levelDifficulty <= maxDifficulty ){ //loop until all levels are completed. 
        bool bLevelComplete = playGame(levelDifficulty);
        std::cin.clear();//clears any errors
        std::cin.ignore();//discards the buffer

        if (bLevelComplete){
            std::cout<<"\n successfully  extracted files, well done! moving on to the next level..\n";
            ++levelDifficulty;
        }else{
            std::cout<<"\nCareful, you've entered the incorrect code\n";
        }
    }//end while loop
    std::cout<<"\nCongrats you've finished all the levels, and recovered all the super top secret files\n";
    return 0;
}//end program
