#include <Data.h>
void Data::createFileIfNotExists(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.good()) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            cout << "File " << filename << " created." << endl;
            outFile.close();
        } else {
            cerr << "Failed to create file " << filename << endl;
        }
    }
}

void Data::saveData(const string& data) {
    ofstream outFile("orders.txt", ios::app);

    if (outFile.is_open()) {
        outFile << data;
        if (outFile.fail()) {
            cerr << "Error writing to file orders.txt\n";
        }
        outFile.close();
    } else {
        cerr << "Failed to open file orders.txt for writing.\n";
    }
}

string Data::loadData() {
    createFileIfNotExists("orders.txt");

    ifstream inFile("orders.txt");
    stringstream ss;

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            ss << line << "\n";
        }
        if (inFile.fail() && !inFile.eof()) {
            cerr << "Error reading from file orders.txt\n";
        }
        inFile.close();
        return ss.str();
    } else {
        cerr << "Failed to open file orders.txt for reading.\n";
        return "";
    }
}