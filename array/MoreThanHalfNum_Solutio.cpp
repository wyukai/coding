//
// Created by wangkai on 2019/9/1.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * ��Ŀ������
 * ��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
 * ��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
 * ��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
 * @return
 */

//����һ��hash_table ʵ��

int moreThanHalfNum(vector<int> a){
    if(a.size()==0) return 0;
    map<int,int> m;
    int length=a.size();
    //��ϣ���д�����  key= a[i]  value=a[i]�����ֵ���ֵĴ���
    for (int i = 0; i < a.size(); ++i) {
        ++m[a[i]];
    }
    //������ϣ���ж��Ƿ���ڳ������鳤��һ���Ԫ��
    for (auto member:m) {
        if(member.second>length/2){
            return member.first;
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int result=moreThanHalfNum(a);
    cout<<"�����г��ִ����������鳤��һ�������Ϊ��"<<result;
    return 0;

}