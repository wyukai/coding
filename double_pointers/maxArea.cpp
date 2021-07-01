//
// Created by Administrator on 2021/6/16.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int maxArea(vector<int>& height){
    int size = height.size();
    int left = 0;
    int right = size - 1;
    int maxWater = min(height[left], height[right]) * (right - left);

    while(left < right){
        if(height[left] < height[right]){
            ++left;
        }
        else{
            --right;
        }
        maxWater = max(maxWater, min(height[left], height[right]) * (right - left));
    }

    return maxWater;
}


int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int maxWater = maxArea(height);
    cout<< "max Water :: "<<maxWater<<endl;
}