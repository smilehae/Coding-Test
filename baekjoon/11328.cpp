/*
    백준 11328. 두 문자열이 strfry ( 위치를 바꾸는 함수)로 같아질 수 있는지 보기

    방법1. algorithm으로 정렬해서, 두개가 같은지 확인
    방법2. 배열 2개를 선언하고 각각 알파벳 갯수를 넣어서 같은지 확인 
*/

#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int n;
    char str1[1001];
    char str2[1001];


    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",str1);
        scanf("%s",str2);

    //방법1. string으로 바꾸고 algorithm으로 sort, str1.compare(str2)로 확인
    //     string st1(str1);
    //     string st2(str2);


    //     std::sort(st1.begin(),st1.begin()+st1.size());
    //     std::sort(st2.begin(),st2.begin()+st2.size());
    //     if(st1.compare(st2)==0){
    //         printf("Possible\n");
    //     }
    //     else{
    //         printf("Impossible\n");
    //     }
    // }

    //방법 2. 알파벳 넣는 배열 찾아서 확인
    int alpha1[26]={};
    int alpha2[26]={};

    int count = 0;
    while(str1[count]!=0){
        alpha1[str1[count]-'a']++;
        count++;
    }
    count = 0;
    while(str2[count]!=0){
        alpha2[str2[count]-'a']++;
        count++;
    }

    bool isSame= true;
    for(int i=0;i<26;i++){
        if(alpha1[i]!=alpha2[i]) isSame = false;
    }

    if(isSame){
    printf("Possible\n");
    }
    else{
        printf("Impossible\n");
    }
    
    }
}