#include <bits/stdc++.h>
using namespace std;

int n;
int length;
int maxLen;
vector<unsigned long long> a;
vector<unsigned long long> cur;
vector<vector<unsigned long long>> ans;   // array that has many subsequence (also array)
void dfs(int idx , unsigned long long last){
    if(idx == length){
        if(cur.size() > maxLen){    // find a longer answer , update it to LIMS
            maxLen = cur.size();
            ans.clear();
            ans.push_back(cur);
        }
        else if(cur.size() == maxLen && maxLen > 0){
            ans.push_back(cur);
        }
        return;
    }
    if(a[idx] > last){       // 選，但要檢查現在看的比last看的大，才可以push_back
        cur.push_back(a[idx]);
        dfs(idx+1 , a[idx]);
        cur.pop_back();
    }
    dfs(idx+1 , last);     // 也可以不選
}
int main(){
    cin >> n;
    while(n--){
        cin >> length;
        a.resize(length);
        for(int i = 0 ; i<length ; i++){
            cin >> a[i];
        }

        maxLen = 0;
        ans.clear();
        cur.clear();

        dfs(0,0);   // start from idx = 0 , last = 0

        cout << ans.size() << endl;

        for(auto &seq : ans){
            for(int i=0 ; i<seq.size() ; i++){
                if(i!=0) cout << " ";
                cout << seq[i];
            }
            cout << endl;
        }

    }
}