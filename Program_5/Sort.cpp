/*
Sort.cpp - Definition of the Sort virtual class.
Intended for Program 5 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#include "Sort.h"

Sort::Sort()
{
    showWork = false;
}

Sort::~Sort()
{
    // does nothing
}

bool Sort::GetShowWork()
{
    return showWork;
}

void Sort::SetShowWork(bool showingWork)
{
    showWork = showingWork;
}