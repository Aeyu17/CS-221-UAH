#include "CityList.h"
#include "ItemType.h"

int main() {
    CityList list(6);

    list.PrintList();

    ItemType item1(20040817, "Las Vegas");
    ItemType item2(19910710, "Frankfurt");
    ItemType item3(19630715, "St Louis");
    ItemType item4(19670615, "Bangkok");
    ItemType item5(20030503, "Guntersville");
    ItemType item6(20040308, "Madrid");
    ItemType item7(20031112, "Scranton");
    ItemType item0;

    bool found = false;
    list.GetItem(item1, found);
    cout << list.DeleteItem(item1) << '\n';

    list.PutItem(item1);
    list.PutItem(item2);
    list.PutItem(item3);
    list.PutItem(item1);
    list.PutItem(item4);
    list.PutItem(item5);
    list.PutItem(item6);
    list.PutItem(item7);
    list.PrintList();

    cout << list.DeleteItem(item1) << '\n';
    cout << list.DeleteItem(item1) << '\n';

    list.PrintList();

    CityList* copyList = new CityList(list);

    list.PutItem(item7);
    copyList->DeleteItem(item2);

    copyList->PrintList();

    delete copyList;
    copyList = nullptr;

    for (int i = 0; i < list.GetLength() + 2; i++) {
        list.GetNext().PrintInfo();
        cout << '\n';
    }
    cout << '\n';

    list.ResetList();

        for (int i = 0; i < list.GetLength() + 4; i++) {
        list.GetNext().PrintInfo();
        cout << '\n';
    }

    list.PrintList();

    list.GetItem(item1, found);
    cout << found << '\n';
    list.GetItem(item4, found);
    cout << found << '\n';
    list.GetItem(item6, found);
    cout << found << '\n';

    list.DeleteItem(item6);

    list.PutItem(item0);
    list.GetItem(item0, found);
    cout << found << '\n';

    list.PrintList();
}