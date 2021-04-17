//
// Created by Administrator on 2021/4/15.
//
/*
 * 买股票的最佳时间之二
 * 给定一个数组，代表每天的价格,可以不停的买入、卖出，但是只有卖出了才能继续买入.
 * 贪心策略:
 * 只要当前天相对于前一天上涨了，我们就前一天买入，当前天卖出。
 */
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& price){
    int profit = 0;
    for(int i = 1; i < price.size(); i++){
        if(price[i] > price[i-1]){
            profit += price[i] - price[i-1];
        }
    }
    return profit;
}

int main(){
    vector<int> price = {5,4,3,3,3};
    int profit = maxProfit(price);
    cout << profit <<endl;
    return 0;
}