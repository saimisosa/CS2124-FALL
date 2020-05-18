//Saimanasa Juluru
//CS2124
//Section A
//30 September 2019
/*This is a modification of the previous Warriors simulation. Instead of having a struct
 * with only the Warriors name and strength, we now have a weapon name.*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Warrior {
private:

    class Weapon {
    private:
        string name;
        int strength;

    public:
        Weapon(const string& weaponName, int weaponStrength) : name(weaponName), strength(weaponStrength) {}
        friend ostream& operator << (ostream& os, const Weapon& weapon)
        {
            os << "weapon: " << weapon.name <<", " << weapon.strength;
            return os;
        }
        void setStrength(int newStrength) { strength = newStrength;}
        int getStrength() { return strength; }
    };

    string name;
    Weapon weapon;

public:
    //name of warrior and name of weapon are not going to chance, hence the 'const'
    //passed by reference to ensure no copies are being made
    Warrior(const string& warriorName, const string& weaponName, int strength) : name(warriorName), weapon(weaponName, strength){}
    //output operator
    friend ostream& operator << (ostream& os, const Warrior& warrior)
    {
        os << "Warrior: " << warrior.name << ", " << warrior.weapon << endl;
        return os;
    }
    //returns the name of the warrior
    string getName() const { return name;}
    //sets the strength of the weapon
    void setStrength(int strength) { weapon.setStrength(strength);}
    //returns the strength of the weapon
    int getStrength() { return weapon.getStrength(); }



};
void battle(Warrior& warrior_1, Warrior& warrior_2);//initiates a battle between two warriors
void displayStatus(const vector<Warrior>& warriors);//displays the warriors' current stats
int findWarrior(const vector<Warrior>& warriors, string name);//finds the index of a warrior if it exists
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
    //check if file exists
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
            string weaponName;
            int strength;
            input >> name;
            input >> weaponName;
            input >> strength;
            warriors.emplace_back(name, weaponName, strength);
        }
        else if (token == "Battle")//battle two warriors and update stats
        {
            string warrior_1, warrior_2;
            input >> warrior_1;
            input >> warrior_2;
            battle(warriors[findWarrior(warriors, warrior_1)],
                   warriors[findWarrior(warriors, warrior_2)]);
        }
        else//display stats
        {

            displayStatus(warriors);
        }
    }
}


int findWarrior(const vector<Warrior>& warriors, string name)
{
    //check if warrior exists in warriors vector
    for (size_t i = 0; i < warriors.size(); i++)
    {
        if (warriors[i].getName() == name)
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
    //for each warrior print Name and Strength
    for (const Warrior& warrior : warriors)
    {
        cout << warrior;
    }
}

void battle(Warrior& warrior_1, Warrior& warrior_2)
{
    cout << warrior_1.getName() << " battles " << warrior_2.getName() << endl;
    if (warrior_1.getStrength() != 0 && warrior_2.getStrength() == 0)
    {
        cout << "He's Dead, " << warrior_1.getName() << endl;
    }
    else if (warrior_2.getStrength() != 0 && warrior_1.getStrength() == 0)
    {
        cout << "He's Dead, " << warrior_2.getName() << endl;
    }
        //if warrior_1 wins subtract strength from warrior_1
    else if (warrior_1.getStrength() > warrior_2.getStrength())
    {
        int newStrength = warrior_1.getStrength() - warrior_2.getStrength();
        warrior_1.setStrength(newStrength) ;
        warrior_2.setStrength(0);

        cout << warrior_1.getName() << " defeats " << warrior_2.getName() << endl;
    }
        //if warrior_2 wins subtract strength from warrior_2
    else if (warrior_2.getStrength() > warrior_1.getStrength())
    {
        int newStrength = warrior_2.getStrength() - warrior_1.getStrength();
        warrior_2.setStrength(newStrength);
        warrior_1.setStrength(0);
        cout << warrior_2.getName() << " defeats " << warrior_1.getName() << endl;
    }
        //if warriors have the same strength
    else
    {
        if(warrior_1.getStrength() == 0 && warrior_2.getStrength() == 0)//both already 0 strength
        {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        else //same strength > o
        {
            warrior_1.setStrength(0);
            warrior_2.setStrength(0);
            cout << "Mutual Annihilation: " << warrior_1.getName() << " and " << warrior_2.getName() << " die at each other's hands" << endl;
        }
    }
}
