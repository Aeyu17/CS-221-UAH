/*
TwoDay.h - This file includes the declaration of the TwoDay class.
Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Intended for CS 221-03, Spring 2024 with Mrs. Delugach
Using compiler g++, Apple clang version 15.0.0
*/

#pragma once

#include <string>
#include "Package.h"
using namespace std;

const float DEFAULT_FLAT_FEE = 9.00;

class TwoDay : public Package
{
    float flatFee;

    public:
        TwoDay();
        TwoDay(string newName, string newAddress, int newOunces, float newCostPerOunce, float newFlatFee);
        ~TwoDay();

        float GetTwoDayFee();

        void SetTwoDayFee(float newFee);

        float CalculateTotalCost();
        void PrintInfo();
};