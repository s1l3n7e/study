#include <iostream>
#include <string.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    char str[6] = {'H', 'e', 'l', 'l', 'o'}; // ���������� ��-������ � ������������ �� ��������
    char str2[6];
    printf("%s\n", str);  // ����� �����
    cout << str << endl; //��� ���� ����� ������
    fgets(str2, 6, stdin); // ���������� ������ �� ������ �����
    cout << "���������� �����" << endl;
    printf("%s\n", strcat(str, str2));
    cout << "����������� �����" << endl;
    printf("%s\n", strcpy(str, str2));
    cout << "����� ������: ";
    printf("%d", strlen(str));
    return 0;
}