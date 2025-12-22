#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int,int>>edge(e);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edge[i]={a,b};
    }
    vector<vector<int>>adj(v);
    for(auto it:edge){
        adj[it.first].push_back(it.second);    
        adj[it.second].push_back(it.first); 
    }
    queue<pair<int,int>>q;
    vector<bool>visited(v,false);
    int st=0;
    q.push({0,-1});
    visited[st]=true;
    while(!q.empty()){
        auto [cur,par]=q.front();
        q.pop();
        for(auto it:adj[cur]){
            if(!visited[it]){
                visited[it]=true;
                q.push({it,cur});
            }
            else if(it!=par){
                cout<<"false"<<endl;
                return 0;
            }
        }
    }
    cout<<"true"<<endl;
    //Write you code here
}
