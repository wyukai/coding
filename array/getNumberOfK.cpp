//
// Created by wangkai on 2019/9/3.
//
#include <iostream>
#include <vector>
using namespace std;
int getFirstK(vector<int> &data,int k,int start,int end){
    if(start>end){
        return -1;
    }
    int mid=(start+end)/2;
    int midData=data[mid];
    if(midData==k){
        if((mid>0&&data[mid-1]!=k)||mid==0){
            return mid;
        } else{
            end=mid-1;
        }
    } else if(midData>k){
        end=mid-1;
    } else{
        start=mid+1;
    }
    return getFirstK(data,k,start,end);
}
int getLastK(vector<int> &data,int k,int start,int end){
    if(start>end){
        return -1;
    }
    int mid=(start+end)/2;
    int midData=data[mid];
    if(midData==k){
        if((mid>0&&data[mid+1]!=k)||mid==0){
            return mid;
        } else{
            start=mid+1;
        }
    }
    else if(midData<k){
        start=mid+1;
    } else{
        end=mid-1;
    }
    return getLastK(data,k,start,end);
}


int getNumberOfK(vector<int> data,int k){
    int number=0;
    int size=data.size();
    if(size<=0){
        return 0;
    }
    int first=getFirstK(data,k,0,size-1);
    int last=getLastK(data,k,0,size-1);
    if(first>-1&&last>-1){
        number=last-first+1;
    }
    return number;


}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> data(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>data[i];
    }
    cout<<getNumberOfK(data,k);
    return 0;
}
