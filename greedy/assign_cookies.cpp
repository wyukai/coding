//
// Created by wk on 2021/4/13.
//

/*
Assign Cookies(Easy)
问题描述：
   有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个孩子只能吃
最多一个饼干，且只有饼干的大小大于孩子的饥饿度时，这个孩子才能吃饱。求解最多有多少孩
子可以吃饱。
题解：
    因为饥饿度最小的孩子最容易吃饱，所以我们先考虑这个孩子。为了尽量使得剩下的饼干可
以满足饥饿度更大的孩子，所以我们应该把大于等于这个孩子饥饿度的、且大小最小的饼干给这
个孩子。满足了这个孩子之后，我们采取同样的策略，考虑剩下孩子里饥饿度最小的孩子，直到
没有满足条件的饼干存在。
    简而言之，这里的贪心策略是，给剩余孩子里最小饥饿度的孩子分配最小的能饱腹的饼干。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& children, vector<int>& cookies){
    //sort
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    //search
    int child = 0, cookie = 0;
    while(child < children.size() && cookie < cookies.size()){
        if(children[child] <= cookies[cookie]) ++child;
        ++cookie;
    }
    return child;
}

int main(){
    //child input
    vector<int> child_v;
    for(int i = 0; ; i++){
        int child;
        cin >> child;
        child_v.push_back(child);
        if(getchar() == '\n') {
            break;
        }
    }
    //cookie input
    vector<int> cookie_v;
    for(int i = 0; ; i++){
        int cookie;
        cin >> cookie;
        cookie_v.push_back(cookie);
        if(getchar() == '\n'){
            break;
        }
    }

    //print
    for(int i = 0; i < child_v.size(); i++){
        cout<<child_v[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < cookie_v.size(); i++){
        cout<<cookie_v[i]<<" ";
    }
    cout<<endl;

    int contentChild;
    contentChild = findContentChildren(child_v,cookie_v);
    cout << "contentChild  ::"<< contentChild;


    return 0;
}
