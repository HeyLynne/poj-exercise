#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<stack>

using namespace std;

typedef struct BST{
    char data;
    BST *left;
    BST *right;
}BST;
typedef struct BST_flag{
    BST* aBST;
    bool isfirst;
}BST_flag;
string s1;
string s2;
BST *head;
stack<BST_flag *> BST_stack;

BST* BST_build(int root,string s){
    if(s.empty())
        return NULL;
    else{
    BST *item=(BST *)malloc(sizeof(BST));
    item->data=s1[root];
    int lo2=s.find(s1[root]);
    item->left=BST_build(root+1,s.substr(0,lo2));
    item->right=BST_build(root+lo2+1,s.substr(lo2+1,s.length()-lo2-1));
    return item;
    }
}

void  post_order(BST *head){
    BST *BST_root=head;
    BST_flag *temp;
    while(BST_root!=NULL||!BST_stack.empty()){
        while(BST_root!=NULL){
            BST_flag *aBST_flag=(BST_flag *)malloc(sizeof(BST_flag));
            aBST_flag->aBST=BST_root;
            aBST_flag->isfirst=true;
            BST_root=BST_root->left;
        }
        if(!BST_stack.empty()){
            temp=BST_stack.top();
            BST_stack.pop();
            if(temp->isfirst==true){
                temp->isfirst=false;
                BST_stack.push(temp);
                BST_root=temp->aBST->right;
            }
            else{
                cout<<BST_root->data;
                BST_root=NULL;
            }
        }
    }
}

int main(){
    while(scanf("%s %s",&s1,&s2)!=EOF){
        head=NULL;
        head=(BST*)malloc(sizeof(BST));
        char *s01=s1.c_str();
        char *s02=
        //cout<<s1<<endl;
        //cout<<s1[0]<<endl;
        //cout<<s2<<endl;
        head->data=s1.c_str(0);
        int lo1=s2.find(s1[0]);
        head->left=BST_build(1,s2.substr(0,lo1));
        head->right=BST_build(lo1+1,s2.substr(lo1+1,s2.length()-lo1-1));
        post_order(head);
        cout<<endl;
    }
}
