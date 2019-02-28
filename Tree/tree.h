class treeNode
{
private :
    treeNode *root;
    //treeNode *doAddNodeRecursion(treeNode *root, int data);

public :
    int data;
    treeNode *left;
    treeNode *right;

    treeNode(int data);
    void addNode(int data);
    //void addNodeRecursion(int data);
};