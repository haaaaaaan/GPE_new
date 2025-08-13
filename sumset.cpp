#include<bits/stdc++.h>
using namespace std;

struct PairSum{
    int sum,i,j;
};

int main(){
    int n;
    while (1)
    {
        cin >> n;
        if(n==0) break;
        vector<int> now(n);

        for(int i=0 ; i<n ; i++) cin >> now[i];
        sort(now.begin(),now.end());

        vector<PairSum> sums;
        sums.reserve(n*n);
        // traverse all a+b combinations
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                sums.push_back({now[i]+now[j],i,j});
            }
        }
        
        unordered_map<int , vector<pair<int,int>>> mp;
        // sum -> (index i , index j)
        // mp 是一個 hash map，記錄了所有 (a+b) 的值以及對應的 (a_idx, b_idx)。
        for(auto &p : sums){
            mp[p.sum].push_back({p.i,p.j});
        }

        bool found = false;
        int ans;

        for(int d_idx = n-1 ; d_idx >= 0 ; d_idx--){
            for(int c_idx = 0 ; c_idx < n ; c_idx++){
                if(c_idx == d_idx) continue;   // 確保 c 跟 d 不是同一個元素（因為四個數必須不同）。
                int target = now[d_idx] - now[c_idx];
                if(mp.count(target)){   // mp 存在有a+b = target的 sum
                    for(auto &pr : mp[target]){
                        int a_idx = pr.first , b_idx = pr.second;
                        if(a_idx != d_idx && a_idx != c_idx && b_idx != d_idx && b_idx != c_idx){
                            ans = now[d_idx];
                            found = true;
                            break;
                        }
                    }
                }
                if(found) break;
            }
        }
        if(found) cout << ans << endl;
        else cout << "no solution" << endl;
    }
    return 0;
    
}