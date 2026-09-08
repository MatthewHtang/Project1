#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    //do while loop to run the menu first and check the condition
    int input = 0;
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
        
        cin >> input;

    } while (input != 9);
    
    return 0;
}

