#include "logger.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

Logger::Logger(const string& filename) : logFilename(filename) {}

// Obtenir date/heure actuelle
/**
 * C++ Date and Time
 * https://www.w3schools.com/cpp/cpp_date.asp
 * 
 * setw() function in C++ with Examples
 * https://www.geeksforgeeks.org/cpp/setw-function-in-cpp-with-examples/
 */
string Logger::getCurrentDateTime() const {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    
    stringstream ss;
    ss << setfill('0')
       << setw(4) << (1900 + ltm->tm_year) << "-"
       << setw(2) << (1 + ltm->tm_mon) << "-"
       << setw(2) << ltm->tm_mday << "|"
       << setw(2) << ltm->tm_hour << ":"
       << setw(2) << ltm->tm_min << ":"
       << setw(2) << ltm->tm_sec;
    
    return ss.str();
}

// Logger: emprunt
void Logger::logCheckOut(const string& isbn, const string& bookTitle, const string& userName) {  
    ofstream f(logFilename, ios::app);  
    if (!f.is_open()) return;
    f << getCurrentDateTime() << "|EMPRUNT|" << isbn << "|" << bookTitle << "|" << userName << "\n";
}

// Logger: retour
void Logger::logReturn(const string& isbn, const string& bookTitle, const string& userName) {
    ofstream f(logFilename, ios::app);
    if (!f.is_open()) return;
    f << getCurrentDateTime() << "|RETOUR|" << isbn << "|" << bookTitle << "|" << userName << "\n";
}

// Afficher logs récents
void Logger::displayRecentLogs(int count) const {
    ifstream f(logFilename);
    if (!f.is_open()) { cout << "Aucun log disponible.\n"; return; }

    vector<string> lines;
    string line;
    while (getline(f, line)) if (!line.empty()) lines.push_back(line);

    cout << "\n=== LOGS D'ACTIVITÉ RÉCENTS ===\n";
    int start = max(0, (int)lines.size() - count);
    for (int i = start; i < (int)lines.size(); ++i) {
        stringstream ss(lines[i]);
        string date, time, action, isbn, title, name;
        getline(ss, date, '|');
        getline(ss, time, '|');
        getline(ss, action, '|');
        getline(ss, isbn, '|');
        getline(ss, title, '|');
        getline(ss, name, '|');

        cout << "\n[" << date << " " << time << "]\n";
        if (action == "RETOUR")
            cout << "  <-- " << name << " a retourne \"" << title << "\"\n";
        else if (action == "EMPRUNT")
            cout << "  --> " << name << " a emprunte \"" << title << "\"\n";
        else
            cout << "  * " << action << " \"" << title << "\"\n";
        cout << "      ISBN: " << isbn << "\n";
        cout << "\n" << string(60, '-') << "\n";
    }

    cout << "\nTotal : " << lines.size() << " activite(s)\n";
}
