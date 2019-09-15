//
// Created by wangkai on 2019/9/15.
//
/*
 * �˿��Ƶ�˳��
 * ���˿�������������ƣ��ж��ǲ���һ��˳�ӣ�2-10λ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13����С��Ϊ0�����Կ�����������
 *
 * ˼·��
 * ��������ͳ�������Ŀ��ͳ�Ʒ���Ԫ�صļ����С��ע���Ƿ��ж��ӳ���
 */
#include <iostream>
#include <algorithm>
#include <vector>
using  namespace std;

bool isContinuous(vector<int> data){
    if(data.size()<=0){
        return false;
    }
    //����
    sort(data.begin(),data.end());
    //ͳ���������������
    int zero=0;
    for (int i = 0; i <data.size()&&data[i]==0; ++i) {
        ++zero;
    }
    //ͳ�Ƽ����Ŀ ���Ϊ������������ data[i+1]-data[i]-1;
    int a=0;
    for (int j = 0; j <data.size()-1 ; ++j) {
        //�ж��Ƿ�Ϊ����
        if(data[j]==data[j+1]){
            return false;
        }
        a+=data[j+1]-data[j]-1;
    }
    //�Ƚ�zero��a
    if(a<=zero){
        return true;
    } else{
        return false;
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
    if(isContinuous(data)) {
        cout<<"˳��";
    } else{
        cout<<"����˳��";
    }
}
