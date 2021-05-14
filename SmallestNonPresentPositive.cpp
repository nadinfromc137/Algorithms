#include <algorithm>
#include <vector>
using namespace std;
#include <iostream>

/*
This is
*/

int SmallestNonPresentPositive(vector<int>& A) {
    int positive_iterator = 1;
    int least = 1;
    int last = 1;
    stable_sort(A.begin(), A.end());
    last = A[0];
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] <= 0)
            continue;
        if (A[i] != positive_iterator)
        {
            return positive_iterator;
        }
        else if (last != A[i])
        {
            positive_iterator++;
        }
        last = A[i];
    }
    return least;
}

int main()
{
    vector<int> A;
    int size = 0;
    cout << "Enter the number of elements to be input : ";
    cin >> size;
    int x = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> x;
        A.push_back(x);
    }
    x = SmallestNonPresentPositive(A);
    cout << x;
    return 0;
}
