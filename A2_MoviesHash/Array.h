/* 
 * File:   Array.h
 * Author: neil
 *
 * Created on March 29, 2011, 1:39 AM
 */
using namespace std;

#ifndef ARRAY_H
#define	ARRAY_H

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
    DataType& operator[](unsigned int);

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
    if(newSize == -1){
        newSize = 2*size;
        i = size;
    }
    else if (newSize < size) i = newSize;
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
getSize(){
    return size;
}

template <class DataType>
void Array<DataType>::
clear(){
    array = new DataType[size];
}

template <class DataType>
DataType& Array<DataType>::
operator[](unsigned int index) {
    if (index > size-1){ //if out of bounds
        cout << endl << "index is out of bounds!!" << endl;
        return *(new DataType); //return garbage
    }
    else
        return array[index];
}

#endif	/* ARRAY_H */

