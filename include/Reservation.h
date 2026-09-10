#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class Reservation {
private:
    int reservationId;     
    int studentId;
    std::string studentName;
    int resourceId;
    std::string reservationDate;

public:
    
    Reservation(int reservationId, int studentId, std::string studentName, int resourceId, std::string reservationDate);

    int getReservationId() const;
    int getStudentId() const;
    std::string getStudentName() const;
    int getResourceId() const;
    std::string getReservationDate() const;

    void display() const; 
};

#endif
