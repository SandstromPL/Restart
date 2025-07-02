#include <bits/stdc++.h>
using namespace std;

class topoSort {

    public:
    // Function to perform topological sort using DFS
    void dfs(int node, vector<vector<int>> & adj, vector<bool> &visited, stack<int> &st){
        visited[node] = true;
        for(auto &neighbour : adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, adj, visited, st);
            }
        }
        st.push(node);
    }

    // Function to perform topological sort using Kahn's algorithm -> BFS
    vector<int> kahn(int V, vector<vector<int>> &adj){
        vector<int> indegree(V,0);
        for(int i = 0; i < V; i++){
            for(auto &it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto &neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        return topo;
    }

};

int main() {return 0;}