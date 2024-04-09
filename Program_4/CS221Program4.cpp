/*
CS221Program4.cpp - Test Driver for Program 4.
Intended for Program 4 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#include "BSTree.h"
#include <iostream>
#include <fstream>

using namespace std;

void requestData(ItemType &item);

// change this as needed, normally it won't let me use the relative name for some reason?
const string INPUT_ROUTE = "./ClientList.csv";
const string OUTPUT_ROUTE = "./ClientsSorted.csv";

int main() 
{
    ifstream input(INPUT_ROUTE);
    ofstream output(OUTPUT_ROUTE);

    if (!input || !output)
    {
        cout << "One of the files could not be opened.\n";
        return 1;
    }

    BSTree* tree = new BSTree;
    string line;

    while (!input.eof())
    {
        getline(input, line);
        int first_comma = line.find(',');
        int last_comma = line.find_last_of(',');

        string name = line.substr(0, first_comma);
        string address = line.substr(first_comma + 1, last_comma - first_comma - 1);
        string phoneNumber = line.substr(last_comma + 1, line.length() - last_comma);
        ItemType item(name, address, phoneNumber);

        if (name == "" || address == "" || phoneNumber == "")
        {
            continue;
        }
        item.PrintInfo();
        cout << '\n';
        tree->PutItem(item);
    }

    int choice = 0;
    
    while (choice != 7)
    {
        choice = 0;
        cout << "\nClient Data Search System\n\n";
        while (choice <= 0 || choice > 7)
        {
            cout << "Choose one:\n";
            cout << "1: Add a client.\n";
            cout << "2: Delete a client.\n";
            cout << "3: Retrieve a client.\n";
            cout << "4: Print the data storage tree.\n";
            cout << "5: Print the data storage tree in tree form.\n";
            cout << "6: Write sorted data to file.\n";
            cout << "7: Exit menu.\n";
            getline(cin, line);

            try
            {
                choice = stoi(line);
            }
            catch(const exception &error)
            {
                cout << "Invalid input.\n";
            }
        }

        ItemType item, retrievedItem;
        bool successful;
        string name, address, phoneNumber;
        switch (choice)
        {
            case 1:
                cout << "You have chosen to add a client.\n";

                requestData(item);

                successful = tree->PutItem(item);
                if (successful)
                {
                    cout << "The item was added successfully.\n";
                }
                else
                {
                    cout << "The item was not able to be added.\n";
                }
                
                break;
            case 2:
                cout << "You have chosen to delete a client.\n";

                requestData(item);

                successful = tree->DeleteItem(item);
                if (successful)
                {
                    cout << "The item has been successfully deleted.\n";
                }
                else
                {
                    cout << "The item was not able to be deleted.\n";
                }

                break;
            case 3:
                cout << "You have chosen to retrieve a client.\n";

                cout << "What is the client's name?\n";
                getline(cin, name);
                item.SetData(name, "nowhere", "2568675309"); // assuming you can look up the name without knowing the address or the phone number

                retrievedItem = tree->GetItem(item, successful);

                if (successful)
                {
                    cout << "The item has been successfully found with the following data:\n";

                    name = retrievedItem.GetData(address, phoneNumber);
                    cout << "Name: " << name << '\n';
                    cout << "Address: " << address << '\n';
                    cout << "Phone number: " << phoneNumber << '\n';
                }
                else
                {
                    cout << "We were unable to find anyone with that name.\n";
                }

                break;
            case 4:
                cout << "You have chosen to print the data storage tree.\n";

                tree->PrintTree();

                break;
            case 5:
                cout << "You have chosen to print the data storage tree in tree form.\n";

                tree->PrintTreeForm();

                break;
            case 6:
                cout << "You have chosen to write the sorted data to a file.\n";

                tree->ResetTree();

                cout << tree->GetCount() << '\n';

                for (int index = 0; index < tree->GetCount(); index++)
                {
                    item = tree->GetNext();
                    name = item.GetData(address, phoneNumber);
                    output << name << ',' << address << ',' << phoneNumber << '\n';
                }

                cout << "The data has been written to the file.\n";
                break;
            case 7:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Unknown input detected.\n";
                break;
        }
    }

    input.close();
    output.close();

    return 0;
}

void requestData(ItemType &item)
{
    string name, address, phoneNumber;
    cout << "What is the client's name?\n";
    getline(cin, name);

    cout << "\nWhat is the client's address?\n";
    getline(cin, address);

    cout << "\nWhat is the client's phone number?\n";
    getline(cin, phoneNumber);

    cout << "\nThank you.\n";
    item.SetData(name, address, phoneNumber);
}