//******************************************************************************
//
//		File:                   Movies.cpp
//
//		Student:                Neil Peterson
//
//		Assignment:             Program #2
//
//		Course Name:            Data Structures 2
//
//		Course Number:          COSC 3100
//
//		Due:                    Apr 5, 2011
//
//		Other files required:   HashTable.h, Movies.txt
//
//******************************************************************************

#include <iostream>
#include <fstream>
#include "HashTable.h"

using namespace std;

struct Movie {
    int MPAC;
    string title;

    Movie(int m = -1, string t = "") {
        MPAC = m;
        title = t;
    }

    friend const bool operator==(Movie left, Movie right) {
        return left.MPAC == right.MPAC;
    }

    friend const bool operator!=(Movie left, Movie right) {
        return left.MPAC != right.MPAC;
    }

    friend ostream & operator<<(ostream& os, Movie movie) {
        return os << movie.MPAC << " -" << movie.title;
    }


};


const int SIZE = 10;
const char* FILE_IN = "Movies.txt";
const char* FILE_OUT = "MoviesOutput.txt";
const char* LINE = "-----------------------------------------";

void buildTable(HashTable<Movie>&, fstream&, fstream&);
void findMovie(const HashTable<Movie>&);
int countCollisions(const HashTable<Movie>&);
bool getMPAC(int&);
int hash(Movie);

int main() {
    HashTable<Movie> table(SIZE, &hash);
    fstream movies(FILE_IN, ios::in);
    fstream output(FILE_OUT, ios::out);
    if (movies.bad() || output.bad()) {
        cout << "There was a problem with one or more of your files" << endl;
        return 99;
    }

    buildTable(table, movies, output);

    findMovie(table);

    cout << "There were " << countCollisions(table) << endl;
    return 0;
}

void buildTable(HashTable<Movie>& table, fstream& movies, fstream& output) {
    int MPAC;
    string title;

    while (movies.peek() != -1) {
        movies >> MPAC;
        getline(movies, title);
        Movie movie(MPAC, title);
        table.insert(movie);

        output << movie << " is being added" << endl;
        output << "\tThe hashed location is " << hash(movie) << endl;
        if (table.getChainSize(hash(movie)) > 1) {
            output << "\tThere was a collision loading " << movie << endl;
            output << "\tIt collided with "
                   << table.getChainHead(hash(movie)) << endl;
        } else output << "\tThere was no collision loading " << movie << endl;
        output << LINE << endl;
    }
}

void findMovie(const HashTable<Movie>& table) {
    int MPAC;

    while (getMPAC(MPAC)) {
        Movie movie = table.retrieve(Movie(MPAC));

        int size = table.getChainSize(hash(movie));
        Movie collisons[size];
        table.getChain(hash(movie), collisons, movie);
        int index = 0;

        cout << LINE << endl;
        cout << "Will search for " << MPAC << endl;

        while (index < size - 1)
            cout << "\tThere was a collision here with "
                 << collisons[index++] << endl;

        if (movie.MPAC != -1)
            cout << "Retrieved from hash table: " << movie << endl;
        else
            cout << "Could not find " << MPAC << endl;
    }
}

int countCollisions(const HashTable<Movie>& table) {
    int tableSize = table.getSize();
    int chainSize = 0;
    int collisions = 0;

    while (tableSize-- > 0) {
        chainSize = table.getChainSize(tableSize);
        if (chainSize) collisions += (chainSize - 1);
    }

    return collisions;
}

bool getMPAC(int& MPAC) {
    do {
        cout << endl << "Enter a MPAC to locate (0 to end): ";
        cin.clear();
        cin >> MPAC;
    } while (MPAC < 0);
    return (bool)MPAC;
}

int hash(Movie hashMe) {
    int hash = 0.618033 * hashMe.MPAC;
    return hash % SIZE; //got invalid operand error as one line?
}

