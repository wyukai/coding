//
// Created by wangkai on 2019/9/8.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void findNumsAppearOnce(vector<int> data,int *num1,int *num2){
    map<int,int> m;
    for (int i = 0; i < data.size(); ++i) {
        m[data[i]]++;
    }
    bool flag= true;
    for (int i = 0; i < data.size(); ++i) {
        if(m[data[i]]==1&&!flag){
            *num2=data[i];
        }
        cout<<endl;
        if(m[data[i]]==1&&flag){
            *num1=data[i];
            flag= false;
        }
    }
}
int main(){
    vector<int> data;
    while (1){
        int temp;
        cin>>temp;
        data.push_back(temp);
        if(cin.get()=='\n'){
            break;
        }
    }
    int n=0;
    int m=1;
    int *num1=&n;
    int *num2=&m;
    findNumsAppearOnce(data,num1,num2);
    cout<<*num1<<" "<<*num2;
    return 0;
}