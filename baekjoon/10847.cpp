/*
    10847번
    총 N개의 정수가 주어졌을때, 정수 V가 몇개인지 구하는 프로그램
*/
#include<cstdio>


int main(){
    int num;
    int arr[100];
    int findNum;
    int count = 0;

    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&findNum);
    for(int i=0;i<num;i++){
        if(arr[i]==findNum) count++;
    }
    printf("%d",count);
}