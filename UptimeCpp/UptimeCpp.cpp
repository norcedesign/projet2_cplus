// UptimeCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <fstream>
#include <string>

#include <chrono>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <iostream>
#include "../UptimeCpp/TimeConverter.h"
#include <vector>
using namespace std;
int main()
{
    //Déteminer l'heure actuelle
    auto n = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(n);
    tm buf;
    localtime_s(&buf, &in_time_t);

    // Read from the text file
    ifstream myFile("uptime_file.txt");

    string ligneText;
    int i = 1;

    TimeConverter* tc = new TimeConverter();

    // lire ligne par ligne
    while (getline(myFile, ligneText)) {

        // istringstream str("15005117.05 6945200.26");
        //cout << "***Cas no. " << i << "**\n";
        istringstream str(ligneText);
        vector<double> array;
        double temp;
        while (str >> temp)
            array.push_back(temp);
        cout << put_time(&buf, "%X") << " up " << tc->ConvertSectoTimeString(array[0]) << endl;
        cout << put_time(&buf, "%X") << " idle " << tc->ConvertSectoTimeString(array[1]) << endl;

        i++;
    }
    // Close the file
    myFile.close();

    return 0;
}

