// ============================================================
//  Network Port Scanner Simulator
//  Author  : Group 7
//  Course  : Programming Fundamentals — NUML University
//  Concepts: Arrays, Functions, Loops
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================
//  PART 1 — DATA
//  We store info about 30 well-known ports.
//  All three arrays use the same index — index 0 means port 21.
// ============================================================

const int TOTAL = 30;

int portNumbers[TOTAL] = {
    21, 22, 23, 25, 53,
    80, 110, 119, 135, 139,
    143, 194, 443, 445, 3389,
    8080, 8443, 3306, 5432, 27017,
    6379, 1433, 5900, 20, 69,
    161, 389, 636, 5060, 1723
};

string portNames[TOTAL] = {
    "FTP",       "SSH",        "Telnet",     "SMTP",       "DNS",
    "HTTP",      "POP3",       "NNTP",       "RPC",        "NetBIOS",
    "IMAP",      "IRC",        "HTTPS",      "SMB",        "RDP",
    "HTTP-Alt",  "HTTPS-Alt",  "MySQL",      "PostgreSQL", "MongoDB",
    "Redis",     "MSSQL",      "VNC",        "FTP-Data",   "TFTP",
    "SNMP",      "LDAP",       "LDAPS",      "SIP",        "PPTP"
};

// 0 = LOW risk, 1 = MEDIUM risk, 2 = HIGH risk
int portRisk[TOTAL] = {
    2, 1, 2, 1, 0,
    0, 1, 0, 2, 2,
    1, 1, 0, 2, 2,
    0, 0, 2, 2, 2,
    2, 2, 2, 1, 2,
    2, 1, 0, 1, 1
};

// Chance (out of 100) that each port is open
int openChance[TOTAL] = {
    30, 40, 15, 35, 60,
    85, 25, 10, 20, 25,
    20, 10, 80, 30, 35,
    55, 45, 40, 25, 20,
    25, 30, 20, 25, 10,
    20, 15, 30, 15, 20
};

// ============================================================
//  PART 2 — SIMPLE RANDOM NUMBER
//  We do not use cstdlib or ctime.
//  This formula gives a different number each time it runs.
// ============================================================

int randomSeed = 12345;

int myRandom(int limit) {
    randomSeed = randomSeed * 1103515245 + 12345;
    if (randomSeed < 0) randomSeed = -randomSeed;
    return randomSeed % limit;
}

// ============================================================
//  PART 3 — SCAN LOGIC
//  Decides if a port is OPEN (1), FILTERED (2), or CLOSED (0)
// ============================================================

int scanPort(int index) {
    int roll     = myRandom(100);
    int open     = openChance[index];
    int filtered = open / 3;

    if (roll < open)
        return 1;  // OPEN
    else if (roll < open + filtered)
        return 2;  // FILTERED
    else
        return 0;  // CLOSED
}

// ============================================================
//  PART 4 — DISPLAY HELPERS
// ============================================================

void printLine() {
    cout << "  --------------------------------------------------\n";
}

string riskText(int r) {
    if (r == 0) return "LOW";
    if (r == 1) return "MED";
    if (r == 2) return "HIGH";
    return "N/A";
}

string stateText(int s) {
    if (s == 1) return "OPEN    ";
    if (s == 2) return "FILTERED";
    return "CLOSED  ";
}

void printTableHeader() {
    printLine();
    cout << "  PORT       STATE     SERVICE        RISK\n";
    printLine();
}

// Print one row — skips closed ports
void printRow(int portNum, int state, string name, int risk) {
    if (state == 0) return;

    cout << "  " << portNum << "/tcp"
         << "    " << stateText(state)
         << "  " << name;

    // manual padding so columns line up
    int spaces = 14 - name.length();
    for (int i = 0; i < spaces; i++) cout << " ";

    if (state == 1) {
        cout << riskText(risk);
        if (risk == 2) cout << "  << HIGH RISK";
    } else {
        cout << "N/A";
    }

    cout << "\n";
}

// ============================================================
//  PART 5 — SUMMARY
// ============================================================

void printSummary(int states[], int risks[], int total) {
    int openCount = 0, filteredCount = 0, closedCount = 0, danger = 0;

    for (int i = 0; i < total; i++) {
        if      (states[i] == 1) openCount++;
        else if (states[i] == 2) filteredCount++;
        else                     closedCount++;

        if (states[i] == 1 && risks[i] == 2)
            danger++;
    }

    printLine();
    cout << "\n  RESULTS\n";
    cout << "  Scanned  : " << total         << "\n";
    cout << "  Open     : " << openCount     << "\n";
    cout << "  Filtered : " << filteredCount << "\n";
    cout << "  Closed   : " << closedCount   << "\n";

    if (danger > 0)
        cout << "\n  WARNING: " << danger << " high-risk port(s) open!\n";
    else
        cout << "\n  All clear. No critical ports detected.\n";

    cout << "\n";
}

// ============================================================
//  PART 6 — SCAN MODES
// ============================================================

// Quick Scan — checks all 30 known ports
void quickScan() {
    cout << "\n  [*] Quick Scan — checking 30 known ports...\n";
    printTableHeader();

    int states[TOTAL];
    int risks[TOTAL];

    for (int i = 0; i < TOTAL; i++) {
        states[i] = scanPort(i);
        risks[i]  = portRisk[i];
        printRow(portNumbers[i], states[i], portNames[i], risks[i]);
    }

    printSummary(states, risks, TOTAL);
}

// Full Scan — checks every port in a given range
void fullScan(int start, int end) {
    cout << "\n  [*] Full Scan — ports " << start << " to " << end << "...\n";
    printTableHeader();

    int states[TOTAL];
    int risks[TOTAL];
    int count = 0;

    for (int port = start; port <= end && count < TOTAL; port++) {

        // Search if this port is in our known list
        int index = -1;
        for (int i = 0; i < TOTAL; i++) {
            if (portNumbers[i] == port) {
                index = i;
                break;
            }
        }

        int state, risk;
        string name;

        if (index != -1) {
            // Port is in our database
            state = scanPort(index);
            name  = portNames[index];
            risk  = portRisk[index];
        } else {
            // Unknown port — very low chance of being open
            int roll = myRandom(100);
            state = (roll < 10) ? 1 : (roll < 13 ? 2 : 0);
            name  = "Unknown";
            risk  = -1;
        }

        printRow(port, state, name, risk);
        states[count] = state;
        risks[count]  = risk;
        count++;
    }

    printSummary(states, risks, count);
}

// Stealth Scan — scans ports in random order
// Randomizing order makes it harder for firewalls to detect the scan
void stealthScan(int start, int end) {
    cout << "\n  [*] Stealth Scan — random order...\n";
    printTableHeader();

    int size = end - start + 1;
    if (size > TOTAL) size = TOTAL;

    // Build list of ports
    int portList[TOTAL];
    for (int i = 0; i < size; i++) {
        portList[i] = start + i;
    }

    // Shuffle the list using random swaps
    for (int i = size - 1; i > 0; i--) {
        int j       = myRandom(i + 1);
        int temp    = portList[i];
        portList[i] = portList[j];
        portList[j] = temp;
    }

    int states[TOTAL];
    int risks[TOTAL];

    for (int i = 0; i < size; i++) {
        int port = portList[i];

        int index = -1;
        for (int k = 0; k < TOTAL; k++) {
            if (portNumbers[k] == port) {
                index = k;
                break;
            }
        }

        int state, risk;
        string name;

        if (index != -1) {
            state = scanPort(index);
            name  = portNames[index];
            risk  = portRisk[index];
        } else {
            int roll = myRandom(100);
            state = (roll < 10) ? 1 : (roll < 13 ? 2 : 0);
            name  = "Unknown";
            risk  = -1;
        }

        states[i] = state;
        risks[i]  = risk;
        printRow(port, state, name, risk);
    }

    printSummary(states, risks, size);
}

// ============================================================
//  PART 7 — INPUT VALIDATION
// ============================================================

int getInput(string msg, int minVal, int maxVal) {
    int val;
    while (true) {
        cout << msg;
        cin >> val;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  Please enter a number.\n";
        } else if (val < minVal || val > maxVal) {
            cout << "  Enter a value between " << minVal << " and " << maxVal << ".\n";
        } else {
            return val;
        }
    }
}

// ============================================================
//  MAIN
// ============================================================

int main() {
    cout << "\n";
    cout << "  ==========================================\n";
    cout << "    NetScan v1.0 — Port Scanner Simulator\n";
    cout << "    Author: Group 7 | NUML\n";
    cout << "  ==========================================\n";
    cout << "  Target : 192.168.1.1 (simulated)\n";

    bool running = true;

    while (running) {
        cout << "\n";
        cout << "  === SCAN MENU ===\n";
        cout << "  [1] Quick Scan\n";
        cout << "  [2] Full Scan\n";
        cout << "  [3] Stealth Scan\n";
        cout << "  [4] Exit\n";

        int choice = getInput("  Choice: ", 1, 4);

        if (choice == 1) {
            quickScan();

        } else if (choice == 2) {
            int s = getInput("  Start port (1-1000): ", 1, 1000);
            int e = getInput("  End port (" + to_string(s) + "-1000): ", s, 1000);
            fullScan(s, e);

        } else if (choice == 3) {
            int s = getInput("  Start port (1-30): ", 1, 30);
            int e = getInput("  End port (" + to_string(s) + "-30): ", s, 30);
            stealthScan(s, e);

        } else {
            cout << "\n  Exiting. Good work.\n\n";
            running = false;
        }
    }

    return 0;
}
