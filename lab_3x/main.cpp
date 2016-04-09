#include <iostream>
#include <string.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    char str[6] = {'H', 'e', 'l', 'l', 'o'}; // объявление си-строки и присваивание ей значения
    char str2[6];
    printf("%s\n", str);  // вывод строк
    cout << str << endl; //еще один вывод строки
    fgets(str2, 6, stdin); // считывание строки из потока ввода
    cout << "склеивание строк" << endl;
    printf("%s\n", strcat(str, str2));
    cout << "копирование строк" << endl;
    printf("%s\n", strcpy(str, str2));
    cout << "длина строки: ";
    printf("%d", strlen(str));
    return 0;
}