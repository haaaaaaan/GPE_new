#include <iostream>
#include <string>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int num , pos = 0 , ins[100];
        
        cin >> num;
        for(int i=1 ; i<=num ; i++){
            string str;
            cin >> str;
            if(str == "LEFT"){
                //cout << "-1" << endl;
                pos--;
                ins[i] = -1;
            }
            else if(str == "RIGHT"){
                //cout << "+1" << endl;
                pos++;
                ins[i] = 1;
            }
            else{
                string temp;
                int now;
                cin >> temp >> now;
                //cout << now << endl;
                if(ins[now] == -1){
                    ins[i] = -1;
                    pos--;
                }
                else{
                    ins[i] = 1;
                    pos++;
                }

            }
        }
        cout << pos << endl;
    }
}