#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "Node.hpp"

template <class T>
class LinkedList
{
    public: // DO NOT CHANGE THIS PART.
        LinkedList();
        LinkedList(const LinkedList &obj);

        ~LinkedList();

        Node<T> *getFirstNode() const; //
        Node<T> *getHead() const;
        Node<T> *getTail() const;
        int getNumberOfNodes();
        bool isEmpty(); //

        void insertAtTheFront(const T &data); //
        void insertAtTheEnd(const T &data); //
        void insertAfterGivenNode(const T &data, Node<T> *prev); //

        void removeNode(Node<T> *node);
        void removeAllNodes();

        Node<T> *findNode(const T &data); //

        void printAllNodes();
        void printReversed();

        LinkedList &operator=(const LinkedList &rhs);

    private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

    private: // DO NOT CHANGE THIS PART.
        Node<T> *head;
        Node<T> *tail;
};

template<class T>
LinkedList<T>::LinkedList()
{
    /* TODO */
    head=new Node<T>;
    tail=new Node<T>;
    head->next = tail;
    tail->prev = head;
    head->prev=NULL;
    tail->next=NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &obj)
{
    /* TODO */
    Node<T> *n;
    this->head = new Node<T>;
    this->tail = new Node<T>;
    head->next = tail;
    tail->prev = head;
    head->prev=NULL;
    tail->next=NULL;

    if(obj.getFirstNode() != NULL){
        for(n=obj.getFirstNode();n!=obj.tail;n=n->next){
            insertAtTheEnd(n->element);
        }
    }

    n=NULL;
    delete n;

}

template<class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
    removeAllNodes();
    delete head;
    delete tail;
}

template<class T>
Node<T> * LinkedList<T>::getFirstNode() const
{
    /* TODO */
    if(head->next == tail){
        return NULL;
    }
    else{
        return head->next;
    }

}

template<class T>
Node<T> * LinkedList<T>::getHead() const
{
    /* TODO */
    return head;
}

template<class T>
Node<T> * LinkedList<T>::getTail() const
{
    /* TODO */
    return tail;
}

template<class T>
int LinkedList<T>::getNumberOfNodes()
{
    /* TODO */
    int i=0;
    Node<T> *n;
    if(getFirstNode() != NULL){
        for(n=getFirstNode();n!=tail;n=n->next){
            i++;
        }
    }
    n=NULL;
    delete n;
    return i;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    /* TODO */
    if(head->next == tail){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data)
{
    /* TODO */
    Node<T> *n;
    n = new Node<T>;
    n->element = data;

    n->next = head->next;
    head->next = n;
    n->prev = head;
    n->next->prev = n;

    n=NULL;
    delete n;

}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data)
{
    /* TODO */
    Node<T> *n;
    n = new Node<T>;
    n->element = data;

    n->prev = tail->prev;
    n->prev->next = n;
    tail->prev = n;
    n->next=tail;

    n=NULL;
    delete n;
}

template<class T>
void LinkedList<T>::insertAfterGivenNode(const T &data, Node<T> *prev)
{
    /* TODO */
    Node<T> *n;
    n = new Node<T>;
    n->element = data;

    n->next = prev->next;
    prev->next = n;
    n->next->prev = n;
    n->prev = prev;

    n=NULL;
    delete n;

}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    /* TODO */
    if(getNumberOfNodes() > 1){
        if(node != head->next && node != tail->prev){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        }
        else if(node == head->next){
        node->next->prev = head;
        head->next = node->next;
        delete node;
        }
        else{
        node->prev->next = tail;
        tail->prev = node->prev;
        delete node;
        }
    }
    else if(getNumberOfNodes()==1){
        head->next = tail;
        tail->prev = head;
        delete node;
    }
    else{
    }


}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
    if(getFirstNode() != NULL){
        for(int j=0;j<getNumberOfNodes();){
            removeNode(getFirstNode());
        }
    }
}

template<class T>
Node<T> * LinkedList<T>::findNode(const T &data)
{
    /* TODO */
    Node<T> *n;
    if(getFirstNode() != NULL){
        for(n=getFirstNode();n!=tail;n=n->next){
            if(n->element == data){
                return n;
            }
        }
    }
    return NULL;
}

template<class T>
void LinkedList<T>::printAllNodes()
{
    /* TODO */
    Node<T> *n;
    if(getFirstNode() != NULL){
        for(n=getFirstNode();n!=tail;n=n->next){
        std::cout<<n->element<<std::endl;
        }
    }

    n=NULL;
    delete n;
}

template<class T>
void LinkedList<T>::printReversed()
{
    /* TODO */
    Node<T> *n;
    for(n=tail->prev;n!=head;n=n->prev){
        std::cout<<n->element<<std::endl;
    }
    n=NULL;
    delete n;
}

template<class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList &rhs)
{
    /* TODO */
    removeAllNodes();
    Node<T> *n;
    for(n=rhs.getFirstNode();n!=rhs.tail;n=n->next){
        insertAtTheEnd(n->element);
    }
    n=NULL;
    delete n;
    return *this;
}

#endif //LINKED_LIST_HPP

