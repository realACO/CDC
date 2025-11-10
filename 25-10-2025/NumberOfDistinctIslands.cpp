#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    void dfs(int i, int j, vector<vector<int>>& grid,
    vector<vector<int>>& visited, vector<pair<int,int>> &temp,
    vector<int> &dr, vector<int> &dc, int baseI, int baseJ){
        int n=grid.size();
        int m=grid[0].size();
        visited[i][j]=1;
        temp.push_back({baseI-i,baseJ-j});//push the index of the land in the temp array
        for(int k=0;k<4;k++){
            int rr=i+dr[k];
            int cc=j+dc[k];
            if(rr>=0 && rr<n && cc>=0 && cc<m && !visited[rr][cc] && grid[rr][cc]==1){
                dfs(rr,cc,grid,visited,temp,dr,dc,baseI,baseJ);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> dr={0,-1,0,1};
        vector<int> dc={-1,0,1,0};
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    //declare a empty array and pass it to the dfs function 
                    // the dfs function will come back with the vector of pair of indeces of all the land traversed by the dfs function
                    //or you can say indeces of a single island
                    vector<pair<int,int>> arr;
                    dfs(i,j,grid,visited,arr,dr,dc,i,j);
                    //we also keep the base index of the island as the the index from where we started the traversal of the island
                    s.insert(arr);
                }
            }
        }
        return s.size();
    }
};

//we will check the distinctive ness of a island by storing the indec {i,j} of a land in a vector and inserting it into a set, the set wil only store thr unique elements and the remaining will not be inserted into the set
//at last return the size of the set, ehich will be number of distinct islands