/* 
 * File:   Movies.cpp.cpp
 * Author: neil
 *
 * Created on March 29, 2011, 1:04 AM
 */

#include <iostream>
#include <fstream>
#include "HashTable.h"

using namespace std;

struct Movie{
    int MPAC;
    string title;

    Movie(int m = -1, string t = ""){
        MPAC = m;
        title = t;
    }
    
    friend const bool operator==(Movie left, Movie right){
    return left.MPAC == right.MPAC;}

    friend const bool operator!=(Movie left, Movie right){
    return left.MPAC != right.MPAC;}

    friend ostream& operator<<(ostream& os, Movie movie){
        return os << movie.MPAC << " -" << movie.title;
    }

	
};


const int SIZE = 10;
const char* FILE_IN = "Movies.txt";
const char* LINE = "-----------------------------------------";
int hash(Movie);
int getMPAC(int&);
void findMovie(const HashTable<Movie>&);
void buildTable(HashTable<Movie>&, fstream&);

int main() {
    HashTable<Movie> table(SIZE,&hash);
    fstream movies(FILE_IN,ios::in);

    buildTable(table, movies);

    findMovie(table);

    return 0;
}

void buildTable(HashTable<Movie>& table, fstream& movies){
    int MPAC;
    string title;

    while(movies.peek()!=-1){
        movies >> MPAC;
        getline(movies,title);
        Movie movie(MPAC,title);
        table.insert(movie);

        cout << movie << " is being added" << endl;
        cout << "\tThe hashed location is " << hash(movie) << endl;
        if (table.getChainSize(hash(movie)) > 1){
            cout << "\tThere was a collision loading " << movie << endl;
            cout << "\tIt collided with " << table.getChainHead(hash(movie)) << endl;
        } else cout << "\tThere was no collision loading " << movie << endl;
        cout << LINE << endl;
    }
}

void findMovie(const HashTable<Movie>& table){
    int MPAC;

    while (getMPAC(MPAC)){
        Movie movie = table.retrieve(Movie(MPAC));
	int size = table.getChainSize(hash(movie));
        Movie collisons[size];
        table.getChain(hash(movie),collisons,movie);
        int index = 0;

	cout << LINE << endl;
	cout << "Will search for " << MPAC << endl;

        while (index < size-1)
                cout << "\tThere was a collision here with " << collisons[index++] << endl;

        if (movie.MPAC != -1)
            cout << "Retrieved from hash table: " << movie << endl;
        else
            cout << "Could not find " << MPAC << endl;
    }
}

int getMPAC(int& MPAC){
    cout << endl << "Enter a MPAC to locate (0 to end): ";
        cin.clear();
	cin >> MPAC;
        return MPAC;
}

int hash(Movie hashMe){
    int hash = 0.618033 * hashMe.MPAC;
    return hash % SIZE; //got invalid operand error as one line?
}

