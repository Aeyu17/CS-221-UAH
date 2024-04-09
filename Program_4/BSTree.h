/*
BSTree.h - Declaration of the BSTree class.
Intended for Program 4 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#pragma once

#include <string>
#include "ItemType.h"
#include <iostream>

using namespace std;

struct TreeNode
{
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

class BSTree
{
    private:
        TreeNode* root;
        TreeNode* curPos;
        int count;
        int maxCapacity;
        bool resetCalled;

        void deepCopyTree(TreeNode* &node, const TreeNode* copiedNode);
        
        bool putItemRecursive(ItemType item, TreeNode* &node);
        ItemType getItemRecursive(ItemType item, bool &found, TreeNode* node);
        bool deleteItemRecursive(ItemType item, TreeNode* &node);

        void makeEmptyRecursive(TreeNode* &node);
        void printTreeRecursive(TreeNode* node, int &count);
        void printTreeFormRecursive(TreeNode* node, int level);
        int getHeight(TreeNode* node);
        int getCountRecursive(TreeNode* node);

    public:
        BSTree();
        BSTree(const BSTree &copy);
        void operator=(const BSTree &copy);
        ~BSTree();
        
        bool PutItem(ItemType item);
        ItemType GetItem(ItemType item, bool &found);
        bool DeleteItem(ItemType item);

        void ResetTree();
        ItemType GetNext();

        void MakeEmpty();
        void PrintTree();
        void PrintTreeForm();
        int GetCount();
};