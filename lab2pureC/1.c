
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void first()
{
    int
            size = 0,
            i, j;

    printf("Введите размер квадрата\n");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i==0 || i==size-1)
                printf("*");
            else if (j==0 || j==size-1)
                printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}

void second()
{
    int
            number = 0,
            result = 0,
            i;

    printf("Введите число в двоичной СС\n");
    scanf("%d", &number);
    for(i = 0; number != 0; i++)
    {
        result += number % 10 * pow(2, i);
        number /= 10;
    }
    printf("%d", result);
}

void third() // По невнимательности сделал до 99999.99
{
    double
            sum = 0,
            rub, kop;
    int
            *array = NULL,
            size = 0, i,
            kop_int, rub_int;

    printf("Введите 0 < число < 99999.99 \n");
    scanf("%lf", &sum);

    kop = modf(sum, &rub);
    kop_int = (int) ceil((kop * 100));
    rub_int = (int) rub;

    if (rub_int == 0)
    {
        printf("Ноль рублей");
    }
    else {

        for (i = 0; rub_int != 0; i++) {
            array = (int *) realloc(array, (i + 1) * sizeof(int));
            array[i] = rub_int % 10;
            rub_int /= 10;
            printf("%d", array[i]);
            size++;
        }

        printf("\n");

        for (i = size - 1; i >= 0; i--) {
            if (array[i - 1] == 1 && (i == size || i == 0 || i == 4) ||
                array[i + 1] == 1 && (i == size || i == 0 || i == 4)) {
                switch (array[i]) {
                    case 0:;
                        break;
                    case 1:
                        printf("Одиннадцать");
                        break;
                    case 2:
                        printf("Двенадцать");
                        break;
                    case 3:
                        printf("Тринадцать");
                        break;
                    case 4:
                        printf("Четырнадцать");
                        break;
                    case 5:
                        printf("Пятнадцать");
                        break;
                    case 6:
                        printf("Шестнадцать");
                        break;
                    case 7:
                        printf("Семнадцать");
                        break;
                    case 8:
                        printf("Восемнадцать");
                        break;
                    case 9:
                        printf("Девятнадцать");
                        break;
                    default:break;
                }
                i--;
            }
            if (i == 2) {
                switch (array[i]) {
                    case 0:;
                        break;
                    case 1:
                        printf("Сто");
                        break;
                    case 2:
                        printf("Двести");
                        break;
                    case 3:
                        printf("Триста");
                        break;
                    case 4:
                        printf("Четыреста");
                        break;
                    case 5:
                        printf("Пятьсот");
                        break;
                    case 6:
                        printf("Шестьсот");
                        break;
                    case 7:
                        printf("Семьсот");
                        break;
                    case 8:
                        printf("Восемьсот");
                        break;
                    case 9:
                        printf("Девятьсот");
                        break;
                    default:break;
                }
            }
            if (i == 1 || i == 4) {
                switch (array[i]) {
                    case 0:;
                        break;
                    case 1:
                        if (array[i - 1] == 0) {
                            printf("Десять");
                            i--;
                        }
                        break;
                    case 2:
                        printf("Двадцать");
                        break;
                    case 3:
                        printf("Тридцать");
                        break;
                    case 4:
                        printf("Сорок");
                        break;
                    case 5:
                        printf("Пятьдесят");
                        break;
                    case 6:
                        printf("Шестьдесят");
                        break;
                    case 7:
                        printf("Семьдесят");
                        break;
                    case 8:
                        printf("Восемьдесят");
                        break;
                    case 9:
                        printf("Девяносто");
                        break;
                    default:break;
                }
            }
            if ((i == 0 || i == size || i == 3) && (array[i - 1] != 1) && (array[i + 1] != 1)) {
                switch (array[i]) {
                    case 0:;
                        break;
                    case 1:
                        if (i == 3) printf("Одна тысяча"); else printf("Один");
                        break;
                    case 2:
                        if (i == 3) printf("Две тысячи"); else printf("Два");
                        break;
                    case 3:
                        printf("Три");
                        break;
                    case 4:
                        printf("Четыре");
                        break;
                    case 5:
                        printf("Пять");
                        break;
                    case 6:
                        printf("Шесть");
                        break;
                    case 7:
                        printf("Семь");
                        break;
                    case 8:
                        printf("Восемь");
                        break;
                    case 9:
                        printf("Девять");
                        break;
                    default:break;
                }
                if (i == 3 && array[i] != 1 && array[i] != 2 || i == 4) {
                    printf(" Тысяч");
                }
            }
            printf(" ");
        }

        if (array[0] == 1)
            printf("Рубль");
        else if (array[0] > 0 && array[0] < 5)
            printf("Рубля");
        else printf("Рублей");
    }

    if (kop_int == 100)
        kop_int--;
    printf(" %d ", kop_int);

    if (kop_int < 10)
        printf(0);
    if (kop_int % 10 == 1)
        printf("Копейка");
    else if (kop_int % 10 > 0 && kop_int % 10 < 5)
        printf("Копейки");
    else printf("Копеек");
}

int fac(int num) {
    if (num < 2)
        return 1;
    else return num * fac(num - 1);
}

void fourth() {
    int i = 0;
    double eps = 0, result = 2, instance = 10;
    scanf("%lf", &eps);
    printf("%d", fac(1));

    for (i = 2; instance >= eps; i++)
    {
        instance = 1.0/fac(i);
        result += instance;
    }

    printf("%lf", result);
}

void main()
{

    int number;

    printf("Введите номер задачи\n");
    scanf("%d", &number);
    printf("Задача %d\n", number);

    if(number == 1) first();
    else if(number == 2) second();
    else if(number == 3) third();
    else if(number == 4) fourth();
}
