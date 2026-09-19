#include <iostream>
#include <limits>
#include <string>

#include "ReservationManager.h"

using namespace std;

/**
 * We need to build a helper function here:
 * If the user type a string input where our variables
 * expect for int input, and also to clear a buffer like java, 
 * We need a method that flushes and wipe out all the 
 * input pipe.
 */

 void clearInputPipe(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); }

int main() {
    //(Create the object)
    ReservationManager reservationManager;

    // 2. Tell the Boss to load the files directly!
    if (!reservationManager.loadResourcesFromFile("data/resources.txt")) {
        cout << "Fatal error: could not load resources. Exiting." << endl;
        return 1;
    }

    // Now we create an empty bucket called choice to hold the user input
    int choice = 0;

    //Since this is a menu, we need to use do while loop to first
    // run the menu then check the condition

    do {
        cout << "\n";
        cout << "===================================================\n";
        cout << "        Campus Resource Reservation System\n";
        cout << "===================================================\n";
        cout << "       1. View Resources\n";
        cout << "       2. Create Reservation\n";
        cout << "       3. Cancel Reservation\n";
        cout << "       4. View Waiting Lists\n";
        cout << "       5. Undo Cancellation\n";
        cout << "       6. Search Reservations\n";
        cout << "       7. Sort Resources\n";
        cout << "       8. Generate Report\n";
        cout << "       9. Exit\n";
        cout << "---------------------------------------------------\n";
        cout << "       Enter Choice: ";
        
        cin >> choice;

        //What if the user type a string instead of int
        if (cin.fail()){
            // called the function we just built
            clearInputPipe();
            cout << "\nInvalid Input: Please enter a valid number from 1 to 9" << endl;
            continue;
        }
        clearInputPipe();

        //Now we will use switch to sort those choices
        switch(choice){
            
            //To view resources
            case 1:
            reservationManager.displayAllResources();
            reservationManager.displayActiveReservations();
            break;

            // Create a reservation
            case 2: {
                // Take studentId, name, resourceid and date
                int studentId;
                string studentName, resourceId, reservationDate;

                cout << "Student ID: ";
                cin >> studentId;

                //Lets call the buffer clearer we just build to clear
                // If the student input is not what our program expected
                // let our pipe clearer do the job
                if (cin.fail()){
                    clearInputPipe();
                    cout << "Invalid Student ID." << endl;
                    break;
                }
                clearInputPipe();   // Clear before another getline

            // Get student name and resource id
            cout << "Student Name: ";
            getline(cin, studentName);  //Standard cin stop as soon as it sees the space, thats why we need this format

            cout << "Resource ID: ";
            cin >> resourceId;
            clearInputPipe(); // Clear before get line

            //Reservation Date
            cout << "Reservation Date (e.g. 2026-09-20): ";
            getline(cin, reservationDate);

            //Create the actual reservation
            reservationManager.createReservation(studentId, studentName, resourceId, reservationDate);
            break;
            }

            //Cancel Reservation
            case 3: {
                int reservationId;
                cout << "Reservation ID: ";
                cin >> reservationId;

                reservationManager.cancelReservation(reservationId);
                break;
            }
            
            //Displaying Waiting List
            case 4:
            reservationManager.displayWaitingList();
            break;

            //Undo Cancellation
            case 5:
            reservationManager.restoreLastCancellation();
            break;

            case 6:
            case 7:
            case 8:
            // Fture milestone
            cout << "\nThis feature will be available in the final submission." << endl;
            break;

            //say goodbye when the user choose 9
            case 9:
            cout << "Good Bye." << endl;
            break;

            // Else the user put something not a number
            default:
            cout <<"\nInvalid choice. Please enter a number from 1 to 9." << endl;
            break;
        }

    } while (choice != 9);
    
    return 0;
}

