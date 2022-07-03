// Nicholas Kong
// PA3 Assignment: a program to manage a car dealership
// Status: Completed
// CSCI 1410 
// 4/30/2017

#include <iostream>
#include <string> // Needed for strings
#include <iomanip> // Needed for fix point
#include <vector> // Needed to use vectors
#include <fstream> // Needed for the use of files
#include "functions.h" // Holds global functions for each menu items
#include "vehicle.h" // Contains class declarations for vehicle and dealer
using namespace std;

// Function prototypes
void displayInventory(vector<Cars> inventory);
vector<Cars> addVehicle(vector<Cars> inventory);
vector<Cars> updateVehicle(vector<Cars> inventory);
vector<Cars> deleteVehicle(vector<Cars> inventory);
vector<Cars> sortInventory(vector<Cars> inventory);
void searchInventory(vector<Cars> inventory);
vector<Cars> readInventory(vector<Cars> inventory);
void writeInventory(vector<Cars> inventory);


// Contains the menu selection and the choices along with the switch statement 
int main ()
{
    vector<Cars> inventory;
    int choice; // Lets the user pick a number from the menu stored in choice
    
    // Lets the user know they are in a dealership program
    cout << "Welcome to Courtesy of Acura dealership!" << endl;
    cout << "Please input the number of the option you would like to select" << endl;
    
    // Displays the menu choice along with giving the user a choice to pick.
    while (choice != 8) // Puts the user in the loop unless choice 8 is selected
    {
    cout << "\n1: Display Inventory" << endl;
    cout << "2: Add a vehicle" << endl;
    cout << "3: Update a vehicle" << endl;
    cout << "4: Delete a vehicle" << endl;
    cout << "5: Sort inventory by VIN" << endl;
    cout << "6: Search inventory by Model" << endl;
    cout << "7: Read inventory from file" << endl;
    cout << "8: Write inventory to file and exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    // Reads the choice the user and executes the case number correlated with the user inputed choice
    switch (choice)
    {
        case 1 : displayInventory(inventory);
            cout << "You are now back in the main menu!" << endl;
                // function call to void displayInventory
         //   printComma(getPrice); Tried to have the comma seperation placed accurately when price id displayed
        break;
        case 2 :  inventory = addVehicle(inventory);
            cout << "You are now back in the main menu!" << endl;
                // Function call to void addVehicle
        break;
        case 3 :  inventory = updateVehicle(inventory);
            cout << "You are now back in the main menu!" << endl;
                // Function call to void updateVehicle
        break;
        case 4 :  inventory = deleteVehicle(inventory);
            cout << "You are now back in the main menu!" << endl;
                // Function call to deleteVehicle
        break;
        case 5 :  inventory = sortInventory(inventory);
            cout << "You are now back in the main menu!" << endl;
                // Function call to sortInventory
        break;
        case 6 :  searchInventory(inventory);
            cout << "You are now back in the main menu!" << endl;
                // Function call to searchInventory
        break;
        case 7 :  inventory = readInventory(inventory);
            cout << "You are now back in the main menu!" << endl;
                // Function call to readInventory
        break;
        case 8 :  writeInventory(inventory);
            cout << "thank you for using Courtesy of Acura Car Dealership Program!" << endl;
                // Function call to writeInventory and exits the program 
        break;
            
    default: cout << "Please input a number from the options stated in the menu" << endl;
            
    }
    }
    return 0;
}


