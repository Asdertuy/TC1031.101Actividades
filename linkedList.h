#pragma once
#include <stddef.h>
#include <iostream>

template <class T>
class Node
{
private:
    T val;
    Node<T> *next;

public:
    ~Node<T>() {};
    Node<T>(T pVal, Node<T> *pNext)
    {
        val = pVal;
        next = pNext;
    };

    T getVal() {return val;};
    void setVal(T pVal) {val = pVal;};
    Node<T> *getNext() {return next;};
    void setNext(Node<T> *pNext) {next = pNext;};
};

template <class T>
class LinkedList
{
    private:
        Node<T> *head;

    public:
        ~LinkedList(){};
        LinkedList(){
            head = NULL;
        }

    int length()
    {
        int length = 0;
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            length++;
            ptr = ptr->getNext();
        }
        return length;
    };

    void push(T pVal)
    {
        Node<T> *node = new Node<T>(pVal, head);
        head = node;
    };

    void print()
    {
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            std::cout << ptr->getVal() << ", ";
            ptr = ptr->getNext();
        }
        std::cout << std::endl;        
    }

    int count(T searchFor){
        Node<T> *ptr = head;
        int count = 0;
        while (ptr != NULL){
            if (ptr->getVal() == searchFor)
                count++;
            ptr = ptr->getNext();
        }
        return count;
    }

    void deleteList(){
        Node<T> *ptr = head;
        Node<T> *next;
        while (ptr != NULL){
            next = ptr->getNext();
            free(ptr);
            ptr = next;
        }
        head = NULL;
    }
    
    Node<T> *newNode(int pVal){
        Node<T> *node = new Node<T>(pVal, NULL);
        return node;
    }

    void sortedInsert(Node<T> *newNode){
        Node<T> *ptr;
        if (head == NULL || head->getVal() >= newNode->getVal()){
            newNode->setNext(head);
            head = newNode;
        }
        else{
            ptr = head;
            while (ptr->getNext() != NULL && ptr->getNext()->getVal() < newNode->getVal()){
                ptr = ptr->getNext();
            }
            newNode->setNext(ptr->getNext());
            ptr->setNext(newNode);
        }

    }

    void removeDuplicates(){
        Node<T> *ptr = head;
        Node<T> *next = NULL;
        while (ptr->getNext() != NULL){
            if (ptr->getVal() == ptr->getNext()->getVal()){
                next = ptr->getNext()->getNext();
                delete(ptr->getNext());
                ptr->setNext(next);
            }
            else{
                ptr = ptr->getNext();
            }
        }

        
    }

    void reverse(){
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        Node<T> *next = NULL;
        while (ptr != NULL){
            next = ptr->getNext();
            ptr->setNext(pre);
            pre = ptr;
            ptr = next;
        }
        head = pre;
    }
};

