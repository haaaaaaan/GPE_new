#include <iostream>
using namespace std;

int main(){
    int prime[10000];
    prime[0] = 2;
    int k=1;

    for(int i=3 ; i<10000 ; i++){    // 從 3 - 10000 一個一個數字去看是不是質數
        for(int j=2 ; j<i ; j++){
            if(i%j == 0) break;
            if(j == i-1){                // 即 j 無法整除 i 到最後一個 j == i-1 ，加入 prime
                prime[k] = i;
                k++;
                break;
            }
        }
    }

    //for(int i=0;i<10;i++) cout << prime[i] << endl;

    int test;
    while ( cin >> test){
        if(test == 0) break;
        int count = 0 , sum = 0 , j = 0;
        for(int i=0 ; test >= prime[i]; i++){
            sum += prime[i];
            //cout << sum << endl;

            while(sum > test){   // 如果 sum 太大，就把前面 prime[j] 拿掉直到 sum <= test
                sum -= prime[j];
                j++;
            }
            if(sum == test){
                count++;
            }
        }
        cout << count << endl;
    }
}