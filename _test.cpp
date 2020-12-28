#include <bits/stdc++.h>
using namespace std;

int expand_out(string s, int i, int j, int len)
{
	int ans = 0;
	// if(even)
	if (i != j)
	{
		while (i >= 0 && j < len && s[i] == s[j])
		{
			ans += 2;
			i--;
			j++;
		}
	}
	// if(odd) => i==j
	else
	{
		ans = 1;
		i--;
		j++;
		while (i >= 0 && j < len && s[i] == s[j])
		{
			ans += 2;
			i--;
			j++;
		}
	}
	return ans;
}
int longestPalindrome(string s)
{
	int len = s.length();
	int maxlen = 0;
	// expand outwards from every element's index
	for (int i = 0; i < len; i++)
	{
		// find for odd
		int forodd = expand_out(s, i, i, len);
		// find for even
		// only if next is equal
		int foreven = INT_MIN;
		if ((i + 1 < len) && (s[i] == s[i + 1]))
		{
			foreven = expand_out(s, i, i + 1, len);
		}
		int maxcurr = max(foreven, forodd);
		if (maxcurr > maxlen)
		{
			maxlen = maxcurr;
		}
	}
	return maxlen;
}

int main()
{
	cout<<longestPalindrome("babad")<<endl;
	cout<<longestPalindrome("cbbd")<<endl;
	cout<<longestPalindrome("a")<<endl;
	cout<<longestPalindrome("ac")<<endl;
}