#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Search space --> 2^n: 2 recursive calls

void TreasureCave(int W, int N, int* weight, int* value, int itemsTaken,int weightTaken, int remainingWeight, int valueTaken, int  index, vector <int>& possibleWeights, vector <int>& correspondingValue)
{
    if (N == 0 || W==0 ) return;
    if (remainingWeight <=0 || index == N || itemsTaken == N || weightTaken == W)
    {
        //possibleWeights.push_back(weightTaken);
        //correspondingValue.push_back(valueTaken);

        cout << weightTaken << endl;
        return;
    }

    possibleWeights.push_back(weightTaken);
    correspondingValue.push_back(valueTaken);
    TreasureCave(W, N, weight, value, itemsTaken + 1, weightTaken + weight[index], remainingWeight - weight[index], valueTaken + value[index], index + 1, possibleWeights, correspondingValue);
    
}


int main() {

    //---------------------Taking inputs-----------------------
    int W, N;
    cin >> W;
    cin >> N;
    int* weight = new int[N];
    int* value = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i];
    }

    //---------------------Taking inputs-----------------------
    vector <int> possibleWeights;
    vector <int> correspondingValue;
    TreasureCave(W, N, weight, value, 0, 0,W, 0, 0, possibleWeights, correspondingValue);
    //int maxWeight = 0;
    int maxValue = 0;
    for (size_t i = 0; i < possibleWeights.size(); i++)
    {
        if (/*possibleWeights[i] > maxWeight &&*/ possibleWeights[i] <= W && correspondingValue[i] > maxValue)
        {
            maxValue = correspondingValue[i];
        }
    }
    cout << maxValue;
    return 0;
}
