/*Saimanasa Juluru*/
/*CS 2124*/
/*06 September 2019*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string text;
    string word;

    int count = 0;

    ifstream testFile;
    testFile.open("jabberwocky");

    if (!testFile) {
        cerr << "Could not open the file.\n";
        exit(1);
    }

    while(getline(testFile,text)) {
        cout << text << endl;
    }

    testFile.close();
    testFile.open("jabberwocky");

    while (testFile >> word) {
        count++;
    }

    cout << "The number of words in this file are: "<< count;
    testFile.close();
}