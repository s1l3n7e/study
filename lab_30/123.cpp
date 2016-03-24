//
// Created by IMPERATOR on 24.03.2016.
//
#include <iostream>
#include <stack>
#include <vector>


using namespace std;

const char DOT = '.',
        COMMA = ',',
        OPENING = '(',
        CLOSING = ')',
        MULT = '*',
        DIV = '/',
        PLUS = '+',
        MINUS = '-';
const string OPERATORS = "+-=/";

int getPriority(char op) {
    if (op == MULT || op == DIV)
        return 2;
    else if (op == PLUS || op == MINUS)
        return 1;
    else
        return 0;
}

vector<string> toPostfix(string input) {
    stack s;
    vector<string> output;
    int i = 0;

    while(i < input.size()) {
        if(isdigit(input[i])) {
            output.push_back("");
            while(isdigit(input[i]) || input[i] == DOT || input[i] == COMMA) {
                output.back() += input[i];
                i++;
            }
        }
        else if(input[i] == OPENING)
            s.push(input[i]);
        else if(input[i] == CLOSING){
            while(s.top() != OPENING) {
                output.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else{
            while (getPriority(input[i]) <= getPriority(s.top())) {
                output.push_back(s.top());
                s.pop();
            }
            s.push(input[i]);
        }
    }
    while(s.size() != 0) {
        output.push_back(s.top());
        s.pop();
    }
    for(i=0; i < output.size(); i++) cout << output[i];

    return output;
}

int main() {
    toPostfix("2+2+2+2");
}