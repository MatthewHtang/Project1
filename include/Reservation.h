#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
using namespace std;

class Reservation {//class used to store reservation information
private:
    int reservationId; // unique ID for the reservation   
    int studentId;// Id of the student
string studentName;//student name
string resourceId;//resource ID
string reservationDate;//reservation date

public:
    Reservation(); // We need default constructor
    Reservation(int reservationId, int studentId, string studentName, string resourceId, string reservationDate);//constructor with reservation details

    int getReservationId() const;// gets the reservation Id
    int getStudentId() const;// gets the student ID
    string getStudentName() const;//gets the student name
    string getResourceId() const;// gets the resource id
    string getReservationDate() const;//gets the reservation date

    void display() const; // shows reservation details
};

#endif
