#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Computing.h"
#include<Windows.h>
using namespace std;

bool FileExist(string path); // �������� ������������� �����
void FileWriteData(vector <string>& text); // ����� ������ � ����
bool ReadOnlyChecking(string path); //�������, �����������, �������� �� ���� ��������� ������ ��� ������. ��������� ���� � �����.
bool FileCorrectChecking(string path); //�������, ����������� ������������ �����
bool FileReadCorrectChecking(string path); //�������, ����������� ������������ �����, �� �������� ��������� ������
bool FileOpenChecking(string path); // �������, ����������� �������� �����