/* 
 * File:   Array.h
 * Author: neil
 *
 * Created on March 29, 2011, 1:39 AM
 */
#include <iostream> //remove
using namespace std;

#ifndef ARRAY_H
#define	ARRAY_H

template <class DataType>
class Array {
private:
    private:

    DataType* array;
    bool* isEmpty;
    int size;
    int maxSize;
    void resize(int);
public:
    Array(int);
    void add(DataType,int);
    void remove(int);
    void clear();
    DataType operator[](unsigned int);

};

template <class DataType>
Array<DataType>::
Array(int s = 1) {
    maxSize = s;
    clear(); //sets size=0 intializes isEmpty and array

}

template <class DataType>
void Array<DataType>::
resize(int newSize) {
    cout << "resizeing! to size " << newSize << endl;
    DataType newArray[newSize];
    bool newIsEmpty[newSize];
    int i;
    
    if (newSize = maxSize) return;
    else if (newSize < maxSize) i = newSize;
    else if (newSize > maxSize) i = maxSize;
    maxSize = newSize;
    
    while (i-- > 0){
        cout << "copying element " << i << " ";
        newArray[i-1] = array[i-1];
        newIsEmpty[i-1] = isEmpty[i-1];
    }
    cout << endl;
    array = newArray;
    isEmpty = newIsEmpty;

}

template <class DataType>
void Array<DataType>::
add(DataType addMe, int index = -1){
    if (index == -1)
        index = size;

    if (index > 2*maxSize) //if out of bounds index is WAY out there...
        resize(index);    //only go one beyond WAY out there
    else if (size >= maxSize) //if index is out of bounds but not WAY out...
        resize(maxSize * 2); //double the space

    array[index] = addMe;
    isEmpty[index] = false;
    size++;

}

template <class DataType>
void Array<DataType>::
remove(int index){
    isEmpty[index] = true;
    
    if (index == size - 1)
        while (isEmpty[size-1])
            size--;

    cout << "we just removed " << array[index] <<
            " at " << index << endl << " size is now "
            << size << " last element is " << array[size];

}

template <class DataType>
void Array<DataType>::
clear(){
   while(--size)
        isEmpty[size-1] = true;
   cout << "data is cleared. size is " << size << endl;
}

template <class DataType>
DataType Array<DataType>::
operator[](unsigned int index) {
    if (!isEmpty[index])
            return array[index];
}


#endif	/* ARRAY_H */

