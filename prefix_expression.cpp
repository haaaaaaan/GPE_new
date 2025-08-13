#include <bits/stdc++.h>
using namespace std;
int result;
bool isOperator(const string& s){
    if(s == "+" || s == "-" || s == "*" || s == "/" ||  s == "%") return true;
    else return false;
}

bool isNumber(const string& s){
    for(char c:s){
        if(!isdigit(c)) return false;
    }
    return !s.empty();
}


bool evaluate(vector<string>& tokens , int& result){
    stack<int> now;

    for(int i=tokens.size()-1 ; i>=0 ; i--){
        string tmp = tokens[i];
        if(isNumber(tmp)) now.push(stoi(tmp));
        else if(isOperator(tmp)){
            if(now.size()<2) return false;

            int a = now.top(); now.pop();
            int b = now.top(); now.pop();

            if(tmp == "+") now.push(a+b);
            else if(tmp == "-") now.push(a-b);
            else if(tmp == "*") now.push(a*b);
            else if(tmp == "/") {
                if( b==0 ) return false;
                now.push(a/b);
            }
            else if(tmp == "%") {
                if( b==0 ) {
                    return false;
                }
                now.push(a%b);
            }
        }
        else {
            cout << "check 2 : " << tmp << endl;
            return false;
        }
    }
    if(now.size() != 1) {
        return false;
    }
    result = now.top();
    return true;

}

int main(){
    string s;
    while(1){
        getline(cin,s);
        if(s==".") break;

        istringstream iss(s);
        vector<string> tokens;
        string token;
        while(iss >> token){
            //cout << token << endl;
            tokens.push_back(token);
        }

        if(evaluate(tokens,result)){
            cout << result << endl;
        }
        else{
            cout << "illegal" << endl;
        }

    }
    return 0;

}