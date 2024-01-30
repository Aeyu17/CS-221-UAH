/*
Overnight.cpp - This file includes the function definitions of the Overnight class.
Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Intended for CS 221-03, Spring 2024 with Mrs. Delugach
Using compiler g++, Apple clang version 15.0.0
*/

#include <string>
#include <iostream>
#include <iomanip>
#include "Overnight.h"
using namespace std;

// CONSTRUCTORS AND DESTRUCTORS

Overnight::Overnight() 
{
    name = "Undefined";
    address = "nowhere";
    costPerOunce = 1.0;
    ounces = 6;
    extraCostPerOunce = 1.0;

    cout << "Welcome to Gaoli shipping! This is our Overnight package service provided by Jamie Roberson! Please provide your information!\n";
}

Overnight::Overnight(string newName, string newAddress, int newOunces, float newCostPerOunce, float newExtraCostPerOunce) 
{
    name = newName;
    address = newAddress;
    costPerOunce = newCostPerOunce;
    ounces = newOunces;
    extraCostPerOunce = newExtraCostPerOunce;

    cout << "Welcome to Gaoli shipping! This is our Overnight package service provided by Jamie Roberson!\n";
}

Overnight::~Overnight() 
{
    cout << "We hope to see you again!\n";
}

// GETTERS

string Overnight::GetNameAndAddress() 
{
    return name + " " + address;
}

float Overnight::GetCostPerOz() 
{
    return costPerOunce;
}

int Overnight::GetNumOz() 
{
    return ounces;
}

float Overnight::GetExtraPerOz() 
{
    return extraCostPerOunce;
}

// SETTERS

void Overnight::SetName(string newName) 
{
    name = newName;
}

void Overnight::SetAddress(string newAddress) 
{
    address = newAddress;
}

void Overnight::SetCostPerOz(float newCost) 
{
    if (newCost > 0) 
    {
        costPerOunce = newCost;
    }
}

void Overnight::SetNumOz(int newOunces) 
{
    if (newOunces >= 6) 
    {
        ounces = newOunces;
    }
    else
    {
        ounces = 6;
    }
}

void Overnight::SetExtraPerOz(float newExtraCost) 
{
    if (newExtraCost > 0)
    {
        extraCostPerOunce = newExtraCost;
    }
}

// HELPER FUNCTIONS

float Overnight::CalculateTotalCost() 
{
    return ounces * (costPerOunce + extraCostPerOunce);
}

void Overnight::PrintInfo() 
{
    cout << "Ship to: " << setw(15) << name << '\n';
    cout << setw(24) << address << '\n';
    cout << "Method: " << setw(16) << "Overnight" << '\n';
    cout << "Package Weight: " << setw(8) << ounces << '\n';
    cout << "Total Cost: " << setw(12) << CalculateTotalCost() << '\n';
}