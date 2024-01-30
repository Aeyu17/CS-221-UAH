#include "TwoDay.h"
#include "Overnight.h"
#include <iostream>

int main() {
    TwoDay package1;
    TwoDay package2("Jamie", "601 John Wright Dr.", 14, 10.0, 2.0);
    Overnight package3;
    Overnight package4("Emily", "Guntersville", 12, 2, 4);

    std::cout << package1.GetNameAndAddress() << '\n';
    std::cout << package1.GetCostPerOz() << '\n';
    std::cout << package1.GetNumOz() << '\n';
    std::cout << package1.GetTwoDayFee() << '\n';
    std::cout << package1.CalculateTotalCost() << '\n';
    package1.PrintInfo();

    std::cout << package2.GetNameAndAddress() << '\n';
    std::cout << package2.GetCostPerOz() << '\n';
    std::cout << package2.GetNumOz() << '\n';
    std::cout << package2.GetTwoDayFee() << '\n';
    std::cout << package2.CalculateTotalCost() << '\n';
    package2.PrintInfo();

    std::cout << package3.GetNameAndAddress() << '\n';
    std::cout << package3.GetCostPerOz() << '\n';
    std::cout << package3.GetNumOz() << '\n';
    std::cout << package3.GetExtraPerOz() << '\n';
    std::cout << package3.CalculateTotalCost() << '\n';
    package3.PrintInfo();

    std::cout << package4.GetNameAndAddress() << '\n';
    std::cout << package4.GetCostPerOz() << '\n';
    std::cout << package4.GetNumOz() << '\n';
    std::cout << package4.GetExtraPerOz() << '\n';
    std::cout << package4.CalculateTotalCost() << '\n';
    package4.PrintInfo();

    package1.SetName("Sofia");
    package1.SetAddress("idk dude");
    package1.SetCostPerOz(15);
    package1.SetNumOz(9);
    package1.SetTwoDayFee(14);
    
    std::cout << package1.GetNameAndAddress() << '\n';
    std::cout << package1.GetCostPerOz() << '\n';
    std::cout << package1.GetNumOz() << '\n';
    std::cout << package1.GetTwoDayFee() << '\n';
    std::cout << package1.CalculateTotalCost() << '\n';
    package1.PrintInfo();

    package3.SetName("Brooks");
    package3.SetAddress("Gadsden");
    package3.SetCostPerOz(12);
    package3.SetNumOz(10);
    package3.SetExtraPerOz(12);

    std::cout << package3.GetNameAndAddress() << '\n';
    std::cout << package3.GetCostPerOz() << '\n';
    std::cout << package3.GetNumOz() << '\n';
    std::cout << package3.GetExtraPerOz() << '\n';
    std::cout << package3.CalculateTotalCost() << '\n';
    package3.PrintInfo();
}