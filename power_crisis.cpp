#include <bits/stdc++.h>
using namespace std;

bool check(int now , int n){
    int pos=0;
    for(int i=2;i<now;i++){    // 跑到最後一個位置
        pos = (pos+n)%i;
    }
    return pos==11;
}

int find(int now){
    int n=1;
    while(1){
        if(check(now,n)) return n;   // 間隔為n , 從1開始慢慢增加，找最小的間隔
        n++;
    }
}


int main(){
    int m;
    while(1){
        cin >> m;
        if(m==0) break;
        cout << find(m) << endl;
    }
    return 0;
}