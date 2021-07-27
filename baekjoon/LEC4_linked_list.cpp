#include<iostream>

using namespace std;
/*
    바킹독님이 알려주신 야매 연결리스트
    3개의 배열을 이용해서 실제값, 전 후의 위치값을 저장해준다.
    unused가 현재 빈 인덱스의 위치를 의미한다.
*/
const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){
    dat[unused] = num;
    nxt[unused] = nxt[addr];
    pre[unused] = addr;
    //원래 addr다음에 있던 값의 prev도 해결해줘야함!!
    //이때, 만약 마지막 원소에 추가할경우, nxt[addr]이 존재하지 않아 -1이므로 예외처리!
    if(nxt[addr]!=-1) pre[nxt[addr]] = unused;
    //nxt[addr]=unused가 여기에 있어야 한다. 앞쪽에 있을 경우, 해당 addr이 가장 뒤인지 확인하는 조건문이 무조건 true가 되어 예상치 못한 값이 나온다..!
    nxt[addr] = unused;
    unused++;
}

void erase(int addr){
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr]!= -1) pre[nxt[addr]] = pre[addr];
    }

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  erase_test();
}