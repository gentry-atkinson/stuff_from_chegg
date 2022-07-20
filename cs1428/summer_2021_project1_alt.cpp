#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>
#include <math.h>
using namespace std;

int main()
{
    cout << "Hello World!\n";
    string designerName;
    string shipName;
    string outFileName;
    float shipMass = 0;    
    float engineThrust = 0;
    float acceleration = 0;
    float changeInVelocity = 0;
    float maxAltitude = 0;
    float thrustFraction = 0;
    const float g0 = 9.8;
    cout << "Kindly enter the First name and Last name of the vehicle designer seperated by spaces Ex: (Micheal Lee): ";       
    getline(cin, designerName, '\n');    
    cout << "\nKindly enter the Ship Name: ";
    getline(cin, shipName, '\n');

    cout << "\nKindly enter the Ship Mass(In Kgs): ";
    cin >> shipMass;
    while (1)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid value entered for ship mass ";
            cout << "\nKindly enter numeric values for Ship Mass" << endl;
            cout << "\nKindly enter the Ship Mass(In Kgs): ";
            cin >> shipMass;
        }
        if (!cin.fail())
            break;
    }    

    cout << "\nKindly enter the engine Thrust(In newtons): ";
    cin >> engineThrust;
    while (1)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid value entered for engine thrust ";
            cout << "\nKindly enter numeric values for engine thrust" << endl;
            cout << "\nKindly enter the engine Thrust(In newtons): ";
            cin >> engineThrust;
        }
        if (!cin.fail())
            break;
    }
    
    if (engineThrust != 0) {        
        acceleration = (shipMass / engineThrust);
        acceleration = acceleration / 100;
        thrustFraction = (100000 / engineThrust);
        changeInVelocity = thrustFraction * g0 * log(2);
    }
    maxAltitude = (changeInVelocity - 200) / 10;
    maxAltitude = maxAltitude + 100;
    outFileName = shipName + ".txt";
    ofstream outfile;
    outfile.open(outFileName);
    outfile << "###########" << shipName << "###########";
    outfile << "\n";
    outfile << "\nDesigned By:\t\t" << std::left  << designerName;
    outfile << "\nShip Mass:\t\t" << std::left <<  shipMass << "kg";
    outfile << fixed << setprecision(1) << "\nAcceleration:\t\t" << std::left <<  acceleration << "m/s2";
    outfile << fixed << setprecision(1) << "\nDelta V:\t\t" << std::left << changeInVelocity << "m/s";
    outfile << fixed << setprecision(1) << "\nMax Altitide:\t\t" << std::left << maxAltitude << "km";
    outfile << "\n";
    outfile << "File save at:\t\t" << time(NULL);
    cout << "File written for " << shipName;
    return 0;
};