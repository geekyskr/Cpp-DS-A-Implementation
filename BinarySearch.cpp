// index of element if element found otherwise -1
// element given in ascending order 23 43 67 987 1231 46534 786765
#include<iostream>
using namespace std;

int indexOfElementItrative(int *a, int s, int t)
{
    int start = 0;
    int end = s-1;
    int mid;
    while(start<=end)
    {
        mid = (start+end)/2;
        if(a[mid]==t)return mid;
        if(a[mid]>t)end = mid-1;
        else start = mid+1;
        
    }
    return -1;
}


int indexOfElementRecursive(int *a, int s, int e, int t)
{
    int m = (s+e)/2;
    if(s>e)return -1;
    if(a[m]==t)return m;
    if(a[m]>t)indexOfElementRecursive(a, s, m-1, t);
    else indexOfElementRecursive(a, m+1, e, t);
}


int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)cin>>arr[i];
    int t;
    cin>>t;
    cout<<indexOfElementRecursive(arr, 0, n-1, t)<<endl;
    cout<<indexOfElementItrative(arr, n, t)<<endl;
}
