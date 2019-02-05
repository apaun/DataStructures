#include<iostream>
#include"tree.h"
using namespace std;

treeNode::treeNode(int data)
{
    this->data = data;
    this->right = NULL;
    this->left = NULL;
    root = this;
}

void treeNode::addNode(int data)
{
    if (root == NULL)
        root = new treeNode(data);
    else
    {
        treeNode *curr = root;
        treeNode *temp = curr;
        while(curr != NULL)
        {
            temp = curr;
            if (curr->data >= data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
            
        } 
        if(temp->data >= data)
        {
            temp->left = new treeNode(data); 
        }
        else
        {
            temp->right = new treeNode(data); 
        }
    }
    
}

// void treeNode::addNodeRecursion(int data)
// {
//     doAddNodeRecursion(this->root, data);
// }

// treeNode *treeNode::addNodeRecursion(treeNode *root, int data)
// {
//     if(root == NULL || root->data == data)
//         return root;
    
//     if (root->data > data)
//         root->left = addNodeRecursion(root->left, data);
//     else
//         root->right = addNodeRecursion(root->right, data);

//     return root;    
// }

int main()
{
    cout << "Trees" << endl;
    treeNode tree1(10);
    tree1.addNode(20);
    tree1.addNode(5);

    cout << tree1.left->data << endl;
    cout << tree1.right->data << endl;
    return 0;
}