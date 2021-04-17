//
// Created by wk on 2021/4/15.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points){
    int size = points.size();
    if(size <= 1){
        return size;
    }
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){ return a[1] < b[1];});

    int arrow = 1;
    int prev = points[0][1];
    for(int i = 1; i < size; i++){
        if(points[i][0] > prev){
            arrow++;
            prev = points[i][1];
        }
    }
    return arrow;

}

int main(){
    vector<vector<int>> points = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
    int minArrows = findMinArrowShots(points);
    cout << "minArrows ::" <<minArrows <<endl;
    return 0;
}