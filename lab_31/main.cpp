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

int getPriority(char op) { // Приоритеты операций
    if (op == MULT || op == DIV)
        return 2;
    else if (op == PLUS || op == MINUS)
        return 1;
    else
        return 0;
}

vector<string> toPostfix(string input) { // Конвертация в постфиксную нотацию
    stack<string> s;
    vector<string> output;
    int i = 0;

    while(i < input.size()) { // Пока есть символ для чтения, читаем очередной символ
        if(isdigit(input[i])) { // Если символ является числом
            output.push_back(""); // Добавляем пустую строку к выходному массиву
            while(isdigit(input[i]) || input[i] == DOT) { // Проверка на многозначность и плавающую точку
                output.back() += input[i];
                i++;
            }
        }
        else if(input[i] == OPENING) { // Если символ является открывающей скобкой, помещаем его в стек
            s.push(string(1, input[i]));
            i++;
        }
        else if(input[i] == CLOSING){ // Если символ является закрывающей скобкой
            while(s.top()[0] != OPENING) { // До тех пор, пока верхним элементом не станет открывающая скобка
                output.push_back(s.top()); // Выталкиваем элементы из стека в выходной массив
                s.pop();
            }
            s.pop(); // При этом открывающая скобка удаляется из стека
            i++;
        }
        else if (isspace(input[i])) {
            i++;
        }
        else{ // Если символ является оператором
            while (s.size() > 0
                   && getPriority(input[i]) <= getPriority(s.top()[0])) { // пока приоритет оператора меньше приоритета оператора, находящегося на вершине стека
                output.push_back(s.top()); // Выталкиваем элементы стека в выходной массив
                s.pop();
            }
            s.push(string(1,input[i])); // Помещаем оператор в стэк
            i++;
        }
    }
    while(s.size() != 0) {
        output.push_back(s.top()); // Когда входная строка закончилась, выталкиваем все символы в выходной массив
        s.pop();
    }
    cout << "RPN-style: ";
    for(i=0; i < output.size(); i++)
        cout << output[i] << " ";
    cout << "\n";

    return output;
}

string calculate(vector<string> nums, string oper) { // Операции с числами
    double result = 0;
    char op = oper[0];
    float o1 = stof(nums[1]),
            o2 = stof(nums[0]);

    if (op == MOD)
        result = fmod(o1, o2);
    else if (op == MULT)
        result = o1 * o2;
    else if (op == DIV)
        result = o1 / o2;
    else if (op == PLUS)
        result = o1 + o2;
    else if (op == MINUS)
        result = o1 - o2;
    return to_string(result);
}

float rpn (string inp) { // Вычисления на стеке
    vector<string> input = toPostfix(inp);
    vector<string> numbers;
    stack<string> s;
    for(int i = 0; i < input.size(); i++) {
        if(isdigit(input[i][0])) { // Если на вход подан операнд, он помещается на вершину стека
            s.push(input[i]);
        }
        else{ // Если на вход подан знак операции
            while(s.size() > 0) {
                numbers.push_back(s.top());
                s.pop();
            }
            s.push(calculate(numbers, input[i])); // то соотсветсвующая операция выполняется над требуемым кол-вом значений
            numbers.clear();
        }
    }
    return stof(s.top()); // После полной обработки входного набора символов результат лежит на вершину стека
}

int main() {
    string input;
    cout << "Введите выражение\n";
    getline(cin, input);
    cout << "\n";
    cout << "Result: " << rpn(input);
}