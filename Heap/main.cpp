/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[7]={6, 5, 3, 2, 8, 10, 9};
    int k=3;
    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
   //kth smallest element 
   
    for (int i=0;i<7;i++)
    {
        maxh.push(arr[i]);
        if(maxh.size()>k)
        maxh.pop();
        
        
    }
    cout<< maxh.top()<<endl;
    
    //kth largest element 
    
        for (int i=0;i<7;i++)
    {
        minh.push(arr[i]);
        if(minh.size()>k)
        minh.pop();
        
        
    }
    cout<< minh.top()<<endl;
    
    
    priority_queue<int,vector<int>,greater<int>> minheap;
   
   //k sorted array  
    for(int i=0;i<7;i++)
    {
        minheap.push(arr[i]);
        if(minheap.size()>k)
        {
           cout<<minheap.top()<<" ";
           minheap.pop();
        }
      
    }
    while(!minheap.empty())
    {
        cout<<minheap.top()<<" ";
        minheap.pop();
    }
    
    
    //k closest numbers
    int k1=4,x=35;
    int arr1[]={12, 16, 22, 30, 35, 39, 42, 
               45, 48, 50, 53, 55, 56};
    priority_queue<pair<int,int>> maxheap;
    cout<<endl;
    for(int i=0;i<13;i++)
    {
        maxheap.push({abs(arr1[i]-x),arr1[i]});
        if(maxheap.size()>k1)
        maxheap.pop();
        
        
    }
    while(!maxheap.empty())
    {
        cout<<maxheap.top().second<<" ";
        maxheap.pop();
        
    }
    cout<<endl;
    
    //frequency sort
    
    priority_queue<pair<int,int>> freq;
   unordered_map<int,int> mp;
    int arr2[]= {1,1,1,2,5,6,7,2,6,5,6,5,5};
    for(int i=0;i<13;i++)
    {
        mp[arr2[i]]++;
    }
    for(auto itr=mp.begin();itr!= mp.end();itr++)
    {
        freq.push({itr->second,itr->first});
    }
    while(freq.size()>0){
        int fr=freq.top().first;
        int number=freq.top().second;
        for (int i=0;i<fr;i++)
        {
            cout<<number<<" ";
        }
        freq.pop();
    }
    
return 0;
}


