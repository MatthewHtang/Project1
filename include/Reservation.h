#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class Reservation {
private:
    int reservationId;     
    int studentId;
    std::string studentName;
    std::string resourceId;
    std::string reservationDate;

public:
    Reservation(); // We need default constructor
    Reservation(int reservationId, int studentId, std::string studentName, std::string resourceId, std::string reservationDate);

    int getReservationId() const;
    int getStudentId() const;
    std::string getStudentName() const;
    std::string getResourceId() const;
    std::string getReservationDate() const;

    void display() const; 
};

#endif
