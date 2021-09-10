#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> reserveSure(n+1); 
    vector<int> hasCloth(n+1,1);     
    
    //여벌 체육복 있는지 확실히 확인 ( 도난 목록에 있는지 확인)
    for(int i=0;i<reserve.size();i++){
        reserveSure[reserve[i]]=1; 
        cout<<reserve[i]<<" "<<reserveSure[reserve[i]]<<" think's he has another cloth\n";
    }
    
    for(int i=0;i<lost.size();i++){
        
        if(reserveSure[lost[i]]!=1){
            cout<<lost[i]<<" losted only cloth!\n";
            hasCloth[lost[i]]=0;
        }
        else{
            cout<<lost[i]<<" losted another copy!\n";
        }
        reserveSure[lost[i]]=0;
    }
    
    for(int i=1;i<n+1;i++){
        if(reserveSure[i]==1){
            cout<<i<<" has one more\n";
        }
        if(hasCloth[i]==0){
            cout<<i<<" has no cloth\n";
        }
        else{
            cout<<i<<" has own cloth\n";
        }
    }
  
    cout<<"\n";
    for(int i=1;i<=n;i++){
        if(reserveSure[i]==1){
            cout<<i<<"has cloth.\n";
            if(i==1 || hasCloth[i-1]==1 && hasCloth[i+1]==0){
                hasCloth[i+1]=1;
                cout<<"gave cloth to i+1 : "<<i+1<<"\n";
            }
            else if(i==n || hasCloth[i+1]==1 && hasCloth[i-1]==0){
                hasCloth[i-1]=1;
                cout<<"gave cloth to i-1 : "<<i-1<<"\n";
            }
            //만약 양쪽 다 비었지만, 한쪽이 자기 자신만 갈 수 있다면 그쪽으로
            else if(i==2) hasCloth[1]=1;
            else if(i==n-1) hasCloth[n]=1;
            else{
                hasCloth[i-1]=1;
                cout<<"gave cloth to i-1 : "<<i-1<<"\n";
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(hasCloth[i]==0){
            answer--;
        }
    }
    cout<<"who has cloths?...\n";
    for(int i=0;i<=n;i++){
        cout<<hasCloth[i]<<" ";
    }
    
    return answer;
}