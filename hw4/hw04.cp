//Saimanasa Juluru
//CS2124
//Section A
//06 September 2019
/*A modification of the previous Warriors class, we have now introduced the concept of Nobles into this code.
 * Instead of the Warriors "voluntarily" fighting amongst themselves, the Nobles hire these warriors as part of
 * their army, conducting the battle and subsequently losing their own health if the warriors fail.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Warrior{
    
public:
    Warrior(string warriorName, double power2): name(warriorName), power(power2){}

    friend ostream& operator << (ostream& os, const Warrior& warrior) //friend operator
    {
        os << "Warrior: " << warrior.name << " Strength:" << warrior.power << endl;
        return os;
    }

    double getStrength()const{ return power; } // returns power

    void setStrength(float ratio){ // resets power to ratio times the remaining power
        if (ratio == 0){ // condition for if the warrior is dead
            power = 0; // makes sure to set their strength to zero
        }
        else{
            power -= ratio * power; 
        }
    }

    string getName(){ return name; } // returns name
    void displayWarrior() { cout << name << " : " << power <<endl; } // displays warrior : power

private:
    string name;
    double power; // double makes sure there are no negative values being entered
};

class Noble{

private:
    string name;
    vector <Warrior*> army; // vector of Warrior pointers named "army"
    double totalStrength; // total strength of the army, also no negative values allowed
    
public:
    Noble(string nobleName): name(nobleName), totalStrength(0){}

   friend ostream& operator << (ostream& os, const Noble& noble) // friend operator
    {
        os << noble.name << " has an army of " << noble.army.size() << endl;
        for (size_t i = 0; i < noble.army.size(); ++i){
            noble.army[i]->displayWarrior();
        }
        return os;
    }
    // hire function
   void hire(Warrior& warriorName){
        army.push_back(&warriorName); // pushes the address of the warrior onto vector
        totalStrength += warriorName.getStrength(); // adds the strength of each warrior to the total strength
    }
    // battle function
    void battle(Noble& nobleName){

        cout << name << " battles " << nobleName.name <<endl;

        // condition for when noble 1's army is stronger than noble 2's
        if (totalStrength > nobleName.totalStrength){
            // if noble 2 is already dead
            if (nobleName.totalStrength == 0){
                cout << "He's dead, " << name << endl;
            }
            /* normal condition, aka when one defeats the other
            * in the case where neither are initially dead or equally matched*/
            else {
                cout << name << " defeats " << nobleName.name << endl;

                double ratio = nobleName.totalStrength / totalStrength; // ratio to recalculate army strength
                totalStrength = 0;
                nobleName.totalStrength = 0;

                for (size_t i = 0; i < nobleName.army.size(); ++i){ // loops through army vector
                    nobleName.army[i]->setStrength(0); // sets strength with ratio 0
                }
                for (size_t i = 0; i < army.size(); ++i){
                    army[i]->setStrength(ratio); // sets strength with ratio calculated above
                    totalStrength += army[i]->getStrength(); // recalculates total strength

                }
            }
        }
        // condition for if noble 2's army strength is greater than noble 1's
        else if (totalStrength < nobleName.totalStrength){

            // condition for if one is already dead
            if (totalStrength == 0){
                cout << "he's dead " << nobleName.name << endl;
            }
            /* normal condition, aka when one defeats the other
             * in the case where neither are initially dead or equally matched*/
            else {
                cout << nobleName.name << " defeats " << name << endl;

                double ratio =  nobleName.totalStrength / totalStrength; // ratio to recalculate army strength

                totalStrength = 0;
                nobleName.totalStrength = 0;

                for (size_t i = 0; i < army.size(); ++i){ // loops through army vector
                    army[i]->setStrength(0); // sets the strength with ratio 0
                }
                for (size_t i = 0; i < nobleName.army.size(); ++i){
                    nobleName.army[i]->setStrength(ratio); // sets strength with ratio calculated above
                    totalStrength += nobleName.army[i]->getStrength(); // recalculates the total strength
                }
            }
        }
        // condition for when they're both already dead
        else if (totalStrength == 0 && nobleName.totalStrength == 0){
            cout << "Oh no they're both dead! yuck!" << endl;
        }
        // condition for when both have equal strength
        else if (totalStrength == nobleName.totalStrength){
            cout << "mutual annihilation: " << name << " and " << nobleName.name <<" die at each other's hands" << endl;

            totalStrength = 0; // sets first noble's total strength to 0
            nobleName.totalStrength = 0; // set's second noble's total strength to 0

            for(size_t i = 0; i < army.size(); ++i) { // if in the case of mutual annihilation
                army[i]->setStrength(0); // set first noble's army strength to 0
                nobleName.army[i]->setStrength(0); // and set the second noble's army strength to 0
            }
    }
    }

    // firing function
    void fire(Warrior& warrior){
        cout << "You don't work for me anymore " << warrior.getName() << "! -- " << name << "." << endl;
        totalStrength = 0;

        for (size_t i=0; i< army.size(); ++i){ // loops through array of Warrior pointers
            if (&warrior== army[i]){ // if the address of Warrior to be fired is found
                army[i]=army[army.size()-1]; // resize vector
                army.pop_back(); // remove Warrior
            }
        }
        for (size_t i = 0; i < army.size(); ++i){ // loops through army vector
            totalStrength += army[i]->getStrength(); // recalculates total army strength after firing
        }
    }
};


int main() {
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);

    cout << "==========\n"
         << "Status before all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";

    art.fire(cheetah);
    cout << art << endl;

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "==========\n"
         << "Status after all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";


}









