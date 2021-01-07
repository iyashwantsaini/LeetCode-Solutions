#include<bits/stdc++.h>
using namespace std;

//Sample Input
// 3
// AAA
// ABCDEFG
// CODECRAFT
//Sample Output
//4
//128
//496

int Subsequences(string in,string out, int **dp)
{
	int ans,option1, option2;
	int len_in=in.length();
	int len_out=out.length();

	if(len_in == 0)
	{
		return 1;
	}
	if(dp[len_in][len_out] != -1)
	{
		return dp[len_in][len_out];
	}
	// include
	option1 = Subsequences(in.substr(1),out+in[0],dp);
	// exclude
	option2 = Subsequences(in.substr(1),out,dp);
	ans = option1 + option2;
	dp[len_in][len_out]= ans;
	return ans;
}

int main()
{
	int t,n,i;
	cin >> t;
	while(t>0)
	{
		string str;
		cin >>str;
		n= str.length();
		
		int **dp = new int*[n+1];
		for(int i=0;i<=n;i++){
			dp[i]=new int[n+1];
			for(int  j=0;j<=n;j++){
				dp[i][j]=-1;
			}
		}
		int ans = Subsequences(str,"",dp);
		cout << ans << endl;		
		t--;
	}
}