#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n , m;
    while(cin >> n >> m){
        vector<int> moves(m);
        for(int i = 0 ; i<m ; i++){
            cin >> moves[i];
        }

        vector<bool> dp(n+1);
        for(int i=0 ; i<n+1 ; i++){
            dp[i] = false;
        }

        for (int i = 1; i <= n; ++i) {
            for (int move : moves) {
                if (i >= move && !dp[i - move]) {
                    dp[i] = true; // 如果有一種拿法能讓對手輸，這是先手必勝局
                    break;
                }
            }
        }
        
        if(dp[n]) cout << "Stan wins" << endl;
        else cout << "Ollie wins" << endl;

    }
    return 0;
}