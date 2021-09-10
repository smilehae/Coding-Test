#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<pair<string,pair<string,string>>>tags;
    int n,q;
    string str,tag,attr,value,dummy;
    string tagNum="";
    char ch;
    cin>>n>>q;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,str);
        stringstream ss(str);
        ss>>tag;
        if(tag[1]!='/'){
            tagNum += tag[4];
            cout<<tagNum<<"\n";
            cout<<"\nadding about tag "<<tagNum<<"\n";
            while(ss>>attr){
                ss>>dummy>>ch>>value;
                if(value[value.size()-1]=='>'){
                    value.erase(value.size()-2,value.size());
                }
                else{
                    value.erase(value.size()-1,value.size());
                }
                cout<<attr<<" = "<<value<<"\n";
                tags.push_back(make_pair(tagNum,make_pair(attr,value)));
                cout<<"putting tag"<<tagNum<<" "<<attr<<" = "<<value<<"\n";
            }
        }
        else{
            int pos = tagNum.find(tag[5]);
            tagNum.erase(pos,1);
            cout<<"pos : "<<pos<<"\n";
            cout<<"tagNum : "<<tagNum<<"\n";
        }
        
    } 

    cout<<"showing vectors...\n";
    for(int i=0;i<tags.size();i++){
        cout<<"tag "<<tags[i].first<<" "<<tags[i].second.first<<" = "<<tags[i].second.second<<"\n";
    }

    for(int i=0;i<q;i++){
        getline(cin,str);
    }
    return 0;
}
