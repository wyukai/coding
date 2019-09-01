//
// Created by wangkai on 2019/9/1.
//

/*
 * ��ֻ��������2��3����5���������������󰴴�С�����˳��ĵ�N������
 */

#include <iostream>
using namespace std;

//�ж�һ�����ǲ��ǳ���
bool isUglyNumber(int number){
    while (number%2==0){
        number/=2;
    }
    while (number%3==0){
        number/=3;
    }
    while (number%5==0){
        number/=5;
    }
    return (number==1)? true: false;
}

//һ���ж�ֱ���ҵ���N������
int getUglyNumber(int n){
    if(n<=0){
        return 0;
    }
    int counter=0;
    int number=0;
    while (counter<n){
        number++;
        if (isUglyNumber(number)){
            counter++;
        }
    }
    return number;
}

int main(){
    int n;
    cin>>n;
    cout<<"��N�������ǣ�"<<getUglyNumber(n);
    return 0;
}