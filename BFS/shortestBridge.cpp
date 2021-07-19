//
// Created by wk on 2021/7/19.
//
/*
 * 934. Shortest Bridge
Input: grid = [[0,1],[1,0]]
Output: 1

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void dfs(queue<pair<int,int>>& points,vector<vector<int>>& grid, int m, int n, int i, int j);
//定义搜索方向
vector<int> directions = {-1,0,1,0,-1};

int shortBrige(vector<vector<int>>& grid){
    int row = grid.size(), col = grid[0].size();
    //定义第一个岛屿的所有点为BFS的第一层级
    queue<pair<int,int>> points;
    // dfs 寻找第一个岛屿，并把所有的1改为2
    bool flag =  false;
    for (int i = 0; i < row; ++i) {
        if(flag) break;
        for (int j = 0; j < col; ++j) {
            if(grid[i][j] == 1){
                dfs(points,grid, row, col, i, j);
                flag = true;
                break;
            }
        }
    }
    // BFS搜索第二个岛屿
    int x,y;
    int distance = 0;
    while(!points.empty()){
        int size = points.size();
        distance += 1;
        for (int i = 0; i < size; ++i) {
            auto [r,c] = points.front();
            points.pop();
            for (int j = 0; j < 4; ++j) {
                 x = r + directions[j];
                 y = c + directions[j+1];
                 if(x >= 0 && x < row && y >=0 && y < col){
                     if(grid[x][y] == 2){
                         continue;
                     }
                     if(grid[x][y] == 1){
                         return distance -1;
                     }
                     // 下一遍历层级
                     points.push({x,y});
                     // 已经遍历过的位置置为2
                     grid[x][y] = 2;
                 }

            }
        }
    }
    return 0;
}

void dfs(queue<pair<int,int>>& points,vector<vector<int>>& grid, int m, int n, int i, int j){
    if( i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1){
        return;
    }
    grid[i][j] = 2;
    points.push({i,j});
    int x,y;
    for (int k = 0; k < 4; ++k) {
        x = i + directions[k];
        y = j + directions[k+1];
        dfs(points,grid, m, n , x, y);
    }
}

int main(){
//    vector<vector<int>> grid = {{1,1,1,1,1},
//                                {1,0,0,0,1},
//                                {1,0,1,0,1},
//                                {1,0,0,0,1},
//                                {1,1,1,1,1}};
    vector<vector<int>> grid = {{0,1,0},{0,0,0},{0,0,1}};
    int min_distance = shortBrige(grid);
    cout << min_distance << endl;
}