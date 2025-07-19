/**
 * @file Rock_Climbing.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2025-06-18
 * @copyright Copyright (c) 2025
 * @problem: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing
 * @tag: dfs, recursion, grid
 */
#include<bits/stdc++.h>
using namespace std;
typedef double dl;
#define ll long long int
#define endl "\n" 


ll n,m;


ll minimum_difficulty=11;

void min_difficulty(int x, int y,vector<vector<int>>& grid,vector<vector<int>>& vis,int max_diff_till_now){
    if(x<0 || y<0 || x>=n || y>=m || vis[x][y]!=0 || grid[x][y]==0)return;
    else if(grid[x][y]==3){
        if(minimum_difficulty>max_diff_till_now) minimum_difficulty=max_diff_till_now;
    }

    else{
        vis[x][y]=1;
        int up=x-1;
        while(up>=0 && grid[up][y]==0){
            up--;
        }

        if(up>=0 && grid[up][y]!=0 && vis[up][y]==0){
            min_difficulty(up,y,grid,vis,max(max_diff_till_now,x-up));
        }

        int down=x+1;
        while((down)<n && grid[down][y]==0){
            down++;
        }
        
        if((down)<n && grid[down][y]!=0 && vis[down][y]==0){
        
            min_difficulty(down,y,grid,vis,max(max_diff_till_now,down-x));
        }


        if((y+1)<m && grid[x][y+1]!=0 && vis[x][y+1]==0){
            min_difficulty(x,y+1,grid,vis,max_diff_till_now);
        }
        if((y-1)>=0 && grid[x][y-1]!=0 && vis[x][y-1]==0){
            min_difficulty(x,y-1,grid,vis,max_diff_till_now);
        }

        vis[x][y]=0;
    }

}
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    minimum_difficulty=11;
    vector<vector<int>> grid(n, vector<int>(m,0));
    vector<vector<int>> vis(n, vector<int>(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j]=0;
            cin>>grid[i][j];

        }
    }
    min_difficulty(n-1,0,grid,vis,0);
    cout<<minimum_difficulty<<endl;

    return 0;
}