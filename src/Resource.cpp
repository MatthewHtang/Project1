#include "Resource.h"
#include <iostream>
#include <string>

using namespace std;

// Default constructor
Resource :: Resource() {
    resourceId = "";
    resourceName = "";
    resourceType = "";
    available = true;

} 

// Main constructor with resource information
Resource :: Resource(string resourceId, string resourceName, string resourceType, bool available) {
    this->resourceId = resourceId;
    this->resourceName = resourceName;
    this->resourceType = resourceType;
    this->available = available;
}

// Returns the resource ID
string Resource :: getResourceId() const {
    return resourceId;
}

// Returns the resource name
string Resource :: getResourceName() const {
    return resourceName;
}

// Returns the resource type
string Resource :: getResourceType() const {
    return resourceType;
}

// Returns the current status of the resource
bool Resource :: isAvailable() const {
    return available;
}

// Changes the resource status
void Resource :: setAvailable(bool available) {
    this->available = available;
}

// Displayes the resource information
void Resource :: display() const {
    cout << "ID: " << resourceId
         << " | Name: " << resourceName
         << " | Type: " << resourceType
         << " | Status: " << (available ? "Available" : "In Use") 
        << endl;

}