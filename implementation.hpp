#ifndef IMPLEMENTATION_HPP
#define IMPLEMENTATION_HPP


// Binary search function to find the index of a spacecraft by id
int binarySearchById(const std::vector<Spacecraft>& spacecraft_list, int id) {
    int left = 0;
    int right = spacecraft_list.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (spacecraft_list[mid].id == id) {
            return mid;
        } else if (spacecraft_list[mid].id < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

void addSpacecraft(std::vector<Spacecraft>& spacecraft_list) {
    Spacecraft spacecraft;
    std::cout << "Enter ID: ";
    std::cin >> spacecraft.id;
    std::cout << "Enter Length: ";
    std::cin >> spacecraft.length;
    std::cout << "Enter Weight: ";
    std::cin >> spacecraft.weight;
    std::cout << "Enter Max Speed: ";
    std::cin >> spacecraft.max_speed;
    std::cout << "Enter Cruise Speed: ";
    std::cin >> spacecraft.cruise_speed;
    std::cout << "Enter Price: ";
    std::cin >> spacecraft.price;
    std::cout << "Enter Release Year: ";
    std::cin >> spacecraft.release_year;
    std::cout << "Enter Brand: ";
    std::cin >> spacecraft.brand;
    std::cout << "Enter Model: ";
    std::cin >> spacecraft.model;
    std::cout << "Enter Color: ";
    std::cin >> spacecraft.color;
    std::cout << "Enter Type: ";
    std::cin >> spacecraft.type;
    spacecraft_list.push_back(spacecraft);
    mergeSort(spacecraft_list, 0, spacecraft_list.size() - 1, [](const Spacecraft& a, const Spacecraft& b) {
        return a.id < b.id;
    });
}

void retrieveSpacecraft(const std::vector<Spacecraft>& spacecraft_list) {
    int id;
    std::cout << "Enter ID of spacecraft to retrieve: ";
    std::cin >> id;
    int index = binarySearchById(spacecraft_list, id);
    if (index != -1) {
        const auto& spacecraft = spacecraft_list[index];
        std::cout << "ID: " << spacecraft.id << std::endl;
        std::cout << "Length: " << spacecraft.length << " m" << std::endl;
        std::cout << "Weight: " << spacecraft.weight << " tons" << std::endl;
        std::cout << "Max Speed: " << spacecraft.max_speed << " km/h" << std::endl;
        std::cout << "Cruise Speed: " << spacecraft.cruise_speed << " km/h" << std::endl;
        std::cout << "Price: " << spacecraft.price << " US dollar" << std::endl;
        std::cout << "Release Year: " << spacecraft.release_year << std::endl;
        std::cout << "Brand: " << spacecraft.brand << std::endl;
        std::cout << "Model: " << spacecraft.model << std::endl;
        std::cout << "Color: " << spacecraft.color << std::endl;
        std::cout << "Type: " << spacecraft.type << std::endl;
    } else {
        std::cout << "Spacecraft not found." << std::endl;
    }
}

void updateSpacecraft(std::vector<Spacecraft>& spacecraft_list) {
    int id;
    std::cout << "Enter ID of spacecraft to update: ";
    std::cin >> id;
    int index = binarySearchById(spacecraft_list, id);
    if (index != -1) {
        auto& spacecraft = spacecraft_list[index];
        std::cout << "Enter new Length: ";
        std::cin >> spacecraft.length;
        std::cout << "Enter new Weight: ";
        std::cin >> spacecraft.weight;
        std::cout << "Enter new Max Speed: ";
        std::cin >> spacecraft.max_speed;
        std::cout << "Enter new Cruise Speed: ";
        std::cin >> spacecraft.cruise_speed;
        std::cout << "Enter new Price: ";
        std::cin >> spacecraft.price;
        std::cout << "Enter new Release Year: ";
        std::cin >> spacecraft.release_year;
        std::cout << "Enter new Brand: ";
        std::cin >> spacecraft.brand;
        std::cout << "Enter new Model: ";
        std::cin >> spacecraft.model;
        std::cout << "Enter new Color: ";
        std::cin >> spacecraft.color;
        std::cout << "Enter new Type: ";
        std::cin >> spacecraft.type;
    } else {
        std::cout << "Spacecraft not found." << std::endl;
    }
}

void removeSpacecraft(std::vector<Spacecraft>& spacecraft_list) {
    int id;
    std::cout << "Enter ID of spacecraft to remove: ";
    std::cin >> id;
    int index = binarySearchById(spacecraft_list, id);
    if (index != -1) {
        spacecraft_list.erase(spacecraft_list.begin() + index);
        std::cout << "Spacecraft removed." << std::endl;
    } else {
        std::cout << "Spacecraft not found." << std::endl;
    }
}

void addRandomSpacecraft(std::vector<Spacecraft>& spacecraft_list, int num_spacecraft) {
    for (int i = 0; i < num_spacecraft; ++i) {
        Spacecraft spacecraft;
        spacecraft.id = rand() % 1000;
        spacecraft.length = rand() % 100;
        spacecraft.weight = rand() % 100;
        spacecraft.max_speed = rand() % 1000;
        spacecraft.cruise_speed = rand() % 1000;
        spacecraft.price = rand() % 1000000;
        spacecraft.release_year = 1950 + rand() % 70;
        spacecraft.brand = "Brand " + std::to_string(spacecraft.id);
        spacecraft.model = "Model " + std::to_string(spacecraft.id);
        spacecraft.color = "Color " + std::to_string(spacecraft.id);
        spacecraft.type = "Type " + std::to_string(spacecraft.id);
        spacecraft_list.push_back(spacecraft);
    }
    mergeSort(spacecraft_list, 0, spacecraft_list.size() - 1, [](const Spacecraft& a, const Spacecraft& b) {
        return a.id < b.id;
    });
    std::cout << num_spacecraft << " random spacecraft added." << std::endl;
}

void displayAllSpacecraft(const std::vector<Spacecraft>& spacecraft_list) {
    for (const auto& spacecraft : spacecraft_list) {
        std::cout << "ID: " << spacecraft.id << std::endl;
        std::cout << "Length: " << spacecraft.length << " m" << std::endl;
        std::cout << "Weight: " << spacecraft.weight << " tons" << std::endl;
        std::cout << "Max Speed: " << spacecraft.max_speed << " km/h" << std::endl;
        std::cout << "Cruise Speed: " << spacecraft.cruise_speed << " km/h" << std::endl;
        std::cout << "Price: " << spacecraft.price << " US dollar" << std::endl;
        std::cout << "Release Year: " << spacecraft.release_year << std::endl;
        std::cout << "Brand: " << spacecraft.brand << std::endl;
        std::cout << "Model: " << spacecraft.model << std::endl;
        std::cout << "Color: " << spacecraft.color << std::endl;
        std::cout << "Type: " << spacecraft.type << std::endl;
        std::cout << std::endl;
    }
}

void displaySpacecraft(const std::vector<Spacecraft>& spacecraft_list) {
    int id;
    std::cout << "Enter ID of spacecraft to display: ";
    std::cin >> id;
    int index = binarySearchById(spacecraft_list, id);
    if (index != -1) {
        const auto& spacecraft = spacecraft_list[index];
        std::cout << "ID: " << spacecraft.id << std::endl;
        std::cout << "Length: " << spacecraft.length << " m" << std::endl;
        std::cout << "Weight: " << spacecraft.weight << " tons" << std::endl;
        std::cout << "Max Speed: " << spacecraft.max_speed << " km/h" << std::endl;
        std::cout << "Cruise Speed: " << spacecraft.cruise_speed << " km/h" << std::endl;
        std::cout << "Price: " << spacecraft.price << " US dollar" << std::endl;
        std::cout << "Release Year: " << spacecraft.release_year << std::endl;
        std::cout << "Brand: " << spacecraft.brand << std::endl;
        std::cout << "Model: " << spacecraft.model << std::endl;
        std::cout << "Color: " << spacecraft.color << std::endl;
        std::cout << "Type: " << spacecraft.type << std::endl;
        std::cout << std::endl;
    } else {
        std::cout << "Spacecraft not found." << std::endl;
    }
}

void displayMenu() {
    std::cout << "1. Add Spacecraft" << std::endl;
    std::cout << "2. Retrieve Spacecraft" << std::endl;
    std::cout << "3. Update Spacecraft" << std::endl;
    std::cout << "4. Remove Spacecraft" << std::endl;
    std::cout << "5. Add Random Spacecraft" << std::endl;
    std::cout << "6. Display All Spacecraft" << std::endl;
    std::cout << "7. Display One Spacecraft" << std::endl;
    std::cout << "8. Sort Spacecraft" << std::endl;
    std::cout << "9. Exit" << std::endl;
}

#endif // IMPLEMENTATION_HPP