#include<bits/stdc++.h>
using namespace std;


bool GetPath(int **edges,int n,int sv,int ev, bool *visited, vector<int> *vec)
{
	int i;
	visited[sv] = true;
	if(visited[ev] == true)
	{
		return true;
	}
	
	for(i=0;i<n;i++)
	{
		if(i == sv)
		{
			continue;
		}
		if(visited[i] == false && edges[sv][i] == 1)
		{
			bool ans=GetPath(edges,n,i,ev,visited,vec);
			if(ans)
			{
				vec->push_back(i);
				return true;
			}
		}
	}
	return false;	
}


int main()
{
	int n,e,i,j;
	cin >> n >> e;
	
	int **edges = new int*[n];
	
	
	for(i=0;i<n;i++)
	{
		edges[i] = new int[n];
		for(j=0;j<n;j++)
		{
			edges[i][j] = 0;
		}
	}
	
	int f,s;
	for(i=0;i<e;i++)
	{
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	
	bool *visited = new bool[n];
	for(i=0;i<n;i++)
	{
		visited[i] = false;
	}
	
	int sv,ev;
	cin >> sv >> ev;
	
	vector<int> *vec=new vector<int>;
	
	bool ans = GetPath(edges,n,sv,ev,visited,vec);
	
	if(ans)
	{
		for(i=0;i<vec->size();i++)
		{
			cout << vec->at(i) << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "" << endl;
	}
}