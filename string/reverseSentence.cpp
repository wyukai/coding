//
// Created by wangkai on 2019/9/15.
//
/*
 * 翻转单词顺序列
 * 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
 * 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
 * 正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
 *
 * 思路：整体反转+局部反转
 */
#include <iostream>
#include <string>
using namespace std;

void reverse(string &str,int s,int e){
    while (s<e){
        swap(str[s++],str[e--]);
    }
}

string reverseSentence(string str){
    if(str.empty()) return "";
    //整体反转
    reverse(str,0,str.size()-1);
    int s=0,e=0;
    int i=0;
    while (i<str.size()){
        while (i<str.size()&&str[i]==' '){
            i++;
        }
        s=e=i;
        while (i<str.size()&&str[i]!=' '){
            e++;
            i++;
        }
        reverse(str,s,e-1);
    }
    return str;
}

int main(){
    string str="I am a student.";

    cout<<str;
    str=reverseSentence(str);
    cout<<str;
}