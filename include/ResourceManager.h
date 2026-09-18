#ifndef RESOURCEMANAGER_H  
#define RESOURCEMANAGER_H   

#include "Resource.h"   // uses the Resource class
#include <vector>       // used to store multiple resources
#include <string>       // used for file names and text
using namespace std;

class ResourceManager { // manages a collection of resources

private:

    vector<Resource> resources;     // Vector to store all resources in memory

public:
    bool loadFromFile(string filename); // loads reosurces from the file into the resources vector

    void displayAll();                  // displays all resources
    void displayAvailable();            // displays resources that are available (not in use)

    Resource* findById(string resourceId); // finds a reosurce by its ID
    bool exists(string resourceId);        // checks if the resource ID exists in the resources vector
    bool setAvailable(string resourceId, bool inUse);     // changes the resouce's status

    int getCount();                     // returns the number of resources in the resources vector
    bool isEmpty();                     // checks if the resources vector is empty

};

#endif 