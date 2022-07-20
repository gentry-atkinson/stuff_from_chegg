#include<iostream>

#include<iomanip>

#include<math.h>

#include<string>

#include<fstream>

#include<vector>

using namespace std;
#define g 9.8
void test_case(string s_n, vector < string > shipName, vector < string > designerName, vector < int > shipMass, vector < double > acceleration, vector < double > deltaV, vector < double > maxAltitude) {
    int i;
    for (i = 0; i < shipName.size(); i++) {
        if (s_n == shipName[i]) {
            break;
        }
    }
    if (i == shipName.size()) {
        cout << s_n << " does not exist!!!" << endl;
        return;
    }
    if (designerName[i] == "Thomas Harris") {
        cout << s_n << " has failed Test 1 " << endl;
        return;
    } else if (shipMass[i] > 1000) {
        cout << s_n << " has failed Test 2 " << endl;
        return;
    } else if (acceleration[i] < 1 || acceleration[i] > 10) {
        cout << s_n << " has failed Test 3 " << endl;
        return;
    } else if (deltaV[i] < 800) {
        cout << s_n << " has failed Test 4 " << endl;
        return;
    } else if (shipMass[i] < 100) {
        if (maxAltitude[i] < 150) {
            cout << s_n << " has failed Test 5 " << endl;
            return;
        }
    } else {
        if (maxAltitude[i] < 200) {
            cout << s_n << " has failed Test 5 " << endl;
            return;
        }
    }
    cout << s_n << " passed all tests." << endl;
    return;
}
int main() {
    vector < string > shipName, designerName;
    string s_n, d_n;
    vector < int > shipMass, engineThrust;
    int s_m, e_t;
    vector < double > acceleration, deltaV, maxAltitude;
    double d_v, acc, m_a;
    cout << "***********************MENU*********************" << endl;
    cout << " D-design a new ship" << endl;
    cout << " T-test a new ship" << endl;
    cout << " Q-quit the program" << endl;
    char ch;
    do {
        cout << endl << "Enter your choice: ";
        cin >> ch;
        if (ch == 'd' || ch == 'D') {
            cout << "ship name: ";
            cin >> s_n;
            cin.ignore();
            shipName.push_back(s_n);
            cout << "Designer name: ";
            getline(cin, d_n);
            designerName.push_back(d_n);
            cout << "Ship mass: ";
            cin >> s_m;
            shipMass.push_back(s_m);
            cout << "Engine thrust: ";
            cin >> e_t;
            engineThrust.push_back(e_t);
            acc = e_t / (double) s_m;
            acceleration.push_back(acc);
            d_v = (100000 / e_t) * g * log(2);
            deltaV.push_back(d_v);
            m_a = 100 + (d_v - 200) / 10;
            maxAltitude.push_back(m_a);
            cout << "\nFile written for " << s_n << endl;
            ofstream out(s_n + ".txt");
            cout << fixed << setprecision(1);
            cout << "###############" << s_n << "###############\n\n";
            cout << "Designed by:\t\t" << setw(10) << d_n << endl;
            cout << "Ship mass:\t\t" << setw(9) << s_m << " kg" << endl;
            cout << "Acceleration:\t\t" << setw(3) << acc << " m/s^2\n";
            cout << "Delta V:\t\t" << setw(10) << d_v << " m/s" << endl;
            cout << "Max Altitude:\t\t" << setw(5) << m_a << " km\n\n";
            cout << "File saves at:\t\t" << setw(10) << time(NULL) << endl;
            cout.close();
        } else if (ch == 'T' || ch == 't') {
            cout << "ship name: ";
            cin >> s_n;
            test_case(s_n, shipName, designerName, shipMass, acceleration, deltaV, maxAltitude);
        }
    } while (ch != 'Q');
    return 0;
}