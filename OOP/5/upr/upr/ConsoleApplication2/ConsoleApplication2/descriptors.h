#pragma once
#include "lexicalUnit.h"
class descriptors
{
	lexicalUnit table[100];
	int number;
public:
	descriptors();
	~descriptors();
	int Add(lexicalUnit &lu);          // ����� 1, ��� ������� �������� � 0 � �������� ������
	int Del(const char *pIdentificator);     // ����� 1, ��� ������� ��������� � 0 � �������� ������
	int Search(const char  *pIdentificator); // ����� ��������� �� ������������ ������� � ������ ��� -1 � �������� ������
	void Print();
};

