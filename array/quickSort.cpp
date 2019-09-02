//
// Created by wangkai on 2019/9/2.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void quickSort(vector<int> &a,int left, int right){
    if(left<right){
        int base=a[left];
        int l=left,r=right;
        while (l!=r){
            while(l<r&&a[r]>=base){
                r--;
            }
            while (l<r&&a[l]<=base){
                l++;
            }
            if(l<r){
                swap(a[l],a[r]);
            }
        }
        //基准数归位
        a[left]=a[l];
        a[l]=base;

        quickSort(a,left,l-1);
        quickSort(a,l+1,right);
    }

}

int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int k = 0; k < n; ++k) {
        cout<<a[k]<<" ";
    }
    cout<<endl;
    quickSort(a,0,n-1);
    for (int j = 0; j < n; ++j) {
        cout<<a[j]<<" ";
    }
    return 0;
}
