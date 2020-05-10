#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data){
        this->data = data;
    }
};
void printLinkedList(node *head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
node *myLinkedList(int s){
    int h;
    cin>>h;
    node *head = new node(h);
    node *tail = head;
    s--;
    while(s!=0){
        int t;
        cin>>t;
        node *temp = new node(t);
        tail->next = temp;
        tail = tail->next;
        s--;
    }
    return head;
}
int findMiddle(node* head)
{
    node* slow = head;
    node* fast = head;
    while(fast!=NULL  and fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
    }
    return slow->data;
}
int lastElement(node *head){
    node *temp = head;
    while(temp->next!=NULL)temp = temp->next;
    return temp->data;
}
int main()
{
    int n;  //size
    cin>>n;
    node *head = myLinkedList(n);   //taking n inputs
    printLinkedList(head);
    cout<<findMiddle(head)<<endl;
    cout<<lastElement(head)<<endl;
    delete head;
}
