#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Search space --> 2^n: 2 recursive calls

void TreasureCave(int W, int N, int* weight, int* value, int weightTaken, int remainingWeight, int valueTaken, int  index, vector <int>& possibleWeights, vector <int>& correspondingValue)
{
    possibleWeights.push_back(weightTaken);
    correspondingValue.push_back(valueTaken);
   
    if (index == N)
    {
       // cout << "5alas " << weightTaken << " with value " << valueTaken <<" at iteration = " << endl;    
        return;
    }
    for (int i = index; i < N; i++, index++) //index hazawedo emta/ezai
    {
        //cout << "Call for index = " << index << endl;
        TreasureCave(W, N, weight, value, weightTaken + weight[index], remainingWeight - weight[index], valueTaken + value[index], index +1 , possibleWeights, correspondingValue);
    }

    // TreasureCave(W, N, weight, value, itemsTaken, weightTaken, valueTaken, index, possibleWeights);


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
    TreasureCave(W, N, weight, value, 0, W, 0, 0, possibleWeights, correspondingValue);
    //int maxWeight = 0;
    int maxValue = 0;
    for (size_t i = 0; i < possibleWeights.size(); i++)
    {
        if (possibleWeights[i] <= W && correspondingValue[i] > maxValue)

        {
           // cout << "Weight = " << possibleWeights[i] << " with value = " << correspondingValue[i] << endl;
            maxValue = correspondingValue[i];
        }
    }
    cout << maxValue;
    //cout << maxValue;
    return 0;
}
