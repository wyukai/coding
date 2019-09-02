//
// Created by wangkai on 2019/9/2.
//

/**
 * 想比较两个数在最终结果中的先后位置，何不直接比较一下不同组合的结果大小？
   举个例子：要比较3和34的先后位置，可以比较334和343的大小，而343比334大，所以34应当在前。
   这样，有了比较两个数的方法，就可以对整个数组进行排序。然后再把排好序的数拼接在一起就好了。
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//排序依据，任意两个string连接之后满足 a+b>b+a
bool cmp(string a, string b){
    return a+b>b+a;
}

string largestNumber(vector<int> &nums){
    string res="";
    if(nums.empty()){
        return res;
    }
    //将int容器里的每一个数字转化为string
    vector<string> s;
    for(auto i:nums){
        s.push_back(to_string(i));
    }
    //对string里的元素进行排序，依据是cmp函数
    sort(s.begin(),s.end(),cmp);
    //将结果进行连接
    for(auto item:s){
        res+=item;
    }
    //特殊情况处理
    while (res[0]=='0'&&res.length()>1){
        res.erase(0,1);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    string res=largestNumber(a);
    cout<<res;
    return 0;
}
