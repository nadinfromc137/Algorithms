#include <iostream>
#include <string>
#include <vector>


void printmyarr(int * arr, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;
}
void BinaryTillN(int n, int * arr, int i, int x)
{
	if (i == n)
	{
		printmyarr(arr, n);
		std::cout << "At function call = " << x << std::endl;
		return;
	}
	arr[i] = 0;
	std::cout << "Right now x= " << x << std::endl;

	BinaryTillN(n, arr, i+1, x++);
	//printmyarr(arr, n);
	arr[i] = 1;
	BinaryTillN(n, arr, i + 1, x++);
	//printmyarr(arr, n);
}

void AllCombinations(int radix, int length, int* arr, int index)
{
	if (length == index)
	{
		printmyarr(arr, length);
		return;
	}
	for (int m = 0; m < radix; m++)
	{
		arr[index] = m;
		AllCombinations(radix, length, arr, index + 1);
	}
}

int FindUniquePaths(int m, int  n)
{
	if (n == 1 || m == 1)
		return 1;
	else
		return FindUniquePaths(n - 1, m) + FindUniquePaths(m - 1, n);
}
int MaximumSum(int *arr, int size) //BRUTE FORCE SOLUTION TO FIND MAX SUM OF 2 UNIQUE NO.S
{
	std::vector <int> sums;
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (arr[i] != arr[j])
			sums.push_back(arr[i]+arr[j]);
		}
	}
	int max = INT_MIN;
	for (int item: sums)
	{
		if (item > max) max = item;
	}
	return max;
}
int LongestIncSubseq(int*arr, int arr_len)		//Longest increasing subsequence
{
	std::vector <std::vector<int>> subseqs;
	std::vector <int> temp;
	
	for (int i = 0; i < arr_len; i++)
	{
		temp.clear();
		temp.push_back(arr[i]);
		int temp_it = 0;
		for (int j = i+1; j < arr_len; j++)
		{
			if (temp[temp_it] <= arr[j])
			{
				temp_it++;
				temp.push_back(arr[j]);
			}	
		}
		subseqs.push_back(temp);
	}

	int max = 0;
	for (int i = 0; i < subseqs.size(); i++)
	{
		if (subseqs[i].size() > max)
		{
			//std::cout << subseqs[i].size() << std::endl;
			max = subseqs[i].size();
		}
	}
	std::cout << max << std::endl;
	return max;
}
int StaircaseCombinations(int stairs) //A child hops stairs 1, 2, or 3 at once, how many combinations depending on number of stairs
{
	if (stairs == 1 || stairs == 1 || stairs == 3)
	{
		
		return stairs;
	}
	return StaircaseCombinations(stairs-1);
	StaircaseCombinations(stairs-2);
	StaircaseCombinations(stairs-3);
}

void CallStaircaseCombinations()
{

}

//To implement
//int BinarySubstrings(std::string one, std::string two, std::vector <std::string> space, int length);


int main()
{
	/*
	int n; cin >> n;
	int *arr = new int [n];
	int x = 1;
	BinaryTillN(n, arr, 0, x);
	*/
	/*
	int m = 2; int n = 2;
	int x = FindUniquePaths(m, n);
	cout << "Paths = " << x << endl;
	*/
	/*
	int n = 3; int k = 3;
	int* arr = new int[n];
	AllCombinations(k, n, arr, 0);
	*/
	/*
	int* arr = new int[5];
	for (size_t i = 0; i < 5; i++)
	{
		std::cin >> arr[i];
	}
	std::cout << MaximumSum(arr, 5) << std::endl;
	*/
	/*
	int* arr = new int[9];
	for (size_t i = 0; i < 9; i++)
	{
		std::cin >> arr[i];
	}
	LongestIncSubseq(arr, 9);
	*/

	
	

	return 0;
}
