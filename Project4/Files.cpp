#include"Menu.h"
#include"Files.h"
#include<stdlib.h>
#include <experimental/filesystem>
using namespace std::experimental::filesystem;

// �������� ������������� �����
bool FileExist(string path) {
	WIN32_FIND_DATA wfd;
	LPCSTR pathLPC = path.c_str();
	HANDLE hfind = ::FindFirstFile(pathLPC, &wfd);
	if (INVALID_HANDLE_VALUE != hfind) {
		::FindClose(hfind);
		return true;
	}
	return false;
}

//�������, �����������, �������� �� ���� ��������� ������ ��� ������. ��������� ���� � �����.
bool ReadOnlyChecking(string path) {
	LPCSTR name = path.c_str();
	WIN32_FIND_DATAA findData;
	FindFirstFileA(name, &findData);
	if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
		cout << endl << "� ������ ���� ���������� �������� ������. �������� ������ ��� ������." << endl;
		return false;
	}
	else {
		return true;
	}
}

//�������, ����������� ������������ �����
bool FileCorrectChecking(string path) {
	int one = 1, four = 4;
	size_t five = 5;
	size_t found = path.find_last_of("\\");
	size_t point = path.find_last_of(".");
	size_t base = point - found - one;
	string basefilenameStr = path.substr(found + one, base);
	const char* basefilenameChar = basefilenameStr.c_str();
	if (!_strcmpi(basefilenameChar, "con")) {
		cout << endl << "������������ ��� �����." << endl;
		return false;
	}
	if (path.size() < five) {
		cout << endl << "������������ ��� �����. ��������� ������ ���������� ����� ����� ��������" << endl;
		return false;
	}
	if (path.substr(path.size() - four) != ".txt") {
		cout << endl << "������������ ������ �����. ��������� ���� ������� .txt" << endl;
		return false;
	}
	if (!FileExist(path)) {
		return true;
	}
	if (!is_regular_file(path)) {
		cout << endl << "���� �� �������� �������." << endl;
		return false;
	}
	return true;
}

//�������, ����������� ������������ �����, �� �������� ��������� ������
bool FileReadCorrectChecking(string path) {
	int one = 1, four = 4;
	size_t five = 5;
	size_t found = path.find_last_of("\\");
	size_t point = path.find_last_of(".");
	size_t base = point - found - one;
	string basefilenameStr = path.substr(found + one, base);
	const char* basefilenameChar = basefilenameStr.c_str();
	if (!_strcmpi(basefilenameChar, "con")) {
		cout << endl << "������������ ��� �����." << endl;
		return false;
	}
	if (path.size() < five) {
		cout << endl << "������������ ��� �����. ��������� ������ ���������� ����� ����� ��������" << endl;
		return false;
	}
	if (!FileExist(path)) {
		cout << endl << "����� �� ���������� ���� �� ����������" << endl;
		return false;
	}
	if (path.substr(path.size() - four) != ".txt") {
		cout << endl << "������������ ������ �����. ��������� ���� ������� .txt" << endl;
		return false;
	}
	if (!is_regular_file(path)) {
		cout << endl << "���� �� �������� �������." << endl;
		return false;
	}
	return true;
}

// �������, ����������� �������� �����
bool FileOpenChecking(string path) {
	if (!FileExist(path)) {
		ofstream fout;
		fout.open(path);
		if (!fout.is_open()) {
			if (!is_regular_file(path)) {
				return false;
			}
			else {
				remove(path);
				return false;
			}
		}
		fout.close();
		remove(path);
		return true;
	}
	else
		return true;
}

// ����� ������ � ����
void FileWriteData(vector <string>& text) {
	unsigned int i;
	ofstream fout;
	string path;
	bool readOnlyCheck = 0;
	bool fileCorrectCheck = 0;
	bool fileOpenCheck = 0;
	cout << endl << "������� ���� � �����:" << endl;
	SetConsoleCP(1251);
	cin >> path;
	SetConsoleCP(866);
	readOnlyCheck = ReadOnlyChecking(path);
	fileCorrectCheck = FileCorrectChecking(path);
	fileOpenCheck = FileOpenChecking(path);
	while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
		cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
		cout << "������� ���� � �����:" << endl;
		SetConsoleCP(1251);
		cin >> path;
		SetConsoleCP(866);
		readOnlyCheck = ReadOnlyChecking(path);
		fileCorrectCheck = FileCorrectChecking(path);
		fileOpenCheck = FileOpenChecking(path);
	}
	if (FileExist(path) == true) { // �������� ������������� �����
		if (MenuReWrite() == true) { // ����������� ������ ���������� � ����
			fout.open(path);
			// ����� �������� ������ � ����
			for (i = 0; i < text.size(); i++) {
				fout << text[i] << endl;
			}
		}
		else { // ����� �� ���������� � ����� ������� ���� � �����
			cout << "������� ���� � �����:" << endl;
			SetConsoleCP(1251);
			cin >> path;
			SetConsoleCP(866);
			readOnlyCheck = ReadOnlyChecking(path);
			fileCorrectCheck = FileCorrectChecking(path);
			fileOpenCheck = FileOpenChecking(path);
			while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
				cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
				cout << "������� ���� � �����:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				readOnlyCheck = ReadOnlyChecking(path);
				fileCorrectCheck = FileCorrectChecking(path);
				fileOpenCheck = FileOpenChecking(path);
			}
			while (FileExist(path) == true) { // ���� �������� �������������, ���������� ��� ������ ������� ���� � �����
				if (MenuReWrite() == true) {
					break;
				}
				else {
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					readOnlyCheck = ReadOnlyChecking(path);
					fileCorrectCheck = FileCorrectChecking(path);
					fileOpenCheck = FileOpenChecking(path);
					while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
						cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
						cout << "������� ���� � �����:" << endl;
						SetConsoleCP(1251);
						cin >> path;
						SetConsoleCP(866);
						readOnlyCheck = ReadOnlyChecking(path);
						fileCorrectCheck = FileCorrectChecking(path);
						fileOpenCheck = FileOpenChecking(path);
					}
				}
			}
			SetConsoleCP(866);
			fout.open(path);
			// ����� �������� ������ � ����
			for (i = 0; i < text.size(); i++) {
				fout << text[i] << endl;
			}
		}
	}
	else { // ���� ����� �� ���������� 
		fout.open(path);
		// ����� �������� ������ � ����
		for (i = 0; i < text.size(); i++) {
			fout << text[i] << endl;
		}
	}
	cout << endl << "���� ������� ��������." << endl;
	fout.close();
}