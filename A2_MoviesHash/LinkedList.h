/* 
 * File:   LinkedList.h
 * Author: neil
 *
 * Created on March 29, 2011, 1:39 AM
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H
using namespace std;
#include <iostream>

template <class DataType>
struct Node{
      DataType data;
      Node* next;
      Node* prev;
      Node(DataType d = *(new DataType)){
          data = d;
          next = NULL;
          prev = NULL;
      }
};

template <class DataType>
class LinkedList{
private:
    
    Node<DataType>* head;
    Node<DataType>* tail;
    int size;
    Node<DataType>* find(DataType);
    bool kill(Node<DataType>*);

public:
    LinkedList();
    void append(DataType);
    bool remove(DataType);
    DataType retrieve(DataType); //gets and removes
    void retrieveAll(DataType**); //added for audit output
    DataType retrieveHead(); //added for audit output
    bool isEmpty();
    int getSize();
};

template <class DataType>
LinkedList<DataType>::
LinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class DataType>
Node<DataType>* LinkedList<DataType>::
find(DataType findMe){
    Node<DataType>* thisOne = head;

    while(thisOne->data != findMe && thisOne->next != NULL)
        thisOne = thisOne->next;

    if (thisOne->data == findMe) return thisOne;
    else return new Node<DataType>;
}

template <class DataType>
bool LinkedList<DataType>::
kill(Node<DataType>* deleteMe){
    if(deleteMe == NULL) //cant kill em if they're dead
        return false; //zombie node
    
    else if(deleteMe->prev == NULL) //is head
        head = deleteMe->next;

    else if(deleteMe->next == NULL) //is head
        tail = deleteMe->prev;

    else if (deleteMe){ //is middle
        deleteMe->prev->next = deleteMe->next;
        deleteMe->prev->next->prev = deleteMe->prev; //YEE HAW
    }

    delete deleteMe;
}

template <class DataType>
void LinkedList<DataType>::
append(DataType addMe){
    if (isEmpty())
        head = tail = new Node<DataType>(addMe);
    else{
        tail->next = new Node<DataType>(addMe);
        tail->next->prev = tail;
        tail = tail->next;
    }

    size++;
}

template <class DataType>
bool LinkedList<DataType>::
remove(DataType removeMe){
    return kill(find(removeMe));
    size--;
}

template <class DataType>
DataType LinkedList<DataType>::
retrieve(DataType findMe){
    return find(findMe)->data;
}

template <class DataType>
void LinkedList<DataType>::
retrieveAll(DataType** all){
    //all = new DataType[size];
    Node<DataType>* copyMe = head;
    int i = 0;
    while(copyMe){
        all[i++] = copyMe->data;
        cout << "copied " << all[i-1] << endl;
        copyMe = copyMe->next;
    }
}

template <class DataType>
DataType LinkedList<DataType>::
retrieveHead(){
    return head->data;
}

template <class DataType>
bool LinkedList<DataType>::
isEmpty(){
    return (head == NULL);
}

template <class DataType>
int LinkedList<DataType>::
getSize(){
    return size;
}

#endif	/* LINKEDLIST_H */

