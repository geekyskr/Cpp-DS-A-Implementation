#include<iostream>
using namespace std;


void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


void mergeSort(int *a, int s)
{
    
}


void quickSort(int *a, int s)
{
    
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
