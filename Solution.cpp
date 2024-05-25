#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

ofstream outfile("output.txt");

struct LogEntry
{
    long long timestamp;
    string logType;
    double severity;
};

class ErrorLogMonitor
{
private:
    vector<LogEntry> logEntries;

public:
    void addLogEntry(const LogEntry &entry)
    {
        logEntries.push_back(entry);
        outfile << "No output\n";
    }

    void computeStatsByLogType(const string &logType)
    {
        vector<double> severities;
        for (const auto &entry : logEntries)
        {
            if (entry.logType == logType)
            {
                severities.push_back(entry.severity);
            }
        }
        if (severities.empty())
        {
            outfile << "Min: 0.0, Max: 0.0, Mean: 0.0" << endl;
            return;
        }
        double minSeverity = *min_element(severities.begin(), severities.end());
        double maxSeverity = *max_element(severities.begin(), severities.end());
        double meanSeverity = 0.0;
        for (const auto &severity : severities)
        {
            meanSeverity += severity;
        }
        meanSeverity /= severities.size();

        outfile << fixed << setprecision(6);
        outfile << "Min: " << minSeverity << ", Max: " << maxSeverity << ", Mean: " << meanSeverity << endl;
    }

    void computeStatsBeforeTimestamp(long long timestamp)
    {
        vector<double> severities;
        for (const auto &entry : logEntries)
        {
            if (entry.timestamp < timestamp)
            {
                severities.push_back(entry.severity);
            }
        }
        if (severities.empty())
        {
            outfile << "Min: 0.0, Max: 0.0, Mean: 0.0" << endl;
            return;
        }
        double minSeverity = *min_element(severities.begin(), severities.end());
        double maxSeverity = *max_element(severities.begin(), severities.end());
        double meanSeverity = 0.0;
        for (const auto &severity : severities)
        {
            meanSeverity += severity;
        }
        meanSeverity /= severities.size();

        outfile << fixed << setprecision(6);
        outfile << "Min: " << minSeverity << ", Max: " << maxSeverity << ", Mean: " << meanSeverity << endl;
    }

    void computeStatsAfterTimestamp(long long timestamp)
    {
        vector<double> severities;
        for (const auto &entry : logEntries)
        {
            if (entry.timestamp > timestamp)
            {
                severities.push_back(entry.severity);
            }
        }
        if (severities.empty())
        {
            outfile << "Min: 0.0, Max: 0.0, Mean: 0.0" << endl;
            return;
        }
        double minSeverity = *min_element(severities.begin(), severities.end());
        double maxSeverity = *max_element(severities.begin(), severities.end());
        double meanSeverity = 0.0;
        for (const auto &severity : severities)
        {
            meanSeverity += severity;
        }
        meanSeverity /= severities.size();

        outfile << fixed << setprecision(6);
        outfile << "Min: " << minSeverity << ", Max: " << maxSeverity << ", Mean: " << meanSeverity << endl;
    }

    void computeStatsByLogTypeBeforeTimestamp(const string &logType, long long timestamp)
    {
        vector<double> severities;
        for (const auto &entry : logEntries)
        {
            if (entry.logType == logType && entry.timestamp < timestamp)
            {
                severities.push_back(entry.severity);
            }
        }
        if (severities.empty())
        {
            outfile << "Min: 0.0, Max: 0.0, Mean: 0.0" << endl;
            return;
        }
        double minSeverity = *min_element(severities.begin(), severities.end());
        double maxSeverity = *max_element(severities.begin(), severities.end());
        double meanSeverity = 0.0;
        for (const auto &severity : severities)
        {
            meanSeverity += severity;
        }
        meanSeverity /= severities.size();

        outfile << fixed << setprecision(6);
        outfile << "Min: " << minSeverity << ", Max: " << maxSeverity << ", Mean: " << meanSeverity << endl;
    }

    void computeStatsByLogTypeAfterTimestamp(const string &logType, long long timestamp)
    {
        vector<double> severities;
        for (const auto &entry : logEntries)
        {
            if (entry.logType == logType && entry.timestamp > timestamp)
            {
                severities.push_back(entry.severity);
            }
        }
        if (severities.empty())
        {
            outfile << "Min: 0.0, Max: 0.0, Mean: 0.0" << endl;
            return;
        }
        double minSeverity = *min_element(severities.begin(), severities.end());
        double maxSeverity = *max_element(severities.begin(), severities.end());
        double meanSeverity = 0.0;
        for (const auto &severity : severities)
        {
            meanSeverity += severity;
        }
        meanSeverity /= severities.size();

        outfile << fixed << setprecision(6);
        outfile << "Min: " << minSeverity << ", Max: " << maxSeverity << ", Mean: " << meanSeverity << endl;
    }
};

int main()
{
    ErrorLogMonitor monitor;
    ifstream infile("input.txt");
    string line;
    while (getline(infile, line))
    {
        istringstream iss(line);
        int operation;
        iss >> operation;
        if (operation == 1)
        {
            long long timestamp;
            string logType;
            double severity;
            char separator;
            iss >> timestamp >> separator;
            getline(iss, logType, ';');
            iss >> severity;

            monitor.addLogEntry({timestamp, logType, severity});
        }
        else if (operation == 2)
        {
            string logType;
            iss >> logType;

            monitor.computeStatsByLogType(logType);
        }
        else if (operation == 3)
        {
            string keyword;
            long long timestamp;
            iss >> keyword >> timestamp;
            if (keyword == "BEFORE")
            {
                monitor.computeStatsBeforeTimestamp(timestamp);
            }
            else if (keyword == "AFTER")
            {
                monitor.computeStatsAfterTimestamp(timestamp);
            }
        }
        else if (operation == 4)
        {
            string logType;
            long long timestamp;
            string keyword;
            iss >> keyword >> logType >> timestamp;
            if (keyword == "BEFORE")
            {
                monitor.computeStatsByLogTypeBeforeTimestamp(logType, timestamp);
            }
            else if (keyword == "AFTER")
            {
                monitor.computeStatsByLogTypeAfterTimestamp(logType, timestamp);
            }
        }
    }
    infile.close();
    outfile.close();
    return 0;
}
