/*
TwoDay.cpp - This file includes the function definitions of the TwoDay class.
Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Intended for CS 221-03, Spring 2024 with Mrs. Delugach
Using compiler g++, Apple clang version 15.0.0
*/

#include "TwoDay.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


// CONSTRUCTORS AND DESTRUCTORS

TwoDay::TwoDay() 
{
    name = "Undefined";
    address = "nowhere";
    costPerOunce = 1.0;
    ounces = 6;
    flatFee = 1.0;

    cout << "Welcome to Gaoli shipping! This is our Two Day package service provided by Jamie Roberson! Please provide your information!\n";
}

TwoDay::TwoDay(string newName, string newAddress, int newOunces, float newCostPerOunce, float newFlatFee) 
{
    name = newName;
    address = newAddress;
    costPerOunce = newCostPerOunce;
    ounces = newOunces;
    flatFee = newFlatFee;

    cout << "Welcome to Gaoli shipping! This is our Two Day package service provided by Jamie Roberson!\n";
}

TwoDay::~TwoDay() 
{
    cout << "We hope to see you again!\n";
}

// GETTERS

string TwoDay::GetNameAndAddress() 
{
    return name + " " + address;
}

float TwoDay::GetCostPerOz() 
{
    return costPerOunce;
}

int TwoDay::GetNumOz() 
{
    return ounces;
}

float TwoDay::GetTwoDayFee() 
{
    return flatFee;
}

// SETTERS

void TwoDay::SetName(string newName) 
{
    name = newName;
}

void TwoDay::SetAddress(string newAddress) 
{
    address = newAddress;
}

void TwoDay::SetCostPerOz(float newCost) 
{
    if (newCost > 0) 
    {
        costPerOunce = newCost;
    }
}

void TwoDay::SetNumOz(int newOunces) 
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

void TwoDay::SetTwoDayFee(float newFee) 
{
    if (newFee > 0) 
    {
        flatFee = newFee;
    }
    
}

// HELPER FUNCTIONS

float TwoDay::CalculateTotalCost() 
{
    return ounces * costPerOunce + flatFee;
}

void TwoDay::PrintInfo() 
{
    cout << "Ship to: " << setw(15) << name << '\n';
    cout << setw(24) << address << '\n';
    cout << "Method: " << setw(16) << "TwoDay" << '\n';
    cout << "Package Weight: " << setw(8) << ounces << '\n';
    cout << "Total Cost: " << setw(12) << CalculateTotalCost() << '\n';

}