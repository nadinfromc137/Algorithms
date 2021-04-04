#include <algorithm>
#include <vector>
using namespace std;
#include <iostream>

int solution(vector<int>& A) {
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
    int size = 6;
    int x = 0;
    for (size_t i = 0; i < 6; i++)
    {
        cin >> x;
        A.push_back(x);
    }
    x =solution(A);
    cout << x;
    return 0;
}
