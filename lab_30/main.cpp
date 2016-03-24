#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
string operators = "+-/*";

bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

int getPriority (string c) { //приоритеты операций
    if(c == "*" || c == "/") {
        return 4;
    }
    else
        return 3;
}

vector<string> getPostfix (string input) {
    vector<string> output;
    stack<char> s;

    for(int i = 0; i < input.size(); i++) {
        if (isdigit(input[i])) {    //является ли элемент строки целым
            output.push_back(string(1, input[i])); //добавляем в итоговый массив
            int j = 1;
            while (isdigit(input[i + j])) { //проверка на многозначные числа
                output.back()+= input[i + j];
                j++;
            }
            i = i + j - 1;
        }
        else if (input[i] == '(') {
            s.push(input[i]);
        }
        else if (input[i] == ')') {
            while (s.top() != '(') {
                output.push_back(string(1, s.top()));
                s.pop();
            }
            s.pop();
        }
        else if (operators.find(input[i]) != string::npos) { //проверка на принадлежность к операторам
            while (s.size() > 0 && getPriority(string(1, s.top())) >= getPriority(string(1, s.top()))) {
                output.push_back(string(1, s.top()));
                s.pop();
            }
            s.push(input[i]);
        }
    }
    while(s.size() != 0) {
        output.push_back(string(1, s.top()));
        s.pop();
    }
    return output;
}

string operations (vector<string> nums, string op) {
    int result;
    if(op == "-" || op == "+")
        result = 0;
    else result = 1;
    for(int i = 0; i < nums.size(); i++) {
        int num = atoi(nums[i].c_str());
        if(op == "+")
            result += num;
        else if(op == "-")
            result -= num;
        else if(op == "*")
            result *= num;
        else
            result /= num;
    }
    return to_string(result);
}

int calculateRPN(string inp) {
    stack<string> s;
    vector<string> out;
    vector<string> input = getPostfix(inp);

    for (int i = 0; i < input.size(); i++) {
        if(is_digits(input[i])) {
            s.push(input[i]);
        }
        else {
            while (s.size() != 0) {
                out.push_back(s.top());
                s.pop();
            }
            s.push(operations(out, input[i]));
            out.clear();
        }
    }
    cout<<s.top();
    return 0;
}

int main () {
    calculateRPN("(1+2)*4+3");
    return 0;
}