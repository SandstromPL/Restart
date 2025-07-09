#include<bits/stdc++.h>
using namespace std;

class MST {

    public:
        int primsAlgo(int node,vector<vector<pair<int,int>>>& adj){
            vector<bool> vis(adj.size(),0);
            vis[node] = 1;
            priority_queue<pair<int,int> , vector<pair<int,int>>, 
            greater<pair<int,int>>> pq; // -> {distance,node}
            
        }

};

int main(){return 0;}