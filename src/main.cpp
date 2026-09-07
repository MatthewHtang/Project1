#include <iostream>
#include <string>

using namespace std;

int main() {
    //do while loop to run the menu first and check the condition
    int input = 0;
    do {
        cout << "\n===== Campus Resource Reservation System =====\n" << endl;
        cout << "1. View Resources" << endl;
        cout << "2. Create Reservation" << endl;
        cout << "3. Cancel Reservation" << endl;
        cout << "4. View Waiting Lists" << endl;
        cout << "5. Undo Cancellation" << endl;
        cout << "6. Search Reservations" << endl;
        cout << "7. Sort Resources" << endl;
        cout << "8. Generate Report" << endl;
        cout << "9. Exit\n" << endl;
        cout << "Enter Choice: ";

        cin >> input;
    } while (input != 9);
    
    return 0;
}

