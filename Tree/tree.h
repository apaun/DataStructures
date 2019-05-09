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
    int treeHeight(treeNode *root);
    int treeDiameter(treeNode *root);
    void dfs(treeNode *root);
    void bfs(treeNode* root);
    void levelOrderSpiral(treeNode* root);
    bool printAncestor(treeNode* root, int target);
    treeNode* LCA(treeNode *root, int n1, int n2);
    int nodeLevel(treeNode* root, int target);
};


/***********************************************************
 I learned that depth and height are properties of a node:

The depth of a node is the number of edges from the node to the tree's root node.
A root node will have a depth of 0.

The height of a node is the number of edges on the longest path from the node to a leaf.
A leaf node will have a height of 0.

Properties of a tree:

The height of a tree would be the height of its root node,
or equivalently, the depth of its deepest node.

The diameter (or width) of a tree is the number of nodes on the longest path between any two leaf nodes.
*************************************************************/