#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <climits>

/*
2
10 15
12 13
25 8
2 3
*/ //---> output = 27

/*You are a hero entering a boss’s lair. The consists of N floors. Each floor is square shaped and consists of multiple square-shaped rooms of similar size. Each floor has N rows by N columns of rooms. From each room, you can access the same room in the floor above, and the rooms to your right, and bottom directions. Upon entering each room, you pay a certain amount of gold. You enter from the lowest floor from the room to the top left. The boss is at the highest floor in the room to the bottom right. Given the amount paid for each room, find the minimum amount of gold needed to reach the boss’s room. You are required to answer the question above using brute force implemented using recursion.

Input Format

    The first line will contain N.
    The next N lines will contain N numbers each denoting the gold required for each room in floor 0 (lowest floor). (Hint: you can input these numbers using cin normally. “cin >> var1 >> var2)
    For each remaining floor the same format is repeated.
*/

int minCoins = INT_MAX;
void BossLair(int** roomCoins, int N, int rows, int currentRow, int currentColoumn, int collectedCoins)
{
    if (currentColoumn == N - 1 && currentRow == (rows - 1))      // rows indexed froom 0.. N^2-1 
    {                                                        // coloumns indexed by N-1 (number of rooms in a width )   
        collectedCoins += roomCoins[rows - 1][N - 1];
        //cout << "Collected coins in this path = " << collectedCoins << endl;

        if (collectedCoins < minCoins)
        {
            minCoins = collectedCoins;

        }
        return;
    }

    //BossLair(roomCoins, N, rows,currentRow,currentColoumn,collectedCoins);
    if (currentRow != rows - 1)
    {
        int floorAbove = currentRow + N;
        BossLair(roomCoins, N, rows, currentRow + 1, currentColoumn, collectedCoins + roomCoins[currentRow][currentColoumn]);
        if (floorAbove <= rows - 1)
            BossLair(roomCoins, N, rows, currentRow + N, currentColoumn, collectedCoins + roomCoins[currentRow][currentColoumn]);
    }
    if (currentColoumn != N - 1)
    {
        BossLair(roomCoins, N, rows, currentRow, currentColoumn + 1, collectedCoins + roomCoins[currentRow][currentColoumn]);
    }

}


int main() {

    int N;
    cin >> N;
    int rows = pow(N, 2);
    int** roomCoins = new int* [rows];
    for (int i = 0; i < rows; i++) {
        roomCoins[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            cin >> roomCoins[i][j];
        }
    }
    BossLair(roomCoins, N, rows, 0, 0, 0);
    cout << minCoins;

    return 0;
}