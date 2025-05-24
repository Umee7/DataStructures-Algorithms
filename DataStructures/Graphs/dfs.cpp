#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      void depthFirstSearch(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &resultArray, int startNode) {
          // Mark the node visited 
          visited[startNode] = true;
          resultArray.push_back(startNode);
          // Repeat Process for each neighbour 
          for(auto neighbour : adj[startNode]) {
              if(visited[neighbour]!=true){
                  depthFirstSearch(adj, visited, resultArray, neighbour);
              }
          }
      }
    
      vector<int> dfs(vector<vector<int>>& adj) {
          vector<bool> visited(adj.size(), false);
          vector<int> resultArray;
          int startNode = 0;
          depthFirstSearch(adj, visited, resultArray, startNode);
          return resultArray;
      }
  };