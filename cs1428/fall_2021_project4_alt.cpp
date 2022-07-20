// C++ program to add custom data type using a struct. 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// create a structure calls Ship containing attributes for Ship
struct Ship
{
    string shipname;
    string designerName;
    float mass;
    float thrust;
    float acceleration;
    float changeInVelocity;
    float maxAltitude;
};

//Function prototypes

// the void function will make hold all te information to make sure
void designShip();
// this function will display the all the information that will be enterned into the ship
// will store the information in a file so that when you need it for another function it can read the information

void testShip();
//this function will get the information from designShip
// and will test the information through a set of test and will pick the test that fits the best

void shipFlight();
// this function will find the speed and the acceleration and will test the ships fight once you enter the information

int main(){

    char choice;
    do {

        //Display Menu to user
        // Added the simulation ship flight to the menu
        //when to chose d/t/s/q the informtion will be in their
        cout << "----Bobcat Aerospace ship menu---" << endl;
        cout << "• D- design a new ship" << endl;
        cout << "• T- test a new ship" << endl;
        cout << "• S - simulate ship flight" << endl;
        cout << "• Q- quit the program" << endl;
        cout << "Option (D/T/S/Q): ";
        cin >> choice;

        //Create if statements for input choice
        //switch cases to show the cases d/t/s/q
        switch (toupper(choice)) {
            case 'D':
            case 'd':
                designShip();
                break;
            case 'T':
            case 't':
                testShip();
                break;
            case 'S':
            case 's':
                shipFlight();
                break;
            case 'Q':
                cout << "Thank you for using Craft Designer Plus." << endl;
                break;
            default:
                cout << "Invalid Choice!" << endl;
        }
    }while(toupper(choice) != 'Q');

    return 0;
}

//Function designShip
// the function is the same from the first and second assignment
void designShip(){

    //Declare the variables
    // identify the change in velocity, maximum altitude, acceleration
    Ship ship;
    //string ship_name, first_name, last_name, designer_name,
    string file_name, line;
    //float mass, engine, accelerate, velocity ,maxAlt, g0;

    // the function to help find the velocity
    float g0 = 9.8;

    //Declare output file to write the user's input to the ship's name
    ofstream fout;
    cout << "Ship's name: ";
    cin >> ship.shipname;

    fout.open(ship.shipname+".txt");

    //Get the input from user for designer name mass and engine thrust
    // read data into ship's attributes
    cout << "Designed by: " << "vehicle's designer: ";
    cin.ignore(100,'\n'); // read and discard \n left by cin>>
    getline(cin, ship.designerName);

    cout << "Ship's mass: ";
    cin >> ship.mass;

    cout << "Engine thrust: ";
    cin >> ship.thrust;

    //Calculate the acceleration by using the thrust divided by mass
    ship.acceleration = ship.thrust/ship.mass;

    //Calculate the change the velocity with
    // 100,000 divided by engine times g0 * ln(2)
    ship.changeInVelocity = (100000 / ship.thrust) * g0 * log(2);

    //Calculate the maxAlt as 100 + (velocity – 200)/10
    ship.maxAltitude = 100 + (ship.changeInVelocity - 200)/10;

    //Write ship's name with 10 #s before and after to file output
    // Enter what the .txt will be inputed to the output statement
    //Console file writen too
    cout << "File written for " << ship.shipname << endl;
    fout << "##########" << ship.shipname << "##########" << endl;
    fout << fixed;
    fout << "Ship mass: " << ship.mass << " kg" << endl;
    fout << "Acceleration: " << ship.acceleration << " m/s2" << endl;
    fout << "Delta V: " << ship.changeInVelocity << " m/s" << endl;
    fout << "Max Altitude: " << ship.maxAltitude << " km" << endl;
    fout << "File saved at: " << time(NULL) << endl;
    fout << "Designed by: " << ship.designerName << endl;

    //Close file
    fout.close();
    return;
}

//Function testShip
void testShip(){

    //Variables for taking values from file
    Ship ship;
    //string ship_name, firstName, lastName, designer_name, file_name
    string line, firstName, lastName;

    //float shipMass, acceleration, deltaV, maxAltitude;

    //Prompt user to give the name of space ship to test
    cout << "\nPlease enter the name of space vehicle: ";
    cin >> ship.shipname; // read name of file which is name of ship into shipname attribute of ship

    ifstream fin; //Open the file of choice
    fin.open(ship.shipname+ ".txt");

    //Check to see if file is valid
    if (!fin.is_open()){
        cout << "File does not exist!" << endl;
    }

    // Based on the output file created in designShip
    // first line (useless)
    //edu/courses/1770792/modules/items/83788087
    //string junk;
    //fin >> junk >> junk >> junk;
    //fin >> junk >> firstName >> lastName;
    //fin >> junk >> age >> junk;
    //fin >> junk >> major1 >> major2;
    //fin >> junk >> gpa;

    //fin >> junk >> junk >> gradSemester >> gradYear;
    getline(fin, line);
    //getline(fin, line);
    string junk;
    //Assign lines from files to variables
    // had help fixing the junk. I had some of my junks covering up some import information that made the test cases not function the right way.
    // second line contains ship mass
    // third line contains acceleration
    // fourth line contain change in velocity
    // fifth line contain max altitude
    // sixth line is useless
    fin >> junk >> junk >> ship.mass
        >> junk >> junk >> ship.acceleration >> junk
        >> junk >> junk >> ship.changeInVelocity >> junk >> junk >> junk
        >> ship.maxAltitude >> junk;
    getline(fin, line);  // read and discard \n left by fin>>
    getline(fin, line); // read and discard 5th line(which contains the time)
    fin >> junk >> junk >> firstName >> lastName;
    // 7th line contains the designer name
    ship.designerName = firstName + " " + lastName;

    // Uncomment the below lines to check if all values are read correctly or not from file
    /*
    cout << "Ship Information:" << endl;
    cout << "Designer: " << ship.designerName << endl;
    cout << "Mass: " << ship.mass << endl;
    cout << "Acceleration: " << ship.acceleration<< endl;
    cout << "Change In velocity: " << ship.changeInVelocity << endl;
    cout << "Max Altitude: " << ship.maxAltitude << endl;
    */
    // Close the file
    fin.close();

    // this came from the last assignment
    // had some help changing the true statements to make sure the code ran better
    // change just if statements to else if
    // test 1
    if(ship.designerName == "Thomas Harris") {
        cout << ship.shipname << " has failed Test 1\n" ;
    }
    // test 2
    else if(ship.mass > 1000) {
        cout << ship.shipname << " has failed Test 2\n";
    }
    // test 3
    else if(ship.acceleration < 1 || ship.acceleration > 10) {
        cout << ship.shipname << " has failed Test 3\n";
    }
    // test 4
    else if(ship.changeInVelocity < 800) {
        cout << ship.shipname << " has failed Test 4\n";
    }
    // test 5
    else if(ship.mass < 100) {
        if(ship.maxAltitude < 150) {
            cout << ship.shipname << " has failed Test 5\n";
        }
    }
    else if (!(ship.maxAltitude >= 200)){
        cout << ship.shipname << " has failed Test 5\n";
    }
    // If all test are good
    else{
        cout << ship.shipname << " has passed all tests.\n";
    }
    return;
    // Created the Simulation Ship Flight
}

void shipFlight(){

    float acceleration = 0, time = 0, speed = 0, altitude = 0;
    cin >> acceleration;
    cin >> time;
    // i is the same as the time
    //I got help with that in the CS lab
    for(int i = 0; i <= time; i++) {
        altitude = 0.5 * acceleration * i * i;
        cout << fixed << setprecision(1);
        cout << "At " << i << " seconds: " << speed << " m/s " << altitude << " m" << endl;
        speed += acceleration;
    }
    return;
}

// end of program