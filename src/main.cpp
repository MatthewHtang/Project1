#include <iostream>
#include <limits>
#include <string>

#include "ReservationManager.h"
#include "ResourceManager.h"


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

    // Build the filing cabinet
    ResourceManager resourceManager;     // Create an object

    //Load resources.txt file from the data and fill it in that cabinet
    // if it fails, then print fail message and return with 1 (this is just self destruct button)
    if (!resourceManager.loadFromFile("data/resources.txt")){
        cout << "Fatal error: could not load resources. Exiting." << endl;
        return 1;
    }

    /**
     * We create other object called reservationManager, and 
     * we used & to hand the map pointing to the filing cabinet 
     * we just built
     */
    ReservationManager reservationManager(&resourceManager);

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
        clearInputPipe;

        //Now we will use switch to sort those choices
        switch(choice){
            
            //To view resources
            case 1:
            reservationManager.displayAllResources();
            reservationManager.displayActiveReservations();
            break;
        }

    } while (choice != 9);
    
    return 0;
}

