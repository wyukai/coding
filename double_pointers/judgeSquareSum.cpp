//
// Created by Administrator on 2021/5/11.
//
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool judgeSquareSum(int c){
    long i = 0;
    long j = (int)sqrt(c);
    cout << j << endl;

    while(i <= j){
        long sum = i * i + j * j;
        if(sum < c){
            i++;
        }
        else if(sum > c){
            j--;
        } else{
            return true;
        }
    }
    return false;
}

int main(){
    bool s = judgeSquareSum(9);
    cout << 9 << "  "<< s << endl;
}