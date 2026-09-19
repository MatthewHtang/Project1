#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
// Stores information about a campus resource (e.g., a study room, a projector, a lab, etc.).

class Resource {
private:
    string resourceId;                 // Unique identifier for this resource
    string resourceName;       // Name of the resource (e.g., "Study Room A", "Projector 1")
    string resourceType;       // category/type of the resource (e.g., "Room", "Equipment", "Lab")
    bool available;                     // Indicates whether the resource is currently in use

public:
    // Creates a resource with default values.
    Resource();

    // Constructor for creating a resource.
    Resource(std::string resourceId, std::string resourceName, std::string resourceType, bool available);

    // Getters 
    string getResourceId() const;
    string getResourceName() const;
    string getResourceType() const;
    bool isAvailable() const;

    // Setter
    // Updates whether the resource is currently in use.
    void setAvailable(bool available);  

    // Prints the resource's information to the console.
    void display() const; 
};

#endif