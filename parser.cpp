#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string expr;
int idx;
bool error = false;

int parseE(); // Expression
int parseT(); // Term
int parseF(); // Factor
int parseN(); // Number

void skipSpaces() {
    while (idx < expr.size() && isspace(expr[idx])) idx++;
}

int parseE() {
    int val = parseT();
    while (!error) {
        skipSpaces();
        if (idx < expr.size() && (expr[idx] == '+' || expr[idx] == '-')) {
            char op = expr[idx++];
            int rhs = parseT();
            if (op == '+') val += rhs;
            else val -= rhs;
        } else break;
    }
    return val;
}

int parseMod() {
    int val = parseF();
    while (!error) {
        skipSpaces();
        if (idx < expr.size() && expr[idx] == '%') {
            idx++;
            int rhs = parseF();
            if (rhs == 0) { error = true; return 0; }
            val %= rhs;
        } else break;
    }
    return val;
}


int parseT() {
    int val = parseMod();
    while (!error) {
        skipSpaces();
        if (idx < expr.size() && (expr[idx] == '*' || expr[idx] == '/' )) {
            char op = expr[idx++];
            int rhs = parseMod();
            if (op == '*') val *= rhs;
            else if (op == '/') {
                if (rhs == 0) { error = true; return 0; }
                val /= rhs;
            }
        } else break;
    }
    return val;
}

int parseF() {
    skipSpaces();
    if (idx >= expr.size()) { error = true; return 0; }

    if (expr[idx] == '-') {
        idx++;
        return -parseF();
    } else if (expr[idx] == '+') {
        idx++;
        return parseF();
    } else if (expr[idx] == '(') {
        idx++;
        int val = parseE();
        skipSpaces();
        if (idx >= expr.size() || expr[idx] != ')') {
            error = true;
            return 0;
        }
        idx++;
        return val;
    } else if (isdigit(expr[idx])) {
        return parseN();
    } else {
        error = true;
        return 0;
    }
}

int parseN() {
    skipSpaces();
    if (idx >= expr.size() || !isdigit(expr[idx])) {
        error = true;
        return 0;
    }
    int val = 0;
    while (idx < expr.size() && isdigit(expr[idx])) {
        val = val * 10 + (expr[idx++] - '0');
    }
    return val;
}

int main() {
    string line;
    int case_num = 1;
    while (getline(cin, line)) {
        if (line.empty()) break;

        expr = line;
        idx = 0;
        error = false;

        int result = parseE();
        skipSpaces();
        if (idx != expr.size()) error = true;

        cout << "case " << case_num++ << ":\n";
        if (error)
            cout << "syntactically incorrect\n";
        else
            cout << result << '\n';
        cout << '\n';
    }
    return 0;
}
