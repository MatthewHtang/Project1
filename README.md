# Campus Resource Reservation System
# CSCE 2110: Foundations of Data Structures

* Contributors - Matthew Htang, Sankalp Gupta, Alka Gurung

This Project is apart of the CSCE 2110: Foundations of Data Structures

In this project we have implemented a reservation system that allow users to create a reservation, cancel, view waiting list, undo cancellation, and view resources using C++. We have used, linked list, Queue and stack algorithms and also inluded a brief complexity breakdown in the complexity.md file. 

Features listed below are not in the system yet, and it is another task for milestone 2.

* Notes
- Reserach Reservation
- Sort Resources
- Generate Report

### 📂 Project Structure
```
├──📂data/
│   ├── reservations.txt
│   └── resources.txt
├──📂include/
│   ├── CancellationHistory.h
│   ├── Reservation.h
│   ├── ReservationList.h
│   ├── ReservationManager.h
│   ├── Resource.h
│   ├── ResourceManager.h
│   ├── tempCodeRunnerFile.h
│   └── WaitingList.h
├──📂src/
│   ├── CancellationHistory.cpp
│   ├── main.cpp
│   ├── Reservation.cpp
│   ├── ReservationList.cpp
│   ├── ReservationManager.cpp
│   ├── Resource.cpp
│   ├── ResourceManager.cpp
│   └── WaitingList.cpp
├── .gitignore
├── COMPLEXITY.md
├── CONTRIBUTIONS.md
└── README.md
```

- How to run:
- Open the terminal and clone the repository
- Open the folder 'Project 1' and compile:    g++ -std=c++17 -Iinclude src/*.cpp -o reservation
- Run:    ./reservation

And Follow the screen menu.


