#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0) break;
        unordered_map<string , int> freq;    // string remember combination , int remember frequency
        freq.reserve(2*n);

        int mx = 0;

        for(int i=0 ; i<n ; i++){
            int a[5];
            for(int j=0;j<5;j++) cin >> a[j];
            sort(a,a+5);

            string key;
            key.reserve(20);
            for(int j=0;j<5;j++){
                key += to_string(a[j]);
                key.push_back(' ');
            }
            int c = ++freq[key];
            if(c > mx) mx = c;

        }
        int ans = 0;
        for(auto &p : freq){
            if(p.second == mx) ans += p.second;   /// maybe there will be some "same frequency" combination
        }
        cout << ans << endl;
    }
}