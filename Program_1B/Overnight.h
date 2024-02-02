/*
Overnight.h - This file includes the declaration of the Overnight class.
Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Intended for CS 221-03, Spring 2024 with Mrs. Delugach
Using compiler g++, Apple clang version 15.0.0
*/

#include "Package.h"
using namespace std;

const float DEFAULT_EXTRA_COST = 1.20;

class Overnight : public Package
{

    float extraCostPerOunce;

    public:
        Overnight();
        Overnight(string newName, string newAddress, int newOunces, float newCostPerOunce, float newExtraCostPerOunce);
        ~Overnight();

        float GetExtraPerOz();

        void SetExtraPerOz(float newExtraCost);

        float CalculateTotalCost();
        void PrintInfo();
};