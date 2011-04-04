/* 
 * File:   HashTable.h
 * Author: neil
 *
 * Created on March 29, 2011, 1:05 AM
 */
//#include "Array.h"
//#include "LinkedList.h"

#include "Array.h";
#include "LinkedList.h"
using namespace std;

#ifndef HASHTABLE_H
#define	HASHTABLE_H

template <class DataType>
class HashTable{
private:
    
    Array< LinkedList<DataType> > table;
    int (*hash)(DataType);
    int size;
    HashTable();
    int chainLink;
public:
    HashTable(int(*)(DataType));
    HashTable(int, int(*)(DataType));

    void insert(DataType);
    void remove(DataType);
    void update(DataType);
    DataType retrieve(DataType);
    int getChainSize(int); //added for audit output
    void getChain(int,DataType&); //added for audit output
    DataType getChainHead(int); //added for audit output

};


template <class DataType>
HashTable<DataType>::
HashTable(int newSize, int (*userHash)(DataType)){
    hash = userHash;
    size = newSize;
    table.reSize(size);
}


template <class DataType>
void HashTable<DataType>::
insert(DataType object){
    table[hash(object)].append(object);
}

template <class DataType>
void HashTable<DataType>::
remove(DataType object){
    table[hash(object)].remove(object);
}

template <class DataType>
void HashTable<DataType>::
update(DataType object){ //no need to maintain order in list
    table[hash(object)].remove(object); //pull it
    table[hash(object)].append(object); //add it back
}

template <class DataType>
DataType HashTable<DataType>::
retrieve(DataType object){
    return table[hash(object)].retrieve(object);
}

template <class DataType>
int HashTable<DataType>::
getChainSize(int index){
    return table[index].getSize();
}

template <class DataType>
DataType HashTable<DataType>::
getChainHead(int index){
    chainLink = 0;
    return table[index].retrieveHead();
}

template <class DataType>
void HashTable<DataType>::
getChainNext(int index, DataType &(chain[])){
    //chain = new DataType[table[index].getSize()];
    table[index].retrieveAll(chain);
}
#endif	/* HASHTABLE_H */

