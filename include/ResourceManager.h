#ifndef RESOURCEMANAGER_H  
#define RESOURCEMANAGER_H   

#include "Resource.h"   // we need the Resource class to store one
#include <vector>       // we keep all our resources in a vector
#include <string>       // used for file names and text
using namespace std;

class ResourceManager { // This class hold every resource in the system, all in one place.
                        // It can load them from a file, show them, and look them up.

private:

    vector<Resource> resources;     // every resource we've loaded goes in here

public:
    // Reads resources from a file and stores them. Returns false if the file won't open.
    bool loadFromFile(string filename); 

    void displayAll();                  // prints every resource we have
    void displayAvailable();            // prints resources that are available (not in use)

    Resource* findById(string resourceId); // finds a reosurce by its ID. Gives back nullptr if it's not there.
    bool exists(string resourceId);        // checks if the resource ID exists in the system
    bool setAvailable(string resourceId, bool inUse);     // Marks a resource as available or not, by its ID.

    int getCount();                     // returns the number of resources are loaded right now.
    bool isEmpty();                     // True if we haven't loaded any resources yet.
};

#endif 