#include<iostream>
#include"Computing.h"
#include"Testing.h"

using namespace std;

// Приветствие
void Greeting() {
	cout << "Данная программа представляет из себя текстовый редактор, в котором пользователь имеет возможность:" << endl;
	cout << "- Удалять символы с начала заданной строки." << endl;
	cout << "- Удалять символы с конца заданной строки." << endl;
	cout << "- Заменять все первые строчные буквы слов прописными." << endl;
	cout << endl;
	cout << "Автор: Кувылькин Андрей" << endl;
	cout << "Группа: 494" << endl;
	cout << "Лабораторная работа №4" << endl;
	cout << "Вариант 10" << endl;
	cout << endl;
}

// Основное Меню
bool Menu() {
	enum MenuCase { again = 1, info, testing, finish };
	int variant;
	cout << endl;
	cout << "MENU" << endl;
	cout << "Выберите вариант:" << endl;
	cout << "1. Начать программу заново." << endl;
	cout << "2. Вывести информацию о программе и авторе." << endl;
	cout << "3. Провести тестирование." << endl;
	cout << "4. Выйти из программы." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case again: return true;
	case info: {cout << endl; Greeting(); return Menu(); }
	case testing: {Testing(); return Menu(); }
	case finish: {cout << "Программа завершена." << endl; return false; }
	default: {cout << "Введено неправильное значение." << endl; return Menu(); }
	}
}

// Меню сохранения результата программы в файл
bool MenuResult() {
	enum MenuResuiltCase { Yes = 1, No };
	int variant;
	cout << endl;
	cout << "Сохранить результат в файл?" << endl;
	cout << "1. Да." << endl;
	cout << "2. Нет." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "Введено неправильное значение." << endl; return MenuResult(); }
	}
}

// Меню сохранения исходных данных в файл
bool MenuExportData() {
	enum MenuExportDataCase { Yes = 1, No };
	int variant;
	cout << endl;
	cout << "Сохранить исходные данные в файл?" << endl;
	cout << "1. Да." << endl;
	cout << "2. Нет." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "Введено неправильное значение." << endl; return MenuExportData(); }
	}
}

// Меню выбора происхождения исходных данных 
bool MenuImportData() {
	enum MenuImportDataCase { Yes = 1, No };
	int variant;
	cout << endl;
	cout << "Загрузить исходные данные из файла?" << endl;
	cout << "1. Загрузить исходные данные из файла." << endl;
	cout << "2. Ввести исходные данные самостоятельно." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "Введено неправильное значение." << endl; return MenuImportData(); }
	}
}

// Меню выбора перезаписи данных в файл
bool MenuReWrite() {
	enum MenuReWriteCase { ReWrite = 1, SeekClear };
	int variant;
	cout << endl;
	cout << "Файл уже хранит в себе данные. Выберите необходимое действие:" << endl;
	cout << "1. Перезаписать данные в файле" << endl;
	cout << "2. Указать путь к другому файлу" << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case ReWrite: return true;
	case SeekClear: return false;
	default: {cout << "Введено неправильное значение." << endl; return MenuReWrite(); }
	}
}

// Меню вариантов работы с текстом
int MenuTextWork() {
	enum MenuTextWorkCase {DelFromBeg = 1, DelFromEnd, ReplaceFirstSmalltoCapital};
	int variant;
	cout << endl;
	cout << "Выберите необходимое действие:" << endl;
	cout << "1. Удалить символы с начала заданной строки." << endl;
	cout << "2. Удалить символы с конца заданной строки." << endl;
	cout << "3. Заменить все первые строчные буквы слов прописными." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case DelFromBeg: return DelFromBeg;
	case DelFromEnd: return DelFromEnd;
	case ReplaceFirstSmalltoCapital: return ReplaceFirstSmalltoCapital;
	default: {cout << "Введено неправильное значение." << endl; return MenuTextWork(); }
	}
}

// Меню выбора продолжения работы с текстом
bool MenuTextWorkSelect() {
	enum MenuTextWorkSelectCase {Yes = 1, No};
	int variant;
	cout << endl;
	cout << "Выберите необходимое действие:" << endl;
	cout << "1. Продолжить работу с текстом." << endl;
	cout << "2. Закончить работу с текстом." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "Введено неправильное значение." << endl; return MenuTextWorkSelect(); }
	}
}