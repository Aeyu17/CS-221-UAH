#include "Package.h"
#include "Overnight.h"
#include "TwoDay.h"

#include <string>
#include <iostream>

int main() {
    Package pkg1;
    Package pkg2("Jamie", "Pyeongtaek", 2, 1); // ounces should default to 5

    std::string name = "";
    std::string address = "";

    pkg1.GetNameAndAddress(name, address);

    std::cout << name << " " << address << '\n';
    std::cout << pkg1.GetCostPerOz() << " " << pkg1.GetNumOz() << "\n\n";
    pkg1.PrintInfo();

    pkg2.GetNameAndAddress(name, address);

    std::cout << name << " " << address << '\n';
    std::cout << pkg2.GetCostPerOz() << " " << pkg2.GetNumOz() << "\n\n";
    pkg2.PrintInfo();

    pkg1.SetName("Brooks");
    pkg1.SetAddress("Gadsden");
    pkg1.SetCostPerOz(7.25);
    pkg1.SetNumOz(10);

    pkg1.GetNameAndAddress(name, address);

    std::cout << name << " " << address << '\n';
    std::cout << pkg1.GetCostPerOz() << " " << pkg1.GetNumOz() << "\n\n";
    pkg1.PrintInfo();


    Overnight overnight_pkg1;
    Overnight overnight_pkg2("Sofia", "Madrid", 3, 10, 11);

    overnight_pkg1.GetNameAndAddress(name, address);

    std::cout << name << " " << address << '\n';
    std::cout << overnight_pkg1.GetExtraPerOz() << '\n';
    std::cout << overnight_pkg1.GetCostPerOz() << " " << overnight_pkg1.GetNumOz() << "\n\n";
    overnight_pkg1.PrintInfo();

    overnight_pkg2.GetNameAndAddress(name, address);

    std::cout << name << " " << address << '\n';
    std::cout << overnight_pkg2.GetExtraPerOz() << '\n';
    std::cout << overnight_pkg2.GetCostPerOz() << " " << overnight_pkg2.GetNumOz() << "\n\n";
    overnight_pkg2.PrintInfo();

    overnight_pkg1.SetName("Emily");
    overnight_pkg1.SetAddress("Guntersville");
    overnight_pkg1.SetCostPerOz(2);
    overnight_pkg1.SetNumOz(15);
    overnight_pkg1.SetExtraPerOz(5);

    
    overnight_pkg1.GetNameAndAddress(name, address);

    std::cout << name << " " << address << '\n';
    std::cout << overnight_pkg1.GetExtraPerOz() << '\n';
    std::cout << overnight_pkg1.GetCostPerOz() << " " << overnight_pkg1.GetNumOz() << "\n\n";
    overnight_pkg1.PrintInfo();


    TwoDay twoday_pkg1;
    TwoDay twoday_pkg2("Wilson", "Chelmsford", 8, 10, 7);

    twoday_pkg1.GetNameAndAddress(name, address);

    std::cout << name << " " << address << '\n';
    std::cout << twoday_pkg1.GetTwoDayFee() << '\n';
    std::cout << twoday_pkg1.GetCostPerOz() << " " << twoday_pkg1.GetNumOz() << "\n\n";
    twoday_pkg1.PrintInfo();

    twoday_pkg2.GetNameAndAddress(name, address);

    std::cout << name << " " << address << '\n';
    std::cout << twoday_pkg2.GetTwoDayFee() << '\n';
    std::cout << twoday_pkg2.GetCostPerOz() << " " << twoday_pkg2.GetNumOz() << "\n\n";
    twoday_pkg2.PrintInfo();

    twoday_pkg1.SetName("Aaron");
    twoday_pkg1.SetAddress("London");
    twoday_pkg1.SetCostPerOz(6);
    twoday_pkg1.SetNumOz(12);
    twoday_pkg1.SetTwoDayFee(5);

    twoday_pkg1.GetNameAndAddress(name, address);

    std::cout << name << " " << address << '\n';
    std::cout << twoday_pkg1.GetTwoDayFee() << '\n';
    std::cout << twoday_pkg1.GetCostPerOz() << " " << twoday_pkg1.GetNumOz() << "\n\n";
    twoday_pkg1.PrintInfo();
}