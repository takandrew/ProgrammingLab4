#include<iostream>
#include"Computing.h"

// ������������ ������ �������� �������� � ������ ������������ ������
bool TestingEraseFromBeginning(vector <string> str) {
	vector <string> tempStr; 
	tempStr = str;

	// ����� ������� �������� �������� � ������ ������ ��� ������ ������ ���������� ������
	EraseFromBeginning(tempStr, 1, 3);
	EraseFromBeginning(tempStr, 2, 10);
	EraseFromBeginning(tempStr, 3, 1);
	EraseFromBeginning(tempStr, 4, 15);
	EraseFromBeginning(tempStr, 5, 5);

	// �������� �������� ������
	bool countFirst = false;
	bool countSecond = false;
	bool countThird = false;
	bool countFourth = false;
	bool countFifth = false;

	if (tempStr[0] == "���")
		countFirst = true;
	else
		cout << "������������ �������� �������� � ������ ������ �� ������ ����� ���������." << endl;
	if (tempStr[1] == "���� � ��������� �����")
		countSecond = true;
	else
		cout << "������������ �������� �������� � ������ ������ �� ���������� ���� ���������." << endl;
	if (tempStr[2] == "2345")
		countThird = true;
	else
		cout << "������������ �������� �������� � ������ ������ �� ���� ���������." << endl;
	if (tempStr[3] == "(12345) � ����")
		countFourth = true;
	else
		cout << "������������ �������� �������� � ������ ������ �� ���������� ���� � ���� ���������." << endl;
	if (tempStr[4] == "%)@&(@")
		countFifth = true;
	else
		cout << "������������ �������� �������� � ������ ������ �� �������� ���������." << endl;
	if (countFirst && countSecond && countThird && countFourth && countFifth)
		return true;
	else {
		cout << "������������ ������ �������� �������� � ������ ������ ���������." << endl;
		return false;
	}
}

// ������������ ������ �������� �������� � ����� ������������ ������
bool TestingEraseFromEnd(vector <string> str) {
	vector <string> tempStr;
	tempStr = str;

	// ����� ������� �������� �������� � ����� ������ ��� ������ ������ ���������� ������
	EraseFromEnd(tempStr, 1, 3);
	EraseFromEnd(tempStr, 2, 10);
	EraseFromEnd(tempStr, 3, 1);
	EraseFromEnd(tempStr, 4, 15);
	EraseFromEnd(tempStr, 5, 5);

	// �������� �������� ������
	bool countFirst = false;
	bool countSecond = false;
	bool countThird = false;
	bool countFourth = false;
	bool countFifth = false;

	if (tempStr[0] == "���")
		countFirst = true;
	else
		cout << "������������ �������� �������� � ����� ������ �� ������ ����� ���������." << endl;
	if (tempStr[1] == "��������� ���� � �����")
		countSecond = true;
	else
		cout << "������������ �������� �������� � ����� ������ �� ���������� ���� ���������." << endl;
	if (tempStr[2] == "1234")
		countThird = true;
	else
		cout << "������������ �������� �������� � ����� ������ �� ���� ���������." << endl;
	if (tempStr[3] == "������ �� ����")
		countFourth = true;
	else
		cout << "������������ �������� �������� � ����� ������ �� ���������� ���� � ���� ���������." << endl;
	if (tempStr[4] == "-_@$_%")
		countFifth = true;
	else
		cout << "������������ �������� �������� � ����� ������ �� �������� ���������." << endl;
	if (countFirst && countSecond && countThird && countFourth && countFifth)
		return true;
	else {
		cout << "������������ ������ �������� �������� � ����� ������ ���������." << endl;
		return false;
	}
}

// ������������ ������ ������ ���� ������ �������� ���� ����������
bool TestingLowerToUpper(vector <string> str) {
	vector <string> tempStr;
	tempStr = str;

	LowerToUpper(tempStr); // ����� ������� ��� ������ ���� ������ �������� ���� ����������

	// �������� �������� ������
	bool countFirst = false;
	bool countSecond = false;
	bool countThird = false;
	bool countFourth = false;
	bool countFifth = false;

	if (tempStr[0] == "������")
		countFirst = true;
	else
		cout << "������������ ������ ������ �������� ���� �� ��������� � ������ �� ������ ����� ���������." << endl;
	if (tempStr[1] == "��������� ���� � ��������� �����")
		countSecond = true;
	else
		cout << "������������ ������ ������ �������� ���� �� ��������� � ������ �� ���������� ���� ���������." << endl;
	if (tempStr[2] == "12345")
		countThird = true;
	else
		cout << "������������ ������ ������ �������� ���� �� ��������� � ������ �� ���� ���������." << endl;
	if (tempStr[3] == "������ �� ���� (12345) � ����")
		countFourth = true;
	else
		cout << "������������ ������ ������ �������� ���� �� ��������� � ������ �� ���������� ���� � ���� ���������." << endl;
	if (tempStr[4] == "-_@$_%)@&(@")
		countFifth = true;
	else
		cout << "������������ ������ ������ �������� ���� �� ��������� � ������ �� �������� ���������." << endl;
	if (countFirst && countSecond && countThird && countFourth && countFifth)
		return true;
	else {
		cout << "������������ ������ ������ ������ �������� ���� �� ��������� ���������." << endl;
		return false;
	}
}

// ��������� �����
void Testing() {
	vector <string> testStr; // ����� ��� ������
	testStr = { "������", "��������� ���� � ��������� �����", "12345", "������ �� ���� (12345) � ����", "-_@$_%)@&(@"};
	if (TestingEraseFromBeginning(testStr) && (TestingEraseFromEnd(testStr))
		&& TestingLowerToUpper(testStr))
		cout << "������������ ��������� �������." << endl;
	else
		cout << "������������ ���������." << endl;
}
