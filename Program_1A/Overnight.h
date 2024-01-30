/*
Overnight.h - This file includes the declaration of the Overnight class.
Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Intended for CS 221-03, Spring 2024 with Mrs. Delugach
Using compiler g++, Apple clang version 15.0.0
*/

#pragma once

#include <string>
using namespace std;

class Overnight 
{
    string name;
    string address;
    float costPerOunce;
    int ounces;
    float extraCostPerOunce;

    public:
        Overnight();
        Overnight(string newName, string newAddress, int newOunces, float newCostPerOunce, float newExtraCostPerOunce);
        ~Overnight();

        string GetNameAndAddress();
        float GetCostPerOz();
        int GetNumOz();
        float GetExtraPerOz();

        void SetName(string newName);
        void SetAddress(string newAddress);
        void SetCostPerOz(float newCost);
        void SetNumOz(int newOunces);
        void SetExtraPerOz(float newExtraCost);

        float CalculateTotalCost();
        void PrintInfo();
};