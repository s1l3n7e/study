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

/* приоритеты операций */
int getPriority(char op) {
    if (op == MULT || op == DIV || op == MOD)
        return 2;
    else if (op == PLUS || op == MINUS)
        return 1;
    else
        return 0;
}

/* конвертация в постфиксную нотацию */
vector<string> toPostfix(string input) {
    stack<string> s;
    vector<string> output;
    bool err = false; // флаг ошибки чтения
    int i = 0;
    /* читаем, пока есть символы */
    while(i < input.size() && !err) {
        /* если символ является числом */
        if(isdigit(input[i])) {
            output.push_back(""); // добавляем пустую строку к выходному массиву
            while(isdigit(input[i]) || input[i] == DOT) { // проверка на многозначность и плавающую точку
                output.back() += input[i];
                i++;
            }
        }
        /* если символ является открывающей скобкой */
        else if(input[i] == OPENING) {
            s.push(string(1, input[i])); // помещаем его в стек
            i++;
        }
        /* если символ является закрывающей скобкой */
        else if(input[i] == CLOSING){
            while(s.top()[0] != OPENING) { // до тех пор, пока верхним элементом не станет открывающая скобка
                output.push_back(s.top()); // выталкиваем элементы из стека в выходной массив
                s.pop();
            }
            s.pop(); // при этом открывающая скобка удаляется из стека
            i++;
        }
        else if (isspace(input[i])) {
            i++;
        }
        /* если символ является оператором */
        else if (OPERATORS.find(input[i]) != string::npos){
            while (s.size() > 0
                   && getPriority(input[i]) <= getPriority(s.top()[0])) { // пока приоритет оператора меньше приоритета оператора, находящегося на вершине стека
                output.push_back(s.top()); // выталкиваем элементы стека в выходной массив
                s.pop();
            }
            s.push(string(1,input[i])); // помещаем оператор в стэк
            i++;
        }
        /* если символ не поддерживается */
        else
            err = true;
    }
    if (!err) {
        while (s.size() != 0) {
            output.push_back(s.top()); // когда входная строка закончилась, выталкиваем все символы в выходной массив
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

/* операции с числами */
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

/* вычисления на стеке */
float rpn (string inp) {
    vector<string> input = toPostfix(inp);
    if(input[0] == "error") {
        cout <<"!неверное выражение!" << endl;
        return 0;
    }
    vector<string> numbers;
    stack<string> s;
    for(int i = 0; i < input.size(); i++) {
        if(isdigit(input[i][0])) { // если на вход подан операнд, он помещается на вершину стека
            s.push(input[i]);
        }
        else{ // если на вход подан знак операции
            for (int j = 0; j < 2; j++) {
                numbers.push_back(s.top());
                s.pop();
            }
            s.push(calculate(numbers, input[i])); // то соотсветсвующая операция выполняется над требуемым кол-вом значений
            numbers.clear();
        }
    }
    return stof(s.top()); // после полной обработки входного набора символов результат лежит на вершину стека
}

int main() {
    setlocale(LC_ALL, "Russian");
    string input;
    cout << "Введите выражение" << endl;
    getline(cin, input);
    cout << "Result: " << rpn(input);
}