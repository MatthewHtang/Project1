#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
using namespace std;
// Stores information about a campus resource (e.g., a study room, a projector, a lab, etc.).

class Resource {
private:
    string resourceId;        // the resource's ID, like "R101"
    string resourceName;      // the name, like "Study Room A"
    string resourceType;      // the type, like "Room" or "Equipment"
    bool available;           // true if you can book it right now
public:
    // Makes an empty resource. Used before we fill in real info.
    Resource();

    // Makes a resource with real info.
    Resource(std::string resourceId, std::string resourceName, std::string resourceType, bool available);

    // Getters 
    // These jsut hand back one piece of info each. Nothng tricky.
    string getResourceId() const;
    string getResourceName() const;
    string getResourceType() const;
    bool isAvailable() const;

    // Setter
    // Flips a resource between available and not available.
    void setAvailable(bool available);  

    // Prints the resource's info to the screen.
    void display() const; 
};

#endif