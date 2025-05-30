#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    void breadthFirstSearch(vector<vector<int>> &adj) {
        vector<int> visited(adj.size(), 0);
        queue<int> neighbours;
        visited[0] = 1;
        neighbours.push(0);
        while(!neighbours.empty()) {
            int node = neighbours.front();
            neighbours.pop();
            cout<<node<<" ";
            for(auto neighbour : adj[node]) {
                if(visited[neighbour] != 1) {
                    visited[neighbour] = 1;
                    neighbours.push(neighbour);
                }
            }
        }
    }
    
    void dfs(vector<vector<int>> &adj, vector<int> &visited, int startNode) {
        visited[startNode] = 1;
        cout<<startNode<<" ";
        for(auto neighbour : adj[startNode]) {
            if(visited[neighbour] != 1) {
                dfs(adj, visited, neighbour);
            }
        }
        
    }
    
    void depthFirstSearch(vector<vector<int>> &adj) {
        vector<int> visited(adj.size(), 0);
        dfs(adj, visited, 0);
    }
};

int main() {
    vector<vector<int>> adj = {{1, 2}, {0, 3}, {0, 4}, {1, 4}, {2, 3, 5}, {4}};
    Solution solution;
    solution.depthFirstSearch(adj);
    
}