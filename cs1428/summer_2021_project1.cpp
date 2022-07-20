#include <iostream>
#include<iomanip>
#include<math.h>
#include<string>
#include<fstream>

using namespace std;

#define g 9.8

int main()
{
    //Input and calculation variables Declaration
    string shipName, designerName;
    int shipMass, engineThrust;
    double acceleration, deltaV, maxAltitude;

    //Get inputs from user
    cout << "Ship name: ";
    cin >> shipName;
    cin.ignore();
    cout << "Designer name: ";
    getline(cin, designerName);
    cout << "Ship mass: ";
    cin >> shipMass;
    cout << "Engine thrust: ";
    cin >> engineThrust;

    //Do calculations
    acceleration = engineThrust/(double)shipMass;
    deltaV = (100000 / engineThrust) * g * log(2);
    maxAltitude = 100 + (deltaV - 200) / 10;

    //Output in console
    cout << "\nFile written for " << shipName << endl;

    //Output in file
    ofstream out(shipName + ".txt");
    out << fixed << setprecision(1);
    out << "##########" << shipName << "##########\n\n";
    out << "Designed by:\t\t" << designerName<< endl;
    out << "Ship mass:\t\t" << shipMass << "kg" << endl;
    out << "Acceleration:\t\t" << acceleration << "m/s2\n";
    out << "Delta V:\t\t" << deltaV << "m/s\n";
    out << "Max Altitude:\t\t" << maxAltitude << "km\n\n";
    out << "File saves at:\t\t" << time(NULL) << endl;
    out.close();
    return 0;
}