#include<iostream>
#include <Windows.h>
#include "Computing.h"
#include "Files.h"
#include "Menu.h"
using namespace std;

// Проверка корректности ввода значений переменной типа int
int NumInInt() {
	int variable;
	while (!(cin >> variable) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Некорректно введенные данные. Пожалуйста, введите цифру: " << endl;
	}
	return variable;
}

// Функция, удаляющая символы количеством number с начала строки 

void EraseFromBeginning(vector <string>& text, int line, int number) {
	text[line-1].erase(0, number);
}

// Функция, удаляющая символы количеством number с конца строки line
void EraseFromEnd(vector <string>& text, int line, int number) {
	int endOfStr; 
	endOfStr = text[line-1].length(); // Переменная, равная количеству символов в строке
	if (number > endOfStr) {
		cout << "В строке нет столько символов, сколько необходимо удалить. Пожалуйста попробуйте еще раз:" << endl;
		cout << "Символов в строке: " << endOfStr << endl;
		cout << "Введите количество символов, которые необходимо удалить:" << endl;
		number = NumInInt();
		while ((number < 0) || (number > endOfStr)) {
			cout << "Некорректно введенные данные. Пожалуйста попробуйте еще раз:" << endl;
			number = NumInInt();
		}
	}
	text[line-1].erase((endOfStr - number), number);
}

// Функция, заменяющая все первые строчные буквы текста прописными
void LowerToUpper(vector <string>& text) {
	char lower = 'я', upper = 'Я';
	string letters = "qwetryuiopasdfghjklzxcbvnmйцукеёнгшщзхъфывапрлоджэячсмитьбюQWERTYUIOPASDFGHJKLZXCVBNMЙЦУКЕЁНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ";
	for (unsigned int i = 0; i < text.size(); i++) {
		for (unsigned int j = 0; j < text[i].length(); j++) {
			if ((j == 0) || (letters.find(text[i][j-1]) == string::npos)) {
				text[i][j] = (char)toupper(text[i][j]);
				if (text[i][j] == lower) 
					text[i][j] = upper;
			}
			
		}
	}
}