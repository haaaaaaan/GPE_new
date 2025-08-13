#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
tuple<int,int,int> getLine(int x1, int y1 , int x2 , int y2){
    int a = y2 - y1;
    int b = x1 - x2;
    int c = a * x1 + b * y1;

    int g = gcd(gcd(abs(a),abs(b)),abs(c));
    if(g!=0){
        a/=g;
        b/=g;
        c/=g;
    }

    if(a < 0 || (a==0 && b < 0)){
        a*=-1;
        b*=-1;
        c*=-1;
    }

    return {a,b,c};


}

int main(){
    int t;
    cin >> t;
    while(t--){
        int test;
        cin >> test;
        vector<pair<int,int>> points(test);

        for(int i=0;i<test;i++){
            cin >> points[i].first >> points[i].second;
        }

        set<tuple<int,int,int>> All_lines;

        for(int i=0;i<test;i++){
            for(int j=i+1;j<test;j++){
                tuple<int, int, int> line = getLine(points[i].first,points[i].second,points[j].first,points[j].second);
                //cout << get<0>(line) << " " << get<1>(line) << " " << get<2>(line) << endl;
                All_lines.insert(line);

            }
        }
        cout << All_lines.size() << endl;
    }
    return 0;
}