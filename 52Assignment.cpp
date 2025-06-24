//Hector Gonzalez

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    ifstream inputFile("FahrenheitTemperature.txt");
    ofstream outputFile("CelsiusTemperature.txt");

    if (!inputFile) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Error: Could not open output file." << endl;
        return 1;
    }

    string city;
    double fahrenheit;

    while (inputFile >> city >> fahrenheit) {
        double celsius = fahrenheitToCelsius(fahrenheit);
        outputFile << city << " " << fixed << setprecision(1) << celsius << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Conversion completed. Check CelsiusTemperature.txt for results." << endl;

    return 0;
}
