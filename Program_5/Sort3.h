/*
Sort3.h - Declaration of the Sort3 class.
Intended for Program 5 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#pragma once

#include "Sort.h"
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Sort3 : public Sort
{
    public:
        Sort3();
        ~Sort3();

        void Sorted(int array[], int len) override;
        void Print(int array[], int len) override;
};