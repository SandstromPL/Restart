#include<bits/stdc++.h>
using namespace std;

class bipartiteGraphDetection {

    public:
    // Fuction to check if the graph is bipartite using BFS
    bool bfs(int start , int col , vector<vector<int>> &adj , vector<int> &color){
        queue<int> q;
        q.push(start);
        color[start] = col;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &neighbour : adj[node]){
                if(color[neighbour] == -1){
                    color[neighbour] = !color[node];
                    q.push(neighbour);
                } else if(color[neighbour] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

    //Function to check if the graph is bipartite using DFS
    bool dfs (int node , int col , vector<vector<int>> &adj , vector<int> &color){
        color[node] = col;

        for(auto neighbour : adj[node]){
            if(color[neighbour] == -1){
                if(!dfs(neighbour, !col, adj, color)){
                    return false;
                }else if(color[neighbour] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

};

int main () {return 0;}