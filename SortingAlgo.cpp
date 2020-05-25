#include<iostream>
using namespace std;


void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


void merging(int *a, int start, int mid, int end, int *ans)
{
    int i = start;
    int j = mid+1;
    int k = start;
    while(i<=mid and j<=end){
        if(a[i]<a[j]){
            ans[k] = a[i];
            i++;
        }
        else{
            ans[k] = a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=end){
            ans[k]  =a[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            ans[k] = a[i];
            i++;
            k++;
        }
    }
    for(i=start; i<=end; i++)a[i] = ans[i];
}
void mergeSort(int *a, int lb, int ub, int *ans)
{
    if(lb>=ub)return;
    int mid = (lb+ub)/2;
    mergeSort(a, lb, mid, ans);
    mergeSort(a, mid+1, ub, ans);
    merging(a, lb, mid, ub, ans);
}
void mergeSort(int *a, int s)
{
    int *ans = new int[s];
    mergeSort(a, 0, s-1, ans);
}


int partition(int *a, int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while(start<end){
        while(a[start]<=pivot)start++;
        while(a[end]>pivot)end--;
        if(start<end)swap(&a[start], &a[end]);
    }
    swap(&a[lb], &a[end]);
    return end;
}
void quickSort(int *a, int lb, int ub)
{
    if(lb>=ub)return;
    int loc = partition(a, lb, ub);
    quickSort(a, lb, loc-1);
    quickSort(a, loc+1, ub);
}
void quickSort(int *a, int s)
{
    quickSort(a, 0, s-1);
}


void insertionSort(int *a, int s)
{
    for(int i=1; i<s; i++){
        int t = a[i];
        int j;
        for(j=i-1; j>=0; j--){
            if(a[j]>t)a[j+1] = a[j];
            else break;
        }
        a[j+1] = t;
    }
}


int minIndex(int *a, int s, int e)
{
    int ans = s;
    for(int i=s; i<=e; i++){
        if(a[i]<a[ans])ans = i;
    }
    return ans;
}
void selectionSort(int *a, int s)
{
    for(int i=0; i<s-1; i++){
        int currIndex = i;
        int swapIndex = minIndex(a, i, s-1);
        swap(&a[currIndex], &a[swapIndex]);
    }
}


void bubbleSort(int *a, int s)
{
    for(int i=0; i<s; i++){
        for(int j=0; j<s-(i+1); j++){
            if(a[j]>a[j+1])swap(&a[j], &a[j+1]);
        }
    }
}


int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0; i<n; i++)cin>>a[i];
    bubbleSort(a, n);
    selectionSort(a, n);
    insertionSort(a, n);
    quickSort(a, n);
    mergeSort(a, n);
    for(int i=0; i<n; i++)cout<<a[i]<<" ";
    cout<<endl;
}
