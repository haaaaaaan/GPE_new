#include <bits/stdc++.h>
using namespace std;

int m,n;
vector<string> grid;
bool visited[101][101];

int dx[8] = {-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1};
int dy[8] = {-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1 };

void dfs(int x , int y){
    visited[x][y] = true;
    for(int idx=0 ; idx <8 ; idx++){
        int new_x = x + dx[idx];
        int new_y = y + dy[idx];
        if(new_x >= 0 && new_x < m && new_y >=0 && new_y < n && visited[new_x][new_y]!=true && grid[new_x][new_y]=='@'){
            dfs(new_x,new_y);
        }
    }
}
int main(){
    while(1){
        cin >> m >> n;
        if(m == 0) break;
        grid.resize(m);
        for(int i=0 ; i<m ; i++) cin >> grid[i];
        memset(visited , false , sizeof(visited));

        int count = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(visited[i][j]==false && grid[i][j]=='@'){
                    dfs(i,j);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}