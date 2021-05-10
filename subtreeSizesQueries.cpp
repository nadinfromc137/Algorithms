#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*Question:

Given a number of nodes n, and the next n lines showing the index of the ith left child and next to it he indx of the ith right child, find 
the answwer to the queries.
You are given the queries q, then for the next q ines you have the query number 1 or 2

type1- given a node on the tree she has to figure out the size of the node's subtree

type2- given a size x she has to count the number of subtrees that have size x

The first line contains n, number of nodes in the tree.

Each of the next n lines contains two integers, a b, where a is the index of left child, and b is the index of right child of ith node.

Note: -1 is used to represent a null node.

The next line contains an integer q, the number of quires

Each of the next q lines contains two integers, x,y where x is the query type and y is the node number or a size value
*/


/*
3
2 3
-1 -1
-1 -1
2
1 1
2 1*/

// output should be 
/*
3
2
*/

/*
11
2 3
4 -1
5 -1
6 -1
7 8
-1 9
-1 -1
10 11
-1 -1
-1 -1
-1 -1
6
2 4
2 4
1 11
2 4
2 4
1 2
*/
//output should be 
/*
1
1
1
1
1
4
*/

/*
5
2 3
-1 4
-1 5
-1 -1
-1 -1
4
1 1
1 5
1 2
2 5
*/
//output should be
/*
5
1
2
1
*/
class Node
{
public:
    int data = 0;
    Node* left = NULL;
    Node* right = NULL;
};
void eachSubtreeSize(Node* root, int sizeX, int& calcSize);
void subtreeSize(Node* root, long long nodes, int* queryType, int* nodeOrSize, long long queries, vector <Node*> tree)
{
    int* queryAnswers = new int[queries];
    int equalSize = 0;
    vector <int> subtreeSizes(nodes, 0);
    int sizeX;
    //
    // get sizes for all subtrees

    for (long long k = 0; k < nodes; k++)
    {
        sizeX = 0;
        int finalSize = 0;
        eachSubtreeSize(tree[k], sizeX, finalSize);
        subtreeSizes[k] = finalSize;
        cout << subtreeSizes[k];
    }

    //
    for (long long i = 0; i < queries; i++)
    {
        if (queryType[i] == 1)
        {
            int chosenNode = nodeOrSize[i] - 1;
            queryAnswers[i] = subtreeSizes[chosenNode];
            cout << queryAnswers[i] << endl;
        }
        else
        {
            for (long long j = 0; j < nodes; j++)
            {
                if (subtreeSizes[j] == nodeOrSize[i]) equalSize++;
            }
            queryAnswers[i] = equalSize;
            cout << queryAnswers[i] << endl;
        }

    }
    //cout << "\n" << equalSize;
}


void eachSubtreeSize(Node* root, int sizeX, int& calcSize)
{
    if (!root)
    {
        return;
    }

    calcSize += 1;

    eachSubtreeSize(root->left, sizeX, calcSize);
    eachSubtreeSize(root->right, sizeX, calcSize);

}

int main()
{
    long long nodes, queries;
    cin >> nodes;
    int* child1 = new int[nodes];
    int* child2 = new int[nodes];
    for (int i = 0; i < nodes; i++)
    {
        cin >> child1[i] >> child2[i];
    }
    //
    //Build tree
    vector <Node*> tree(nodes, NULL);
    for (int i = 0; i < nodes; i++)
    {
        tree[i] = new Node();
    }
    for (int i = 0; i < nodes; i++)
    {
        if (child1[i] != -1)
        {
            tree[i]->left = tree[child1[i] - 1];
        }
        //else no need for else already set to null when created
        if (child2[i] != -1)
        {
            tree[i]->right = tree[child2[i] - 1];
        }
    }
    // 
    cin >> queries;
    int* queryType = new int[queries];
    int* nodeOrSize = new int[queries];
    for (int i = 0; i < queries; i++)
    {
        cin >> queryType[i] >> nodeOrSize[i];
    }
    subtreeSize(tree[0], nodes, queryType, nodeOrSize, queries, tree);
    return 0;
}
