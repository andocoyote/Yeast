#include <windows.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <memory>

#include "yeast.h"

using namespace std;

int menu(); //Displays the user menu, returns the menu selection

// Align Glusose so we can use it with InterlockedDecrement
__declspec(align(32)) LONG Glucose = 0;

//Begin main function
void main()
{
    UINT choice; //Menu choice from user
    BOOL exit = false;	//User wants to exit program?
    UINT selection = 0;
    WCHAR* yeast1Name = L"Saccaromyces Cerevisiae";
    WCHAR* yeast2Name = L"Brettanomyces bruxellensis";
    unique_ptr<Yeast> yeast1 = nullptr;
    unique_ptr<Yeast> yeast2 = nullptr;

    do //while (!exit)
	{
        choice = menu(); //Display user menu and get selection

        switch(choice) //Perform switch on choice from menu
        {
				//User wants to create yeast
        case 1: wcout << L"Creating yeast:\n";

                yeast1 = unique_ptr<Yeast>(new Yeast(yeast1Name, &Glucose));
                yeast2 = unique_ptr<Yeast>(new Yeast(yeast2Name, &Glucose));
                
                if(yeast1)
                {
                    wcout << yeast1Name << " created.\n";
                }
                else
                {
                    wcout << "Failed to create " << yeast1Name << ".\n";
                }
                
                if(yeast2)
                {
                    wcout << yeast2Name << " created.\n";
                }
                else
                {
                    wcout << "Failed to create " << yeast2Name << ".\n";
                }
                
                exit = false; 
                break;
				
				// User wants to add more glucose
        case 2: wcout << L"How much glucose would you like to create? (int): ";
                wcin >> selection;
				
                // TODO: Use mutex to += glucose for user's entered value
                Glucose += selection;
                
                exit = false; 
                break;
				
				// User wants to feed the yeast
        case 3: wcout << L"Feeding yeast\n";
				
                // While glucose exists (>0), let the yeast eat
                if(yeast1 && yeast2)
                {
                    while(Glucose > 0)
                    {
                        yeast1->Print();
                        yeast1->Run();
                        
                        yeast2->Print();
                        yeast2->Run();
                    }
                }
                
                exit = false; 
                break;

				//User wants to exit the program
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
    wcout << L"3.  Feed yeast" << endl;
    wcout << L"0.  Exit the program" << endl;
    wcout << L": ";
    wcin >> selection; //Get the selection from the menu

    return selection; //Return the selection to main program
}//End function menu()
