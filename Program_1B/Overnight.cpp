/*
Overnight.cpp - This file includes the function definitions of the Overnight class.
Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Intended for CS 221-03, Spring 2024 with Mrs. Delugach
Using compiler g++, Apple clang version 15.0.0
*/

#include <string>
#include <iostream>
#include "Overnight.h"

using namespace std;

// CONSTRUCTORS AND DESTRUCTORS

Overnight::Overnight()
{
    extraCostPerOunce = DEFAULT_EXTRA_COST;

    cout << "Welcome to Gaoli shipping! This is our Overnight package service provided by Jamie Roberson!\n";
}

Overnight::Overnight(string newName, string newAddress, int newOunces, float newCostPerOunce, float newExtraCostPerOunce)
{
    SetName(newName);
    SetAddress(newAddress);
    SetNumOz(newOunces);
    SetCostPerOz(newCostPerOunce);
    SetExtraPerOz(newExtraCostPerOunce);

    cout << "Welcome to Gaoli shipping! This is our Overnight package service provided by Jamie Roberson!\n";
}

Overnight::~Overnight()
{
    cout << "We hope to see you again!\n";
}

// GETTERS

float Overnight::GetExtraPerOz()
{
    return extraCostPerOunce;
}

// SETTERS

void Overnight::SetExtraPerOz(float newExtraCost)
{
    if (newExtraCost > MARGIN)
    {
        extraCostPerOunce = newExtraCost;
    }
    else if (newExtraCost < -MARGIN)
    {
        extraCostPerOunce = -newExtraCost;
    }
    else
    {
        extraCostPerOunce = DEFAULT_EXTRA_COST;
    }
}

// HELPER FUNCTIONS

float Overnight::CalculateTotalCost()
{
    return GetNumOz() * (GetCostPerOz() + extraCostPerOunce);
}

void Overnight::PrintInfo()
{
    Package::PrintInfo("Overnight", GetNumOz() * extraCostPerOunce);
}