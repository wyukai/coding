//
// Created by Administrator on 2021/4/16.
//

/*
 * ��һ������������������ҵ���������ʹ���ǵĺ�Ϊ����ֵ����֪����ֻ��һ�Խ⡣
 *
 * ��⣺
 * ��Ϊ�����Ѿ��ź������ǿ��Բ��÷����෴��˫ָ����Ѱ�����������֣�һ����ʼָ����
С��Ԫ�أ�����������ߣ����ұ�����һ����ʼָ������Ԫ�أ����������ұߣ����������
�������ָ��ָ��Ԫ�صĺ͵��ڸ���ֵ����ô���Ǿ�������Ҫ�Ľ�����������ָ��ָ��Ԫ
�صĺ�С�ڸ���ֵ�����ǰ���ߵ�ָ������һλ��ʹ�õ�ǰ�ĺ�����һ�㡣�������ָ��ָ��Ԫ
�صĺʹ��ڸ���ֵ�����ǰ��ұߵ�ָ������һλ��ʹ�õ�ǰ�ĺͼ���һ�㡣

 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& v, const int target){
    int size = v.size();
    int start = 0, last = size - 1;
    int sum = 0;
    while (start < last){
        sum = v[start] + v[last];
        if(sum == target) break;
        else if(sum < target){
            start++;
        }
        else{
            last--;
        }
    }
    return vector<int>{start + 1, last + 1};
}

int main(){
    vector<int> v;
    for(int i = 0; ;i++){
        int n;
        cin >> n;
        v.push_back(n);
        if(getchar() == '\n'){
            break;
        }
    }
    int target;
    cin >> target;

    vector<int> index_v = twoSum(v, target);
    cout<< index_v[0] <<" "<<index_v[1]<<endl;


}