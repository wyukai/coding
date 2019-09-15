//
// Created by wangkai on 2019/9/15.
//
/*
 * 和为S的连续正数序列
 * 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
 * 但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
 * 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
 * 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
 *
 * 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
 *
 *
 * 思路：
 * 以求和为9的所有连续序列为例，
 * 初始化left=1,right=2. 和为3，小于9，所以让right++；
 * 如果left到right的和大于9, 减去left ,left++;
 * 相等的话，输出一个序列，加上right++；
 */
#include <iostream>
#include <vector>
using  namespace std;

vector<vector<int>> findContinuousSequence(int sum){
    vector<vector<int>> res;
    if(sum<3) return  res;
    int left=1,right=2;
    int middle=(sum+1)/2;
    int curSum=left+right;
    while (left<middle){
        vector<int> data;
        if(curSum==sum){
            int i=left;
            while (i<=right){
                data.push_back(i);
                i++;
            }
            res.push_back(data);
            curSum+=++right;
        }
        else if(curSum<sum){
            curSum+=++right;
        }
        else{
            curSum-=left++;
        }
    }
    return res;
}

int main(){
    int sum;
    cin>>sum;
    vector<vector<int>> res=findContinuousSequence(sum);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

}