﻿#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    system("chcp 1251>nul");                                     // Изменение кодировки кансоли для корректного отображения кирилици
    system("color 70");                                          // Изменяем цвет консоли и текста
    string file = "Text_test.txt";                               // Переменная для записи адреса тестового файла
    string t;                                                    // Переменная для записи адреса искомого файла
    char ch;                                                     // Переменная для записи символа из файла
    cout << " Тестовый файл лежит в корневой папке программы: "; // Ввывод сообщения об адресе тест-файла
    cout << file << endl;
    cout << " Введите адрес файла для прочтения: ";              // Запрос адреса файла
    cin >> t;                                                    // Записываем адрес в переменную 
    cout << endl;
    ifstream text;                                               // Объявляем поток
    text.open(t, ios::binary);                                   // Открываем в потоке файл в двоичном коде
    if (!text.is_open())                                         // Проверяем открытие файла
    {
        cerr << "Файл не может быть открыт!" << endl;            // Выводим сообщение об ошибке
        system("pause>nul");                                     // Задержка консоли окна 
        return 1;                                                // Возвращяем ошибку 1
    }
    system("chcp 65001>nul");                                    // Изменение кодировки на UTF-8 для корректного чтения кирилици из файла
    while (!text.eof())                                          // Пока не конец файла
    {
        text.get(ch);                                            // Методом get() считываем символ из файла
        cout<<ch;                                                // Ввыводим в консоль ститаный символ
    }
    text.close();                                                // Закрываем поток
    cout << endl;
    system("pause>nul");                                         // Задержка консоли окна 
    return 0;                                                    // Возвращаем 0 в случае благополучного окончания программы
}