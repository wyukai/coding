//
// Created by wangkai on 2019/9/2.
//



/*
 * 归并排序：
 * 归并是指将若干个已排序的子文件合并成一个有序的文件。
 * 常见的有两路归并排序，多路归并排序 Strand排序。
 *
 * 两路归并排序
 * 最差时间复杂度：O(nlogn)
 * 平均时间复杂度：O(nlogn)
 * 最差空间复杂度：O(n)
 * 稳定排序
 */

/*
 * 思路：
 * 分治：
 * 1. 分解 ： 将当前区间一分为二，求分裂点
 * 2. 求解 ： 递归地对两个子区间L[low,mid]和R[mid+1,high]进行归并排序
 * 3. 组合 ： 将已排序的两个子区间归并为一个有序区间R[low,high]
 *
 *递归的终结条件 ： 子区间的长度为1
 */

/*
 * 归并操作：
 * 1. 申请两个与已经排序序列相同大小的空间，并将两个序列拷贝其中
 * 2. 设定最初位置分别为两个已经拷贝排序序列的起始位置，比较两个序列元素的大小，
 *    依次选择相对小的元素的元素放到原始序列；
 * 3. 重复2直到某一拷贝序列全部放入原始序列，将另一个序列剩下的元素直接复制到原始序列尾部
 *
 */

#include <iostream>
#include <vector>
using namespace std;

void merge(int *a,int left,int mid,int right){
    int nl=mid-left+1; //左边序列元素个数
    int nr=right-mid; //右边序列元素个数
    //申请两个与已经排序序列相同大小的空间，并将两个序列拷贝其中
    int *L =new int[nl+1];
    int *R =new int[nr+1];
    for (int i = 0; i < nl; ++i) {
        L[i]=a[left+i];
    }
    for (int j = 0; j < nr; ++j) {
        R[j]=a[mid+1+j];
    }
    L[nl]=11111111;
    R[nr]=11111111;
    // 数组L从0~n1-1存放，第n1个存放int型所能表示的最大数，即认为正无穷，这是为了
    //处理合并时，比如当数组L中的n1个元素已经全部按顺序存进数组a中，只剩下数组R的
    //部分元素，这时因为R中剩下的元素全部小于11111111,则执行else语句，直接将剩下的
    //元素拷贝进a中。
    for (int i=0,j=0,k = left; k <=right ; ++k) {
        if(L[i]<=R[j]){
            a[k]=L[i++];
        } else{
            a[k]=R[j++];
        }
    }
    delete []L;
    delete []R;
}
void mergeSort(int *a,int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    for (int j = 0; j < n; ++j) {
        cout<<a[j]<<" ";
    }
    return 0;
}