#ifndef GDL_LIST_H
#define GDL_LIST_H

#include <iostream>
#include "GDLLNode.h"

using namespace std;

template <class T>
class GDLList {
public:
    GDLList();
    ~GDLList();
    void addToHead(T data);
    void addToTail(T data);
    void deleteFromHead();
    void deleteFromTail();
    void sortInsert(const T& data);
    bool isEmpty() const;
    void printList() const;
    void printRevList() const;
    GDLLNode<T>* search(const string& title) const;
    void deleteNode(const string& title);
    GDLLNode<T>* searchByTitle(const string& title) const; // Declaración de la función searchByTitle


private:
    GDLLNode<T>* head;
    GDLLNode<T>* tail;
};

template <class T>
GDLList<T>::GDLList() : head(nullptr), tail(nullptr) {}

template <class T>
GDLList<T>::~GDLList() {
    GDLLNode<T>* current = head;
    while (current != nullptr) {
        GDLLNode<T>* next = current->getNext();
        delete current;
        current = next;
    }
}

template <class T>
void GDLList<T>::addToHead(T data) {
    GDLLNode<T>* newNode = new GDLLNode<T>(data);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }
}

template <class T>
void GDLList<T>::addToTail(T data) {
    GDLLNode<T>* newNode = new GDLLNode<T>(data);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->setPrev(tail);
        tail->setNext(newNode);
        tail = newNode;
    }
}

template <class T>
void GDLList<T>::deleteFromHead() {
    if (!isEmpty()) {
        GDLLNode<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->getNext();
            head->setPrev(nullptr);
        }
        delete temp;
    }
}

template <class T>
void GDLList<T>::deleteFromTail() {
    if (!isEmpty()) {
        GDLLNode<T>* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->getPrev();
            tail->setNext(nullptr);
        }
        delete temp;
    }
}

template <class T>
bool GDLList<T>::isEmpty() const {
    return head == nullptr;
}

template <>
void GDLList<string>::printList() const {
    GDLLNode<string>* current = head;
    while (current != nullptr) {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
}


template <class T>
void GDLList<T>::printRevList() const {
    GDLLNode<T>* current = tail;
    while (current != nullptr) {
        cout << current->getData() << " ";
        current = current->getPrev();
    }
    cout << endl;
}

template <class T>
GDLLNode<T>* GDLList<T>::search(const string& title) const {
    GDLLNode<T>* current = head;
    while (current != nullptr) {
        if (current->getData().getGenre() == title) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

template <class T>
void GDLList<T>::sortInsert(const T& data) {
GDLLNode<Movie>* newNode = new GDLLNode<Movie>(data);
    if (isEmpty() || data < head->getData()) {
        addToHead(data); // Si la lista está vacía o el nuevo dato es menor que el primer dato de la lista, agregamos al inicio
    } else {
        GDLLNode<T>* current = head;
        while (current->getNext() != nullptr && current->getNext()->getData() < data) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        newNode->setPrev(current);
        if (current->getNext() != nullptr) {
            current->getNext()->setPrev(newNode);
        }
        current->setNext(newNode);
        if (newNode->getNext() == nullptr) {
            tail = newNode;
        }
    }
}





template <class T>
GDLLNode<T>* GDLList<T>::searchByTitle(const string& title) const {
    GDLLNode<T>* current = head;
    while (current != nullptr) {
        if (current->getData().getTitle() == title) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}



template <class T>
void GDLList<T>::deleteNode(const string& title) {
    GDLLNode<T>* nodeToDelete = search(title);
    if (nodeToDelete != nullptr) {
        if (nodeToDelete == head) {
            deleteFromHead();
        } else if (nodeToDelete == tail) {
            deleteFromTail();
        } else {
            nodeToDelete->getPrev()->setNext(nodeToDelete->getNext());
            nodeToDelete->getNext()->setPrev(nodeToDelete->getPrev());
            delete nodeToDelete;
        }
    }
}

#endif // GDL_LIST_H

