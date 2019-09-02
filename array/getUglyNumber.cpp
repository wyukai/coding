//
// Created by wangkai on 2019/9/1.
//

/*
 * 把只包含因子2，3，和5的数称作丑数，求按从小到大的顺序的第N个数。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 直接法 判断每一个数是不是丑数，时间复杂度高，
 * @param number
 * @return
 */
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
/**
 * 方法二 用一个数组存储已经排好序的丑数，下一个丑数一定是前边某个丑数乘以 2，3或者5后的三个数的最小者。
 * 空间换时间
 * @return
 */

int getUglyNumber2(int index){
    if(index<=0){
        return 0;
    }
    vector<int> numbers(index,0);
    numbers[0]=1;
    int t2=0,t3=0,t5=0;
    for (int i = 1; i < index; ++i) {
        numbers[i]=min(numbers[t2]*2,min(numbers[t3]*3,numbers[t5]*5));
        if(numbers[i]==numbers[t2]*2) ++t2;
        if(numbers[i]==numbers[t3]*3) ++t3;
        if(numbers[i]==numbers[t5]*5) ++t5;
    }
    return numbers[index-1];
}
int main(){
    int n;
    cin>>n;
    cout<<"第N个丑数是："<<getUglyNumber(n);
    return 0;
}