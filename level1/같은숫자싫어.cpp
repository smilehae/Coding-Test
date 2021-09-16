//    arr.erase(unique(arr.begin(), arr.end()),arr.end());

/*
프로그래머스 lv1. 같은 숫자는 싫어.
배열에서 연속적으로 나타내는 숫자는 제거하고 리턴.
생각한 방법1. arr[i+1] !=arr[i]로 돌면서 풀기
-> 마지막 원소 예외처리 안하면 fault일어나기 좋음
생각한 방법 2. 직전에 넣은 값에 대한 정보 저장, 값이 아닐 경우 push(하단 풀이)

프로그래머스에서 알아온 풀이
-> unique(arr.begin(),arr.end()) 함수를 사용하면, arr을 돌면서 유니크한 값만 남겨주고, iterator로 다음 위치 리턴해준다.
알고리즘 헤더에 들어있다.

*/
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int prev=-1;

    for(int i=0;i<arr.size();i++){
        if(arr[i]!=prev){
            answer.push_back(arr[i]);
            prev = arr[i];
        }
    }
  
    return answer;
}

//프로그래머스 고수님의 풀이
//unique를 쓰면, arr에서 중복된 거 제거, 압축 후 다음 위치 입력됨.
//그래서 바로 erase로 arr끝까지 지워버리면 컴팩트한 arr를 리턴가능.
vector<int> solution(vector<int>arr){
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    return arr;
}