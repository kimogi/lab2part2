/*���� 2, ����� 2, ������� 2. 
������� �.�., ����� �����, ����� �� �����, ���� ���������� ���������.*/
/*
1 - ���� ���������(�����) ���������
2 - �����
3 - �������� ����������������� ����������
4 - ����� ��������� ����������������� ����������
5 - ����� � ������� ��������� � ����������� ��������� ��������� ����
6 - ����� � ������� �������� �������� � �������� ��������� ���� ��� � �������� ������� � ���� �� ��������
7 - �������� ��������� ��������
8 - ���������(��������������) ��������� ��������
9 - ���������� ������� �������� � ������� ����������� ��������� ����
	(��� ���������� ����� ������������ ��� ����, ��� � ��++ ����������� ������������ ����������������� ����������)
10 - ���������� � ��������� � �������������� ���� ��������� ������� �� ��������� ������� � �������
	(��������, ����� ����� �� ���� ������) - ������ ������������� 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//struct Date
//{
//	unsigned short day;
//	unsigned short month;
//	unsigned short year;
//};
//struct Name
//{
//	char first_name[80];
//	char last_name[80];
//	char *patronymic[80];
//};
struct Account 
{
	int test;
	//int id;
	//bool is_empty;
	//unsigned long long account_id;
	//long fund_sum;
	//long last_edited;
	//Date date;
	//Name name;
}d;
Account scanData()
{
	Account a;
	scanf("please type a number: %d\n", &a.test);
	return a;
}
void printData(Account a)
{
	printf("your number: %d\n", a.test);
}

void main()
{
	d = scanData();
	printData(d);
}