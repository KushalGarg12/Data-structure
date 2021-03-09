#include<iostream>
#include<bits/stdc++.h>
#include<vector>


using namespace std;
void dfs( int );
vector<int> arr[100001];
int vis[100001];
 //DFS
void dfs(int node)
{
	vis[node] = 1;
    cout<<node<<" ";
	for(int child : arr[node])
	if(!vis[child])
	dfs(child);
 
}




int main()
{
 int N=6;
    int M=7;
    int a,b;
    
    while(M--)
    {
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=0;i<N;i++)
    {
         cout<<"vertex"<<i<<"->";
        for(int node:arr[i])
        {
            cout<<node<<" ";
            
        }
        cout<<endl;
    }
 //count number of connected components
 int cc = 0;
 
	for(int i=0;i<N;i++)
	if(!vis[i])
	dfs(i) , cc++;
 
	cout<<cc;
    

    
    return 0;
    
}




