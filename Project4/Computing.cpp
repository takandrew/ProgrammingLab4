#include<iostream>
#include <Windows.h>
#include "Computing.h"
#include "Files.h"
#include "Menu.h"
using namespace std;

// �������� ������������ ����� �������� ���������� ���� int
int NumInInt() {
	int variable;
	while (!(cin >> variable) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "����������� ��������� ������. ����������, ������� �����: " << endl;
	}
	return variable;
}

// �������, ��������� ������� ����������� number � ������ ������ 

void EraseFromBeginning(vector <string>& text, int line, int number) {
	text[line-1].erase(0, number);
}

// �������, ��������� ������� ����������� number � ����� ������ line
void EraseFromEnd(vector <string>& text, int line, int number) {
	int endOfStr; 
	endOfStr = text[line-1].length(); // ����������, ������ ���������� �������� � ������
	if (number > endOfStr) {
		cout << "� ������ ��� ������� ��������, ������� ���������� �������. ���������� ���������� ��� ���:" << endl;
		cout << "�������� � ������: " << endOfStr << endl;
		cout << "������� ���������� ��������, ������� ���������� �������:" << endl;
		number = NumInInt();
		while ((number < 0) || (number > endOfStr)) {
			cout << "����������� ��������� ������. ���������� ���������� ��� ���:" << endl;
			number = NumInInt();
		}
	}
	text[line-1].erase((endOfStr - number), number);
}

// �������, ���������� ��� ������ �������� ����� ������ ����������
void LowerToUpper(vector <string>& text) {
	char lower = '�', upper = '�';
	string letters = "qwetryuiopasdfghjklzxcbvnm��������������������������������QWERTYUIOPASDFGHJKLZXCVBNM����Ũ���������������������������";
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