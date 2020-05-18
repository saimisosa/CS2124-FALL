/*
 * Saimanasa Juluru
 * Lab 14: Recursion
 */

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};
//Task 1
//Task 2
void listAddHead(Node*& headPtr, int entry) {
    headPtr = new Node(entry, headPtr);
}
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listAddHead(result, vals[index-1]);
    }
    return result;
}

Node* sumList(Node* firstList, Node* secondList){
    if (firstList == nullptr && secondList == nullptr){
        return nullptr;
    }
    if (firstList == nullptr && secondList != nullptr){
        return new Node(secondList->data, sumList(firstList, secondList->next));
    }
    else if(secondList == nullptr && firstList != nullptr){
        return new Node(firstList->data, sumList(firstList->next, secondList));
    }
    return new Node(firstList->data + secondList->data, sumList(firstList->next, secondList->next));
}
//Task 3
//Task 4
bool palindrome(char arr[], int size) {
    if (size == 0 || size == 1){
        return true;
    }
    else if (arr[0] != arr[size-1]){
        return false;
    }
    else {
       return palindrome(arr+1, size-2);
    }
}
//Task 5
//Task 6
void mystery(int n) {
    if (n > 1) {
        cout << 'a';
        mystery(n/2);
        cout << 'b';
        mystery(n/2);
    }
    cout << 'c';
}

int main() {
    //Task 2
    Node* lst1 = listBuild({1,2,3,4});
    Node* lst2 = listBuild({5,6,7,8,9});
    Node* newList = sumList(lst1, lst2);
    cout << "SecondList > FirstList :D" << endl;
    cout << "{ ";
    while (newList != nullptr){
        cout << newList->data << " ";
        newList = newList->next;
    }
    cout << "}";
    cout << endl;

    Node* lst3 = listBuild({5,1,3,5,10});
    Node* lst4 = listBuild({2,7,1,11});
    Node* newList1 = sumList(lst3, lst4);
    cout << "FirstList > SecondList :D" << endl;
    cout << "{ ";
    while (newList1 != nullptr){
        cout << newList1->data << " ";
        newList1 = newList1->next;
    }
    cout << "}";
    cout << endl;

    Node* lst5 = listBuild({});
    Node* lst6 = listBuild({2,3,4,5,6});
    Node* newList2 = sumList(lst5, lst6);
    cout << "FirstList nullptr :D" << endl;
    cout << "{ ";
    while (newList2 != nullptr){
        cout << newList2->data << " ";
        newList2 = newList2->next;
    }
    cout << "}";
    cout << endl;

    Node* lst7 = listBuild({5,6,7,8});
    Node* lst8 = listBuild({});
    Node* newList3 = sumList(lst7, lst8);
    cout << "SecondList nullptr :D" << endl;
    cout << "{ ";
    while (newList3 != nullptr){
        cout << newList3->data << " ";
        newList3 = newList3->next;
    }
    cout << "}";
    cout << endl;

    //Task 4
    char s[] = "racecar";
    cout << palindrome(s, 7) << endl;

    char a[] = "a";
    cout << palindrome(a, 1) << endl;

    char b[] = "ap";
    cout << palindrome(b, 2) << endl;

    char c[] = "apple";
    cout << palindrome(c, 5) << endl;

    char d[] = "hannah";
    cout << palindrome(d, 6) << endl;

    /* Task 6 Predicted Outputs
    * n = 0, 'c'
    * n = 1, 'c'
    * n = 2, "acbcc"
    * n = 3, "acbcc"
    * n = 4, "aacbccbacbccc"
    * n = 5, "aacbccbacbccc"
    * n = 6, "aacbccbacbccc"
    * n = 7, "aacbccbacbccc"
    * n = 8, "aaacbccbacbcccbaacbccbacbcccc"
    * n = 9, "aaacbccbacbcccbaacbccbacbcccc"
    * n = 10, "aaacbccbacbcccbaacbccbacbcccc"
 */

    //Task 6 Tested Outputs

    mystery(4);
    cout << "\n";

    // aacbc

}






