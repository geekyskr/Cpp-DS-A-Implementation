#include<bits/stdc++.h>
using namespace std;
void swapElement(int *a, int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
class PriorityQueues
{
    vector<int> pq;
    public:
    PriorityQueues(){
        
    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty())return INT_MIN;
        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int ci = pq.size()-1;
        while(ci>0){
            int pi = (ci-1)/2;
            if(pq[ci]<pq[pi]){
                swapElement(&pq[ci], &pq[pi]);
            }
            else{
                break;
            }
            ci = pi;
        }
    }
    int removeMin()
    {
        if(pq.size()==0)return INT_MIN;
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        
        int pi = 0;
        int lci = 2*pi+1;
        int rci = 2*pi+2;
        while(lci<pq.size()){
            int mi = pi;
            if(pq[mi]>pq[lci]){
                mi = lci;
            }
            if(rci<pq.size() and pq[lci]>pq[rci]){
                mi = rci;
            }
            if(mi==pi){
                break;
            }
            swapElement(&pq[mi], &pq[pi]);
            pi = mi;
            lci = 2*pi+1;
            rci = 2*pi+2;
        }
        return ans;
    }
};
int main()
{
    PriorityQueues  p;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        p.insert(t);
    }
    cout<<p.getSize()<<" "<<p.getMin()<<endl;
    while(!p.isEmpty()){
        cout<<p.removeMin()<<" ";
    }
    return 0;
}
