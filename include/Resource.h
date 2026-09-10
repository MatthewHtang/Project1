#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource {
private:
    int resourceId;     
    std::string resourceName;
    std::string resourceType;
    bool inUse;

public:
    
    Resource(int resourceId, std::string resourceName, std::string resourceType, bool inUse);

    int getResourceId() const;
    std::string getResourceName() const;
    std::string getResourceType() const;
    bool isInUse() const;

    void setInUse(bool inUse);
    void display() const; 
};

#endif