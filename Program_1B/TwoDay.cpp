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

// CONSTRUCTORS AND DESTRUCTORS

TwoDay::TwoDay()
{
    flatFee = DEFAULT_FLAT_FEE;

    cout << "Welcome to Gaoli shipping! This is our Two Day package service provided by Jamie Roberson!\n";
}

TwoDay::TwoDay(string newName, string newAddress, int newOunces, float newCostPerOunce, float newFlatFee)
{
    SetName(newName);
    SetAddress(newAddress);
    SetNumOz(newOunces);
    SetCostPerOz(newCostPerOunce);
    SetTwoDayFee(newFlatFee);

    cout << "Welcome to Gaoli shipping! This is our Two Day package service provided by Jamie Roberson!\n";
}

TwoDay::~TwoDay()
{
    cout << "We hope to see you again!\n";
}

// GETTERS

float TwoDay::GetTwoDayFee()
{
    return flatFee;
}

// SETTERS

void TwoDay::SetTwoDayFee(float newFee)
{
    if (newFee > MARGIN)
    {
        flatFee = newFee;
    }
    else if (newFee < -MARGIN)
    {
        flatFee = -newFee;
    }
    else 
    {
        flatFee = DEFAULT_FLAT_FEE;
    }
}

// HELPER FUNCTIONS

float TwoDay::CalculateTotalCost()
{
    return Package::CalculateTotalCost() + flatFee;
}

void TwoDay::PrintInfo()
{
    Package::PrintInfo("TwoDay", flatFee);
}