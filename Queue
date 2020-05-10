#include<iostream>
using namespace std;
class queue
{
    public:
    int q[100];
    int front, rear;
    queue(){
        front = 0;
        rear = 0;
    }
    void push(int d){
        if(rear>=100){
            cout<<"queue overflow\n";
        }
        else{
            q[rear] = d;
            rear++;
        }
    }
    void pop(){
        if(front==rear){
            cout<<"queue underflow";
        }
        else{
            front++;
        }
    }
    int Front(){return q[front];}
    bool isEmpty(){
        if(front == rear)return true;
        return false;
    }
};
int main()
{
    queue q;
    cout<<q.isEmpty()<<endl;
    q.push(10);
    cout<<q.Front()<<endl;
    q.pop();
    q.pop();
}
