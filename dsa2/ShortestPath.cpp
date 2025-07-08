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

        // Function to find the shortest path in a graph using Dijkstra's algorithm -> priority queue
        vector<int> dijkstra(int V, vector<vector<int>> &edges, int source){
            vector<vector<pair<int,int>>> adj;
            for(int i = 0; i < V; i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                adj[u].push_back({v,wt});
                //adj[v].push_back({u,wt}); // for undirected graph
            }

            vector<int> dist(V,INT_MAX);
            dist[source] = 0;
            
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({dist[source], source});

            while(!pq.empty()){
                int node = pq.top().second;
                int d = pq.top().first;
                pq.pop();

                for(auto it : adj[node]){
                    int v = it.first;
                    int wt = it.second;

                    if(d + wt < dist[v]){
                        dist[v] = d + wt;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        }

        // Function to find the shortest path in a graph using dijkstra's algorithm -> set
        vector<int> dikjstra(int V, vector<vector<pair<int,int>>>& adj, int source){
            vector<int> dist(V,INT_MAX);
            set<pair<int,int>> s;
            dist[source] = 0;
            s.insert({0,source});

            while(!s.empty()){
                auto it = *(s.begin());
                int node = it.second;
                int d = it.first;
                s.erase(it);

                for(auto it : adj[node]){
                    int adjNode = it.first;
                    int wt = it.second;

                    if(d + wt < dist[adjNode]){
                        if(dist[adjNode] != INT_MAX)
                            s.erase({dist[adjNode],adjNode});
                        dist[adjNode] = d + wt;
                        s.insert({dist[adjNode],adjNode});
                    }
                }
            }
            return dist;
        }

        // Function to find the shortest path in a graph using Bellman-Ford Algorithm
        vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src] = 0;
        
        for(int i = 1; i <= V - 1; i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        
        return dist;
    }

    // Function to find the shortest path in a graph using Floyd-Warshall Algorithm
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] != 1e8 && dist[k][j] != 1e8)
                        dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }
    }

};

int main() {return 0;}