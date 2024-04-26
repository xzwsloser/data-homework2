#include<stdio.h>
#include<stdlib.h>
int binarySearch (int*  arr,int n,int target);
// 二分查找代码实现
int main(){
    int arr[12] = {2,3,5,6,7,8,11,13,15,17,19,21};
    int index = binarySearch(arr,12,11);
    if (index == -1) {
        printf("没有找到对应元素\n");
    } else {
        printf("11 的下标为 %d\n",index);
    }
    return 0;
}

int binarySearch(int* arr,int n,int target) {
    int start = 0;
    int end = n - 1;
    // 假设查找闭区间里面的值
    while(start <= end) {
        int mid = (start  + end) / 2;
        // 假设原来的数组递增
        if (arr[mid] < target) {
            start ++;
        }  else if (arr[mid] > target) {
            end --;
        } else {
            return mid;
        }
    }
    return -1;
}