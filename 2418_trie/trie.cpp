#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

struct treenode{
    string treestring;
    int counts;
    treenode *lnode,*rnode;
}*root;
int allcounts;

int insert(string in){
    if(root==NULL){
        root=new treenode;
        root->treestring=in;
        root->counts=1;
        root->lnode=NULL;
        root->rnode=NULL;
    }
    else{
        treenode *p=root;
        treenode *newn=new treenode;
        newn->treestring=in;
        newn->counts=1;
        newn->lnode=NULL;
        newn->rnode=NULL;
        while(p!=NULL){
            if(in=p->treestring){
                    p->counts++;
                    break;
            }
            else if(in<p->treestring){
                if(p->lnode!=NULL)
                    p=p->lnode;
                else{
                    p->lnode=newn;
                    break;
                }
            }
            else{
                if(p->rnode!=NULL)
                    p=p->rnode;
                else{
                    p->rnode=newn;
                    break;
                }
            }
        }
    }
}

int output(treenode *p){
    if(p!=NULL){
    printf("%s %.4f\n",p->treestring.c_str(),(p->counts/(double)allcounts)*100;
    output(p->lnode);
    output(p->rnode);
    }
}
