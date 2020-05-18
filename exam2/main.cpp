#include <iostream>
#include <vector>
using namespace std;

class Starcraft;
class Zerglings;
class BroodWar : public Starcraft {
    friend ostream& operator<< (ostream& os, const BroodWar& person) const {
        os << person.name << "'s collection contains: ";
        for (const Zerglings* thing : person.alienCollection) {
            os << *thing;
        }
        return os;
    }
private:
    string name;
    vector <Zerglings*> alienCollection;
public:
    BroodWar(const string& name, const int regCode) : name(name), Starcraft(regCode) {};

    // copy constructor
    BroodWar(const BroodWar& rhs) {
        name = rhs.name;
        for (Zerglings* alien : rhs.alienCollection) {
            alienCollection.push_back(new Zerglings(*alien))
        }
        return *this;
    }
    // assignment operator
    BroodWar& operator=(const BroodWar& rhs) {
        if (this != &rhs) {
            for (Zerglings* alien : alienCollection) {
                delete alien;
                alien = nullptr;
            }
            alienCollection.clear();
            delete [] alienCollection;
            name = rhs.name;
            for (Zerglings* alien : rhs.alienCollection) {
                alienCollection.push_back(new Zerglings(*alien))
            }
        }
        return *this;
    }
    // destructor
    ~BroodWar() {
        for (Zerglings* alien : alienCollection) {
            delete alien;
            alien = nullptr;
        }
        alienCollection.clear();
    }
    // equality operator
    bool operator==(const BroodWar& rhs) {
       if (alienCollection.size() == rhs.alienCollection.size()) {
           for (size_t i = 0; i < alienCollection.size(); ++i) {
              if (*(alienCollection[i]) != *(rhs.alienCollection[i]) {
                  return false;
              }
           }
           return true;
       }
       else {
           return false;
       }
    }
    // operator bool
    explicit operator bool() const {
        return (alienCollection != 0);
    }

};
int main() {

}