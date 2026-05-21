#include <iostream>
using namespace std;

int main() {
    int choice;
    
    cout << "\n===== C++ BOOK SYSTEM =====" << endl;
    
    do {
        cout << "\n1. History of C++" << endl;
        cout << "2. Learn C++ Concepts" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\n--- HISTORY OF C++ ---" << endl;
                cout << "1. Origins: Bjarne Stroustrup, 1979" << endl;
                cout << "2. Development: C with Classes -> C++" << endl;
                cout << "3. Evolution: C++98, C++11, C++17, C++20" << endl;
                break;
                
            case 2:
                cout << "\n--- LEARN C++ ---" << endl;
                cout << "1. Data Types: int, float, char, bool, string" << endl;
                cout << "2. Control Flow: if-else, switch-case" << endl;
                cout << "3. Loops: for, while, do-while" << endl;
                cout << "4. Arrays: int arr[5] = {1,2,3,4,5}" << endl;
                cout << "5. File Streams: ifstream for reading files" << endl;
                break;
                
            case 3:
                cout << "Goodbye!" << endl;
                break;
                
            default:
                cout << "Wrong choice! Try again." << endl;
        }
    } while(choice != 3);
    
    return 0;
}