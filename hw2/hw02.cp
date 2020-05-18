//Saimanasa Juluru
//CS2124
//22 September 2019
/*This code reads in a file, warriors.txt, and executes the commands
 * detailed in each line. It reads in the warriors, has them battle,
 * and displays their ending stats. */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Warrior {
    string warriorName;
    int weaponStrength;
};

void battle(Warrior& warrior_1, Warrior& warrior_2);//starts battle between two warriors
void displayStatus(const vector<Warrior>& warriors);//displays warriors' current stats
int findWarrior(const vector<Warrior>& warriors, const string& name);//finds the index of a warrior if it exists
void start_program(ifstream& input);//runs program

int main()
{
    ifstream input("warriors.txt");
    start_program(input);

    input.close();

}

void start_program(ifstream& input)
{
    string token;
    vector<Warrior> warriors;
    if (!input)
    {
        cerr << "failed to open file";
        exit(1);
    }
    while (input >> token)
    {
        if (token == "Warrior")//create new Warrior
        {
            string name;
            int strength;
            input >> name;
            input >> strength;

            Warrior person; //creates new warrior object
            person.warriorName = name; //manually sets name
            person.weaponStrength = strength; //manually sets strength
            warriors.emplace_back(person); //pushes this struct into the vector
        }
        else if (token == "Battle")//battle two warriors and update stats
        {
            string warrior_1, warrior_2;
            input >> warrior_1;
            input >> warrior_2;
            battle(warriors[findWarrior(warriors, warrior_1)],
                   warriors[findWarrior(warriors, warrior_2)]);
        }
        else //display stats
        {
            displayStatus(warriors);
        }
    }
}


int findWarrior(const vector<Warrior>& warriors, const string& name)
{
    //check if warrior exists in the vector
    for (size_t i = 0; i < warriors.size(); i++)
    {
        if (warriors[i].warriorName == name)
        {
            return i;
        }
    }
    //return size if warrior not found
    return warriors.size();
}

void displayStatus(const vector<Warrior>& warriors)
{
    cout << "There are: " << warriors.size() << " warriors" << endl;
    //for each warrior, print Name and Strength
    for (const Warrior& warrior : warriors)
    {
        cout << warrior.warriorName << " " << warrior.weaponStrength << endl;
    }

}

void battle(Warrior& warrior_1, Warrior& warrior_2)
{
    cout << warrior_1.warriorName << " battles " << warrior_2.warriorName << endl;
    if (warrior_1.weaponStrength != 0 && warrior_2.weaponStrength == 0) 
    {
        cout << "He's Dead, " << warrior_1.warriorName << endl;
    }
    else if (warrior_2.weaponStrength != 0 && warrior_1.weaponStrength == 0)
    {
        cout << "He's Dead, " << warrior_2.warriorName << endl;
    }
        //if warrior_1 wins subtract strength from warrior_1
    else if (warrior_1.weaponStrength > warrior_2.weaponStrength)
    {
        int newStrength = warrior_1.weaponStrength - warrior_2.weaponStrength;
        warrior_1.weaponStrength = newStrength;
        warrior_2.weaponStrength = 0;

        cout << warrior_1.warriorName << " defeats " << warrior_2.warriorName << endl;
    }
        //if warrior_2 wins subtract strength from warrior_2
    else if (warrior_2.weaponStrength > warrior_1.weaponStrength)
    {
        int newStrength = warrior_2.weaponStrength - warrior_1.weaponStrength;
        warrior_2.weaponStrength = newStrength;
        warrior_1.weaponStrength = 0;
        cout << warrior_2.warriorName << " defeats " << warrior_1.warriorName << endl;
    }
        //same strength
    else
    {
        if(warrior_1.weaponStrength == 0 && warrior_2.weaponStrength == 0)//both already 0 strength
        {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        else //same but not 0 strength
        {
            warrior_1.weaponStrength = 0;
            warrior_2.weaponStrength = 0;
            cout << "Mutual Annihilation: " << warrior_1.warriorName << " and " << warrior_2.warriorName << " die at each other's hands" << endl;
        }
    }
}
