#include<bits/stdc++.h>
using namespace std;

class traversal{
    private:

    public:
    //BFS Traversal
    void bfs(int start , vector<vector<int>> &adj,vector<bool> &visited){
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout << node << " ";
            for(auto &neighbour : adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;  
                    q.push(neighbour);              
                }
            }
        }
    }

    //DFS Traversal
    void dfs(int start , vector<vector<int>> &adj , vector<bool> &visited){
        visited[start] = true;
        cout<<start<<" ";
        for(auto &neighbour : adj[start]){
            if(!visited[neighbour]){
                dfs(neighbour , adj, visited);
            }
        }
    }
};

int main(){return 0;}
