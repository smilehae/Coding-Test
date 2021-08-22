#include <string>
#include <vector>
#include <iostream>
#include <map>
#include<algorithm>
#include<queue>

using namespace std;

bool cmp(const pair<string,int>& a, const pair<string,int>& b){
        if(a.second == b.second) return a.first<b.first;
        return a.second < b.second;
    }

bool cmpPairVec(const pair<int,pair<string,int>>& a, const pair<int,pair<string,int>>& b){
    if(a.second.second==b.second.second) return a.first<b.first;
    return a.second.second>b.second.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    vector<int> answer;
    map<string,int>genreMap;
    vector<pair<int,pair<string,int>>>songVec;
   
    for(int i=0;i<genres.size();i++){
        genreMap[genres[i]]+=plays[i];
    }

    for(int i=0;i<genres.size();i++){
        songVec.push_back(make_pair(i,make_pair(genres[i],plays[i])));
    }

    vector<pair<string,int>> genreVec(genreMap.begin(),genreMap.end());
    sort(genreVec.begin(),genreVec.end(),cmp);
    sort(songVec.begin(),songVec.end(),cmpPairVec);

    while(genreVec.size()!=0){
        string genre = genreVec.back().first;
        genreVec.pop_back();
        int count=0;

        for(int i=0;i<songVec.size();i++){
            if(songVec[i].second.first!=genre)continue;
            answer.push_back(songVec[i].first);
            count++;
            if(count>=2)break;
        }
    }
    
    return answer;
}

int main(){
    vector<string> mygenre={"classic","pop","classic","classic","pop"};
    vector<int> myplay={500,600,150,800,2500};

    vector<int>mysol = solution(mygenre,myplay);
    for(int elem : mysol){
        cout<<elem<<" ";
    }
}


/*
 장르별로 노래를 2개씩 모아서 앨범 출시.
 더 많이 재생된 장르를 먼저 수록.

*/