#include<bits/stdc++.h>
using namespace std;

class cycleDetection {
    public:
    // Function to detect cycle in an undirected graph using BFS
    bool bfs(int start , vector<vector<int>> &adj, vector<bool> &visited){
        queue<pair<int,int>> q; // ds -> {node , parent of node}
        q.push({start, - 1});
        visited[start] = true;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto &neighbour : adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push({neighbour, node});
                }else if(neighbour != parent){
                    return true;
                }
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph using DFS
    bool dfs(int node , int parent,vector<vector<int>> &adj, vector<bool> &visited){
        visited[node] = true;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                if(dfs(neighbour, node, adj, visited)) {
                    return true;
                } else if(neighbour != parent){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    cycleDetection cd;
    return 0;
}