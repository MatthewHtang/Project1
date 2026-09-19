#include "Reservation.h"
#include <iostream>
#include <string>

using namespace std;

// Default constructor
// Gives starting values when a reservation is created
Reservation::Reservation() {
    reservationId = 0;
    studentId = 0;
    studentName = "";
    resourceId = "";
    reservationDate = "";
}

// Constructor with reservation details
// Stores the information given when a reservation is created
Reservation::Reservation(int reservationId, int studentId,
                         string studentName, string resourceId,
                         string reservationDate) {
    this->reservationId = reservationId;
    this->studentId = studentId;
    this->studentName = studentName;
    this->resourceId = resourceId;
    this->reservationDate = reservationDate;
}

// Returns the reservation ID
int Reservation::getReservationId() const {
    return reservationId;
}

// Returns the student ID
int Reservation::getStudentId() const {
    return studentId;
}

// Returns the student name
string Reservation::getStudentName() const {
    return studentName;
}

// Returns the resource ID
string Reservation::getResourceId() const {
    return resourceId;
}

// Returns the reservation date
string Reservation::getReservationDate() const {
    return reservationDate;
}

// Displays all reservation information
void Reservation::display() const {
    cout << "Reservation ID: " << reservationId << endl;
    cout << "Student ID: " << studentId << endl;
    cout << "Student Name: " << studentName << endl;
    cout << "Resource ID: " << resourceId << endl;
    cout << "Reservation Date: " << reservationDate << endl;
}