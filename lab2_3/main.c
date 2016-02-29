#include <math.h>
#include <stdio.h>
#include <windows.h>

void int_to_words(int num) {
    int i;

    for(i = 100; num != 0; i /= 10) {
        if(i == 10 && num / 10 == 1) {
            switch(num / i) {
                case 1: printf("����������� ");break;
                case 2: printf("�������� ");break;
                case 3: printf("�������� ");break;
                case 4: printf("������������ ");break;
                case 5: printf("���������� ");break;
                case 6: printf("����������� ");break;
                case 7: printf("���������� ");break;
                case 8: printf("������������ ");break;
                case 9: printf("������������ ");break;
                default: break;
            }
            i /= 10;
        }

        else if(i == 1)
            switch(num / i) {
                case 1: printf("���� ");break;
                case 2: printf("��� ");break;
                case 3: printf("��� ");break;
                case 4: printf("������ ");break;
                case 5: printf("���� ");break;
                case 6: printf("����� ");break;
                case 7: printf("���� ");break;
                case 8: printf("������ ");break;
                case 9: printf("������ ");break;
                default: break;
            }
        else if(i == 10)
            switch(num / i) {
                case 1: printf("������ ");break;
                case 2: printf("�������� ");break;
                case 3: printf("�������� ");break;
                case 4: printf("����� ");break;
                case 5: printf("��������� ");break;
                case 6: printf("���������� ");break;
                case 7: printf("��������� ");break;
                case 8: printf("����������� ");break;
                case 9: printf("��������� ");break;
                default: break;
            }
        else if(i == 100)
            switch(num / i) {
                case 1: printf("��� ");break;
                case 2: printf("������ ");break;
                case 3: printf("������ ");break;
                case 4: printf("��������� ");break;
                case 5: printf("������� ");break;
                case 6: printf("�������� ");break;
                case 7: printf("������� ");break;
                case 8: printf("��������� ");break;
                case 9: printf("��������� ");break;
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
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char *rub_enders[3] = {"������ ", "����� ", "����� "},
         *kop_enders[3] = {"������ ", "������� ", "������� "};

    float sum;
    int rub, kop;

    printf("������� �����");
    scanf("%f", &sum);

    rub = (int)sum;
    kop = (int)roundf((sum-rub) * 100);

    if (rub != 0)
        int_to_words(rub);
    else
        printf("���� ");

    print_ender(rub, rub_enders);
    printf("%d ", kop);
    print_ender(kop, kop_enders);
}
