#include<iostream>
#include"Computing.h"
#include"Files.h"
#include"Menu.h"
#include"Testing.h"
#include <vector>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	Greeting(); // ����� �����������
	Testing(); // ���������� ��������� ������
	while (true) {
		unsigned int i;
		vector <string> text;
		int textChoice;
		int choiceOne = 1;
		int choiceTwo = 2;
		if (MenuImportData() == true) { // �������� ������������� �������� ������
			ifstream fin;
			int fileReadCorrectCheck = 0;
			cout << "������� ���� � �����:" << endl;
			string path;
			SetConsoleCP(1251);
			cin >> path;
			SetConsoleCP(866);
			fileReadCorrectCheck = FileReadCorrectChecking(path);
			while (fileReadCorrectCheck == false) { // �������� ������������ �����
				cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
				cout << "������� ���� � �����:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
			}
			string buffer = "\0";
			fin.open(path);
			while (!fin.eof()) { // ������ ������ �� �����
				while (getline(fin, buffer))
					text.push_back(buffer);
			}
			fin.close();
			while (text.size() == 0) {
				cout << "������ ���� �� �������� �����. ���������� ���������� ��� ���." << endl;
				cout << "������� ���� � �����:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
				while (fileReadCorrectCheck == false) { // �������� ������������ �����
					cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
				}
				buffer = "\0";
				fin.open(path);
				while (!fin.eof()) { // ������ ������ �� �����
					while (getline(fin, buffer))
						text.push_back(buffer);
				}
				fin.close();
			}
			cout << endl << "���������� �� ����� �����:" << endl;
			for (i = 0; i < text.size(); i++)
				cout << text[i] << endl;
			cout << endl;
		}
		else { // ���� ������ � ����������
			cout << "������� �����:" << endl;
			cout << "����� ��������� ���� ������, ������� Enter ������." << endl;
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
							cout << "�� �� ����� �����. ����������, ���������� ��� ���." << endl;
							cout << "������� �����:" << endl;
							cout << "����� ��������� ���� ������, ������� Enter ������." << endl;
							SetConsoleCP(1251);
						}
					}
					else
						break;
				}
			}
			SetConsoleCP(866);
			if (MenuExportData() == true) // ����������� ������ ��������� ������ � ����
				FileWriteData(text);
		}
		do { // ������ � �������
			cout << endl;
			for (i = 0; i < text.size(); i++) { 
				cout << i+1 << ". " << text[i] << endl;
			}
			textChoice = MenuTextWork(); // ��������� �������� ������ � ������� �� ������������
			if (textChoice == choiceOne) { // �������� �������� � ������ ������������ ������
				int line, number;
				cout << "�������� ������, � ������� ����� ������� �������:" << endl;
				line = NumInInt();
				int text_size = text.size();
				while ((line <= 0) || (line > text_size)) {
					cout << "����������� ��������� ������. ���������� ���������� ��� ���:" << endl;
					line = NumInInt();
				}
				cout << "������� ���������� ��������, ������� ���������� �������:" << endl;
				number = NumInInt();
				while (number < 0) {
					cout << "����������� ��������� ������. ���������� ���������� ��� ���:" << endl;
					number = NumInInt();
				}
				EraseFromBeginning(text, line, number); // ����� ������� ��� �������� �������� ����������� number
				                                  //� ������ ������ line
				cout << endl;
				for (i = 0; i < text.size(); i++) {
					cout << i+1 << ". " << text[i] << endl;
				}
			}
			else if (textChoice == choiceTwo) { // �������� �������� � ����� ������������ ������
				int line, number;
				cout << "�������� ������, � ������� ����� ������� �������:" << endl;
				line = NumInInt();
				int text_size = text.size();
				while ((line <= 0) || (line > text_size)) {
					cout << "����������� ��������� ������. ���������� ���������� ��� ���:" << endl;
					line = NumInInt();
				}
				cout << "������� ���������� ��������, ������� ���������� �������:" << endl;
				number = NumInInt();
				while (number < 0) {
					cout << "����������� ��������� ������. ���������� ���������� ��� ���:" << endl;
					number = NumInInt();
				}
				EraseFromEnd(text, line, number); // ����� ������� ��� �������� �������� ����������� number � ����� ������ line
				cout << endl;
				for (i = 0; i < text.size(); i++) {
					cout << i+1 << ". " << text[i] << endl;
				}
			}
			else { // ������ ���� ������ �������� ���� ����������
				LowerToUpper(text);
				cout << endl;
				for (i = 0; i < text.size(); i++) {
					cout << i+1 << ". " << text[i] << endl;
				}
			}
		} while (MenuTextWorkSelect() == true); // ����������� ������ ����������� ������ � �������
		if (MenuResult() == true) // ����������� ������ ���������� ���������� ��������� � ����
			FileWriteData(text);
		if (Menu() == false) // ����� ��������� ���� ����� ���������� ������ ���������
			return false;
	}
	return 0;
}