class node
{
private:
    node *head;

public :
    int data;
    node *next;
    node(int data);
    void printList();
    void insertNodeAtBegin(int data);
    void insertNodeAtEnd(int data);
    void reverseList();
    int findMiddle();
    int listLength();
};