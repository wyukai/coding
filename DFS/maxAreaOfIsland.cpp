//
// Created by wk on 2021/7/9.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> directions = {-1,0,1,0,-1};

/*
 * 在辅函数里，一个一定要注意的点是辅函数内递归搜索时，边界条件的判定。边界判定一般
有两种写法，一种是先判定是否越界，只有在合法的情况下才进行下一步搜索（即判断放在调用
递归函数前）；另一种是不管三七二十一先进行下一步搜索，待下一步搜索开始时再判断是否合
法（即判断放在辅函数第一行）
 */
//递归写法
int dfs(vector<vector<int>>& grid, int i, int j){
    // 边界情况
    if(grid[i][j] == 0){
        return 0;
    }
    //已经访问过的陆地置为0
    grid[i][j] = 0;
    int x, y , area = 1;
    //在四个方向上进行搜索
    for(int n = 0; n < 4; ++n){
        x = i + directions[n];
        y = j + directions[n + 1];
        //注意考虑越界情况
        if(x >= 0 && x < grid.size() && y >= 0 && y< grid[0].size()){
            area += dfs(grid, x, y);
        }
    }
    return area;
}

int maxAreaOfIsland(vector<vector<int>> grid){
    // 判断边界及异常情况
    if(grid.empty() || grid[0].empty()){
        return 0;
    }
    //遍历
    int max_area = 0;
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
            //当遇到陆地时，开始深度优先遍历上下左右相连的陆地
            if(grid[i][j] == 1) {
                max_area = max(max_area, dfs(grid, i, j));
            }
        }
    }
    return max_area;

}

// 栈实现深度优先搜索
int maxAreaOfIsland_2(vector<vector<int>> grid){
    int area=0, local_area = 0;
    int m = grid.size();
    int n = grid[0].size();
    int x, y;
    //循环搜索
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            //探索岛屿
            if(grid[i][j]){
                local_area = 1;
                //访问过的岛屿置为0
                grid[i][j] = 0;
                stack<pair<int, int>> island;
                island.push({i,j});
                while (!island.empty()){
                    auto [r,c] = island.top();
                    island.pop();
                    for(int k = 0; k < 4; ++k){
                        x = r + directions[k];
                        y = c + directions[k + 1];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                            grid[x][y] = 0;
                            ++local_area;
                            island.push({x,y});
                        }
                    }
                }
                area = max(area, local_area);
            }
        }
    }
    return area;
}


int main(){
    vector<vector<int>> isLand = {{1,0,1,1,0,1,0,1},
                                  {1,0,1,1,0,1,1,1},
                                  {0,0,0,0,0,0,0,1}};
    int max_area = maxAreaOfIsland(isLand);
    cout << "max island is : "<<max_area << endl;

    int max_area_2 = maxAreaOfIsland_2(isLand);
    cout << "max island is : "<<max_area_2 << endl;
}