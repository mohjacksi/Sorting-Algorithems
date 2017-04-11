//
//  main.cpp
//  Sorting Algorithems
//
//  Created by Mohammed Jacksi on 4/10/17.
//  Copyright © 2017 Mohammed Jacksi. All rights reserved.
//

#include <iostream>
using namespace std;

// print array
void print(int arr[],int size){
    for (int i = 0; i<size; i++)
        cout<<arr[i]<<"  ";
    cout<<endl;
}

// 1 bubble sorting
void BubbleSort(int arr[],int size){
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < size-1 ;i++)
        {
            if (arr[i]>arr[i+1]) {
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i]=temp;
                flag = true;
            }
        }
    }
    print(arr,size);
    
}

// 2 Insertion Sotring
void InsertionSorting(int arr[],int size){
    for (int i = 1; i<size; i++) {
        int hole = i;
        int val = arr[i];
        while (hole > 0  &&  arr[hole-1] > val) {
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=val;
    }
    print(arr, size);
}

// 3 Selection Sorting
void SelectionSorting(int arr[],int size){
    for (int i = 0; i<size-1; i++) {
        int min = i;
        for (int j = i+1; j<size; j++) {
            if (arr[min]>arr[j])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    print(arr,size);
}

// 4 merge - part 1
void Merge(int arr[],int beg,int mid,int end){
    int i ,j, k, a[50];
    i=beg;
    k=beg;
    j=mid+1;
    while (i<=mid && j<=end) {
        if (arr[i]<arr[j]) {
            a[k]=arr[i];
            k++;
            i++;
        }else{
            a[k]=arr[j];
            k++;
            j++;
        }
    }
    
    while (i<=mid) {
        a[k]=arr[i];
        k++;
        i++;
    }
    while (j<=end) {
        a[k]=arr[j];
        k++;
        j++;
    }
    
    for (int i = beg; i<k; i++) {
        arr[i] = a[i];
    }
    
}
// 4 merge - part 2
void MergeSorting(int arr[],int beg,int end){
    if (beg < end) {
        int mid = (beg+end)/2;
        MergeSorting(arr,beg,mid);
        MergeSorting(arr, mid+1, end);
        Merge(arr,beg,mid,end);
    }
}



// 5 Quick Sort - part 1
int Partition(int arr[],int beg,int end)
{
    int p = beg,
    pivot = arr[end];
    for (int i = beg; i<end; i++) {
        if (arr[i] <= pivot) {
            int temp = arr[p];
            arr[p] = arr[i];
            arr[i] = temp;
            
            p++;
        }
    }
    int temp = arr[end];
    arr[end] = arr[p];
    arr[p] = temp;
    
    return p;
}
// 5 Qucik Sort - part 2
void QuickSorting(int arr[],int beg,int end){
    if (beg<end) {
        int pivot = Partition(arr,beg,end);
        QuickSorting(arr, beg, pivot-1);
        QuickSorting(arr, pivot+1, end);
    }
}

// 6 Shell Sort
// soon..
void ShellSorting(int arr[],int size){
    int gap = size/2;
    while (gap>0) {
        for (int i = gap; i<size; i++) {
            int j = i;
            int val = arr[j];
            while (j>gap-1 && arr[j-gap]>val) {
                arr[i]=arr[j-gap];
                j-=gap;
            }
            arr[j]=val;
        }
        gap/=2;
    }
}

int main(int argc, const char * argv[]) {
    
    int arr[]={5,3,4,2,1};
    cout<<"before    ";
    print(arr, 5);
    
    cout<<"Bubble    ";
    BubbleSort(arr, 5);
    
    cout<<"Insertion ";
    InsertionSorting(arr, 5);
    
    cout<<"selection ";
    SelectionSorting(arr, 5);
    
    cout<<"merge     ";
    MergeSorting(arr,0,4);
    print(arr, 5);
    
    cout<<"Quick     ";
    QuickSorting(arr,0,4);
    print(arr, 5);
    
    cout<<"Shell     ";
    ShellSorting(arr,5);
    print(arr, 5);
    
    return 0;
}
