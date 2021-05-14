#include<iostream>
#include"Computing.h"
#include"Testing.h"

using namespace std;

// �����������
void Greeting() {
	cout << "������ ��������� ������������ �� ���� ��������� ��������, � ������� ������������ ����� �����������:" << endl;
	cout << "- ������� ������� � ������ �������� ������." << endl;
	cout << "- ������� ������� � ����� �������� ������." << endl;
	cout << "- �������� ��� ������ �������� ����� ���� ����������." << endl;
	cout << endl;
	cout << "�����: ��������� ������" << endl;
	cout << "������: 494" << endl;
	cout << "������������ ������ �4" << endl;
	cout << "������� 10" << endl;
	cout << endl;
}

// �������� ����
bool Menu() {
	enum MenuCase { again = 1, info, testing, finish };
	int variant;
	cout << endl;
	cout << "MENU" << endl;
	cout << "�������� �������:" << endl;
	cout << "1. ������ ��������� ������." << endl;
	cout << "2. ������� ���������� � ��������� � ������." << endl;
	cout << "3. �������� ������������." << endl;
	cout << "4. ����� �� ���������." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case again: return true;
	case info: {cout << endl; Greeting(); return Menu(); }
	case testing: {Testing(); return Menu(); }
	case finish: {cout << "��������� ���������." << endl; return false; }
	default: {cout << "������� ������������ ��������." << endl; return Menu(); }
	}
}

// ���� ���������� ���������� ��������� � ����
bool MenuResult() {
	enum MenuResuiltCase { Yes = 1, No };
	int variant;
	cout << endl;
	cout << "��������� ��������� � ����?" << endl;
	cout << "1. ��." << endl;
	cout << "2. ���." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "������� ������������ ��������." << endl; return MenuResult(); }
	}
}

// ���� ���������� �������� ������ � ����
bool MenuExportData() {
	enum MenuExportDataCase { Yes = 1, No };
	int variant;
	cout << endl;
	cout << "��������� �������� ������ � ����?" << endl;
	cout << "1. ��." << endl;
	cout << "2. ���." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "������� ������������ ��������." << endl; return MenuExportData(); }
	}
}

// ���� ������ ������������� �������� ������ 
bool MenuImportData() {
	enum MenuImportDataCase { Yes = 1, No };
	int variant;
	cout << endl;
	cout << "��������� �������� ������ �� �����?" << endl;
	cout << "1. ��������� �������� ������ �� �����." << endl;
	cout << "2. ������ �������� ������ ��������������." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "������� ������������ ��������." << endl; return MenuImportData(); }
	}
}

// ���� ������ ���������� ������ � ����
bool MenuReWrite() {
	enum MenuReWriteCase { ReWrite = 1, SeekClear };
	int variant;
	cout << endl;
	cout << "���� ��� ������ � ���� ������. �������� ����������� ��������:" << endl;
	cout << "1. ������������ ������ � �����" << endl;
	cout << "2. ������� ���� � ������� �����" << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case ReWrite: return true;
	case SeekClear: return false;
	default: {cout << "������� ������������ ��������." << endl; return MenuReWrite(); }
	}
}

// ���� ��������� ������ � �������
int MenuTextWork() {
	enum MenuTextWorkCase {DelFromBeg = 1, DelFromEnd, ReplaceFirstSmalltoCapital};
	int variant;
	cout << endl;
	cout << "�������� ����������� ��������:" << endl;
	cout << "1. ������� ������� � ������ �������� ������." << endl;
	cout << "2. ������� ������� � ����� �������� ������." << endl;
	cout << "3. �������� ��� ������ �������� ����� ���� ����������." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case DelFromBeg: return DelFromBeg;
	case DelFromEnd: return DelFromEnd;
	case ReplaceFirstSmalltoCapital: return ReplaceFirstSmalltoCapital;
	default: {cout << "������� ������������ ��������." << endl; return MenuTextWork(); }
	}
}

// ���� ������ ����������� ������ � �������
bool MenuTextWorkSelect() {
	enum MenuTextWorkSelectCase {Yes = 1, No};
	int variant;
	cout << endl;
	cout << "�������� ����������� ��������:" << endl;
	cout << "1. ���������� ������ � �������." << endl;
	cout << "2. ��������� ������ � �������." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "������� ������������ ��������." << endl; return MenuTextWorkSelect(); }
	}
}