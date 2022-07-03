#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string> // Needed for strings
#include <iomanip> // Needed for fix point
#include <vector> // Needed to use vectors
#include <fstream> // Needed for the use of files
using namespace std;


// Creates the private and public classes
class Cars
{
    private: // Everything below is private until it hits the public
    string VIN; // Holds the VIN in data type string
    string Make; // Holds the Make in data type string
    string Model; // Holds the Model in the data type string
    int Year; // Holds years in the data type int
    double Price; // Holds price in the data type double
    
    public: // Everthing below is public
    Cars(string iVIN, string iMake, string iModel, int iYear, double iPrice); // Constructor
    Cars(); // Constructor
    string getVIN(); // Calls to gets the VIN and displays it
    string getMake(); // Calls to get the Make and displays it
    string getModel(); // Calls to get the Model and displays it
    int getYear(); // Calls to get the Year and displays it
    double getPrice(); // Calls to get the Price and displays it
    void setVIN(string); // Sets the VIN of the member variable VIN
    void setMake(string); // Sets the Make of the member variable Make
    void setModel(string); // Sets the Model of the member variable Model
    void setYear(int); // Sets the Year of the member variable Year
    void setPrice(double); // Sets the Price of the member variable Price
};


#endif
