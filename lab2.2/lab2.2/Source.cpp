/*���� 2, ����� 2, ������� 2. 
������� �.�., ����� �����, ����� �� �����, ���� ���������� ���������.*/
/*
1 - ���� ���������(�����) ��������� +
2 - ����� +
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
#include <malloc.h>

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

void scanData(Account *accounts, int *a)
{
	printf("please type a number:\n");
	scanf("%d", &accounts->test);
}

void printData(Account *accounts, int *a)
{
	printf("your number: %d\n", accounts->test);
}

void menu(Account *accounts, int *id)
{
	printf("\t please, write a number to select an option\n\n");
	printf("\t 1. create new account\n\t 2. show account\n\n");
	int in = 0;
	printf("\t ");
	scanf("%d\n", &in);

	switch (in)
	{
	case 1:
		scanData(accounts, id);
		break;
	case 2:
		printData(accounts, id);
		break;
	}
}

void main()
{
	int size = 1;

	int *id = (int *)malloc(size * sizeof(int));
	Account *accounts = (Account *)malloc(size * sizeof(Account));
	menu(accounts, id);

	free(accounts);
	free(id);
}
