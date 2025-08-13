#include<bits/stdc++.h>
using namespace std;
int n;
vector<double> rad;
double best;

double compute(const vector<double> &r){
    int m = r.size();
    vector<double> x(m,0.0);
    x[0] = r[0];   // first circle , so middle of circle is 0.0 to r
    double width = 2.0 * r[0];

    for(int i=1; i<m ; i++){
        double pos = r[i];
        for(int j=0 ; j<i ; j++){
            double dx = sqrt((r[i]+r[j])*(r[i]+r[j])-(r[i]-r[j])*(r[i]-r[j]));
            pos = max(pos , x[j]+dx);
        }
        x[i] = pos;
        width = max(width,x[i]+r[i]);
    }
    return width;
}

void backtrack(int idx){
    if(idx == n){
        best = min(best,compute(rad));
        return;
    }
    for(int i=idx;i<n;i++){
        swap(rad[idx],rad[i]);
        backtrack(idx+1);
        swap(rad[idx],rad[i]);
    }
}

int main() {

    cout << fixed << setprecision(3);

    while (cin >> n && n != 0) { // 直到讀到 0
        rad.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> rad[i];
        }
        best = 1e18;
        backtrack(0);
        cout << best << "\n";
    }
}