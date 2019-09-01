//
// Created by wangkai on 2019/9/1.
//

/*
 * 把只包含因子2，3，和5的数称作丑数，求按从小到大的顺序的第N个数。
 */

#include <iostream>
using namespace std;

//判断一个数是不是丑数
bool isUglyNumber(int number){
    while (number%2==0){
        number/=2;
    }
    while (number%3==0){
        number/=3;
    }
    while (number%5==0){
        number/=5;
    }
    return (number==1)? true: false;
}

//一次判断直到找到第N个丑数
int getUglyNumber(int n){
    if(n<=0){
        return 0;
    }
    int counter=0;
    int number=0;
    while (counter<n){
        number++;
        if (isUglyNumber(number)){
            counter++;
        }
    }
    return number;
}

int main(){
    int n;
    cin>>n;
    cout<<"第N个丑数是："<<getUglyNumber(n);
    return 0;
}