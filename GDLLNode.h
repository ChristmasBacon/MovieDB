#ifndef GDLL_NODE_H
#define GDLL_NODE_H

#include <string> // Inclusiones de bibliotecas estándar primero

template <class T>
class GDLLNode
{
public:
    GDLLNode();
    GDLLNode(T data);
    T getData() const;
    GDLLNode<T> *getNext() const;
    GDLLNode<T> *getPrev() const;
    void setData(T data);
    void setNext(GDLLNode<T> *next);
    void setPrev(GDLLNode<T> *prev);
    explicit GDLLNode(const T &newData) : data(newData), next(nullptr), prev(nullptr) {}
    GDLLNode(T &&data) : data(std::move(data)), prev(nullptr), next(nullptr) {}
    void setMovie(const T &newMovie);   // Declaración del nuevo miembro setMovie
    T getMovie() const { return data; } // Nuevo miembro getMovie

private:
    T data;
    GDLLNode<T> *next;
    GDLLNode<T> *prev;
};

template <class T>
GDLLNode<T>::GDLLNode() : next(nullptr), prev(nullptr) {}

template <class T>
GDLLNode<T>::GDLLNode(T data) : data(data), next(nullptr), prev(nullptr) {}

template <class T>
T GDLLNode<T>::getData() const
{
    return data;
}

template <class T>
GDLLNode<T> *GDLLNode<T>::getNext() const
{
    return next;
}

template <class T>
GDLLNode<T> *GDLLNode<T>::getPrev() const
{
    return prev;
}

template <class T>
void GDLLNode<T>::setData(T data)
{
    this->data = data;
}

template <class T>
void GDLLNode<T>::setNext(GDLLNode<T> *next)
{
    this->next = next;
}

template <class T>
void GDLLNode<T>::setPrev(GDLLNode<T> *prev)
{
    this->prev = prev;
}

template <class T>
void GDLLNode<T>::setMovie(const T &newMovie)
{
    data = newMovie;
}

#endif // GDLL_NODE_H
