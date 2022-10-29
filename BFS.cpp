#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//BFS on Adjacency Matrix
vector<size_t> BFS(const size_t &v, const vector<vector<int>> &G) {
    auto size = G[0].size();
    vector<size_t> path{};
    vector<bool> visited(size, 0);
    queue<size_t> q;
    
    path.push_back(v);
    q.push(v);
    visited[v] = 1;
    
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        
        for(size_t i = 0; i < size; ++i) {
            if(G[u][i] == 1 && visited[i] == 0) {
                path.push_back(i);
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    return path;
}

void Test() {
    //The graph
    vector<vector<int>> G ={{0, 1, 1, 1, 0, 0, 0},
                            {1, 0, 1, 0, 0, 0, 0},
                            {1, 1, 0, 1, 1, 0, 0},
                            {1, 0, 1, 0, 1, 0, 0},
                            {0, 0, 1, 1, 0, 1, 1},
                            {0, 0, 0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 1, 0, 0}};
    auto result = BFS(3, G);
    
    for(auto i : result) {
        cout<<i<<" ";
    } cout<<endl;
}