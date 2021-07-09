//
// Created by wk on 2021/7/9.
//

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& friends, int i, vector<bool>& visited){
    visited[i] = true;
    for (int j = 0; j < friends.size(); ++j) {
        if(friends[i][j] == 1 && !visited[j]){
            dfs(friends,j,visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& friends){
    int size = friends.size();
    int count = 0;
    vector<bool> visited(size, false);
    for (int i = 0; i < size; ++i) {
        if(!visited[i]){
            dfs(friends,i,visited);
            ++count;
        }
    }
    return count;
}

int main(){
    vector<vector<int>> friends ={{1,1,0},
                                  {1,1,0},
                                  {0,0,1}};
    int friends_circles = findCircleNum(friends);
    cout << "Friends Cricles is: " << friends_circles << endl;
}