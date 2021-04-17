//
// Created by wk on 2021/4/14.
//
/*
 * 给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
 *
 * 题解：
 * 在选择要保留区间时，区间的结尾十分重要：选择的区间结尾越小，余留给其它区间的空间
就越大，就越能保留更多的区间。因此，我们采取的贪心策略为，优先保留结尾小且不相交的区
间。
具体实现方法为，先把区间按照结尾的大小进行增序排序，每次选择结尾最小且和前一个选
择的区间不重叠的区间。我们这里使用 C++ 的 Lambda，结合 std::sort() 函数进行自定义排
序。

 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int eraseOverlapIntervals(vector<vector<int>>& intervals){
    if(intervals.empty()){
        return 0;
    }
    int size = intervals.size();

    //按区间结尾排序，采取的贪心策略为优先保留结尾小且不相交的区间
    sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b){return a[1]<b[1];});

    int total = 0;
    int prev = intervals[0][1];
    for(int i = 1; i < size; i++){
        if(intervals[i][0] < prev){
            total++;
        }
        else{
            prev = intervals[i][1];
        }
    }
    return total;
}


int main() {
    vector<vector<int>> intervals = {{1, 2},
                                     {2, 3},
                                     {3, 4}};
    int eraseNum = eraseOverlapIntervals(intervals);
    cout << eraseNum <<endl;

    return 0;
}
