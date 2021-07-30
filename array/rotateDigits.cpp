//
// Created by wk on 2021/7/30.
//
/*
 * 788 旋转数字
 * 我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。
 * 如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；
 * 2 和 5 可以互相旋转成对方（在这种情况下，它们以不同的方向旋转，换句话说，2 和 5 互为镜像）；
 * 6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。

现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？

 输入: 10
输出: 4
解释:
在[1, 10]中有四个好数： 2, 5, 6, 9。
注意 1 和 10 不是好数, 因为他们在旋转之后不变。
 */
#include <iostream>
#include <vector>

using namespace std;

bool valid(int n){
    int flag = 0;
    while(n){
        int t = n % 10;
        if(t == 3 || t == 4 || t == 7) return 0;
        if(t == 2 || t == 5 || t == 6 || t == 9) flag = 1;
        n /= 10;

    }
    return flag;
}

int rotateDigits(int n){
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if(valid(i)) ++count;
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    int count = rotateDigits(n);
    cout << count << endl;
    return count;
}