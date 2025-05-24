#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to return Breadth First Traversal of given graph.
      vector<int> bfs(vector<vector<int>> &adj) {
          // Code here
          vector<int> visited(adj.size(), 0);
          queue<int> neighbours;
          vector<int> resultArray;
          visited[0] = 1;
          neighbours.push(0);
          while(!neighbours.empty()) {
              // get neighbour from queue
              int node = neighbours.front();
              neighbours.pop();
              // add visited neighbour to queue
              resultArray.push_back(node);
              // explore its neighbours and mark visited
              for(auto neighbour : adj[node]) {
                  if(visited[neighbour]!=1){
                      visited[neighbour] = 1;
                      neighbours.push(neighbour);
                  }
              }
          }
          return resultArray;
      }
  };