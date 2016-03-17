#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool findword(vector<vector<char> >& board,string word,vector<vector<bool> >& visited,int line,int col,int index){
    if(index=word.size()) return true;
    if(col<0||line<0||line>=board.size()||col>=board[0].size()||board[line][col]!=word[index]||visited[line][col])
        return false;
    visited[line][col]=1;
    if(findword(board,word,visited,line-1,col,index+1)) return true;
    if(findword(board,word,visited,line+1,col,index+1)) return true;
    if(findword(board,word,visited,line,col-1,index+1)) return true;
    if(findword(board,word,visited,line,col+1,index+1)) return true;
    visited[line][col] = false;
    return false;
}


int main(){
    vector<char> inboard(1,'a');
    vector<vector<char> > board(1,inboard);
    string word="ab";
    if(board.empty()||board[0].empty()){
        return false;
    }
    vector<vector<bool> > visited(board.size(),vector<bool>(board[0].size(),false));
    int i,j;
    int line=board.size();
    int col=board[0].size();
    for(i=0;i<line;i++){
        for(j=0;j<col;j++){
            if(findword(board,word,visited,i,j,0))
                return true;
        }
    }
    return false;
}
