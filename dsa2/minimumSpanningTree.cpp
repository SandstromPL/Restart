#include<bits/stdc++.h>
using namespace std;

class MST {

    public:
        int primsAlgo(int source,vector<vector<pair<int,int>>>& adj){
            vector<bool> vis(adj.size(),0);
            int mwt = 0;
            priority_queue<pair<int,int> , vector<pair<int,int>>, 
            greater<pair<int,int>>> pq; // -> {wt,node}
            pq.push({0,source});

            while(!pq.empty()){
                int wt = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                vis[node] = 1;
                mwt += wt;

                for(auto it : adj[node]){
                    int adjNode = it.first;
                    int w = it.second;
                    if(!vis[adjNode]){
                        pq.push({w,adjNode});
                    }
                }
            }
        }

};

class DisjointSet {
    // cntr -> rank , parent , size
    // fn -> union , findParent
    private:
        vector<int> rank, parent, size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i = 0; i< n; i++) parent[i] = i;
        }

        int findUltPar(int node){
            if(parent[node] == node){
                return node;
            }else{
                return parent[node] = findUltPar(parent[node]);
            }
        }

        void unionByRank(int u,int v){
            int ultp_u = findUltPar(u);
            int ultp_v = findUltPar(v);

            if(ultp_u == ultp_v) return;
            if(rank[ultp_u] < rank[ultp_v]){
                parent[ultp_u] = ultp_v;
            }else if(rank[ultp_v] < rank[ultp_u]){
                parent[ultp_v] = ultp_u;
            }else{
                parent[ultp_v] = ultp_u;
                rank[ultp_u]++;
            }

        }


};

int main(){return 0;}