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

    // Function to detect cycle in a directed graph using DFS
    bool directedDfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> & pathVisited){
        visited[node] = true;
        pathVisited[node] = true;

        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                if(directedDfs(neighbour, adj, visited, pathVisited)){
                    return true;
                }
            }else if(pathVisited[neighbour]){
                return true; // Cycle detected
            }
        }
        // Backtrack
        pathVisited[node] = false;
        return false;
    }

};

int main(){
    cycleDetection cd;
    
/*     for(int i = 0; i < V; i++){
        vector<vector<int>> adj(V); // Adjacency list representation of the graph
        vector<bool> visited(V, false); // Visited array for BFS/DFS
        vector<bool> pathVisited(V, false); // Path visited array for directed graph cycle detection

        // Example usage of BFS cycle detection
        if(cd.bfs(0, adj, visited)){
            cout << "Cycle detected in undirected graph using BFS." << endl;
        } else {
            cout << "No cycle detected in undirected graph using BFS." << endl;
        }

        // Example usage of DFS cycle detection
        if(cd.dfs(0, -1, adj, visited)){
            cout << "Cycle detected in undirected graph using DFS." << endl;
        } else {
            cout << "No cycle detected in undirected graph using DFS." << endl;
        }

        // Example usage of directed DFS cycle detection
        if(cd.directedDfs(0, adj, visited, pathVisited)){
            cout << "Cycle detected in directed graph using DFS." << endl;
        } else {
            cout << "No cycle detected in directed graph using DFS." << endl;
        }
    } */

    return 0;
}