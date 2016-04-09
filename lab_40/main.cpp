#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <map>

using namespace std;

/* ��������� ������� */
void log_in();
void user_interface();

/* ������ �� ����� � ������� */
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

/* ����� ������� */
void display_map (map<string, string> input) {
    cout << "���: " << input["name"] << "\n"
    << "�������: " << input["surname"] << "\n"
    << "��������: " << input["second_name"] << "\n"
    << "���� ��������: " << input["birth_date"] << "\n"
    << "�������(�): " << input["ended"] << "\n";
}

/* ������� �� ������� */
void display_filtered(vector<map<string, string>> input, vector<string> key, vector<string> value) {
    for (int i = 0; i < input.size(); i++)
        for (int j = 0; j < key.size(); j++)
            if (input[i][key[j]] == value[j])
                display_map(input[i]);
    user_interface();
}

/* ��������� ������������ */
void user_interface () {
    vector<map<string, string>> studs;
    studs = map_from_file("../students.txt");
    string filter_input;

    cout << "1 - �������\n2 - ����� ������������\n3 - �����\n";

    int choice = -1;
    cin >> choice;

    if (choice == 1) {
        vector<string> key_filters;
        vector<string> value_filters;

        cout << "�������� �������� � ������� ��� ��������:\n1 - ���\n2 - �������\n3 - ��������\n4 - ���� ��������\n5 - �������\n";
        cin >> filter_input;

        string current_filter;
        for (int i = 0; i < filter_input.length(); i++) {
            if (filter_input[i] == '1') {
                key_filters.push_back("name");
                cout << "������� ���\n";
            }
            else if (filter_input[i] == '2') {
                key_filters.push_back("surname");
                cout << "������� �������\n";
            }
            else if (filter_input[i] == '3') {
                key_filters.push_back("second_name");
                cout << "������� ��������\n";
            }
            else if (filter_input[i] == '4') {
                key_filters.push_back("birth_date");
                cout << "������� ���� ��������\n";
            }
            else if (filter_input[i] == '5') {
                key_filters.push_back("ended");
                cout << "������� ��� ���������";
            }
            else {
                cout << "������������ ����";
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

/* ���� */
void log_in () {
    string username, password;
    bool logged_in = false;
    vector<map<string, string>> users;

    users = map_from_file("../users.txt");

    while (!logged_in) {
        cout << "������� ��� ������������\n";
        cin >> username;
        cout << "������� ������\n";
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