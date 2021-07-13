//
// Created by wk on 2021/7/12.
//

/*
 * O(1) 空间复杂度下去除重复点
 */

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicate(vector<int>& numbers){
    int size = numbers.size();
    if(size == 0){return 0;}
    int i = 0;
    for(int n = 1; n < size; ++n) {
        if (numbers[i] != numbers[n]) {
            ++i;
            numbers[i] = numbers[n];
        }
    }
    return i + 1;
}

int main(){
    vector<int> numbers = {1,1,2,2,3,5,6,6};
    int len = removeDuplicate(numbers);
    cout << "len :" << len << endl;
    for(int i = 0 ; i < len; ++i){
        cout << numbers[i] << " " ;
    }
}