#include "Resource.h"
#include <iostream>
#include <string>

using namespace std;

// Default constructor
Resource :: Resource() {
    resourceId = 0;
    resourceName = "";
    resourceType = "";
    inUse = false;

} 

// Main constructor with resource information
Resource :: Resource(int resourceId, string resourceName, string resourceType, bool inUse) {
    this->resourceId = resourceId;
    this->resourceName = resourceName;
    this->resourceType = resourceType;
    this->inUse = inUse;
}

// Returns the resource ID
int Resource :: getResourceId() const {
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
bool Resource :: isInUse() const {
    return inUse;
}

// Changes the resource status
void Resource :: setInUse(bool inUse) {
    this->inUse = inUse;
}

// Displayes the resource information
void Resource :: display() const {
    cout << "ID: " << resourceId
         << " | Name: " << resourceName
         << " | Type: " << resourceType
         << " | Status: " << (inUse ? "In Use" : "Available") 
        << endl;

}
