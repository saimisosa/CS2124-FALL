#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

class Iterator {
public:
    Iterator operator->() { return *this; }

    Iterator& operator++() {
        return *(this + 1);
    }
    Iterator& operator*(int value) {
        return (*this) * value;
    }

    Iterator& operator*=(int value) {
        *this = *this * value;
    }

};



int main() {
};
