#include<iostream>
#include<queue>
#include<stack>
#include"tree.h"
using namespace std;

int max(int m , int n)
{
    return m > n ? m : n;
}

treeNode *root;

treeNode::treeNode(int data)
{
    this->data = data;
    this->right = NULL;
    this->left = NULL;
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

int treeNode::treeHeight(treeNode *node)
{
    if (node == NULL)
        return 0;

    int leftHeight = treeHeight(node->left);
    int rightHeight = treeHeight(node->right);

    if(leftHeight > rightHeight)
        return 1 + leftHeight;
    else
        return 1 + rightHeight;
}

int treeNode::treeDiameter(treeNode *node)
{
    if (node == NULL)
        return 0;

    int leftHeight = treeHeight(node->left);
    int rightHeight = treeHeight(node->right);

    int leftDiameter = treeDiameter(node->left);
    int rightDiameter = treeDiameter(node->right);

    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

void treeNode::dfs(treeNode* node)
{
    if (node == NULL)
        return;
    dfs(node->left);
    cout << node->data << " ";
    dfs(node->right);
}

void treeNode::bfs(treeNode* node)
{
    if (node== NULL)
        cout << "Tree is empty";
    
    queue<treeNode*> q;
    q.push(node);

    while(!q.empty())
    {
        auto item = q.front();
        q.pop();
        cout << item->data << " ";

        if(item->left != NULL)
            q.push(item->left);
        
        if(item->right != NULL)
            q.push(item->right);
    }
}

void treeNode::levelOrderSpiral(treeNode* node)
{
    if (root== NULL)
        cout << "Tree is empty";

    stack<treeNode*> s1;
    stack<treeNode*> s2;

    s1.push(node);

    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            auto item = s1.top();
            s1.pop();
            cout << item->data << " ";

            if(item->left != NULL)
                s2.push(item->left);

            if(item->right != NULL)
                s2.push(item->right);
        }

        while(!s2.empty())
        {
            auto item = s2.top();
            s2.pop();
            cout << item->data << " ";

            if(item->right != NULL)
                s1.push(item->right);

            if(item->left != NULL)
                s1.push(item->left);
        }
    }
    
}

bool treeNode::printAncestor(treeNode* node, int target)
{

    if (node == NULL)
        return false;
    
    if(node->data == target)
        return true;
    
    if(printAncestor(node->left, target) || printAncestor(node->right, target))
    {
        cout << node->data << " ";
        return true; 
    }


    return false;
}

treeNode* treeNode::LCA(treeNode *node, int n1, int n2)
{
    if (node == NULL)
        return NULL;

    if (node->data == n1 || node->data == n2)
        return node;

    auto leftLCA = LCA(node->left, n1, n2);
    auto rightLCA = LCA(node->right, n1, n2);

    if (leftLCA && rightLCA)
        return node;

    return leftLCA != NULL ? leftLCA : rightLCA;
}

int nodeLevelUtil(treeNode* node,int target,int level)
{
    if(node == NULL)
        return 0;
    
    if(node->data == target)
        return level;
    
    int downlevel = nodeLevelUtil(node->left, target, level + 1);
    if (downlevel != 0)
        return downlevel;

    downlevel = nodeLevelUtil(node->right, target, level + 1);

    return downlevel;

}

int treeNode::nodeLevel(treeNode* node, int target)
{
    return nodeLevelUtil(node, target, 1);
}

int main()
{

    cout << "Trees" << endl;
    root = new treeNode(10);
    root->addNode(20);
    root->addNode(5);
    root->addNode(6);
    root->addNode(4);
    root->addNode(15);

    cout << root->left->data << endl;
    cout << root->left->left->data << endl;
    cout << root->right->data << endl;

    cout << "Height of tree is " << root->treeHeight(root) << endl;  
    cout << "Diameter of tree is " << root->treeDiameter(root) << endl;  
    cout << "DFS of tree is ";
    root->dfs(root);
    cout << endl;

    cout << "BFS of tree is ";
    root->bfs(root);
    cout << endl;

    cout << "Spiral of tree is ";
    root->levelOrderSpiral(root);
    cout << endl;

    int target = 6;
    cout << "Ancestors of node " << target << " is " ;
    root->printAncestor(root, target);
    cout << endl;

    int n1 = 4;
    int n2 = 6;

    cout << "LCA of " << n1 << " and " << n2 << " is " << root->LCA(root, n1, n2)->data << endl;

    cout << "Level of " << n1 << " is " << root->nodeLevel(root, n1) << endl;

    
    
    return 0;
}