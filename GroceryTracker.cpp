#include "GroceryTracker.h"
#include <fstream>
#include <iostream>

GroceryTracker::GroceryTracker(const std::string& filename) {
    loadItemsFromFile(filename);
}

void GroceryTracker::loadItemsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string item;
    while (file >> item) {
        ++itemFrequency[item];
    }
    file.close();
}

int GroceryTracker::getItemFrequency(const std::string& item) {
    return itemFrequency[item];
}

void GroceryTracker::printAllItems() {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

void GroceryTracker::printHistogram() {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " " << std::string(pair.second, '*') << std::endl;
    }
}

void GroceryTracker::backupData(const std::string& backupFilename) {
    std::ofstream outFile(backupFilename);
    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << std::endl;
    }
    outFile.close();
}
