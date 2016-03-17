#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include <windows.h>
using namespace std;
class naiveBayes{
public:
    void loadData(){
        ifstream fin(dataFile.c_str());
        if(!fin){
            cout<<"训练数据文件打开失败"<<endl;
           return ;
        }
        while(fin){
            string line;
            getline(fin,line);
            if(line.size()>1){
                stringstream sin(line);
                string s[16];
                int c;
                sin>>c>>s[0]>>s[1]>>s[2]>>s[3]>>s[4]>>s[5]>>s[6]>>s[7]>>s[8]>>s[9]>>s[10]>>s[11]>>s[12]>>s[13]>>s[14]>>s[15];
                //cout<<s1<<" "<<s2<<" "<<c<<endl;
                dataSize++;
                //for(int i=0;i<26;i++)
                    //ym[i]=1;
                if(ym.count(c)>0){
                ym[c]++;
                }else{
                    ym[c]=1;
                }
                for(int i=0;i<16;i++){
                    if(feam.count(s[i])>0){
                        if(feam[s[i]].count(c)>0){
                            feam[s[i]][c]++;
                        }else{
                            feam[s[i]][c]=1;
                        }
                    }else{
                        map<int,int> mt;
                        //for(int i=0;i<26;i++)
                            //mt[i]=1;
                        mt[c]++;
                        feam[s[i]]=mt;
                    }
                }
            }

        }
    }
    void dispModel(){
        cout<<"训练数据总数"<<endl;
        cout<<dataSize<<endl;
        cout<<"分类统计计数"<<endl;
        for(map<int,int>::iterator mi=ym.begin();mi!=ym.end();mi++){
            cout<<mi->first<<" "<<mi->second<<endl;
        }
        cout<<"特征统计计数:"<<endl;
        for(map<string, map<int,int> >::iterator mi=feam.begin();mi!=feam.end();mi++){
            cout<<mi->first<<": ";
            for(map<int,int>::iterator ii=mi->second.begin();ii!=mi->second.end();ii++){
                cout<<"<"<<ii->first<<" "<<ii->second<<"> ";
            }
            cout<<endl;
        }
}
    void predictive(){
        string s[16];
        int i,j;
        double py,tmpmax,tmpsign;
        int ry;
        //string a1[]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"};
        //set<string> a1set(a1,a1+16);
        //set<string> a2set(a2,a2+3);
        ifstream fin("test.txt");
        ofstream fout("result.txt");
        //freopen("result.txt","w",stdout);
        if(!fin){
            cout<<"测试数据文件打开失败"<<endl;
           return ;
        }
        while(fin){
            string line;
            getline(fin,line);
            stringstream sin(line);
            sin>>ry>>s[0]>>s[1]>>s[2]>>s[3]>>s[4]>>s[5]>>s[6]>>s[7]>>s[8]>>s[9]>>s[10]>>s[11]>>s[12]>>s[13]>>s[14]>>s[15];
            predictnumber++;
            py=0.0;
            tmpsign=0;
            for(i=0;i<26;i++){
                py=(double(ym[i])/dataSize);
                for(j=0;j<16;j++)
                    py*=double(feam[s[j]][i])/ym[i];
                if(py>tmpmax){
                    tmpsign=i;
                    tmpmax=py;
                }
            }
            if(tmpsign==ry)
                rightnumber++;
            fout<<ry<<' ';
            for(j=0;j<16;j++)
                fout<<s[j];
            fout<<" 原始:"<<ry<<" 分类结果:"<<tmpsign<<endl;
        }
        fout<<"测试："<<predictnumber<<endl;
        fout<<"正确：" <<rightnumber<<endl;
        fout<<"正确率："<<((double)rightnumber/predictnumber)<<endl;
    }
    naiveBayes(string df="data.txt"):dataFile(df),dataSize(0),predictnumber(0),rightnumber(0){
        for(int i=0;i<26;i++)
            ym[i]=1;

    }
private:
    string dataFile;
    int dataSize;
    int predictnumber;
    int rightnumber;
    //分类->计数
    map<int,int> ym;
    //分类->( 特征->计数 )
    map<string, map<int,int> >feam;
};
int main(){
    naiveBayes nb;
    nb.loadData();
    nb.dispModel();
    nb.predictive();
    //system("pause");
    return 0;
}
