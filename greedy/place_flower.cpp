//
// Created by wk on 2021/4/14.
//

#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowered, int& n){
    int size = flowered.size();
    //贪心策略：查看当前位置的左右两侧，若没有花朵，则当前位置可以种植花朵
    for(int i = 0; i < size; i++ ){
        if(flowered[i] == 0 && (flowered[i-1] == 0 || i == 0) && (flowered[i+1] == 0 || i == size - 1)){
            flowered[i] = 1;
            --n;
        }
    }
    return  n<=0;
}

int main(){
    vector<int> flowered = {0,0,1,0,1};
    int n = 1;
    bool canPlace = canPlaceFlowers(flowered,n);
    cout<< "canPlaceFlowers  :" << canPlace<<endl;
    return 0;
}