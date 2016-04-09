#include <iostream>
#include <stack>
#include <vector>
#include <math.h>

using namespace std;

const char
        DOT = '.',
        OPENING = '(',
        CLOSING = ')',
        MULT = '*',
        DIV = '/',
        PLUS = '+',
        MINUS = '-',
        MOD = '%';

const string OPERATORS = "*/+-%";

/* ���������� �������� */
int getPriority(char op) {
    if (op == MULT || op == DIV || op == MOD)
        return 2;
    else if (op == PLUS || op == MINUS)
        return 1;
    else
        return 0;
}

/* ����������� � ����������� ������� */
vector<string> toPostfix(string input) {
    stack<string> s;
    vector<string> output;
    bool err = false; // ���� ������ ������
    int i = 0;
    /* ������, ���� ���� ������� */
    while(i < input.size() && !err) {
        /* ���� ������ �������� ������ */
        if(isdigit(input[i])) {
            output.push_back(""); // ��������� ������ ������ � ��������� �������
            while(isdigit(input[i]) || input[i] == DOT) { // �������� �� �������������� � ��������� �����
                output.back() += input[i];
                i++;
            }
        }
        /* ���� ������ �������� ����������� ������� */
        else if(input[i] == OPENING) {
            s.push(string(1, input[i])); // �������� ��� � ����
            i++;
        }
        /* ���� ������ �������� ����������� ������� */
        else if(input[i] == CLOSING){
            while(s.top()[0] != OPENING) { // �� ��� ���, ���� ������� ��������� �� ������ ����������� ������
                output.push_back(s.top()); // ����������� �������� �� ����� � �������� ������
                s.pop();
            }
            s.pop(); // ��� ���� ����������� ������ ��������� �� �����
            i++;
        }
        else if (isspace(input[i])) {
            i++;
        }
        /* ���� ������ �������� ���������� */
        else if (OPERATORS.find(input[i]) != string::npos){
            while (s.size() > 0
                   && getPriority(input[i]) <= getPriority(s.top()[0])) { // ���� ��������� ��������� ������ ���������� ���������, ������������ �� ������� �����
                output.push_back(s.top()); // ����������� �������� ����� � �������� ������
                s.pop();
            }
            s.push(string(1,input[i])); // �������� �������� � ����
            i++;
        }
        /* ���� ������ �� �������������� */
        else
            err = true;
    }
    if (!err) {
        while (s.size() != 0) {
            output.push_back(s.top()); // ����� ������� ������ �����������, ����������� ��� ������� � �������� ������
            s.pop();
        }
        cout << "RPN-style: ";
        for (i = 0; i < output.size(); i++)
            cout << output[i] << " ";
        cout << endl;
    }
    else {
        output.clear();
        output.push_back("error");
    }

    return output;
}

/* �������� � ������� */
string calculate(vector<string> nums, string oper) {
    double result = 0,
    o1 = stof(nums[0]),
    o2 = stof(nums[1]);

    char op = oper[0];

    if (op == MULT)
        result = o1 * o2;
    else if (op == DIV){
        if (o1 == 0)
            result = 0;
        else
            result = o2 / o1;
        }
    else if (op == PLUS)
        result = o1 + o2;
    else if (op == MINUS)
        result = o2 - o1;
    else if (op == MOD)
        result = fmod(o1, o2);
    return to_string(result);
}

/* ���������� �� ����� */
float rpn (string inp) {
    vector<string> input = toPostfix(inp);
    if(input[0] == "error") {
        cout <<"!�������� ���������!" << endl;
        return 0;
    }
    vector<string> numbers;
    stack<string> s;
    for(int i = 0; i < input.size(); i++) {
        if(isdigit(input[i][0])) { // ���� �� ���� ����� �������, �� ���������� �� ������� �����
            s.push(input[i]);
        }
        else{ // ���� �� ���� ����� ���� ��������
            for (int j = 0; j < 2; j++) {
                numbers.push_back(s.top());
                s.pop();
            }
            s.push(calculate(numbers, input[i])); // �� ��������������� �������� ����������� ��� ��������� ���-��� ��������
            numbers.clear();
        }
    }
    return stof(s.top()); // ����� ������ ��������� �������� ������ �������� ��������� ����� �� ������� �����
}

int main() {
    setlocale(LC_ALL, "Russian");
    string input;
    cout << "������� ���������" << endl;
    getline(cin, input);
    cout << "Result: " << rpn(input);
}