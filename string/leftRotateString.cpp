//
// Created by wangkai on 2019/9/15.
//


#include <iostream>
#include <string>
using namespace std;

//解法一：三步反转
void Reverse(string &str,int from,int to){
    while(from<to){
        char t=str[from];
        str[from++]=str[to];
        str[to--]=t;
    }
}
string LeftRotateString(string str, int n) {
    Reverse(str,0,n-1);
    Reverse(str,n,str.size()-1);
    Reverse(str,0,str.size()-1);
    return str;
}
//解放2：库函数实现
//string LeftRotateString(string str, int n) {
//    string str1;
//    str1=str.substr(0,n);
//    str.erase(0,n);
//    return str+str1;
//}

int main(){
    string s;
    cin>>s;
    string n=LeftRotateString(s,2);
    cout<<s<<" "<<endl;
    cout<<n;
}