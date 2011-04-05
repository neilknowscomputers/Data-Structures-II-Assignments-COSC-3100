//******************************************************************************
//
//		File:                   HashTable.h
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
//		Other files required:   Array.h, LinkedList.h
//
//******************************************************************************

#include "Array.h"
#include "LinkedList.h"

#ifndef HASHTABLE_H
#define	HASHTABLE_H

using namespace std;

template <class DataType>
class HashTable {
private:

    Array< LinkedList<DataType> > table;
    int (*hash)(DataType);
    int size;

    int chainLink;
public:
    HashTable();
    HashTable(int(*)(DataType));
    HashTable(int, int(*)(DataType));

    void insert(DataType);
    void remove(DataType);
    void update(DataType);
    DataType retrieve(DataType) const;
    int getSize() const; //added for audit output
    int getChainSize(int) const; //added for audit output
    bool getChain(int, DataType*, DataType) const; //added for audit output
    DataType getChainHead(int) const; //added for audit output

};

template <class DataType>
HashTable<DataType>::
HashTable(int newSize, int (*userHash)(DataType)) {
    hash = userHash;
    size = newSize;
    table.reSize(size);
}

template <class DataType>
void HashTable<DataType>::
insert(DataType object) {
    table[hash(object)].append(object);
}

template <class DataType>
void HashTable<DataType>::
remove(DataType object) {
    table[hash(object)].remove(object);
}

template <class DataType>
void HashTable<DataType>::
update(DataType object) { //no need to maintain order in list
    table[hash(object)].remove(object); //pull it
    table[hash(object)].append(object); //add it back
}

template <class DataType>
DataType HashTable<DataType>::
retrieve(DataType object) const {
    return table[hash(object)].retrieve(object);
}

template <class DataType>
int HashTable<DataType>::
getSize() const {
    return size;
}

template <class DataType>
int HashTable<DataType>::
getChainSize(int index) const {
    return table[index].getSize();
}

template <class DataType>
DataType HashTable<DataType>::
getChainHead(int index) const {
    return table[index].retrieveHead();
}

template <class DataType>
bool HashTable<DataType>::
getChain(int index, DataType* chain, DataType excludeMe = NULL) const {
    int allSize = table[index].getSize();
    int chainIndex = -1;
    int allIndex = -1;
    DataType all[allSize];
    table[index].retrieveAll(all);

    while (++allIndex < allSize)
        if (excludeMe != all[allIndex])
            chain[++chainIndex] = all[allIndex];


    return true;
}
#endif	/* HASHTABLE_H */

