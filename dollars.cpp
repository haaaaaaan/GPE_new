#include<iostream>
#include <vector>
#include<iomanip>
using namespace std;

int main(){
    vector<int> coins = {5,10,20,50,100,200,500,1000,2000,5000,10000};
    vector<long long> dp(30005,0);
    dp[0]=1;  // 不使用任何硬幣，湊出 0 元 有 1 種方法（就是什麼都不做）
    // dp[i] 表示：湊出「金額 i（單位為分）」的所有不同組合方法數

    for(int coin:coins){
        for(int i=coin ; i<= 30000 ; i++){
            dp[i] += dp[i-coin];  //dp[i - c] : 先組出 i - c 的方法數，再補上一枚 c 硬幣，就會變成 i
        }
    }


    double now;
    while(cin >> now){
        if( now == 0.00) break;
        else{
            int target = (int)(now*100+0.5);
            cout << setw(6) << fixed << setprecision(2) << now << setw(17) << dp[target] << endl;
        }
    }
}