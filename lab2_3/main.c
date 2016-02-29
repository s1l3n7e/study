#include <math.h>
#include <stdio.h>
//#include <windows.h>

void int_to_words(int num) {
    int i;

    for(i = 100; num != 0; i /= 10) {
        if(i == 10 && num / 10 == 1) {
            switch(num / i) {
                case 1: printf("Одиннадцать ");break;
                case 2: printf("Двадцать ");break;
                case 3: printf("Тридцать ");break;
                case 4: printf("Четырнадцать ");break;
                case 5: printf("Пятнадцать ");break;
                case 6: printf("Шестнадцать ");break;
                case 7: printf("Семнадцать ");break;
                case 8: printf("Восемнадцать ");break;
                case 9: printf("Девятнадцать ");break;
                default: break;
            }
            i /= 10;
        }

        else if(i == 1)
            switch(num / i) {
                case 1: printf("Один ");break;
                case 2: printf("Два ");break;
                case 3: printf("Три ");break;
                case 4: printf("Четыре ");break;
                case 5: printf("Пять ");break;
                case 6: printf("Шесть ");break;
                case 7: printf("Семь ");break;
                case 8: printf("Восемь ");break;
                case 9: printf("Девять ");break;
                default: break;
            }
        else if(i == 10)
            switch(num / i) {
                case 1: printf("Десять ");break;
                case 2: printf("Двадцать ");break;
                case 3: printf("Тридцать ");break;
                case 4: printf("Сорок ");break;
                case 5: printf("Пятьдесят ");break;
                case 6: printf("Шестьдесят ");break;
                case 7: printf("Семьдесят ");break;
                case 8: printf("Восемьдесят ");break;
                case 9: printf("Девяносто ");break;
                default: break;
            }
        else if(i == 100)
            switch(num / i) {
                case 1: printf("Сто ");break;
                case 2: printf("Двести ");break;
                case 3: printf("Триста ");break;
                case 4: printf("Четыреста ");break;
                case 5: printf("Пятьсот ");break;
                case 6: printf("Шестьсот ");break;
                case 7: printf("Семьсот ");break;
                case 8: printf("Восемьсот ");break;
                case 9: printf("Девятьсот ");break;
                default: break;
            }
        num %= i;
    }
}

void print_ender(int num, char** enders) {
    if(num % 100 > 10 && num % 100 < 20)
        printf("%s", enders[0]);
    else if(num % 10 > 1 && num % 10 < 5)
        printf("%s", enders[1]);
    else if(num % 10 == 1)
        printf("%s", enders[2]);
    else
        printf("%s", enders[0]);
}

void main() {
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    char *rub_enders[3] = {"Рублей ", "Рубля ", "Рубль "},
         *kop_enders[3] = {"Копеек ", "Копейки ", "Копейка "};

    float sum;
    int rub, kop;

    printf("Введите сумму\n");
    scanf("%f", &sum);

    rub = (int)sum;
    kop = (int)roundf((sum-rub) * 100);

    if (rub != 0)
        int_to_words(rub);
    else
        printf("Ноль ");

    print_ender(rub, rub_enders);
    printf("%d ", kop);
    print_ender(kop, kop_enders);
}
