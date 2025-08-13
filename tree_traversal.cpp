#include <bits/stdc++.h>
using namespace std;
string build_postorder(string preorder , string inorder){
    if(preorder.empty()) return "";

    char root = preorder[0];
    int rootIdx = inorder.find(root);

    // substr (start_location , length) , if no mention length then til the end
    string left_In = inorder.substr(0,rootIdx);
    string right_In = inorder.substr(rootIdx+1);

    string left_pre = preorder.substr(1,left_In.length());
    string right_pre = preorder.substr(left_In.length()+1);

    return build_postorder(left_pre,left_In) + build_postorder(right_pre,right_In) + root;

}
string read_seq(int n){
    string s , token;
    for(int i=0;i<n;i++){
        cin >> token;
        s+= token;
    }
    //cout <<"after read : " << s << endl;
    return s;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int now;
        cin >> now;

        string preorder = read_seq(now);
        string inorder = read_seq(now);
        
        string final = build_postorder(preorder,inorder);
        for (int i = 0; i < final.length(); ++i) {
            cout << final[i];
            if (i != final.length() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}