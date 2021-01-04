/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1,2), (1,3) and (2,2).
*/

#include <bits/stdc++.h>
using namespace std;

int CoinChange(int n, int *arr, int l) // But here repititions will take place
{
	if (n == 0)
	{
		return 1;
	}

	if (n < 0)
	{
		return 0;
	}

	if (l == 0)
	{
		return 0;
	}

	int first = CoinChange(n - arr[0], arr, l);
	int second = CoinChange(n, arr + 1, l - 1);

	return first + second;
}

int CoinChange1(int n, int *arr, int l, int **arr1)
{
	if (n == 0)
	{
		return 1;
	}

	if (n < 0)
	{
		return 0;
	}

	if (l == 0)
	{
		return 0;
	}

	if (arr1[n][l] > -1)
	{
		return arr1[n][l];
	}

	int first = CoinChange1(n - arr[0], arr, l, arr1);
	int second = CoinChange1(n, arr + 1, l - 1, arr1);

	arr1[n][l] = first + second;
	return first + second;
}

int main()
{
	int n, l, i, ans;
	cin >> l; // total no. of coins we have

	int *arr = new int[l];
	for (i = 0; i < l; i++)
	{
		cin >> arr[l];
	}

	sort(arr,arr+l);

	cin >> n;

	ans = CoinChange(n, arr, l);
	cout << ans;

}