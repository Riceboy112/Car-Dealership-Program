#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string> // Needed for strings
#include <iomanip> // Needed for fix point
#include <vector> // Needed to use vectors
#include <fstream> // Needed for the use of files
#include "vehicle.h" // Includes vehicle.h
#include <stdio.h> // Needed for comma seperation
using namespace std;
// This will hold all the global fucntions for each menu option stated in main.cpp

void displayInventory(vector<Cars> inventory)
{
    // If the inventory is empty, it will display this message.
    if(inventory.empty())
    {
        cout << "\nThe inventory is empty, enter some entries first" << endl << endl;
    }
    
    // The else will display the information of the car in order from top to bottom
    else
    {
        for(int x = 0; x < inventory.size(); x++)
        {
            cout << setprecision(2) << fixed;
            cout << "\nVehicle: # " << x+1 << endl;
            cout << "\nVIN: " << inventory[x].getVIN() << endl;
            cout << "\nMake: " << inventory[x].getMake() << endl;
            cout << "\nModel: " << inventory[x].getModel() << endl;
            cout << "\nYear: " << inventory[x].getYear() << endl;
            cout << "\nPrice: $" << inventory[x].getPrice() << endl;
            cout << "\nDealer Name: Courtesy of Acura" << endl;
            cout << "\nDealer Address: 7590 S Broadway Centennial, CO 80122" << endl;
        }
        cout << "\nThat is the end of the inventory" << endl;
    }
}

// Function call to seperate the numbers with commas in the appropriate places
// Does not work approiately
void printComma (double getPrice)
{
    if (getPrice < 0)
    {
        printf ("-");
        printComma (-getPrice);
        return;
    }
    if (getPrice < 1000)
    {
        printf ("%d", getPrice);
        return;
    }
    printComma (getPrice/1000);
   // printf (",%03d", getPrice%1000); // This brings up an error code
}


vector<Cars> addVehicle(vector<Cars> inventory)
{
    int num; // Assigns int to num
    cout << "Enter any number to begin. Enter -1 when you are finished." << endl;
    cin >> num; // Gets input from user stored in num
    
    while(num != -1) // Loops if the user doesn't enter -1
    {
        
        string iVIN, iMake, iModel; // Assigns strings to these variable
        int iYear;  // Assigns int to this variable
        double iPrice; // Assigns double to this variable
        
        // Displays questions for the user to input the answers. Stores the inputted answers
        cout << "Enter the VIN of the vehicle" << endl;
        cin >> iVIN;
        cout << "Enter the Make of the vehicle" << endl;
        cin >> iMake;
        cout << "Enter the Model of the vehicle" << endl;
        cin >> iModel;
        cout << "Enter the year of the vehicle" << endl;
        cin >> iYear;
        cout << "Enter the price of the vehicle" << endl;
        cin >> iPrice;
        
        // Makes the inventory have enough space to hold the new information tahts was recently inputted
        inventory.push_back(Cars(iVIN, iMake, iModel, iYear, iPrice));
        cout << "\nEnter any number to add another vehicle or -1 to exit." << endl;
        cin >> num;
        
    }
    
    return inventory;
}

vector<Cars> updateVehicle(vector<Cars> inventory)
{
    // If the inventory is empty, it will display this message.
    if(inventory.empty())
    {
        cout << "\nThe inventory is empty" << endl;
        return inventory;
    }
    
    // Ask the user what vehicle he wants to update and which info the user wants to update
    else
    {
        int update; // Assigns int to update
        cout << "There is " << inventory.size() << " vehicles currently in the inventory." << endl;
        cout << "The VIN # for these vehicles are as follows: " << endl;
        
        // Displays the inventory by VIN along with a number associated with them
        for (int a = 0; a < inventory.size(); a++)
        {
            cout << a + 1 << ". " << inventory[a].getVIN() << endl;
        }
        
        // Allows the user which vehicle he wants to update
        cout << "Enter the inventory number of the vehicle you wish to update." << endl;
        cin >> update;
        
        // ALlows the user to pick what information they want to update
        if(update < inventory.size() + 1)
        {
            int pick;
            cout << "What would you like to update for this vehicle?" << endl;
            cout << "1.     VIN" << endl;
            cout << "2.     Make" << endl;
            cout << "3.     Model" << endl;
            cout << "4.     Year" << endl;
            cout << "5.     Price" << endl;
            cin >> pick;
            
            string iVIN, iMake, iModel;
            double iPrice;
            int iYear;
            
            // Switch statement that take user int the specific one of which information he wants to update 
            switch(pick)
            {
                case 1: // Updates the VIN
                {
                    cout << "Enter the vehicle's new VIN" << endl;
                    cin >> iVIN;
                    inventory[update - 1].setVIN(iVIN);
                    cout << "You have sucessfully updated the vehicle's VIN" << endl;
                }
                    break;
                case 2: // Updates the Make
                {
                    cout << "Enter the vehicle's new Make" << endl;
                    cin >> iMake;
                    inventory[update - 1].setMake(iMake);
                    cout << "You have sucessfully updated the vehicle's Make" << endl;
                }
                    break;
                case 3: // Updates the model
                {
                    cout << "Enter the vehicle's new Model" << endl;
                    cin >> iModel;
                    inventory[update - 1].setModel(iModel);
                    cout << "You have sucessfully updated the vehicle's Model" << endl;
                }
                    break;
                case 4: // Updates the Year
                {
                    cout << "Enter the vehicle's new Year" << endl;
                    cin >> iYear;
                    inventory[update - 1].setYear(iYear);
                    cout << "You have sucessfully updated the vehicle's Year" << endl;
                }
                    break;
                case 5: // Updates the price
                {
                    cout << "Enter the vehicle's new Price" << endl;
                    cin >> iPrice;
                    inventory[update - 1].setPrice(iPrice);
                    cout << "You have sucessfully updated the vehicle's Price" << endl;
                }
                    break;
                default: // Error message of one of the 5 cases above is not selected 
                {
                    cout << "Error, invalid selection" << endl;
                }
            }
        }
        
        // Displays error message if invalid selection is picked
        else
        {
            cout << "Error, invalid selection" << endl;
        }
        return inventory;
    }
}
vector<Cars> deleteVehicle(vector<Cars> inventory)
{
    // If the inventory is empty, it will display this message.
    if(inventory.empty())
    {
        cout << "The inventory is empty, enter some enteries first" << endl;
    }
    
    // The code to delete the selected vehicle
    else
    {
        int erase;
        cout << "There is " << inventory.size() << " vehicles currently stored in the inventory" << endl;
        cout << "The VIN for the vehicles are as follows: " << endl;
        
        // Gets the inventory by the vehicle VIN number
        for (int b = 0; b < inventory.size(); b++)
        {
            cout << b + 1 << ". " << inventory[b].getVIN() << endl;
        }
        
        // Lets the user pick which inventory he would like to delete
        cout << "Enter the inventory number you would like to delete" << endl;
        cin >> erase;
        
        if(erase < inventory.size() + 1)
        {
            for (int c = erase - 1; c < inventory.size() - 1; c++)
            {
                inventory[c] = inventory[c + 1];
            }
            inventory.pop_back();  //last vector element is deleted
            
            cout << "You have sucessfully deleted the vehicle" << endl;
        }
        
        // Displays error message if a vehicle is not found or deleted
        else
        {
            cout << "Error, invalid selection" << endl;
        }
    }
    return inventory;
}

vector<Cars> sortInventory (vector<Cars> inventory)
{
    // If the inventory is empty, it will display this message.
    if(inventory.empty())
    {
        cout << "The inventory is empty, enter some entries first" << endl;
    }
    
    // Sorts the inventory by the vehicle's VIN number
    else
    {
        cout << "\nSorting the inventory list by the VIN number" << endl;
        
        bool swap;
        Cars temp1;
        Cars temp2;
        
        do
        //while (swap = true)
        {
            swap = false;
            
            for(int count = 0; count < inventory.size() - 1; count++)
            {
                if(inventory[count].getVIN() > inventory[count + 1].getVIN())
                {
                    temp1 = inventory[count];
                    temp2 = inventory[count + 1];
                    inventory[count] = temp2;
                    inventory[count + 1] = temp1;
                    swap = true;
                }
            }
        }while(swap);
    }
    return inventory;
}

void searchInventory (vector<Cars> inventory)
{
    // If the inventory is empty, it will display this message.
    if(inventory.empty())
    {
        cout << "The inventory is empty, enter some entries first" << endl;
    }
    
    // Searches for the vehicle by the Make name
    else
    {
        int index = 0;
        int position = -1;
        string carMake;
        bool found = false;
        
        cout << "Enter the Make of the vehicle you wish to search" << endl;
        cin >> carMake;
        cout << "\nSearching for the vehicle now" << endl;
        
        // Searches for the make of the car. If found it will display the inventory number for it. Not found it will display an error message
        while(index < inventory.size() && !found)
        {
            if(inventory[index].getMake() == carMake)
            {
                found = true;
                position = index;
            }
            index++;
        }
        if(position == -1)
        {
            cout << "Error, could not find the Make: " << carMake << " in our inventory" << endl;
        }
        else
        {
            cout << "Vehicle found!" << endl;
            cout << carMake << " is #" << position + 1 << " in the inventory" << endl;
        }
    }
}

vector<Cars> readInventory (vector<Cars> inventory)
{
    cout << "\nReading from the file called inventory.txt" << endl;
    string iModel, iMake, iVIN;
    int iYear;
    double iPrice;
    
    ifstream dataFile;
    dataFile.open("inventory.txt"); // Opens file
    if(dataFile)
    {
        // Reads all teh data from the file inventory.txt
        while(!dataFile.eof())
        {
            dataFile >> iVIN;
            dataFile >> iMake;
            dataFile >> iModel;
            dataFile >> iYear;
            dataFile >> iPrice;
            dataFile.ignore(25, '\n');
            inventory.push_back(Cars(iVIN, iMake, iModel, iYear, iPrice));
        }
        cout << "\nThe data file was sucessfully read from inventory.txt" << endl;
        dataFile.close(); // Closes the file
        return inventory;
    }
    
    // Displays error message if the file could not be read
    else
    {
        cout << "Error, file could not be read from inventory.txt" << endl;
        return inventory;
    }
}

void writeInventory (vector<Cars> inventory)
{
    cout << "\nWriting the contents of the inventory to the file inventory.txt" << endl;
    ofstream outputFile;
    outputFile.open("inventory.txt"); // Opens the file
    if(outputFile)
    {
        
        // Starts writing all the information from the inventory to the file called inventory.txt
        cout << "\nThe file has been open sucessfully" << endl;
        for(int d = 0; d < inventory.size(); d++)
        {
            outputFile << setprecision(2) << fixed;
            outputFile << inventory[d].getVIN() << endl;
            outputFile << inventory[d].getMake() << endl;
            outputFile << inventory[d].getModel() << endl;
            outputFile << inventory[d].getYear() << endl;
            outputFile << inventory[d].getPrice() << endl;
        }
        outputFile.close(); // Closes the file
        cout << "\nThe data has been sucessfully been save to the file inventory.txt" << endl;
    }
    
    // Displays error message of the file could not be written
    else
    {
        cout << "Error, the inventory could not be written to the file" << endl;
    }
}

#endif
