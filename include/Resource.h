#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

// Stores information about a campus resource (e.g., a study room, a projector, a lab, etc.).

class Resource {
private:
    int resourceId;                 // Unique identifier for this resource
    std::string resourceName;       // Name of the resource (e.g., "Study Room A", "Projector 1")
    std::string resourceType;       // category/type of the resource (e.g., "Room", "Equipment", "Lab")
    bool inUse;                     // Indicates whether the resource is currently in use

public:
    // Creates a resource with default values.
    Resource();

    // Constructor for creating a resource.
    Resource(int resourceId, std::string resourceName, std::string resourceType, bool inUse);

    // Getters 
    int getResourceId() const;
    std::string getResourceName() const;
    std::string getResourceType() const;
    bool isInUse() const;

    // Setter
    // Updates whether the resource is currently in use.
    void setInUse(bool inUse);  

    // Prints the resource's information to the console.
    void display() const; 
};

#endif