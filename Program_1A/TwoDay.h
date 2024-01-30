/*
TwoDay.h - This file includes the declaration of the TwoDay class.
Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Intended for CS 221-03, Spring 2024 with Mrs. Delugach
Using compiler g++, Apple clang version 15.0.0
*/

#pragma once

#include <string>
using namespace std;

class TwoDay 
{
    string name;
    string address;
    float costPerOunce;
    int ounces;
    float flatFee;

    public:
        TwoDay();
        TwoDay(string newName, string newAddress, int newOunces, float newCostPerOunce, float newFlatFee);
        ~TwoDay();

        string GetNameAndAddress();
        float GetCostPerOz();
        int GetNumOz();
        float GetTwoDayFee();

        void SetName(string newName);
        void SetAddress(string newAddress);
        void SetCostPerOz(float newCost);
        void SetNumOz(int newOunces);
        void SetTwoDayFee(float newFee);

        float CalculateTotalCost();
        void PrintInfo();
};