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

int main() {
    HashTable<Movie> table(SIZE,&hash);
    fstream movies(FILE_IN,ios::in);

    int MPAC;
    string title;

    //buildHash()
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

    //findMovie()
    do{
	cout << "Enter a MPAC to locate (0 to end): ";
        cin.clear();
	cin >> MPAC;
        cout << endl;
	cout << LINE << endl;
	cout << "Will search for " << MPAC << endl;

        Movie movie(MPAC);
        table.retrieve(movie);
        int i = table.getChainSize(hash(movie));
        Movie allMovies[i];
        table.getChain(hash(movie),*allMovies);
        
        while (i--)
            if (allMovies[i] != movie)
                cout << "There was a collision here with " << allMovies[i] << endl;

        if (movie.MPAC != -1)
            cout << "Retrieved from hash table: " << movie << endl;
        else
            cout << "Could not find " << MPAC << endl;

    } while (MPAC);

    return 0;
}

int hash(Movie hashMe){
    int hash = 0.618033 * hashMe.MPAC;
    return hash % SIZE; //got invalid operand error as one line
}

