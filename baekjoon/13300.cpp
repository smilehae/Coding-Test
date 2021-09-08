#include <iostream>
#include <math.h>

/*
방 배정하기.
남학생끼리 여학생끼리, 같은 학년끼리. 한방에 한 명만 배정 가능
한방의 최대 인원 k. 모든 학생 배정하는 최소 방 수.
*/

using namespace std;
int people[12];

int main(){
    int n, k;
    int ans=0;

    cin>>n>>k;

    for(int i=0;i<n;i++){
        int gender,year;
        cin>>gender>>year;
        if(gender==1){
            people[year-1]++;
        }
        else{
            people[year-1+6]++;
        }
    }

    for(int i=0;i<12;i++){
        ans += ceil((double)people[i]/(double)k);
    }

    cout<<ans;
}