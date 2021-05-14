#include<iostream>
#include"Computing.h"

// Тестирование модуля удаления символов с начала определенной строки
bool TestingEraseFromBeginning(vector <string> str) {
	vector <string> tempStr; 
	tempStr = str;

	// Вызов функции удаления символов с начала строки для каждой строки временного текста
	EraseFromBeginning(tempStr, 1, 3);
	EraseFromBeginning(tempStr, 2, 10);
	EraseFromBeginning(tempStr, 3, 1);
	EraseFromBeginning(tempStr, 4, 15);
	EraseFromBeginning(tempStr, 5, 5);

	// Счетчики успешных тестов
	bool countFirst = false;
	bool countSecond = false;
	bool countThird = false;
	bool countFourth = false;
	bool countFifth = false;

	if (tempStr[0] == "ока")
		countFirst = true;
	else
		cout << "Тестирование удаления символов с начала строки из одного слова провалено." << endl;
	if (tempStr[1] == "слов с маленькой буквы")
		countSecond = true;
	else
		cout << "Тестирование удаления символов с начала строки из нескольких слов провалено." << endl;
	if (tempStr[2] == "2345")
		countThird = true;
	else
		cout << "Тестирование удаления символов с начала строки из цифр провалено." << endl;
	if (tempStr[3] == "(12345) и букв")
		countFourth = true;
	else
		cout << "Тестирование удаления символов с начала строки из нескольких слов и цифр провалено." << endl;
	if (tempStr[4] == "%)@&(@")
		countFifth = true;
	else
		cout << "Тестирование удаления символов с начала строки из символов провалено." << endl;
	if (countFirst && countSecond && countThird && countFourth && countFifth)
		return true;
	else {
		cout << "Тестирование модуля удаления символов с начала строки провалено." << endl;
		return false;
	}
}

// Тестирование модуля удаления символов с конца определенной строки
bool TestingEraseFromEnd(vector <string> str) {
	vector <string> tempStr;
	tempStr = str;

	// Вызов функции удаления символов с конца строки для каждой строки временного текста
	EraseFromEnd(tempStr, 1, 3);
	EraseFromEnd(tempStr, 2, 10);
	EraseFromEnd(tempStr, 3, 1);
	EraseFromEnd(tempStr, 4, 15);
	EraseFromEnd(tempStr, 5, 5);

	// Счетчики успешных тестов
	bool countFirst = false;
	bool countSecond = false;
	bool countThird = false;
	bool countFourth = false;
	bool countFifth = false;

	if (tempStr[0] == "стр")
		countFirst = true;
	else
		cout << "Тестирование удаления символов с конца строки из одного слова провалено." << endl;
	if (tempStr[1] == "несколько слов с мален")
		countSecond = true;
	else
		cout << "Тестирование удаления символов с конца строки из нескольких слов провалено." << endl;
	if (tempStr[2] == "1234")
		countThird = true;
	else
		cout << "Тестирование удаления символов с конца строки из цифр провалено." << endl;
	if (tempStr[3] == "строка из цифр")
		countFourth = true;
	else
		cout << "Тестирование удаления символов с конца строки из нескольких слов и цифр провалено." << endl;
	if (tempStr[4] == "-_@$_%")
		countFifth = true;
	else
		cout << "Тестирование удаления символов с конца строки из символов провалено." << endl;
	if (countFirst && countSecond && countThird && countFourth && countFifth)
		return true;
	else {
		cout << "Тестирование модуля удаления символов с конца строки провалено." << endl;
		return false;
	}
}

// Тестирование модуля замены всех первых строчных букв прописными
bool TestingLowerToUpper(vector <string> str) {
	vector <string> tempStr;
	tempStr = str;

	LowerToUpper(tempStr); // Вызов функции для замены всех первых строчных букв прописными

	// Счетчики успешных тестов
	bool countFirst = false;
	bool countSecond = false;
	bool countThird = false;
	bool countFourth = false;
	bool countFifth = false;

	if (tempStr[0] == "Строка")
		countFirst = true;
	else
		cout << "Тестирование замены первых строчных букв на прописные в строке из одного слова провалено." << endl;
	if (tempStr[1] == "Несколько Слов С Маленькой Буквы")
		countSecond = true;
	else
		cout << "Тестирование замены первых строчных букв на прописные в строке из нескольких слов провалено." << endl;
	if (tempStr[2] == "12345")
		countThird = true;
	else
		cout << "Тестирование замены первых строчных букв на прописные в строке из цифр провалено." << endl;
	if (tempStr[3] == "Строка Из Цифр (12345) И Букв")
		countFourth = true;
	else
		cout << "Тестирование замены первых строчных букв на прописные в строке из нескольких слов и цифр провалено." << endl;
	if (tempStr[4] == "-_@$_%)@&(@")
		countFifth = true;
	else
		cout << "Тестирование замены первых строчных букв на прописные в строке из символов провалено." << endl;
	if (countFirst && countSecond && countThird && countFourth && countFifth)
		return true;
	else {
		cout << "Тестирование модуля замены первых строчных букв на прописные провалено." << endl;
		return false;
	}
}

// Модульные тесты
void Testing() {
	vector <string> testStr; // Текст для тестов
	testStr = { "строка", "несколько слов с маленькой буквы", "12345", "строка из цифр (12345) и букв", "-_@$_%)@&(@"};
	if (TestingEraseFromBeginning(testStr) && (TestingEraseFromEnd(testStr))
		&& TestingLowerToUpper(testStr))
		cout << "Тестирование проведено успешно." << endl;
	else
		cout << "Тестирование провалено." << endl;
}
