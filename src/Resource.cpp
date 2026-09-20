#include "Resource.h"
#include <iostream>
#include <string>

using namespace std;

// This runs when we make a blank Resource, before we have real data for it.
Resource :: Resource() {
    resourceId = "";
    resourceName = "";
    resourceType = "";
    available = true;

} 

// This  runs when we make a real Resource, with actual info filled in.
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

// Tells us if the resource can be booked right now.
bool Resource :: isAvailable() const {
    return available;
}

// Marks the resource as available or not available.
void Resource :: setAvailable(bool available) {
    this->available = available;
}

// Prints out everything about this one resource, on one line.
void Resource :: display() const {
    cout << "ID: " << resourceId
         << " | Name: " << resourceName
         << " | Type: " << resourceType
         << " | Status: " << (available ? "Available" : "In Use") 
        << endl;

}