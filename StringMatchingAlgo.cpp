#include<iostream>
#include<vector>
using namespace std;


//store the index of string where matching is start and return in vector.


bool isMatch(string s, string t, int start, int end)
{
    int j =0;
    int i = start;
    while(i<=end){
        if(s[i]!=t[j])return false;
        i++;
        j++;
    }
    return true;
}
vector<int> naiveAlgo(string s, string t)   // time complexity = O(m*(n-m+1))
{
    vector<int> ans;
    int w = t.size()-1;
    for(int i=0; i<s.size()-w; i++) if(isMatch(s, t, i, i+w))ans.push_back(i);
    return ans;
}


int main()
{
    string str;
    cin>>str;
    string test;
    cin>>test;
    vector<int> ans = naiveAlgo(str, test);
    //vector<int> ansKMP = kmpAlgo(str, test);
    //vector<int> ansRK = rabinKarpAlgo(str, test);
    if(ans.size()==0)cout<<"-1\n";
    if(ans.size()!=0){
        for(int i:ans)cout<<i<<" ";
        cout<<endl;
        //for(int i:ansKMP)cout<<i<<" ";
        //cout<<endl;
        //for(int i:ansRK)cout<<i<<" ";
        //cout<<endl;
    }
    return 0;
}
