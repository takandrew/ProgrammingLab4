#pragma once
#include<string>
#include <vector>
using namespace std;

int NumInInt(); // ѕроверка корректности ввода значений переменной типа int
void EraseFromBeginning(vector <string>& text, int line, int number); // ‘ункци€, удал€юща€ символы 
                                               //количеством number с начала строки line
void EraseFromEnd(vector <string>& text, int line, int number); // ‘ункци€, удал€юща€ символы количеством number с конца строки line
void LowerToUpper(vector <string>& text); // ‘ункци€, замен€юща€ все первые строчные буквы текста прописными