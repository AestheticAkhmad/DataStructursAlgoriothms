#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//DFS on Adjacency Matrix
vector<size_t> DFS(const size_t U, const vector<vector<int>> &G) {
    static auto size = G.size();
    static vector<size_t> path{};
    static vector<bool> visited(size, 0);
    if(visited[U] == 0) {
        path.push_back(U);
        visited[U] = 1;
        for(auto i = 0; i < size; ++i) {
            if(G[U][i] == 1 && visited[i] == 0) {
                DFS(i, G);
            }
        }
    }
    return path;
}

void Test() {
    vector<vector<int>> G ={{0, 1, 1, 1, 0, 0, 0},
                            {1, 0, 1, 0, 0, 0, 0},
                            {1, 1, 0, 1, 1, 0, 0},
                            {1, 0, 1, 0, 1, 0, 0},
                            {0, 0, 1, 1, 0, 1, 1},
                            {0, 0, 0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 1, 0, 0}};
    auto path = DFS(5, G);
    cout<<endl;
    
    for(auto &i : path) {
        cout<<i<<" ";
    } cout <<endl;
}