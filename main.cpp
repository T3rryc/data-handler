#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "data.hpp"
#include "sort.hpp"
#include "implementation.hpp"

using namespace std;

void displaySortMenu() {
    std::cout << "1. Sort by Price" << std::endl;
    std::cout << "2. Sort by Name" << std::endl;
    std::cout << "3. Sort by Max Speed" << std::endl;
    std::cout << "4. Sort by Cruise Speed" << std::endl;
    std::cout << "5. Sort by Release Year" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    std::vector<Spacecraft> spacecraft_list;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addSpacecraft(spacecraft_list);
                break;
            case 2:
                retrieveSpacecraft(spacecraft_list);
                break;
            case 3:
                updateSpacecraft(spacecraft_list);
                break;
            case 4:
                removeSpacecraft(spacecraft_list);
                break;
            case 5: {
                int num_spacecraft;
                std::cout << "Enter the number of random spacecraft to add: ";
                std::cin >> num_spacecraft;
                addRandomSpacecraft(spacecraft_list, num_spacecraft);
                break;
            }
            case 6:
                displayAllSpacecraft(spacecraft_list);
                break;
            case 7:
                displaySpacecraft(spacecraft_list);
                break;
            case 8: {
                int sort_choice;
                displaySortMenu();
                std::cin >> sort_choice;
                switch (sort_choice) {
                    case 1:
                        mergeSort(spacecraft_list, 0, spacecraft_list.size() - 1, compareByPrice);
                        std::cout << "Spacecraft list sorted by price." << std::endl;
                        break;
                    case 2:
                        mergeSort(spacecraft_list, 0, spacecraft_list.size() - 1, compareByName);
                        std::cout << "Spacecraft list sorted by name." << std::endl;
                        break;
                    case 3:
                        mergeSort(spacecraft_list, 0, spacecraft_list.size() - 1, compareByMaxSpeed);
                        std::cout << "Spacecraft list sorted by max speed." << std::endl;
                        break;
                    case 4:
                        mergeSort(spacecraft_list, 0, spacecraft_list.size() - 1, compareByCruiseSpeed);
                        std::cout << "Spacecraft list sorted by cruise speed." << std::endl;
                        break;
                    case 5:
                        mergeSort(spacecraft_list, 0, spacecraft_list.size() - 1, compareByReleaseYear);
                        std::cout << "Spacecraft list sorted by release year." << std::endl;
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                }
                break;
            }
            case 9:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 9);

    return 0;
}