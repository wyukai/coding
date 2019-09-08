//
// Created by wangkai on 2019/9/5.
//
#include <iostream>
#include <vector>

using namespace std;


int partSort(vector<int> &data,int start,int end){
    int left=start;
    int right=end;
    int base=data[left];
    while (left<right){
        //从右边开始找到比base小的数
        while (left<right&& data[right]>=base){
            --right;
            //cout<<"right: "<<right;
        }
        //从左边开始找到比base大的数
        while(left<right&&data[left]<=base){
            ++left;
            //cout<<"left: "<<left;
        }

        if(left<right){
            swap(data[left],data[right]);
        }
    }
    //基准归位
    //cout<<data[left];
    swap(data[left],data[start]);
    //cout<<data[left];

    return left;
}

int getMidNumber(vector<int> &data){
    int size=data.size();
    int mid=(size-1)/2;
    int index=partSort(data,0,size-1);
    while (index!=mid){
        if(mid<index){
            index=partSort(data,0,index-1);
        }
        else{
            index=partSort(data,index+1,size-1);
        }
    }
    //cout<<"index::"<<index;
    return data[index];
}
int main(){
    int temp;
    vector<int> data;
    while (1){
        cin>>temp;
        data.push_back(temp);
        if(cin.get()=='\n'){
            break;
        }
    }
    for (int i = 0; i < data.size(); ++i) {
        cout<<data[i]<<" ";
    }
    int mid=getMidNumber(data);
    cout<<"mid: "<<mid;
}
