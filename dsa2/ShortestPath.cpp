#include <bits/stdc++.h>
using namespace std;

class shortPath {
    private:
        void topoDfs(int node, int vis[], stack<int> &st, vector<vector<pair<int,int>>> &adj){
            vis[node] = 1;
            for(auto it : adj[node]){
                if(!vis[it.first]){
                    topoDfs(it.first, vis, st, adj);
                }
            }
            st.push(node);
        }
    public:
        // Function to find the shortest path in a graph using topological sorting
        // 1 -> topological sort the graph
        // 2 -> relax the edges in topological order
        // 3 -> return the distance array
        vector<int> shortestPath(int V, vector<vector<int>> &edges, int source){
            vector<vector<pair<int,int>>> adj;
            for(int i = 0; i < V; i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                adj[u].push_back({v,w});
            }

            //step 1
            int vis[V] = {0};
            stack<int> st;
            
            for(int i = 0; i < V; i++){
                if(!vis[i]){
                    topoDfs(i, vis, st, adj);
                }
            }

            //step 2
            vector<int> dist(V, INT_MAX);
            dist[source] = 0;
            while(!st.empty()){
                int node = st.top();
                st.pop();
                for(auto it : adj[node]){
                    int v = it.first;
                    int w = it.second;
                    if(dist[node] + w < dist[v]){
                        dist[v] = dist[node] + w;
                    }
                }
            }
            return dist;
        }

};

int main() {return 0;}