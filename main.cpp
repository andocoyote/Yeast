#include <windows.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <memory>
#include <vector>

#include "yeast.h"

using namespace std;

// Displays the user menu, returns the menu selection
int menu(); 

// Align Glusose so we can use it with InterlockedDecrement
__declspec(align(32)) LONG Glucose = 0;

// Begin main function
void main()
{
    UINT choice; // Menu choice from user
    BOOL exit = false;	// User wants to exit program?
    UINT selection = 0;
    UINT yeastCount = 0;
    WCHAR* yeast1Name = L"Saccaromyces Cerevisiae";
    WCHAR* yeast2Name = L"Brettanomyces bruxellensis";
    vector<unique_ptr<Yeast>> yeast;

    do // while (!exit)
	{
        choice = menu(); // Display user menu and get selection

        switch(choice) // Perform switch on choice from menu
        {
				// User wants to create yeast
        case 1: wcout << L"How many yeast would you like to create? (int): ";
                wcin >> yeastCount;
                
                for(DWORD i = 0; i < yeastCount; i++)
                {
                    unique_ptr<Yeast> tempYeast(new Yeast(yeast1Name, &Glucose));
                
                    if(tempYeast)
                    {
                        wcout << yeast1Name << " created.\n";
                        yeast.push_back(std::move(tempYeast));
                    }
                    else
                    {
                        wcout << "Failed to create " << yeast1Name << ".\n";
                    }
                }
                
                wcout << yeast.size() << " yeast were created.\n";
                
                exit = false; 
                break;
				
				// User wants to add more glucose
        case 2: wcout << L"How much glucose would you like to create? (int): ";
                wcin >> selection;
				
                // TODO: Use mutex to += glucose for user's entered value
                Glucose += selection;
                
                exit = false; 
                break;
        
        case 0: exit = true;
                break;
				
        default:
                break;
        }

    }while(!exit);//End do while loop for main program

}//End of main program

//-----------------------------------------------------------------------

//Beginning of menu()
int menu()
{
    int selection; //Holds the user's menu choice

	//Display the menu
    wcout << L"Please choose from the following options" << endl;
    wcout << L"1.  Create yeast" << endl;
    wcout << L"2.  Create glucose" << endl;
    wcout << L"0.  Exit the program" << endl;
    wcout << L": ";
    wcin >> selection; //Get the selection from the menu

    return selection; //Return the selection to main program
}//End function menu()

//-----------------------------------------------------------------------

