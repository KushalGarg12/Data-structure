#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>

using namespace std;

class graph{
  int v;
  list<int> *l;
  unordered_map<int,int> visited;
    queue<int> q;
  
  public:
    graph(int v)
    {
        this->v=v;
        l=new list<int> [v];
    }
    
    void edge(int x,int y )
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    void print()
    {
        for(int i=0;i<v;i++)
        {
            cout<<"vertex"<<i<<"->";
            for(int nbr:l[i])
            {
                cout<<nbr<<" ";
            }
            cout<<endl;
        }
    }
    
    
    //BFS


void BFS(int src)
{
    
    
    q.push(src);
    visited[src]=true;
    
    while(!q.empty())
    {
        int node=q.front();
        cout<<node<<" ";
        q.pop();
        
        for(int nbr:l[node])
        {
            if(!visited[nbr]){
            q.push(nbr);
            
            visited[nbr]=true;
        }}
    }
}



};



int main()
{
    graph g(4);
    g.edge(0,1);
    g.edge(0,2);
    g.edge(1,2);
    g.edge(2,3);
    
    g.print();
    
    g.BFS(0);
    return 0;
}
