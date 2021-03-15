#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> ar[1000001];
vector<int> primes;

int dist[1000001],vis[1000001];

bool isPrime(int n)
{
    for (int i=2;i*i<=n;i++)
    
        if(n%i==0) return false;
        
        return true;
    
}

bool isvalid(int a,int b)
{
    int cnt=0;
    
    while(a>0)
    {
        if(a%10!=b%10) cnt++;
        
        a /=10 ,b/=10;
    }
    if(cnt==1) return true;
    
    else 
    return false;
}
void buildgraph()
{
    for(int i=1000;i<9999;i++)
    {
        if(isPrime(i))
        primes.push_back(i);
    }
    
    for (int i=0;i<primes.size();i++)
    {
        for(int j=i+1;j<primes.size();j++)
        {
            int a=primes[i];
            int b=primes[j];
            
            if(isvalid(a,b))
            ar[a].push_back(b),ar[b].push_back(a);
            
        }
    }
}


void bfs(int src)
{
    queue<int> q ;
    q.push(src);
    
    dist[src]=0;
    vis[src]=1;
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int child:ar[curr])
        {
            if(vis[child]==0)
            {
                vis[child]=1;
                
                dist[child]=dist[curr]+1;
                q.push(child);
            }
        }
    }
}

int main()
{
    int t,a ,b;
    cout<<"Enter the number of test cases";
    cin>>t;
    buildgraph();
    cout<<"Enter the two prime numbers: ";
    
    while(t--)
    {
        
        cin>>a>>b;
        for(int i=1000;i<9999;i++) dist[i]=-1,vis[i]=0;
        
        bfs(a);
        
        if(dist[b]==-1)
        cout<<"Impossible";
        
        else
        cout<<dist[b]<<endl;
        
        
    }
}