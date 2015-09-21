#include<iostream>
#include<map>
#include<stdio.h>
#include <string>
using namespace std;
map<string,int> trees;
int main(){
    string tree;
    map<string,int>::iterator it;
    int counts=0;
    while(getline(cin,tree)){
            if(tree=="end")
                break;
        counts++;
        it=trees.find(tree);
        if(it!=trees.end()){
            trees[tree]++;
        }
        else{
            trees.insert(pair<string,int>(tree,1));
        }
    }
    it=trees.begin();
    while(it!=trees.end()){
        string first=it->first;
        double second=(it->second/(double)counts)*100;
        printf("%s %.4f\n",first.c_str(),second);
        it++;
    }
    return 0;
}
