//
// Created by wk on 2021/8/4.
//
/*
 * 202 快乐数
 * 编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 true ；不是，则返回 false 。

 输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

 输入：n = 2
输出：false
 */

#include <iostream>
#include <vector>

using namespace std;

int func(int n){
    int temp = 0;
    while(n){
        int m = n % 10;
        temp += m * m;
        n /= 10;
    }
    return temp;
}

bool isHappy(int n){
    if(n == 1) return true;
    int slow = n, fast = func(n);
    while(slow != fast){
        fast = func(fast);
        fast = func(fast);
        slow = func(slow);
        if(fast == 1){
            return true;
        }
    }
    return false;
}

int main(){
    int n = 2;
    cout << isHappy(n) <<endl;
}