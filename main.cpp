#include <windows.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <memory>

#include "yeast.h"

using namespace std;

int menu(); //displays the user menu, returns the menu selection

// Align Glusose so we can use it with InterlockedDecrement
__declspec(align(32)) LONG volatile Glucose = 5;

//begin main function
void main()
{
	UINT choice; //menu choice from user
	BOOL exit = false;	//user wants to exit program?
	WCHAR selection = L'n';
    unique_ptr<Yeast> yeast1 = nullptr;
    unique_ptr<Yeast> yeast2 = nullptr;

	do //while (!exit)
	{
		choice = menu(); //display user menu and get selection

		switch(choice) //perform switch on choice from menu
		{
				//user wants to add a name to the list
		case 1: wcout << L"Playing with yeast:\n";

                yeast1 = unique_ptr<Yeast>(new Yeast(&Glucose));
                yeast2 = unique_ptr<Yeast>(new Yeast(&Glucose));
                
                while(Glucose > 0)
                {
                    yeast1->Print();
                    yeast1->Run();
                    
                    yeast2->Print();
                    yeast2->Run();
                }
                
				exit = false; 
				break;
				
				// User wants to sort via Selection Sort
		case 2: wcout << L"Do you want to show the sorting algorithm's work? (y/n): ";
				wcin >> selection;
				
				exit = false; 
				break;
				
				// User wants to sort via Insertion Sort
		case 3: wcout << L"Do you want to show the sorting algorithm's work? (y/n): ";
				wcin >> selection;
				
				exit = false; 
				break;
				
				// User wants to sort via Bubble Sort
		case 4: wcout << L"Do you want to show the sorting algorithm's work? (y/n): ";
				wcin >> selection;
				
				exit = false; 
				break;

				//user wants to exit the program
		case 0: exit = true;
				break;
				
		default:
				break;
		}

	}while(!exit);//end do while loop for main program

}//end of main program

//-----------------------------------------------------------------------

//beginning of menu()
int menu()
{
	int selection; //holds the user's menu choice

	//display the menu
	wcout << L"Please choose from the following options" << endl;
	wcout << L"1.  Display the array" << endl;
	wcout << L"2.  Sort the array using Selection Sort" << endl;
	wcout << L"3.  Sort the array using Insertion Sort" << endl;
	wcout << L"4.  Sort the array using Bubble Sort" << endl;
	wcout << L"0.  Exit the program" << endl;
	wcout << L": ";
	wcin >> selection; //get the selection from the menu

	return selection; //return the selection to main program
}//end function menu()
