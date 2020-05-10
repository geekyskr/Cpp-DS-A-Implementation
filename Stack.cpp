#include<iostream>
using namespace std;
class stack
{
    public:
    int arr[100];
    int top;
    stack(){
        top = -1;
    }
    void push(int data){
        if(top==99){
            cout<<"Stack overflow\n";
        }
        else{
        top++;
        arr[top] = data;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack underflow\n";
        }
        else{
        top--;
        }
    }
    int Top(){
        if(top==-1)return 0;
        return arr[top];
    }
    bool isEmpty(){
        if(top==-1)return true;
        return false;
    }
};
int main()
{
    stack s;
    s.push(10);
    cout<<s.Top()<<endl;
    cout<<s.isEmpty()<<endl;
    s.pop();
    s.pop();
}
