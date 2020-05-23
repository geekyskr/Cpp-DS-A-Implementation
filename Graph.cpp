#include<iostream>
#include<queue>     //for bfs
using namespace std;
void printDFS(int **e, int n, int s, bool *visited)
{
    cout<<s<<" ";
    visited[s] = true;
    for(int i=0; i<n; i++){
        if(i==s){
            continue;
        }
        if(e[s][i]==1){
            if(visited[i]==true)continue;
            printDFS(e, n, i, visited);
        }
    }
}
void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        cout<<q.front()<<" ";
        for(int i=0; i<n; i++){
            if(!visited[i] and edges[q.front()][i]){
                q.push(i);
                visited[i] = true;
            }
        }
        q.pop();
    }
}
int main()
{
    int v, e;
    cin>>v>>e;
    
    // making a 2d array of vxv with 0
    int **el = new int*[v];
    for(int i=0; i<v; i++){
        el[i] = new int[v];
        for(int j=0; j<v; j++)el[i][j]=0;
    }
    
    // taking input from user as a list and marking in el matrix 
    //0, 3 means edge between 1st and 4th node
    for(int i=0; i<e; i++){
        int f, s;
        cin>>f>>s;
        el[f][s] = 1;
        el[s][f] = 1;
    }
    bool *visited = new bool[v];
    for(int i=0; i<v; i++)visited[i]=false;
    printDFS(el, v, 0, visited);
    cout<<endl;
    for(int i=0; i<v; i++)visited[i]=false;
    printBFS(el, v, 0, visited);
    
    //memory deallocation
    delete []visited;
    for(int i=0; i<v; i++)delete []el[i];
}
