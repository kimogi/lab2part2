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
typedef struct Account {
	int test;
	//int id;
	//bool is_empty;
	//unsigned long long account_id;
	//long fund_sum;
	//long last_edited;
	//Date date;
	//Name name;
} Account;

void scanData(Account *acc)
{
	printf("please type a number:\n");
	scanf("%d", &acc->test);
}

void printData(Account *acc)
{
	printf("your number: %d\n", acc->test);
}

void main()
{
	Account d;

	scanData( &d );
	printData( &d );
}
