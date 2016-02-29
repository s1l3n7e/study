// Game Over

// A first Cþþ program

// 1

#include <iostream> // подключение библиотек

int first() // объявлении функции, возвращающей int

{

    std::cout << "Game Over!" << std::endl; // вывод сообщения в консоль, перевод каретки

    return 0; // возврат целого значения

} 

// 2

// Game Over 2.0

// Demonstrates a using directive

using namespace std; // объявление пространства имён

int second()

{ // объявлении функции, возвращающей int

    cout << "Game Over!" << endl; // вывод сообщения в консоль, перевод каретки

    return 0; // возврат целого значения
}

// 3

using std::cout; // объявление пространства имён для cout

using std::endl; // объявление пространства имён для endl

int third() // объявлении функции, возвращающей int

{

    cout << "Game Over!" << endl; // вывод сообщения в консоль, перевод каретки

    return 0; //возврат целого значения

} 
int  main() {
	first();
	second();
	third();
	return 0;
}
