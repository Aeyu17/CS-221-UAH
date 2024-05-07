/*
Sort.h - Declaration of the Sort virtual class.
Intended for Program 5 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/
#pragma once

class Sort
{
    private:
        bool showWork;

    public:
        Sort();
        ~Sort();

        bool GetShowWork();
        void SetShowWork(bool showingWork);
        virtual void Sorted(int array[], int len) = 0;
        virtual void Print(int array[], int len) = 0;
};