
#include "menu.h"
#include <iostream>
#include <string>

static void printMenu() {
    std::cout << "\n=== MENY ===\n";
    std::cout << "1) Add measurement value\n";
    std::cout << "2) Show all metrics\n";
    std::cout << "3) Show statistics\n";
    std::cout << "4) Clear all metrics\n";
    std::cout << "5) Save and exit\n";
    std::cout << "Choose: ";
}

void runMenu(DataManager& manager, const std::string& filename) {
    while (true) {
        printMenu();

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string timestamp;
            float value;

            std::cout << "Timestamp (ex: 2025-10-07 09:00): ";
            std::getline(std::cin, timestamp);

            std::cout << "Value: ";
            std::cin >> value;
            std::cin.ignore();

            manager.addMeasurement(value, timestamp);
            std::cout << "Measured values.\n";
        }
        else if (choice == 2) {
            manager.printAll();
        }
        else if (choice == 3) {
            manager.printStatistics();
        }
        else if (choice == 4) {
            manager.clear();
            std::cout << "All metrics are cleared.\n";
        }
        else if (choice == 5) {
            if (manager.saveToFile(filename)) {
                std::cout << "Saved to " << filename << ". Bye!\n";
            }
            else {
                std::cout << "Could not save the file..\n";
            }
            break;
        }
        else {
            std::cout << "Invalid selection, please try again..\n";
        }
    }
}

