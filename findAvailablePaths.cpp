#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
You are trying to find all the paths from the root node 1 to all the eaf nodes such that the number of consecutive 
nodes marked as 1 does not exceed a given M. 

Notes : The tree is not binary so the node may have multiple children, also it is not guaranteed that the edges
will be given from parent to child so if node B has a parent A the edge in the input could be B A or A B 

The first line contains two integers, N and M — the number of nodes of the tree and the maximum number of consecutive 
1 nodes.

The second line contains n numbers either equals to 1 if the node is dark, or 0 otherwise.

It is guaranteed that the given set of edges specifies a tree.

*/


/*
7 1
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7
*/

//output shoud be: 2


/*
12 3
1 0 1 0 1 1 1 1 0 0 0 0
6 7
12 1
9 7
1 4
10 7
7 1
11 8
5 1
3 7
5 8
4 2
*/

// output shoud be: 7



class Node {
public:
    int key = 0;
    vector <Node*> children;
    int index;
    vector <int> Path;
    bool hasParent = false;

};
//cout << "From " << root->index << " to " << root->children[i]->index << endl;
//root->Passed[i]. = 1;
void findPaths(Node* root, int maxM, int& safePaths, int consecutiveOnes)
{

    if ((int)root->children.size() == 0)         //equiv of !root
    {
        safePaths++;
        //cout << "at nodes " << root->index  << " --> "<< consecutiveOnes<< endl;
        return;
    }

    for (int i = 0; i < (int)root->children.size(); i++)
    {
        //cout << "For " << root->index << " consecpaths " << consecutiveOnes << endl;
        if ((consecutiveOnes + root->children[i]->key) <= maxM)
        {
            if (root->children[i]->key == 1)
                findPaths(root->children[i], maxM, safePaths, consecutiveOnes+1);
            else
                findPaths(root->children[i], maxM, safePaths, 0);

        }
        /*   else if (consecutiveOnes == maxM && root->children[i]->key == 0)
        {
               cout << "For " << root->index << " consecpaths " << consecutiveOnes << endl;
               root->Path.push_back(root->index);
               findPaths(root->children[i], maxM, root->key, safePaths, consecutiveOnes);
        }*/
    }

}

int main() {
    int nodeCount, maxM;
    cin >> nodeCount >> maxM;
    int marked1or0;
    vector <Node*> tree(nodeCount, NULL);
    for (int i = 0; i < nodeCount; i++)
    {
        cin >> marked1or0;
        tree[i] = new Node();
        tree[i]->key = marked1or0;
        tree[i]->index = i;
    }
    vector <bool> connectedTo1(nodeCount, false);
    //edges, get edge and add to list of vectors
    int* edge1 = new int[nodeCount - 1];
    int* edge2 = new int[nodeCount - 1];

    // first connect the nodes directly to 1
    for (int i = 0; i < nodeCount - 1; i++)
    {
        cin >> edge1[i] >> edge2[i];
        if (edge2[i] == 1)
        {
            tree[edge2[i] - 1]->children.push_back(tree[edge1[i] - 1]);
            tree[edge1[i] - 1]->hasParent = true;
            connectedTo1[edge1[i] - 1] = true;
            continue;
        }
        if (edge1[i] == 1)
        {
            tree[edge1[i] - 1]->children.push_back(tree[edge2[i] - 1]);
            tree[edge2[i] - 1]->hasParent = true;
            connectedTo1[edge2[i] - 1] = true;
        }
    }
    tree[0]->hasParent = true;
    // then connect the rest
    for (int i = 0; i < nodeCount - 1; i++)
    {
        if (connectedTo1[edge1[i] - 1] && !tree[edge2[i] - 1]->hasParent)
        {
            tree[edge1[i] - 1]->children.push_back(tree[edge2[i] - 1]);
            tree[edge2[i] - 1]->hasParent = true;
            connectedTo1[edge2[i] - 1] = true;
        }
        else if (connectedTo1[edge2[i] - 1] && !tree[edge1[i] - 1]->hasParent)
        {
            tree[edge2[i] - 1]->children.push_back(tree[edge1[i] - 1]);
            tree[edge1[i] - 1]->hasParent = true;
            connectedTo1[edge1[i] - 1] = true;
        }
    }
	
	// Uncomment to check for inputs 
    //just to check input
    /* for (int i = 0; i < nodeCount; i++)
   {
        cout << "children of tree node " << i << endl;
        for (int k = 0; k < tree[i]->children.size(); k++)
        {
            cout << "child = " << tree[i]->children[k]->index << endl;
        }
   }*/

	// uNcomment to check children are set correctly
    /* for (int i = 0; i < tree.size(); i++)
     {
           cout << "\nPath for " << tree[i]->index << endl;
           for (int k = 0; k < tree[i]->children.size(); k++)
           {
               cout << tree[i]->children[k]->index << " ";
           }
     }*/

    int safePaths = 0;
    findPaths(tree[0], maxM, safePaths, tree[0]->key);
    cout << safePaths;

	
    return 0;
}

