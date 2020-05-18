#include <iostream>
#include <string>
using namespace std;

// write simply function
// call it every time you do addition
// use the bottom two functions to fix it

int gcf(int, int);
int posNeg(int, int);

class Rational {
    friend istream& operator>>(istream& is, Rational& rhs){
        char oper;
        is >> rhs.numerator >> oper >> rhs.denominator;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Rational& rhs) {
        os << rhs.numerator << "/" << rhs.denominator << endl;
        return os;
    }

    friend bool operator==(const Rational& lhs, const Rational& rhs);
    friend bool operator<(const Rational& lhs, const Rational& rhs);
public:
    Rational(int numerator = 1, int denominator = 1) : numerator(numerator), denominator(denominator) {}

    //+= operator
    Rational& operator+=(const Rational& rhs){
        if (rhs.denominator != denominator){
            numerator = (numerator * rhs.denominator) + (rhs.numerator * denominator);
            denominator = (denominator * rhs.denominator);
        }
        else {
            numerator = numerator + rhs.numerator;
        }
        int div = gcf(numerator, denominator);
        numerator /= div;
        denominator /= div;
        posNeg(numerator, denominator);
        return *this;
    }
    // ++fraction
    Rational& operator++(){
        numerator = numerator + denominator;
        return *this;
    }
    // fraction++
    Rational operator++(int dummy) {
        Rational result(*this);
        numerator = numerator + denominator;
        return result;
    }

    explicit operator bool() const {
        return (numerator == 1 && denominator == 1);
    }

private:
    int numerator, denominator;

};

// non-member non-friend + operator, calls the += operator
Rational operator+(const Rational& lhs, const Rational& rhs){
    Rational result(lhs);
    result += rhs;
    return result;
}

// non-member friend == operator
bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator);
}

// non-member non-friend != operator
bool operator !=(const Rational& lhs, const Rational& rhs){
    return !(lhs == rhs);
}

// non-member non-friend --fraction
Rational& operator--(Rational& num){
    num += -1;
    return num;
}

// non-member non-friend fraction--
Rational operator--(Rational& num, int) {
    Rational result(num);
    num += -1;
    return result;
}

// non-member friend < operator
bool operator<(const Rational& lhs, const Rational& rhs) {
    int leftNum = lhs.numerator * rhs.denominator;
    int rightNum = rhs.numerator * lhs.denominator;
    return (leftNum < rightNum);
}
// non-member non-friend > operator
bool operator>(const Rational& lhs, const Rational& rhs){
    return !(lhs < rhs);
}

// non-member non-friend >= operator
bool operator>=(const Rational& lhs, const Rational& rhs){
    return !(lhs < rhs) or (lhs == rhs);
}

// non-member non-friend <= operator
bool operator<=(const Rational& lhs, const Rational& rhs){
    return (lhs < rhs) or (lhs == rhs);
}

// gcf
int gcf(int numerator, int denominator){
    if (numerator < 0){
        numerator = -numerator;
    }
    else if (denominator < 0){
        denominator = -denominator;
    }
    while (denominator != 0) {
        int temp = numerator % denominator;
        numerator = denominator;
        denominator = temp;
    }
    return numerator;
}

// makes sure theres no neg in denominator
int posNeg(int num, int den){
    if (den < 0){
        den = -den;
        num = -num;
    }
    else if (den < 0 && num < 0){
        den = -den;
        num = -num;
    }
    return num, den;
}

int main() {
    Rational twoThirds(2,3);
    cout << twoThirds << endl;

    Rational a, b;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "b: ";
    cin >> b;
    const Rational one = 1;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;	// Implement as member
    cout << "a = " << a << endl;

    // Implement as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;

    // How does this manage to work?
    // It does NOT require writing another == operator.
    cout << "1 == one: " << boolalpha << (1 == one) << endl;

    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;

    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;

    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;

    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // But some compiler vendors might let it...  Is your compiler
    // doing the right thing?
    // cout << "a-- -- = " << (a-- --) << endl;
    // cout << "a = " << a << endl;


    // Should report that 1 is true

    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    }

    // Should report that 0 is false
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    }
}