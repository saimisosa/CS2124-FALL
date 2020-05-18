//Saimanasa Juluru
//CS2124
//Section A
//15 September 2019

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
string fileName;

struct chemicalInfo {
    vector<string> formulas;
    int numofCarbon;
    int numofHydrogen;
};

void openFile(ifstream& input);
void fillVector(ifstream& file, vector<chemicalInfo>& formulas);
void addFormula(string& name, int numC, int numH, vector<chemicalInfo>& formulas);
size_t dupFormula(int numC, int numH, const vector<chemicalInfo>& formulas);
void sortFormulas(vector<chemicalInfo>& hydrocarbons);
void displayContents(const vector<chemicalInfo>&);

int main() {

    ifstream chemicals;
    openFile(chemicals);

    vector<chemicalInfo> fullHydroCarbons;

    fillVector(chemicals, fullHydroCarbons);
    chemicals.close();

    sortFormulas(fullHydroCarbons);
    displayContents(fullHydroCarbons);
}
// opens file with ifstream declared in main
// will prompt the user to enter a valid filename until it can actually be opened
void openFile(ifstream& input){
    cout << "Please enter the filename: ";
    cin >> fileName;

    input.open(fileName);
    while (!input) {
        input.clear();
        cout << "Could not open the file. Please enter a new name. ";
        cin >> fileName;
        input.open(fileName);
    }
}
// for each line in file, obtain each piece of info (char by char)
// with that info, call the addFormula function
void fillVector(ifstream& file, vector<chemicalInfo>& formulas) {
    string names;
    char carbon;
    int numC;
    char hydrogen;
    int numH;

    while (file >> names >> carbon >> numC >> hydrogen >> numH) {
        addFormula(names, numC, numH, formulas);
    }
}

// adds formulas to the vector of Hydrocarbons
// calls dupFormula to find the location of repeat compounds
void addFormula(string& name, int numC, int numH, vector<chemicalInfo>& formulas) {
    int location;
    location = dupFormula(numC, numH, formulas);
    chemicalInfo newHydrocarbon;

    if (location == -1) {
        newHydrocarbon.formulas.push_back(name);
        newHydrocarbon.numofCarbon = numC;
        newHydrocarbon.numofHydrogen = numH;
        formulas.push_back(newHydrocarbon);
    }
    else {
        formulas[location].formulas.push_back(name);
    }

}
// checks for the location of repeat compounds
size_t dupFormula(int numC, int numH, const vector<chemicalInfo>& formulas) {
    for (size_t elem = 0; elem < formulas.size(); ++elem) {
        if (formulas[elem].numofCarbon == numC && formulas[elem].numofHydrogen == numH) {
            return elem;
        }
    }
    return -1;
}
// bubble sort to order them from least # of Carbon. if # of C is same, sort based on H.
void sortFormulas(vector<chemicalInfo>& hydrocarbons) {
    for (size_t size = 0; size < hydrocarbons.size(); ++size) {
        for (size_t rest = 0; rest < hydrocarbons.size() - 1; ++rest) {
            if (hydrocarbons[rest].numofCarbon > hydrocarbons[rest + 1].numofCarbon) {
                swap(hydrocarbons[rest], hydrocarbons[rest + 1]);
            }
            else if (hydrocarbons[rest].numofCarbon == hydrocarbons[rest + 1].numofCarbon &&
                       hydrocarbons[rest].numofHydrogen > hydrocarbons[rest + 1].numofHydrogen) {
                swap(hydrocarbons[rest], hydrocarbons[rest + 1]);
            }
        }
    }
}
// displays the contents of the now sorted vector on the console
void displayContents(const vector<chemicalInfo>& hydrocarbonList) {
    for (size_t element = 0; element < hydrocarbonList.size(); ++element) {
        cout << 'C' << hydrocarbonList[element].numofCarbon <<
             'H' << hydrocarbonList[element].numofHydrogen << ' ';
        for (int compound = 0; compound < hydrocarbonList[element].formulas.size(); ++compound) {
            cout << hydrocarbonList[element].formulas[compound] << ' ';
        }
        cout << endl;
    }
}