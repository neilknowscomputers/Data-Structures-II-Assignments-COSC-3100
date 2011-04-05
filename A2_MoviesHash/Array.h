//******************************************************************************
//
//		File:                   Array.h
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
//		Other files required:   None
//
//******************************************************************************

#ifndef ARRAY_H
#define	ARRAY_H

using namespace std;

template <class DataType>
class Array {
private:
    DataType* array;
    int size;
public:
    Array(int);
    void reSize(int);
    int getSize();
    void clear();
    DataType & operator[](unsigned int);
    DataType & operator[](unsigned int) const;

};

template <class DataType>
Array<DataType>::
Array(int s = 1) {
    size = s;
    clear();
}

template <class DataType>
void Array<DataType>::
reSize(int newSize = -1) {
    int i;
    if (newSize == -1) {
        newSize = 2 * size;
        i = size;
    } else if (newSize < size) i = newSize;
    else if (newSize > size) i = size;
    else if (newSize == size) return;

    DataType* newArray = new DataType[newSize];
    size = newSize;

    while (i-- > 0)
        newArray[i] = array[i];

    array = newArray;
}

template <class DataType>
int Array<DataType>::
getSize() {
    return size;
}

template <class DataType>
void Array<DataType>::
clear() {
    array = new DataType[size];
}

template <class DataType>
DataType& Array<DataType>::
operator[](unsigned int index) {
    if (index > size - 1) //if out of bounds
        return *(new DataType); //return garbage
    else
        return array[index];
}

template <class DataType>
DataType& Array<DataType>::
operator[](unsigned int index) const {
    if (index > size - 1) //if out of bounds
        return *(new DataType); //return garbage
    else
        return array[index];
}
#endif	/* ARRAY_H */

