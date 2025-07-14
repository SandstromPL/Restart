#include <bits/stdc++.h>
using namespace std;

class SCC {

    public:
        void dfs(int node, vector<vector<int>>& adj, stack<int>& st, vector<bool>& vis){
            vis[node] = 1;
            for(auto adjNode : adj[node]){
                if(!vis[adjNode]){
                    dfs(adjNode,adj,st,vis);
                }
            }
            st.push(node);
        }

        void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
            vis[node] = 1;
            for(auto adjNode : adj[node]){
                if(!vis[adjNode]){
                    dfs(adjNode,adj,vis);
                }
            }
        }

        int sccCnt (int V, vector<vector<int>>& adj){
            // 1-> do topo dfs
            // 2-> reverse adj
            // 3-> do dfs on stack from step 1
            vector<bool> vis(V,0);
            stack<int> st;
            vector<vector<int>> revAdj(V);
            int cnt = 0;
            // 1
            for(int i = 0; i < V; i++){
                if(!vis[i]){
                    dfs(i,adj,st,vis);
                }
            }

            // 2
            for(int i = 0; i < V; i++){
                for(auto it : adj[i]){
                    revAdj[it].push_back(i);
                }
            }

            // 3
            fill(vis.begin(), vis.end(), 0);
            while(!st.empty()){
                int node = st.top();
                st.pop();
                if(!vis[node]){
                    cnt++;
                    dfs(node,revAdj,vis);
                }
            }

            return cnt;
        }

};

int main() {return 0;}