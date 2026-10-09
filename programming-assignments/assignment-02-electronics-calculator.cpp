#include <iostream>
using namespace std;

int main() {
    // declaring my variables first
	string name;
    double voltage;
    double resistance;
    
    cout << "Tell me your name "; 
    cin >> name; // receives name input
    cout << "You can put in the voltage now ";
    cin >> voltage; // receives voltage input
    cout << "You can put in your resistance ";
    cin >> resistance; // receives resistance input
    
    // Warning: Calculations ahead :)
    double current = voltage / resistance;
    double power = voltage * current;
    
    //Displaying results
    cout << "\n";
    cout << "-------------------------------" << "\n";
    cout << "Results loaded" << "\n";
    cout << "Name: " << name << "\n";
    cout << "Current: " << current << "\n";
    cout << "Power: " << power << "\n";
    
    return 0;
}
