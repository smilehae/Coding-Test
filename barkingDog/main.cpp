#include<iostream>

using namespace std;

int func1(int N){
    int result = 0;
    int count = 1;
    while(count<=N){
        if(count % 3 == 0 || count % 5 == 0) result += count;
        count++;
    }
    return result;
}

int func2(int arr[], int N){
    int answer= 0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(arr[i]+arr[j]==100){
                answer = 1;
            }
        }
    }
    return answer;
}

int func3(int N){
    int count = 1;
    while(count<N){ //이렇게만 두면 O(n)인데
        if(count*count == N){
            return 1;
        }
        count++;
        if(count*count > N) break; //이 조건을 추가해서 O(루트N) 으로 줄인다!
    }
    return 0;
}

int func4(int N){
    int count =1;
    while(1){
        if(count*2>N) break;
        count *= 2;
    }
    return count;
}

int main(){
    int myarr[4]{4,13,63,87};

    cout<<func1(27639)<<endl;
    cout<<func2(myarr,4)<<endl;
    cout<<func3(693953651)<<endl;
    cout<<func4(1024)<<endl;
    
}