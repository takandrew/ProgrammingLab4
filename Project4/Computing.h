#pragma once
#include<string>
#include <vector>
using namespace std;

int NumInInt(); // �������� ������������ ����� �������� ���������� ���� int
void EraseFromBeginning(vector <string>& text, int line, int number); // �������, ��������� ������� 
                                               //����������� number � ������ ������ line
void EraseFromEnd(vector <string>& text, int line, int number); // �������, ��������� ������� ����������� number � ����� ������ line
void LowerToUpper(vector <string>& text); // �������, ���������� ��� ������ �������� ����� ������ ����������