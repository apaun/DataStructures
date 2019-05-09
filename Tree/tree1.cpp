#include<iostream>
#include<queue>
#include<stack>
#include"tree.h"
using namespace std;

int max(int m , int n)
{
    return m > n ? m : n;
}

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

int treeNode::treeHeight(treeNode *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    if(leftHeight > rightHeight)
        return 1 + leftHeight;
    else
        return 1 + rightHeight;
}

int treeNode::treeDiameter(treeNode *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    int leftDiameter = treeDiameter(root->left);
    int rightDiameter = treeDiameter(root->right);

    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

void treeNode::dfs(treeNode* root)
{
    if (root == NULL)
        return;
    dfs(root->left);
    cout << root->data << " ";
    dfs(root->right);
}

void treeNode::bfs(treeNode* root)
{
    if (root== NULL)
        cout << "Tree is empty";
    
    queue<treeNode*> q;
    q.push(root);

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

void treeNode::levelOrderSpiral(treeNode* root)
{
    if (root== NULL)
        cout << "Tree is empty";

    stack<treeNode*> s1;
    stack<treeNode*> s2;

    s1.push(root);

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

bool treeNode::printAncestor(treeNode* root, int target)
{

    if (root == NULL)
        return false;
    
    if(root->data == target)
        return true;
    
    if(printAncestor(root->left, target) || printAncestor(root->right, target))
    {
        cout << root->data << " ";
        return true; 
    }


    return false;
}

treeNode* treeNode::LCA(treeNode *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    auto leftLCA = LCA(root->left, n1, n2);
    auto rightLCA = LCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return leftLCA != NULL ? leftLCA : rightLCA;
}

int nodeLevelUtil(treeNode* root,int target,int level)
{
    if(root == NULL)
        return 0;
    
    if(root->data == target)
        return level;
    
    int downlevel = nodeLevelUtil(root->left, target, level + 1);
    if (downlevel != 0)
        return downlevel;

    downlevel = nodeLevelUtil(root->right, target, level + 1);

    return downlevel;

}

int treeNode::nodeLevel(treeNode* root, int target)
{
    return nodeLevelUtil(root, target, 1);
}

int main()
{

    cout << "Trees" << endl;
    treeNode *tree1 = new treeNode(10);
    tree1->addNode(20);
    tree1->addNode(5);
    tree1->addNode(6);
    tree1->addNode(4);
    tree1->addNode(15);

    cout << tree1->left->data << endl;
    cout << tree1->left->left->data << endl;
    cout << tree1->right->data << endl;

    cout << "Height of tree is " << tree1->treeHeight(tree1) << endl;  
    cout << "Diameter of tree is " << tree1->treeDiameter(tree1) << endl;  
    cout << "DFS of tree is ";
    tree1->dfs(tree1);
    cout << endl;

    cout << "BFS of tree is ";
    tree1->bfs(tree1);
    cout << endl;

    cout << "Spiral of tree is ";
    tree1->levelOrderSpiral(tree1);
    cout << endl;

    int target = 6;
    cout << "Ancestors of node " << target << " is " ;
    tree1->printAncestor(tree1, target);
    cout << endl;

    int n1 = 4;
    int n2 = 6;

    cout << "LCA of " << n1 << " and " << n2 << " is " << tree1->LCA(tree1, n1, n2)->data << endl;

    cout << "Level of " << n1 << " is " << tree1->nodeLevel(tree1, n1) << endl;

    
    
    return 0;
}