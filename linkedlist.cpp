#include <iostream>
#include"linkedlist.h"
using namespace std;

node::node(int data)
{
    this->data = data;
    next = NULL;
    head = this;
}

void node::printList()
{
    node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL"<< endl;
}

void node::insertNodeAtBegin(int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void node::insertNodeAtEnd(int data)
{
    node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new node(data);
}

void node::reverseList()
{
    if (head == NULL)
        cout << "List is empty" << endl;

    node *curr = head;
    node *next = NULL;
    node *prev = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    head = prev;
}

int node::findMiddle()
{
    if (head == NULL || head->next == NULL)
        return head->data;

    node *slowPtr = head;
    node *fastPtr = head;
    
    while(fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    return slowPtr->data;
}

int node::listLength()
{
    int length = 0;
    node *temp = head;

    if (head == NULL)
        return length;

    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
}


int main()
{
    node list1(20);
    list1.insertNodeAtBegin(5);
    list1.insertNodeAtBegin(1);
    list1.insertNodeAtEnd(30);
    list1.insertNodeAtEnd(40);
    list1.printList();
    list1.reverseList();
    list1.printList();
    cout << "Middle is " << list1.findMiddle() << endl;
    cout << "Length is " << list1.listLength() << endl;
    return 0;
}