/*
BSTree.cpp - Definition of the BSTree class.
Intended for Program 4 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#include "BSTree.h"

// CONSTRUCTORS AND DESTRUCTORS

BSTree::BSTree()
{
    cout << "Jamie Roberson's Veterinary Clinic: GouMao\n";
    root = nullptr;
    curPos = nullptr;
    count = 0;
    maxCapacity = 500;
}

BSTree::BSTree(const BSTree &copy)
{
    root = nullptr;
    curPos = nullptr;
    count = 0;
    maxCapacity = 500;

    deepCopyTree(root, copy.root);
}

void BSTree::operator=(const BSTree &copy)
{
    MakeEmpty();
    curPos = nullptr;
    count = 0;
    deepCopyTree(root, copy.root);
}

void BSTree::deepCopyTree(TreeNode* &node, const TreeNode* copiedNode)
{
    if (copiedNode == nullptr)
    {
        node = nullptr;
    }
    else 
    {
        node = new TreeNode();
        node->info = copiedNode->info;
        count++;
        deepCopyTree(node->left, copiedNode->left);
        deepCopyTree(node->right, copiedNode->right);
    }
}

BSTree::~BSTree()
{
    MakeEmpty();
    root = nullptr;
    curPos = nullptr;
}

// HELPER FUNCTIONS

bool BSTree::PutItem(ItemType item)
{
    if (count < maxCapacity) 
    {
        return putItemRecursive(item, root);
    }
    return false;
}
bool BSTree::putItemRecursive(ItemType item, TreeNode* &node)
{
    if (node == nullptr)
    {
        node = new TreeNode;
        node->info = item;
        node->left = nullptr;
        node->right = nullptr;

        count++;

        cout << "Added " << item.GetData() << '\n';
        return true;
    }
    else if (item > node->info)
    {
        return putItemRecursive(item, node->right);
    }
    else if (item < node->info)
    {   
        return putItemRecursive(item, node->left);
    }
    else // item is there
    {
        cout << item.GetData() << " is already in the tree!\n";
        return false;
    }
}

ItemType BSTree::GetItem(ItemType item, bool &found)
{
    cout << "Searching...\n";
    found = false;
    return getItemRecursive(item, found, root);
}
ItemType BSTree::getItemRecursive(ItemType item, bool &found, TreeNode* node)
{
    if (node == nullptr)
    {
        cout << "Not found.\n";
        found = false;
        return ItemType();
    }
    cout << item.GetData() << "  ";

    if (item > node->info)
    {
        return getItemRecursive(item, found, node->right);
    }
    else if (item < node->info)
    {
        return getItemRecursive(item, found, node->left);
    }
    else // item is there
    {
        cout << "Found.\n";
        found = true;

        string copyAddress, copyPhoneNumber;
        string copyName = node->info.GetData(copyAddress, copyPhoneNumber);
        ItemType returnedItem(copyName, copyAddress, copyPhoneNumber);

        return returnedItem;
    }
}

bool BSTree::DeleteItem(ItemType item)
{
    bool deleted = deleteItemRecursive(item, root);
    if (deleted)
    {
        cout << "Deleted " << item.GetData() << '\n';
    }

    return deleted;
}
bool BSTree::deleteItemRecursive(ItemType item, TreeNode* &node)
{
    if (node == nullptr)
    {
        return false;
    }
    else if (item > node->info)
    {
        return deleteItemRecursive(item, node->right);
    }
    else if (item < node->info)
    {
        return deleteItemRecursive(item, node->left);
    }
    else // item is there
    {
        TreeNode* replacementNode = node;
        if (node->left == nullptr && node->right == nullptr)
        {
            delete replacementNode;
            node = nullptr;
            replacementNode = nullptr;
            count--;
            return true;
        }
        else if (node->right == nullptr)
        {
            node = node->left;
            delete replacementNode;
            count--;
            return true;
        }
        else if (node->left == nullptr)
        {
            node = node->right;
            delete replacementNode;
            count--;
            return true;
        }
        else // node to delete has 2 children
        {
            replacementNode = replacementNode->left;
            while (replacementNode->right != nullptr)
            {
                replacementNode = replacementNode->right;
            }
            node->info = replacementNode->info;
            return deleteItemRecursive(replacementNode->info, node->left);
        }
    }
}

void BSTree::ResetTree()
{
    curPos = root;
    while (curPos->left != nullptr)
    {
        curPos = curPos->left;
    }
    resetCalled = true;
}

ItemType BSTree::GetNext()
{
    if (resetCalled)
    {
        resetCalled = false;
        return curPos->info;
    }
    else if (curPos == nullptr)
    {
        return ItemType();
    }
    else if (curPos->right != nullptr)
    {
        curPos = curPos->right;
        while (curPos->left != nullptr)
        {
            curPos = curPos->left;
        }
        return curPos->info;
    }
    else
    {
        TreeNode* checkedNode = root;
        TreeNode* returnedNode = nullptr;

        while (checkedNode != curPos)
        {
            if (curPos->info < checkedNode->info)
            {
                returnedNode = checkedNode;
                checkedNode = checkedNode->left;
            }
            else
            {
                checkedNode = checkedNode->right;
            }
        }
        if (returnedNode == nullptr)
        {
            return ItemType();
        }

        curPos = returnedNode;
        return returnedNode->info;
    }
}

void BSTree::MakeEmpty()
{
    makeEmptyRecursive(root);
}
void BSTree::makeEmptyRecursive(TreeNode *&node) {
    if (node != nullptr) 
    {
        makeEmptyRecursive(node->left);
        makeEmptyRecursive(node->right);
        count--;
        delete node;
        node = nullptr;
    }
}

void BSTree::PrintTree()
{
    cout << "Print tree:\n";
    int printCount = 0;
    printTreeRecursive(root, printCount);
    cout << "Tree count: " << printCount << '\n';
}
void BSTree::printTreeRecursive(TreeNode* node, int &printCount)
{
    if (node != nullptr)
    {
        printCount++;
        printTreeRecursive(node->left, printCount);
        node->info.PrintInfo();
        cout << '\n';
        printTreeRecursive(node->right, printCount);
    }
    
}

void BSTree::PrintTreeForm()
{
    int height = getHeight(root);
    for (int level = 0; level < height; level++)
    {
        printTreeFormRecursive(root, level);
        cout << '\n';
    }
}
void BSTree::printTreeFormRecursive(TreeNode* node, int level)
{   
    // very hard to get the spacing right on this approach
    if (node == nullptr && level == 0)
    {
        cout << "[] ";
    }
    else if (node == nullptr)
    {
        printTreeFormRecursive(nullptr, level - 1);
        printTreeFormRecursive(nullptr, level - 1);
    }
    else if (level == 0)
    {
        cout << node->info.GetData() << "  ";
    }
    else
    {
        printTreeFormRecursive(node->left, level - 1);
        printTreeFormRecursive(node->right, level - 1);
    }
}
int BSTree::getHeight(TreeNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int left_height = getHeight(node->left);
    int right_height = getHeight(node->right);

    return max(left_height, right_height) + 1;
}


int BSTree::GetCount()
{
    return getCountRecursive(root);
}
int BSTree::getCountRecursive(TreeNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + getCountRecursive(node->left) + getCountRecursive(node->right);
    }
}