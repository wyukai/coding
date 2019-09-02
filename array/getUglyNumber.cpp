//
// Created by wangkai on 2019/9/1.
//

/*
 * ��ֻ��������2��3����5���������������󰴴�С�����˳��ĵ�N������
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * ֱ�ӷ� �ж�ÿһ�����ǲ��ǳ�����ʱ�临�Ӷȸߣ�
 * @param number
 * @return
 */
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
/**
 * ������ ��һ������洢�Ѿ��ź���ĳ�������һ������һ����ǰ��ĳ���������� 2��3����5�������������С�ߡ�
 * �ռ任ʱ��
 * @return
 */

int getUglyNumber2(int index){
    if(index<=0){
        return 0;
    }
    vector<int> numbers(index,0);
    numbers[0]=1;
    int t2=0,t3=0,t5=0;
    for (int i = 1; i < index; ++i) {
        numbers[i]=min(numbers[t2]*2,min(numbers[t3]*3,numbers[t5]*5));
        if(numbers[i]==numbers[t2]*2) ++t2;
        if(numbers[i]==numbers[t3]*3) ++t3;
        if(numbers[i]==numbers[t5]*5) ++t5;
    }
    return numbers[index-1];
}
int main(){
    int n;
    cin>>n;
    cout<<"��N�������ǣ�"<<getUglyNumber(n);
    return 0;
}