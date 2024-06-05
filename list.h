#ifndef __LIST__
#define __LIST__
#include <iostream>

template <typename T>
class List
{
public:
    void push_back(const T& data);
    void pop_back();
    void push_front(const T& value);
    void pop_front();
    void printList();
    void deleteNode(const int& index);
    bool search(const T& value);
    T searchFromEnd(const int& index);
    void insert(const T& value,const int& index);

    bool hasCycle();
    void reverse();

private:
    class Node
    {
    public:
        Node(const T& value);

    public:
        Node* next = nullptr;
        T data;

    };

    Node* head = nullptr;

};

#endif //__LIST__


//////////NODE///////////////////////////////////////////////////////////
template <typename T>
List<T>::Node::Node(const T& value) : data(value)
{
}


//////////LIST////////////////////////////////////////////////////////////
template <typename T>
void List<T>::push_back(const T& data)
{
    Node* newNode = new Node(data);

    if(head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

template <typename T>
void List<T>::pop_back()
{
     if(head == nullptr)
    {
        std::cout<<"The List is empty."<<std::endl;
        return;
    }

    Node* ptr1 = head;
    Node* ptr2 = head->next;
    while (ptr2->next != nullptr)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    ptr1->next = nullptr;
    delete ptr2;
    
}


template <typename T>
void List<T>::printList() 
{
    if (head == nullptr)
    {
        std::cout<<"There is no data!"<<std::endl;
        return;
    }
    
    Node* temp = head;
     
    while (temp != nullptr)
    {
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }

}

template <typename T>
void List<T>::push_front(const T& value)
{
    Node* ptr = new Node(value);
    Node* temp = head;

    head = ptr;
    ptr->next = temp;

}

template <typename T>
void List<T>::pop_front()
{
    Node* temp = head;

    head = temp->next;
    delete temp;

}

template <typename T>
void List<T>::deleteNode(const int& index)
{
    if (head == nullptr)
    {
        std::cout<<"The list is empty!"<<std::endl;
        return;
    }

    int length = 0;
    Node* temp1 = head;

    while (temp1 != nullptr)
    {
        ++length;
        temp1 = temp1->next;
    }

    if (index >= 0 && index < length)
    {

        if (index == 0)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            temp1 = head;
            for (int i = 0; i < index - 1; ++i)
            {
                temp1 = temp1->next;
            }

            Node* temp2 = temp1->next;
            temp1->next = temp2->next;
            delete temp2;
        }
        
    }
    else
    {
        std::cout<<"There is no Node with that index."<<std::endl;
    }
}

template <typename T>
bool List<T>::search(const T& value)
{
    Node* temp = head;
    int i = 0;

    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            std::cout<<"The index of Node: "<<i<<std::endl;
            return true;
        }
        ++i;
        temp = temp->next;
    }
    
    std::cout<<"There is no Node with that value."<<std::endl;
    return false;
}

template <typename T>
void List<T>::insert(const T& value,const int& index)
{
    int length = 0;
    Node* temp1 = head;

    while (temp1 != nullptr)
    {
        ++length;
        temp1 = temp1->next;
    }

    if (index == 0 && length == 0)
    {
        Node* ptr = new Node(value);
        head = ptr;
        return;
    }

    if (index == 0)
    {
        Node* ptr = new Node(value);
        temp1 = head;
        head = ptr;
        ptr->next=temp1;
        return;
    }
    
    

    if (index >= 0 && index < length)
    {

        Node* temp2 = nullptr;
        temp1 = head;

        int i = 0;
        while (i < index)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            ++i;
        }

        Node* ptr = new Node(value);
        temp2->next = ptr;
        ptr->next = temp1;
        
    }
    else
    {
        std::cout<<"The index is greater than the length."<<std::endl;
    }
}


template <typename T>
void List<T>::reverse()
{
    Node* current = head;
    Node* leftPoint = nullptr;
    Node* rightPoint = nullptr;

    while (current != nullptr) {
        rightPoint = current->next;

        current->next = leftPoint;

        leftPoint = current;

        current = rightPoint;
    }
    head = leftPoint;
}

template <typename T>
T List<T>::searchFromEnd(const int& index)
{
    if (head == nullptr)
    {
        std::cout<<"The list is empty"<<std::endl;
        return T();
    }
    
    int length = 0;
    Node* temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
        ++length;
    }
    
    if (index < 0 || index >= length)
    {
        std::cout<<"The index is  under length."<<std::endl;
        return T();
    }

    int wanted = (length - 1) - index;

    temp = head;
    for (size_t i = 0; i < wanted; ++i)
    {
        temp = temp->next;
    }
    
    return temp->data;
}