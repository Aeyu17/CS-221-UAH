/*
Package.h - This file includes the declaration of the Package class.
Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Intended for CS 221-03, Spring 2024 with Mrs. Delugach
Using compiler g++, Apple clang version 15.0.0
*/

#pragma once

#include <string>
using namespace std;

const string DEFAULT_NAME = "Undefined";
const string DEFAULT_ADDRESS = "nowhere";
const float DEFAULT_COST_PER_OUNCE = 0.45;
const int MIN_OUNCES = 5; 
const float MARGIN = 0.001;

class Package 
{
    string name;
    string address;
    float costPerOunce;
    unsigned int ounces;

    public:
        Package();
        Package(string newName, string newAddress, int newOunces, float newCost);
        ~Package();

        void GetNameAndAddress(string &returnedName, string &returnedAddress);
        float GetCostPerOz();
        int GetNumOz();

        void SetName(string newName);
        void SetAddress(string newAddress);
        void SetCostPerOz(float newCost);
        void SetNumOz(int newOunces);

        float CalculateTotalCost();
        void PrintInfo(string method = "Package", float extra = 0.0);

    protected:
        string GetName();
        string GetAddress();
};