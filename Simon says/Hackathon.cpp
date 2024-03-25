#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;

void generatePattern(int &levelNumber, string & generatedPattern)
{
    srand(time(0));
    generatedPattern = "";

    for (int i = 0; i < levelNumber+2; i++)
    {
        
        char randomChar = '!' + rand() % 90;
        cout << randomChar;
        generatedPattern = generatedPattern + randomChar;  
       
    }
    
    cout << endl;
 
}


int main() {

    string userInput;
    string generatedPattern;
    int levelNumber = 1;



    cout << "\033[95m" << "This is Siomn says game!" <<  endl;

    do   {

    cout << "\033[32m" << "You are in level " << levelNumber << endl;
    cout << "\033[0m" << "Try to remember this pattern" <<  endl;


    generatePattern(levelNumber, generatedPattern);
    sleep(5);
    system("clear");
    cin>>userInput;

    
    if (userInput == generatedPattern)
    {
        
        cout << "\033[32m" << "Nice!\n\n" ;
        levelNumber = levelNumber + 1;
    }

    else{
        cout << "\033[91m" << "YOU LOST" <<  endl;
        return 0;

    }

    
    
   } while (levelNumber <6);

    cout << "\033[32m" << "You won!" <<  endl;
   
}