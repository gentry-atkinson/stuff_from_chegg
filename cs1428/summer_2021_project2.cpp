#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;

// Define function prototypes
void designShip();
void testShip();

int main() {
    char choice;

    // Run loop until user choose to quit
    do {
        // Display the menu
        cout << "Menu:\n";
        cout << "• D - Design a new ship\n";
        cout << "• T - Test a new ship\n";
        cout << "• Q - Quit the Program\n";

        // Ask user to select option from the menu
        cout << "Choose an option (D/T/Q): ";
        cin >> choice;

        // Do operation as per user's choice
        switch (toupper(choice)) {
            case 'D': designShip(); break; // Design a Ship
            case 'T': testShip(); break; // Test Ship Design
            case 'Q': cout << "Thank you for using Craft Desiner Plus\n"; exit(0);
            default: cout << "Invalid Choice!!!!\n";
        }

    } while (choice != 'q' || choice != 'Q');

    return 0;
}

// Function to design a new ship
void designShip() {
    string designerName, shipName;
    int shipMass, engineThrust;

    getchar();

    // Ask user to enter ship name
    cout << "\nEnter Ship Name: ";
    getline(cin, shipName);

    // Ask user to enter designer name
    cout << "Enter Designer Name: ";
    getline(cin, designerName);

    // Ask user to enter ship mass
    cout << "Enter Ship Mass: ";
    cin >> shipMass;

    // Ask user to enter engine thrust
    cout << "Enter Engine Thrust: ";
    cin >> engineThrust;

    // Calculate acceleration, change in velocity and maximum altitude
    float acceleration = (float)engineThrust/shipMass;
    float changeInVelocity = (100000/engineThrust)*9.8*log(2);
    float maxAltitute = 100 + (changeInVelocity - 200)/10 ;

    ofstream file;

    // Open text file in write mode
    file.open(shipName+".txt");

    // Write the obtained information to the text file
    file << "##########"+shipName+"##########" << endl << endl;
    file << "Designed By:\t\t" << designerName << endl;
    file << "Ship Mass:\t\t" << shipMass << "kg" << endl;
    file << "Acceleration:\t\t" << fixed << setprecision(1) << acceleration << "m/s2" << endl;
    file << "Delta V:\t\t" << fixed << setprecision(1) << changeInVelocity << "m/s" << endl;
    file << "Max Altitude:\t\t" << fixed << setprecision(1) << maxAltitute << "km" << endl << endl;
    file << "File saved at:\t\t" << time(NULL);

    // Close the file.
    file.close();

    cout << "File written for " + shipName << endl << endl;
}

// Function to test design of a ship
void testShip() {
    string nameOfSpaceVehicle;

    getchar();

    // Ask user to enter name of space vehicle he/she want to test
    cout << "\nEnter name of space vehicle: ";
    getline(cin, nameOfSpaceVehicle);

    ifstream file;

    // Open the data file in read mode
    file.open(nameOfSpaceVehicle+".txt");

    // Check if file is successfully opened
    if(!file.is_open()) {
        cout << "\nFile doesn't exists!!\n\n";
        return;
    }

    bool testFail = false;
    string line;

    // Get first-two line (useless)
    getline(file, line);
    getline(file, line);

    // Get name of the designer
    getline(file, line);
    string designerName = line.substr(2+line.find("\t\t"));
    
    // Get mass of ship
    getline(file, line);
    int shipMass = stoi(line.substr(2+line.find("\t\t")));

    // Get acceleration
    getline(file, line);
    double acceleration = stod(line.substr(2+line.find("\t\t")));

    // Get change in velocity (delta V)
    getline(file, line);
    double deltaV = stod(line.substr(2+line.find("\t\t")));

    // Get maximum altitude
    getline(file, line);
    double maxAltitude = stod(line.substr(2+line.find("\t\t")));

    // Close the file
    file.close();

    // TEST 1
    if(designerName == "Thomas Harris") {
        testFail = true;
        cout << nameOfSpaceVehicle << " has failed Test 1\n";
        return;
    }

    // TEST 2
    if(!(shipMass < 1000)) {
        testFail = true;
        cout << nameOfSpaceVehicle << " has failed Test 2\n";
        return;
    }

    // TEST 3
    if(!(acceleration > 1 && acceleration < 10)) {
        testFail = true;
        cout << nameOfSpaceVehicle << " has failed Test 3\n";
        return;
    }

    // TEST 4
    if(!(deltaV >= 800)) {
        testFail = true;
        cout << nameOfSpaceVehicle << " has failed Test 4\n";
        return;
    }

    // TEST 5
    if(shipMass < 100) {
        if(!(maxAltitude >= 150)) {
            testFail = true;
            cout << nameOfSpaceVehicle << " has failed Test 5\n";
            return;
        }
    } else {
        if(!(maxAltitude >= 200)) {
            testFail = true;
            cout << nameOfSpaceVehicle << " has failed Test 5\n";
            return;
        }
    }

    // If all test are OK
    if(!testFail) {
        cout << nameOfSpaceVehicle << " has passed all tests.\n";
    }
    
    cout << endl;
}