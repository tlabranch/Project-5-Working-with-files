#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ifstream inFS;   // Input file stream
    string cityName;    //File data
    int cityTemp;     // File data
    double tempCelsius; 

    // Open file
    cout << "Opening file FahrenheitTemperature.txt." << endl;
    inFS.open("FahrenheitTemperature.txt");

    if (!inFS.is_open()) {
        cout << "Could not open file FahrenheitTemperature.txt." << endl;
        return 1;
    }

  

    /* Print read numbers to output*/
    cout << "Reading and printing numbers." << endl;

    
   
    while (!inFS.eof()) {
        inFS >> cityName;
        inFS >> cityTemp; //This will be the city temp
        cout << cityName << " " << cityTemp << endl;
       /* numbers.push_back(fileNum);*/


    }
    if (!inFS.eof()) {
        cout << "Input failure before reaching end of file." << endl;
    }

    cout << "Closing file FahrenheitTemperature.txt." << endl;

    // Done with file, so close it
    inFS.close();








    ofstream outFS; // Output file stream

    // Open file
    outFS.open("CelsiusTemperature.txt");

    if (!outFS.is_open()) {
        cout << "Could not open file CelsiusTemperature.txt." << endl;
        return 1;
    }

    inFS.open("FahrenheitTemperature.txt");

    while (inFS >> cityName >> cityTemp) {
        tempCelsius = (cityTemp - 32) * (5.0 / 9.0);
        outFS << cityName << " " << tempCelsius << endl;
    }

    // Done with file, so close
    inFS.close();
    outFS.close();

    return 0;
}