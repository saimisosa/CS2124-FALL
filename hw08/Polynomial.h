//
// Created by Saimanasa Juluru on 12/4/19.
//

#ifndef HW08_POLYNOMIAL_H
#define HW08_POLYNOMIAL_H


#include <vector>
#include <string>
#include <iostream>

struct Node {
    Node(int data = 0, Node* next = nullptr): data(data), next(next) {}
    int data;
    Node* next;
};

Node* listDuplicate(Node* headPtr);

void listInsertHead(int entry, Node*& headPtr);

int exponent(int x, int degree);

class Polynomial {
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);
public:
    Polynomial();
    Polynomial(std::vector<int> coefficient);
    ~Polynomial();
    Polynomial(const Polynomial& rhs);
    Polynomial& operator=(const Polynomial& rhs);
    Polynomial& operator+=(const Polynomial& rhs);
    bool operator==(const Polynomial& rhs);
    int evaluate(int x);
private:
    size_t degree = 0;
    Node* coefficients = nullptr;
};

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);

bool operator!=(Polynomial lhs, Polynomial rhs);


#endif //HW08_POLYNOMIAL_H
