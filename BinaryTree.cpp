#include<iostream>
#include<queue>
using namespace std;
template < typename T > class BinaryTreeNode
{
public:
  T data;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
  BinaryTreeNode (T data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
  ~BinaryTreeNode ()
  {
    delete left;
    delete right;
  }
};

void
printTree (BinaryTreeNode < int >*root)
{
  if (root == NULL)
    return;
  if (root->left != NULL and root->right != NULL)
    cout << root->data << " : L" << root->left->data << ", R" << root->right->
      data << endl;
  else if (root->left == NULL and root->right == NULL)
    cout << root->data << endl;
  else if (root->left == NULL)
    cout << root->data << " : R" << root->right->data << endl;
  else
    cout << root->data << " : L" << root->left->data << endl;
  printTree (root->left);
  printTree (root->right);
}
BinaryTreeNode<int> *UserInput()
{
    //if user give 0 as NULL. 0 is termination point. we don't allow to use 0 as tree data.
    // for user input 1 2 0 0 3 0 0 this tree will e like 1, 2, 3 in preorder; 2, 1, 3 in inorder.
    int data;
    cin>>data;
    if(data==0)return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int> *leftC = UserInput();
    BinaryTreeNode<int> *rightC = UserInput();
    root->left = leftC;
    root->right = rightC;
    return root;
}
BinaryTreeNode<int> *UserInputLevelwise()
{
    int data;
    cout<<"Enter root data\n";
    cin>>data;
    if(data==0)return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()){
        int frontNode  = pendingNodes.front()->data;
        int leftChild;
        cout<<"Write left child of "<<frontNode<<endl;
        cin>>leftChild;
        if(leftChild!=0){
            BinaryTreeNode<int>* leftC = new BinaryTreeNode<int>(leftChild);
            pendingNodes.front()->left = leftC;
            pendingNodes.push(leftC);
        }
        int rightChild;
        cout<<"Write right child of "<<frontNode<<endl;
        cin>>rightChild;
        if(rightChild!=0){
            BinaryTreeNode<int>* rightC = new BinaryTreeNode<int>(rightChild);
            pendingNodes.front()->right = rightC;
            pendingNodes.push(rightC);
        }
        pendingNodes.pop();
        
    }
    return root;
}
int main ()
{
  /*BinaryTreeNode < int >*root = new BinaryTreeNode < int >(1);
  BinaryTreeNode < int >*node1 = new BinaryTreeNode < int >(2);
  BinaryTreeNode < int >*node2 = new BinaryTreeNode < int >(3);
  root->left = node1;
  root->right = node2;*/
  
  //BinaryTreeNode<int> *root = UserInput();
  BinaryTreeNode<int> *root = UserInputLevelwise();
  printTree (root);
  delete root;
  return 0;
}
