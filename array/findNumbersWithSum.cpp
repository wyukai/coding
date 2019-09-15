//
// Created by wangkai on 2019/9/15.
//

/*
 * 和为S的两个数字
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
 * 思路：
 * 双指针法，定义两个指针left,right（标识）指向有序数组的第一位和最后一位，判断其和与S的关系，== 及找到这样的一对数；大于，--right;
 * 小于，++left。
 *
 * 注意边界情况，若数字的长度小于2，则不存在这样一对数。
 */

#include <iostream>
#include <vector>

using  namespace std;

vector<int> findNumbersWithSum(vector<int> data,int sum){
    vector<int> res;
    int size=data.size();
    //边界判断
    if(size<2) return res;
    int left=0,right=size-1;
    while (left<right){
        int s=data[left]+data[right];
        if(s==sum){
            res.push_back(data[left]);
            res.push_back(data[right]);
            break;
        }
        else if(s>sum){
            --right;
        } else {
            ++left;
        }
    }
    return res;
}

int main(){
    int sum;
    cin>>sum;
    vector<int> data;
    while (1){
        int temp;
        cin>>temp;
        data.push_back(temp);
        if(cin.get()=='\n'){
            break;
        }
    }
    vector<int> res=findNumbersWithSum(data,sum);
    cout<<res[0]<<" "<<res[1];

}

