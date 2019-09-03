//
// Created by wangkai on 2019/9/3.
//
#include <iostream>
#include <vector>
using namespace std;
long countRes;

void MergeArray(vector<int>& data,int first,int mid,int end,vector<int> tmp){
    int i = first;int m = mid;
    int j = mid + 1;int n = end;

    while(i<=m && j<=n){
        if(data[i] > data[j]){
            tmp.push_back(data[i++]);
            countRes += n - j + 1;
        }
        else{
            tmp.push_back(data[j++]);
        }
    }
    while(i<=m)
        tmp.push_back(data[i++]);
    while (j<=n)
        tmp.push_back(data[j++]);

    //更新data数组
    int k = 0;
    for (int i = first; i <= end &&k<tmp.size(); i++)
        data[i] = tmp[k++];
}

void MergeSort(vector<int>& data,int first,int end){
    if(first < end){
        int mid = (first + end)/2;
        //cout<<mid;
        MergeSort(data,first,mid);
        MergeSort(data,mid+1,end);
        vector<int> tmp;
        MergeArray(data,first,mid,end,tmp);
    }
}

int InversePairs(vector<int> &data) {
    countRes = 0;
    if(data.size() == 0)
        return 0;
    MergeSort(data,0,data.size()-1);
    return countRes%1000000007 ;
}

int main(){
    int n;
    cin>>n;
    vector<int> data(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>data[i];
    }

    cout<<InversePairs(data);


}
