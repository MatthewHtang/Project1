#include "ResourceManager.h" // Include the class declaration and dependencies
#include <iostream>          // Required for standard input/output console operations
#include <fstream>           // Required for file stream operations (reading files)
#include <sstream>           // Required for string stream operations (parsing lines)

using namespace std;         // Utilize the standard namespace for simplicity

// ===========================================
// Load resource information from a file
// ===========================================
// Reads one resource per line in the format:
// ID, Name, Type, InUse(1 or 0)
// Uses getline() with a stringstream to properly handle strings with spaces.

bool ResourceManager::loadFromFile(string filename) { // Attempt to populate the resource list from a specified file
    ifstream inFile(filename); // Initialize an input file stream with the provided filename
    if (!inFile.is_open()) { // Verify whether the file was successfully opened
        cout << "Error: Could not open file \"" << filename << "\"." << endl; // Output an error message if access fails
        return false; // Terminate the function and indicate failure
    } // End of file validation block

    string line; // Declare a string variable to hold the contents of each file line
    while (getline(inFile, line)) { // Iterate through the file line by line until the end of file (EOF) is reached
        if (line.empty()) { // Check if the current extracted line is empty
            continue; // Skip further processing for empty lines and proceed to the next iteration
        } // End of empty line check

        stringstream ss(line); // Initialize a stringstream with the current line for delimiter parsing
        string field; // Declare a temporary string to hold each comma-separated value

        getline(ss, field, ','); // Extract the first substring up to the comma character
        string id = field; // Convert the extracted string field into an integer for the Resource ID

        getline(ss, field, ','); // Extract the second substring
        string name = field; // Assign the extracted string to the Resource name

        getline(ss, field, ','); // Extract the third substring
        string type = field; // Assign the extracted string to the Resource type

        getline(ss, field, ','); // Extract the final substring
        bool available = (stoi(field) == 1); // Convert the string to an integer, then evaluate as a boolean (1 = true, 0 = false)

        Resource r(id, name, type, available); // Instantiate a new Resource object using the parsed data
        resources.push_back(r); // Append the newly created Resource to the internal vector
    } // End of the while loop

    inFile.close(); // Close the input stream to release system resources
    cout << "Loaded " << resources.size() << " resource(s) from " << filename << "." << endl; // Output a summary of the operation
    return true; // Return true to signify the loading process completed successfully
} // End of loadFromFile method

//===========================================
// Display all resources
//===========================================
void ResourceManager::displayAll() { // Output the details of every loaded resource to the console
    if (resources.empty()) { // Verify if the internal vector contains any elements
        cout << "No resources loaded." << endl; // Notify the user that the list is empty
        return; // Exit the function to prevent further execution
    } // End of empty vector check
    
    cout << "\n----- All Resources -----" << endl; // Print the section header
    for (size_t i = 0; i < resources.size(); i++) { // Iterate through the vector using an index
        resources[i].display(); // Invoke the display method of each individual Resource object
    } // End of iteration loop
} // End of displayAll method

//===========================================
// Display available resources
//===========================================
void ResourceManager::displayAvailable() { // Output the details of resources that are not currently in use
    bool foundAny = false; // Initialize a boolean flag to track if any available resources exist
    
    cout << "\n----- Available Resources -----" << endl; // Print the section header
    for (size_t i = 0; i < resources.size(); i++) { // Iterate through all stored resources
        if (resources[i].isAvailable()) { // Evaluate if the current resource's in-use flag is false
            resources[i].display(); // Output the available resource's details
            foundAny = true; // Update the flag to true since at least one resource was found
        } // End of availability evaluation
    } // End of iteration loop
    
    if (!foundAny) { // Evaluate the flag after the loop completes
        cout << "No resources are currently available." << endl; // Notify the user if no available resources were found
    } // End of check
} // End of displayAvailable method

//===========================================
// Find a resource by ID
//===========================================
Resource* ResourceManager::findById(string resourceId) { // Search for and return a pointer to a specific Resource
    for (size_t i = 0; i < resources.size(); i++) { // Iterate through the resource vector
        if (resources[i].getResourceId() == resourceId) { // Compare the current resource's ID against the target ID
            return &resources[i]; // Return the memory address of the matching resource
        } // End of ID comparison
    } // End of iteration loop
    return nullptr; // Return a null pointer if no matching ID was found in the vector
} // End of findById method

//===========================================
// Check if a resource exists by ID
//===========================================
bool ResourceManager::exists(string resourceId) { // Evaluate whether a resource with the specified ID exists in the system
    return findById(resourceId) != nullptr; // Return true if findById yields a valid pointer, false otherwise
} // End of exists method

//===========================================
// Update a resource's in-use status
//===========================================
bool ResourceManager::setAvailable(string resourceId, bool available) { // Modify the availability status of a specific resource
    Resource* r = findById(resourceId); // Retrieve a pointer to the target resource
    if (r == nullptr) { // Verify if the returned pointer is null (resource not found)
        return false; // Terminate the function and return false to indicate the operation failed
    } // End of null validation
    r->setAvailable(available); // Invoke the setter method on the valid resource pointer
    return true; // Return true to indicate the update was successfully applied
} // End of setInUse method

//===========================================
// Return how many resources are currently loaded
//===========================================
int ResourceManager::getCount() { // Retrieve the total count of loaded resources
    return static_cast<int>(resources.size()); // Cast the size_t value to an integer and return it
} // End of getCount method

//===========================================
// Check whether any resources have been loaded
//===========================================
bool ResourceManager::isEmpty() { // Evaluate whether the internal resource list is empty
    return resources.empty(); // Return the boolean result of the vector's native empty() method
} // End of isEmpty method