#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    char s[101];
    char alpha[26];
    fill(alpha,alpha+26,0);
    scanf("%s",s);
    

    int count = 0;
    while(s[count]!=0){
       alpha[(int)s[count]-97]++;
       count++;

    }

    for(int i=0;i<26;i++){
        printf("%d ",alpha[i]);
    }
}