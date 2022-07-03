#include <iostream>
#include <string> // Needed for strings
#include <iomanip> // Needed for fix point
#include <vector> // Needed to use vectors
#include <fstream> // Needed for the use of files
#include "vehicle.h"// Access to vehicle.h
// This class will contain all the class implementations 

// The Scope Resolution Operators
Cars::Cars(string iVIN, string iMake, string iModel, int iYear, double iPrice)
{
    VIN = iVIN;
    Make = iMake;
    Model = iModel;
    Year = iYear;
    Price = iPrice;
}


Cars::Cars()
{
    VIN = " ";
    Make = " ";
    Model = " ";
    Year = 0;
    Price = 0.0;
}

//Function calls with specific data instructions

// Retruns the car's VIN
string Cars::getVIN()
{
    return VIN;
}

// Returns the cars make
string Cars::getMake()
{
    return Make;
}

// Returns the car's Model '
string Cars::getModel()
{
    return Model;
}

// Returns the car's year
int Cars::getYear()
{
    return Year;
}

// Returns the car's price
double Cars::getPrice()
{
    return Price;
}

// Assigns VIN to iVIN which user places input stored as iVIN
void Cars::setVIN(string iVIN)
{
    VIN = iVIN;
}

// Assigns make to iMake which user places input stored as iMake
void Cars::setMake(string iMake)
{
    Make = iMake;
}

// Assigns Model to iModel which user places input stored as iModel
void Cars::setModel(string iModel)
{
    Model = iModel;
}

// Assigns Year to iYear which user places input stored as iYear
void Cars::setYear(int iYear)
{
    Year = iYear;
}

// Assigns Price to iPrice which user places input stored as iPrice 
void Cars::setPrice(double iPrice)
{
    Price = iPrice;
}
