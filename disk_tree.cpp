#include <bits/stdc++.h>
using namespace std;

struct Node{
    map<string,Node*> child;   // child[x86] can find Node* .....
    ~Node(){
        for(auto &kv : child) delete kv.second;
    }
};

void insert_path(Node *root , const string &path){
    stringstream ss(path);
    string part;
    Node *cur = root;

    while(getline(ss,part,'\\') ){   // 先用'\'來切傳進來要搜的path
        auto it = cur->child.find(part);   // 目前Node的child中，有沒有跟切好的名字一樣
        if(it == cur->child.end()){
            // No child is the same , create new Node
            Node *nxt = new Node();
            cur->child[part] = nxt;
            cur = nxt;
        }
        else{
            cur = it->second;   // 找到了，把cur移到已存在的 child 下面
        }
    }
}
void dfs_print(Node* now , int depth){
    for(const auto &kv : now->child){
        for(int i=0;i<depth;i++){
            cout << ' ';
        }
        cout << kv.first << endl;
        dfs_print(kv.second,depth+1);
    }
}
int main(){
    int N;
    if(!(cin >> N)) return 0;

    Node *root = new Node();
    string path;
    for(int i=0 ; i<N ; i++){
        cin >> path;
        // insert a path from root
        insert_path(root,path);
    }
    dfs_print(root,0);
    delete root;
    return 0;
}