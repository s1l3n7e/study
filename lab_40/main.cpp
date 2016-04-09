#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <map>

using namespace std;

/* прототипы функций */
void log_in();
void user_interface();

/* запись из файла в словарь */
vector<map<string, string>> map_from_file (string path) {
    string line, current_key, current_value;
    map<string, string> st;
    vector<map<string, string>> result;
    int index;

    ifstream file;
    file.open(path);

    while (getline(file, line)) {
        index = 0;

        while (index < line.length()) {
            current_key = "";
            current_value = "";

            for (index; line[index] != ':'; index++)
                current_key += line[index];
            index ++;

            for (index; line[index] != ','; index++)
                current_value += line[index];
            index ++;

            st[current_key] = current_value;
        }
        result.push_back(st);
    }
    file.close();
    return result;
};

/* вывод словаря */
void display_map (map<string, string> input) {
    cout << "Имя: " << input["name"] << "\n"
    << "Фамилия: " << input["surname"] << "\n"
    << "Отчество: " << input["second_name"] << "\n"
    << "Дата рождения: " << input["birth_date"] << "\n"
    << "Окончил(а): " << input["ended"] << "\n";
}

/* выборка из словаря */
void display_filtered(vector<map<string, string>> input, vector<string> key, vector<string> value) {
    for (int i = 0; i < input.size(); i++)
        for (int j = 0; j < key.size(); j++)
            if (input[i][key[j]] == value[j])
                display_map(input[i]);
    user_interface();
}

/* интерфейс пользователя */
void user_interface () {
    vector<map<string, string>> studs;
    studs = map_from_file("../students.txt");
    string filter_input;

    cout << "1 - Выборка\n2 - Смена пользователя\n3 - Выход\n";

    int choice = -1;
    cin >> choice;

    if (choice == 1) {
        vector<string> key_filters;
        vector<string> value_filters;

        cout << "Выберите критерии и введите без пробелов:\n1 - Имя\n2 - Фамилия\n3 - Отчество\n4 - Дата рождения\n5 - Окончил\n";
        cin >> filter_input;

        string current_filter;
        for (int i = 0; i < filter_input.length(); i++) {
            if (filter_input[i] == '1') {
                key_filters.push_back("name");
                cout << "Введите имя\n";
            }
            else if (filter_input[i] == '2') {
                key_filters.push_back("surname");
                cout << "Введите фамилию\n";
            }
            else if (filter_input[i] == '3') {
                key_filters.push_back("second_name");
                cout << "Введите отчество\n";
            }
            else if (filter_input[i] == '4') {
                key_filters.push_back("birth_date");
                cout << "Введите дату рождения\n";
            }
            else if (filter_input[i] == '5') {
                key_filters.push_back("ended");
                cout << "Введите год окончания";
            }
            else {
                cout << "Неправильный ключ";
                user_interface();
            }
            cin >> current_filter;
            value_filters.push_back(current_filter);
        }
        display_filtered(studs, key_filters, value_filters);
    }
    else if (choice == 2) {
        log_in();
    }
    else if (choice == 3) {
        return;
    }
    else
        user_interface();

};

/* вход */
void log_in () {
    string username, password;
    bool logged_in = false;
    vector<map<string, string>> users;

    users = map_from_file("../users.txt");

    while (!logged_in) {
        cout << "Введите имя пользователя\n";
        cin >> username;
        cout << "Введите пароль\n";
        cin >> password;

        for (int i = 0; i < users.size() && !logged_in; i++) {
            if (users[i]["username"] == username && users[i]["password"] == password)
                logged_in = true;
        }
    }
    user_interface();
};

int main() {
    SetConsoleCP (1251);
    SetConsoleOutputCP(1251);

    log_in();
}