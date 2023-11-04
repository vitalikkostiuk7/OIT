#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<algorithm>
#include<cctype>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Heap overflow" << endl;
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (!isEmpty())
            return top->data;
        else
            return -1;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int size() {
        Node* temp = top;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        if (isEmpty()) {
            cout << "Стек порожній" << endl;
            return;
        }
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "null";
        cout << "\nРозмір стеку: " << size() << endl;
    }
};


bool isPalindrome(const string& str) {
    Stack s;
    for (int i = 0; i < str.length(); i++) {
        s.push(tolower(str[i]));
    }
    for (int i = 0; i < str.length(); i++) {
        if (tolower(str[i]) != s.peek()) {
            return false;
        }
        s.display();
        s.pop();
    }
    return true;
}

vector<string> printReverse(const string& filename) {
    vector<string> myVector;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не вдалося відкрити файл" << endl;
        return myVector; // Повертаємо порожній вектор
    }
    string line;
    while (getline(file, line)) {
        if (isPalindrome(line) and line.length()!=NULL) {
            myVector.push_back(line);
        }
    }
    return myVector; // Повертаємо вектор зі зібраними рядками
}

int main() {
    setlocale(LC_ALL, "UKR");
    Stack s;

    cout << "Додаємо 10 в стек:" << endl;
    s.push(10);
    s.display();

    cout << "Додаємо 20 в стек:" << endl;
    s.push(20);
    s.display();

    cout << "Додаємо 30 в стек:" << endl;
    s.push(30);
    s.display();

    cout << "Верхній елемент стеку: " << s.peek() << endl;

    cout << "Видаляємо верхній елемент зі стеку:" << endl;
    s.pop();
    s.display();
    cout << "Видаляємо верхній елемент зі стеку:" << endl;
    s.pop();
    s.display();
    cout << "Видаляємо верхній елемент зі стеку:" << endl;
    s.pop();
    s.display();

    //vector<string> reversedVector = printReverse("data.txt");

    //// Виведення вектора у зворотньому порядку
    //for (int i = reversedVector.size() - 1; i >= 0; i--) {
    //    cout << reversedVector[i] << endl;
    //}
    //cout << endl;


    return 0;
}
