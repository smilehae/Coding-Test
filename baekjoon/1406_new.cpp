#include <iostream>
#include <list>
#include <string>

using namespace std;

void showList(const list<char>& L){
   
    for(auto it=L.begin();it!=L.end();it++){
        if(it==L.begin()) continue;
        cout<<*it;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int n;
    list<char> myList;
    list<char>::iterator it;
    list<char>::iterator it2;

    cin>>s;
    cin>>n;

    myList.push_back('d');
    it = myList.begin();
    
    for(char elem : s){
        myList.push_back(elem);
        ++it;
        // cout<<*it<<" ";    
    }

    
    for(int i=0;i<n;i++){
       // cout<<"enter order.\n";
        char input;
        cin>>input;
        if(input=='P'){
         //   cout<<"you pressed P. enter word\n";
            char newWord;
            cin>>newWord;
            myList.insert(++it,newWord);
            it--;
           // showList(myList);
        }
        // if(input=='Q'){
        //     cout<<"you pressed Q\n";
        //     cout<<*it;
        //     if(it==myList.begin()) cout<<"it's on begin"<<"\n";
        //     else if(it==myList.end()) cout<<"it's on end"<<"\n";
        // }
        if(input=='L'){
         //  it2 = it;
            if(it!=myList.begin())it--;
          //  cout<<"it's now pointing "<<*it<<"\n";
        }
        if(input=='D'){
            it2 = it;
            if(++it2!=myList.end()) it++;
            //cout<<"it's now pointing "<<*it<<"\n";

        }
        if(input=='B'){
            if(it!=myList.begin()){
                it = myList.erase(it);
                it--;
            }
            
           // showList(myList);
        }
    }


    showList(myList);


}