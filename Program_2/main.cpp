#include <string>
#include <iostream>

#include "InventoryManager.h"
#include "ItemType.h"
#include "Node.h"

using namespace std;

int main() {
    InventoryManager* carList = new InventoryManager(3);
    ItemType* item1 = new ItemType("BA 1965 Mustang GT Fastback", 48383829922); // several of these
    ItemType* item2 = new ItemType("BA 1966 Mustang GT Fastback", 19284906422);
    ItemType* item3 = new ItemType("BA 1967 Mustang GT Fastback", 12349420245);
    cout << "items made\n";
    carList->PutItem(item1);
    carList->PutItem(item2);
    carList->PutItem(item3);

    ItemType* item4 = new ItemType("BA 1968 Mustang GT Fastback", 60063324456);

    carList->PutItem(item4);

    carList->PrintList();

    bool found = false;
    ItemType* gottenItem = carList->GetItem(item1, found);
    cout << "Item 1 found is: " << found << '\n';
    if (found) {
        gottenItem->PrintInfo();
    }

    carList->PutItem(item1);
    carList->DeleteItem(item2); // Delete from several
    
    carList->PrintList();

    carList->MakeEmpty();

    carList->PutItem(item3);
    carList->PutItem(item4);
    carList->PutItem(item1);

    cout << carList->GetNext() << '\n';

    cout << carList->GetLength() << '\n';

    carList->ResetList();

    for (int i = 0; i < carList->GetLength()+2; i++) {
        cout << carList->GetNext() << '\n';
    }

    delete carList;
    carList = NULL;

}