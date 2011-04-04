//******************************************************************************
//
//		File:                   main.cpp
//
//		Student:                Neil Peterson
//
//		Assignment:             Program #1
//
//		Course Name:            Data Structures 1
//
//		Course Number:          COSC 3100
//
//		Due:                    Mar 22, 2011
//
//		Other files required:   None
//
//******************************************************************************

#include <iostream>
using namespace std;


int constant(int);
int linear(int);
int quadratic(int);
int cubic(int);
int logrithmic(int);
int linearLogrithmic(int);


int main() {
    cout << "\t\tn=30 \t\tn=1000" << endl;

    cout << "O(1)\t\t"
         << constant(30) << "\t\t"
         << constant(1000) << endl;

    cout << "O(n)\t\t"
         << linear(30) << "\t\t"
         << linear(1000) << endl;

    cout << "O(n^2)\t\t"
         << quadratic(30) << "\t\t"
         << quadratic(1000) << endl;

    cout << "O(n^3)\t\t"
         << cubic(30) << "\t\t"
         << cubic(1000) << endl;

    cout << "O(log2 n)\t"
         << logrithmic(30) << "\t\t"
         << logrithmic(1000) << endl;

    cout << "O(n log2 n)\t"
         << linearLogrithmic(30) << "\t\t"
         << linearLogrithmic(1000) << endl;

    return 0;
}

int constant(int n){
    return 1;
}

int linear(int n){
    int a = n;
    int count = 0;
    while(a>0){
        a--;
        count ++;
    }
    return count;
}

int quadratic(int n){
    int a = n;
    int count = 0;
    while(a>0){
        count += linear(n);
        a--;
    }
    return count;
}

int cubic(int n){
    int a = n;
    int count = 0;
    while(a>0){
            count += quadratic(n);
            a--;
    }
    return count;
}

int logrithmic(int n){
    int a = n;
    int count = 0;
    while(a>0){
            count++;
            a/=2;
    }
    return count;
}

int linearLogrithmic(int n){
    int a = n;
    int count = 0;
    while(a>0){
            count+=linear(n);
            a/=2;
    }
    return count;
}