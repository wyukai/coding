//
// Created by Administrator on 2021/6/18.
//

#include <iostream>

using namespace std;

int mySqrt(int a){
    if(a == 0) return a;
    int left = 1, right = a, mid, sqrt;
    while (left <= right){
        mid = left + (right - left) / 2;
        sqrt = a / mid;
        if(sqrt == mid){
            return mid;
        }
        else if(sqrt < mid){
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }
    return right;

}

int main(){
    int a = 16;
    int sqrt = mySqrt(a);
    cout<< sqrt <<endl;
    return 0;
}