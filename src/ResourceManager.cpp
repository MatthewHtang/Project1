#include "ResourceManager.h" 
#include <iostream>          
#include <fstream>           
#include <sstream>           

using namespace std;         

// Reads resources froma a file, one resource per line.
// Each line looks like this: R101|Study Room 101|Study Room|Available
// We split on the | symbol to pull out each piece.
bool ResourceManager::loadFromFile(string filename) { 
    ifstream inFile(filename); 
    if (!inFile.is_open()) { 
        cout << "Error: Could not open file \"" << filename << "\"." << endl; 
        return false; 
    } 

    string line; 
    while (getline(inFile, line)) { 
        if (line.empty()) { 
            continue; 
        } 

        stringstream ss(line); 
        string field; 

        // first piece is the ID
        getline(ss, field, ','); 
        string id = field;

        // second piece is the name
        getline(ss, field, ','); 
        string name = field; 

        // third piece is the type
        getline(ss, field, ','); 
        string type = field; 

        // last piece says "Available" or "Unavailable", so we just check the word
        getline(ss, field, ','); 
        bool available = (stoi(field) == 1); 

        Resource r(id, name, type, available); 
        resources.push_back(r);
    } 

    inFile.close(); 
    cout << "Loaded " << resources.size() << " resource(s) from " << filename << "." << endl; 
    return true; 
}

// Goes through every resource and prints it.
void ResourceManager::displayAll() { 
    if (resources.empty()) { 
        cout << "No resources loaded." << endl; 
        return; 
    } 
    
    cout << "\n----- All Resources -----" << endl; 
    for (size_t i = 0; i < resources.size(); i++) { 
        resources[i].display(); 
    } 
} 

// Goes through every resource, but only prints the one that are free.
void ResourceManager::displayAvailable() { 
    bool foundAny = false; 
    
    cout << "\n----- Available Resources -----" << endl; 
    for (size_t i = 0; i < resources.size(); i++) { 
        if (resources[i].isAvailable()) { 
            resources[i].display(); 
            foundAny = true; 
        }
    }
    
    if (!foundAny) { 
        cout << "No resources are currently available." << endl; 
    } 
} 

// Walks through the list looking for a matching ID.
// Stops and returns it as soon as it finds one.
Resource* ResourceManager::findById(string resourceId) { 
    for (size_t i = 0; i < resources.size(); i++) { 
        if (resources[i].getResourceId() == resourceId) { 
            return &resources[i]; 
        } 
    } 
    return nullptr; 
} 

// Just reuses finfById to check if something exists.
bool ResourceManager::exists(string resourceId) { 
    return findById(resourceId) != nullptr;
} 

// Finds the resource first, then flips its available status.
bool ResourceManager::setAvailable(string resourceId, bool available) { 
    Resource* r = findById(resourceId); 
    if (r == nullptr) { 
        return false; 
    } 
    r->setAvailable(available); 
    return true; 
} 

// The vector already knows its own size, so we just ask it.
int ResourceManager::getCount() { 
    return static_cast<int>(resources.size()); 
} 

// Same idea, the vector already knows if it's empty.
bool ResourceManager::isEmpty() { 
    return resources.empty();
}