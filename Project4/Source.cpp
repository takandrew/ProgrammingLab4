#include<iostream>
#include"Computing.h"
#include"Files.h"
#include"Menu.h"
#include"Testing.h"
#include <vector>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	Greeting(); // Вывод приветствия
	Testing(); // Проведение модульных тестов
	while (true) {
		unsigned int i;
		vector <string> text;
		int textChoice;
		int choiceOne = 1;
		int choiceTwo = 2;
		if (MenuImportData() == true) { // Проверка происхождения исходных данных
			ifstream fin;
			int fileReadCorrectCheck = 0;
			cout << "Введите путь к файлу:" << endl;
			string path;
			SetConsoleCP(1251);
			cin >> path;
			SetConsoleCP(866);
			fileReadCorrectCheck = FileReadCorrectChecking(path);
			while (fileReadCorrectCheck == false) { // Проверка корректности файла
				cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
				cout << "Введите путь к файлу:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
			}
			string buffer = "\0";
			fin.open(path);
			while (!fin.eof()) { // Чтение текста из файла
				while (getline(fin, buffer))
					text.push_back(buffer);
			}
			fin.close();
			while (text.size() == 0) {
				cout << "Данный файл не содержит текст. Пожалуйста попробуйте еще раз." << endl;
				cout << "Введите путь к файлу:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
				while (fileReadCorrectCheck == false) { // Проверка корректности файла
					cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
					cout << "Введите путь к файлу:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
				}
				buffer = "\0";
				fin.open(path);
				while (!fin.eof()) { // Чтение текста из файла
					while (getline(fin, buffer))
						text.push_back(buffer);
				}
				fin.close();
			}
			cout << endl << "Полученный из файла текст:" << endl;
			for (i = 0; i < text.size(); i++)
				cout << text[i] << endl;
			cout << endl;
		}
		else { // Ввод текста с клавиатуры
			cout << "Введите текст:" << endl;
			cout << "Чтобы завершить ввод текста, нажмите Enter дважды." << endl;
			string buffer = "\0";
			SetConsoleCP(1251);
			bool firstTry = true;
			while (true) {
				getline(cin, buffer);
				if (buffer != "\0")
					text.push_back(buffer);
				else {
					if (text.size() == false) {
						if (firstTry == true)
							firstTry = false;
						else {
							SetConsoleCP(866);
							cout << "Вы не ввели текст. Пожалуйста, попробуйте еще раз." << endl;
							cout << "Введите текст:" << endl;
							cout << "Чтобы завершить ввод текста, нажмите Enter дважды." << endl;
							SetConsoleCP(1251);
						}
					}
					else
						break;
				}
			}
			SetConsoleCP(866);
			if (MenuExportData() == true) // Возможность вывода исходного текста в файл
				FileWriteData(text);
		}
		do { // Работа с текстом
			cout << endl;
			for (i = 0; i < text.size(); i++) { 
				cout << i+1 << ". " << text[i] << endl;
			}
			textChoice = MenuTextWork(); // Получение варианта работы с текстом от пользователя
			if (textChoice == choiceOne) { // Удаление символов с начала определенной строки
				int line, number;
				cout << "Выберите строку, в которой нужно удалить символы:" << endl;
				line = NumInInt();
				int text_size = text.size();
				while ((line <= 0) || (line > text_size)) {
					cout << "Некорректно введенные данные. Пожалуйста попробуйте еще раз:" << endl;
					line = NumInInt();
				}
				cout << "Введите количество символов, которые необходимо удалить:" << endl;
				number = NumInInt();
				while (number < 0) {
					cout << "Некорректно введенные данные. Пожалуйста попробуйте еще раз:" << endl;
					number = NumInInt();
				}
				EraseFromBeginning(text, line, number); // Вызов функции для удаления символов количеством number
				                                  //с начала строки line
				cout << endl;
				for (i = 0; i < text.size(); i++) {
					cout << i+1 << ". " << text[i] << endl;
				}
			}
			else if (textChoice == choiceTwo) { // Удаление символов с конца определенной строки
				int line, number;
				cout << "Выберите строку, в которой нужно удалить символы:" << endl;
				line = NumInInt();
				int text_size = text.size();
				while ((line <= 0) || (line > text_size)) {
					cout << "Некорректно введенные данные. Пожалуйста попробуйте еще раз:" << endl;
					line = NumInInt();
				}
				cout << "Введите количество символов, которые необходимо удалить:" << endl;
				number = NumInInt();
				while (number < 0) {
					cout << "Некорректно введенные данные. Пожалуйста попробуйте еще раз:" << endl;
					number = NumInInt();
				}
				EraseFromEnd(text, line, number); // Вызов функции для удаление символов количеством number с конца строки line
				cout << endl;
				for (i = 0; i < text.size(); i++) {
					cout << i+1 << ". " << text[i] << endl;
				}
			}
			else { // Замена всех первых строчных букв прописными
				LowerToUpper(text);
				cout << endl;
				for (i = 0; i < text.size(); i++) {
					cout << i+1 << ". " << text[i] << endl;
				}
			}
		} while (MenuTextWorkSelect() == true); // Возможность выбора продолжения работы с текстом
		if (MenuResult() == true) // Возможность выбора сохранения результата программы в файл
			FileWriteData(text);
		if (Menu() == false) // Вызов основного меню после завершения работы программы
			return false;
	}
	return 0;
}