using namespace std;

long long solution(int price, int money, int count)
{
    long long needMoney = 0;
    for(int i=0;i<count;i++){
        needMoney += price*(i+1);
    }
    if(needMoney<money) return 0;
    else return needMoney - money;

}