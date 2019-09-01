//
// Created by wangkai on 2019/9/1.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * 从数组中找出N个数，满足偶数在前奇数在后，偶数间从大到小，奇数间从大到小
 * 输入： 55，66，23，709，87；3
 * 输出： 66，709，87
 * @param a
 * @param n
 * @return
 */
vector<int> func(vector<int> a,int n){
    vector<int> res;
    if(a.empty()||a.size()<n){
        return res;
    }
    vector<int> even;
    vector<int> odd;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i]%2==0){
            even.push_back(a[i]);
        } else{
            odd.push_back(a[i]);
        }
    }
    sort(even.begin(),even.end(),greater<int>());
    sort(odd.begin(),odd.end(),greater<int>());
    even.insert(even.end(),odd.begin(),odd.end());
    return even;
}

int main() {
    string s;
    cin>>s;
    vector<int> a;
    int n=0;
    int tmp=0;
    for (int i = 0; i <s.size(); ++i) {
        if(s[i]!=','&&s[i]!=';'){
            tmp=tmp*10+s[i]-'0';
        }
        if(s[i]==','){
            a.push_back(tmp);
            tmp=0;
        }
        if(s[i]==';'){
            a.push_back(tmp);
            while(i+1<s.size()){
                n=n*10+s[i+1]-'0';
                i++;
            }
            break;
        }
    }

    vector<int> res=func(a,n);
    for (int j = 0; j <n -1; ++j) {
        cout<<res[j]<<",";
    }
    cout<<res[n-1];

    return 0;
}