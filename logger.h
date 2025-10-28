#ifndef LOGGER_H 
#define LOGGER_H

#include <string>
#include <fstream>

using namespace std;

class Logger {
    private:

        string logFilename;
        string getCurrentDateTime() const;

    public:
        // Constructor
        Logger(const string& filename = "library_activity.log");

        // Methods
        void logCheckOut(const string& isbn, const string& bookTitle, const string& userName);
        void logReturn(const string& isbn, const string& bookTitle, const string& userName);

        void displayRecentLogs(int count = 10) const;
};

#endif