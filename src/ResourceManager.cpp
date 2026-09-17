#include "ResourceManager.h" // Class declaration and dependencies
#include <iostream>         // Required for standard input/output console operations
#include <fstream>         // Required for file stream operations (reading files)
#include <sstream>        // Required for string stream operations (parsing lines)

using namespace std;

// ===========================================
// Load resource information from a file
// ===========================================
// Reads one resource per line in the format:
// ID, Name, Type, InUse(1 or 0)
// Uses getline() with a stingstream (instead of >>) so a name
// like "Study Room A" doesn't get cut off at the first space.

bool ResourceManager :: loadFromFile(string filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error: Could not open file \"" << filename << "\"." << endl;
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }

        stringstream ss(line);
        string field;

        getline(ss, field, ',');
        int id = stoi(field);

        getline(ss, field, ',');
        string name = field;

        getline(ss, field, ',');
        string type = field;

        getline(ss, field, ',');
        bool inUse = (stoi(field) == 1);

        Resource r(id, name, type, inUse);
        resources.push_back(r);
    }

    inFile.close();
    cout << "Loaded " << resources.size() << " resource(s) from " << filename << "." << endl;
    return true;
}

//===========================================
// Display all resources
//===========================================
void ResourceManager :: displayAll() {
    if (resources.empty()) {
        cout << "No resources loaded." << endl;
        return;
    }
    cout << "\n----- All Resources -----" << endl;
    for (size_t i = 0; i < resources.size(); i++) {
        resources[i].display();
    }
}

//===========================================
// Display available resources
//===========================================

void ResourceManager :: displayAvailable() {
    bool foundAny = false;
    
    cout << "\n----- Available Resources -----" << endl;
    for (size_t i = 0; i < resources.size(); i++) {
        if (!resources[i].isInUse()) {
            resources[i].display();
            foundAny = true;
        }
    }
    if (!foundAny) {
        cout << "No resources are currently available." << endl;
    }
}

//===========================================
// Find a resource by ID
//===========================================
Resource* ResourceManager :: findById(int resourceId) {
    for (size_t i = 0; i < resources.size(); i++) {
        if (resources[i].getResourceId() == resourceId) {
            return &resources[i];
        }
    }
    return nullptr; // Resource not found
} 

//===========================================
// Check if a resource exists by ID
//===========================================
bool ResourceManager :: exists(int resourceId) {
    return findById(resourceId) != nullptr;
}   

//===========================================
// Update a resource's in-use status
//===========================================
bool ResourceManager :: setInUse(int resourceId, bool inUse) {
    Resource* r = findById(resourceId);
    if (r != nullptr) {
        return false;
    }
    r->setInUse(inUse);
    return true;
}

//===========================================
// Return how many resources are currently loaded
//===========================================
int ResourceManager :: getCount() {
    return static_cast<int>(resources.size());
}

//===========================================
// Check whether any resources have been loaded
//===========================================
bool ResourceManager :: isEmpty() {
    return resources.empty();
}       
