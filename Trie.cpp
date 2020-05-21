#include<iostream>
using namespace std;


class TrieNode
{
    public:
    char data;
    TrieNode* *children;
    bool isTerminal;
    
    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0; i<26; i++)children[i]=NULL;
        isTerminal = false;
    }
};


class Trie
{
    TrieNode *root;
    
    public:
    
    
    Trie(){
        root = new TrieNode('\0');
    }
    
    
    void insertWord(TrieNode *root, string word){
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }
        int index = word[0]-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child =  root->children[index];   
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertWord(child, word.substr(1));
    }
    void insertWord(string word){
        insertWord(root, word);
    }
    
    
    bool isExist(TrieNode* root, string word){
        if(word.size()==0){
            return root->isTerminal;
        }
        int index = word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)child = root->children[index];
        else return false;
        return isExist(child, word.substr(1));
    }
    bool isExist(string word){
        return isExist(root, word);
    }
    
    
    void removeWord(TrieNode* root, string word){
        if(word.size()==0){
            root->isTerminal = false;
            return;
        }
        int index = word[0]-'a';
        if(root->children[index]!=NULL)removeWord(root->children[index], word.substr(1));
        else return;
        if(root->children[index]==false){
            for(int i=0; i<26; i++){
                if(root->children[index]->children[i]!=NULL)return;
            }
            delete root->children[index];
            root->children[index]=NULL;
        }
    }
    void removeWord(string word){
        removeWord(root, word);
    }
};


int main()
{
    Trie t;
    t.insertWord("or");
    t.insertWord("sunil");
    t.insertWord("dot");
    cout<<t.isExist("and")<<endl;
    t.insertWord("and");
    cout<<t.isExist("and")<<endl;
    return 0;
}
