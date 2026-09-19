#include "ResourceManager.h" 
#include <iostream>          
#include <fstream>           
#include <sstream>           

using namespace std;         

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

        getline(ss, field, ','); 
        string id = field;

        getline(ss, field, ','); 
        string name = field; 

        getline(ss, field, ','); 
        string type = field; 

        getline(ss, field, ','); 
        bool available = (stoi(field) == 1); 

        Resource r(id, name, type, available); 
        resources.push_back(r);
    } 

    inFile.close(); 
    cout << "Loaded " << resources.size() << " resource(s) from " << filename << "." << endl; 
    return true; 
}

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

Resource* ResourceManager::findById(string resourceId) { 
    for (size_t i = 0; i < resources.size(); i++) { 
        if (resources[i].getResourceId() == resourceId) { 
            return &resources[i]; 
        } 
    } 
    return nullptr; 
} 

bool ResourceManager::exists(string resourceId) { 
    return findById(resourceId) != nullptr;
} 

bool ResourceManager::setAvailable(string resourceId, bool available) { 
    Resource* r = findById(resourceId); 
    if (r == nullptr) { 
        return false; 
    } 
    r->setAvailable(available); 
    return true; 
} 

int ResourceManager::getCount() { 
    return static_cast<int>(resources.size()); 
} 

bool ResourceManager::isEmpty() { 
    return resources.empty();
}