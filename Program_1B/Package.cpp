/*
Package.cpp - This file includes the function definitions of the Package class.
Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Intended for CS 221-03, Spring 2024 with Mrs. Delugach
Using compiler g++, Apple clang version 15.0.0
*/

#include "Package.h"
#include <string>
#include <iostream>
using namespace std;

// CONSTRUCTORS AND DESTRUCTORS

Package::Package()
{
    name = DEFAULT_NAME;
    address = DEFAULT_ADDRESS;
    costPerOunce = DEFAULT_COST_PER_OUNCE;
    ounces = MIN_OUNCES;

    cout << "Welcome to Gaoli shipping! This is our Package service provided by Jamie Roberson!\n";
}

Package::Package(string newName, string newAddress, int newOunces, float newCost)
{
    SetName(newName);
    SetAddress(newAddress);
    SetCostPerOz(newCost);
    SetNumOz(newOunces);

    cout << "Welcome to Gaoli shipping! This is our Package service provided by Jamie Roberson!\n";
}

Package::~Package()
{
    cout << "We hope to see you again!\n";
}

// GETTERS

void Package::GetNameAndAddress(string &returnedName, string &returnedAddress)
{
    returnedName = name;
    returnedAddress = address;
}

float Package::GetCostPerOz()
{
    return costPerOunce;
}

int Package::GetNumOz()
{
    return ounces;
}

string Package::GetName()
{
    return name;
}

string Package::GetAddress()
{
    return address;
}

// SETTERS

void Package::SetName(string newName)
{
    name = newName;
}

void Package::SetAddress(string newAddress)
{
    address = newAddress;
}

void Package::SetCostPerOz(float newCost)
{
    if (newCost > MARGIN) 
    {
        costPerOunce = newCost;
    } 
    else if (newCost < -MARGIN)
    {
        costPerOunce = -newCost;
    }
    else // cost == 0
    {
        costPerOunce = DEFAULT_COST_PER_OUNCE;
    }
}

void Package::SetNumOz(int newOunces)
{
    if (newOunces >= MIN_OUNCES)
    {
        ounces = newOunces;
    }
    else 
    {
        ounces = MIN_OUNCES;
    }
}

// HELPER FUNCTIONS

float Package::CalculateTotalCost()
{
    return ounces * costPerOunce;
}

void Package::PrintInfo(string method, float extra)
{
    cout << "Ship to:           " << name << '\n';
    cout << "                   " << address << '\n';
    cout << "Method:            " << method << '\n';
    cout << "Package weight:    " << ounces << '\n';
    cout << "Total cost:        " << CalculateTotalCost() + extra << "\n\n";
}