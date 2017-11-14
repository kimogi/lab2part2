//����� 2, ���� 2, ������� 2. 
//������� �.�., ����� �����, ����� �� �����, ���� ���������� ���������.
/*
1 - ���� ���������(�����) ��������� +
2 - ����� +
3 - �������� ����������������� ���������� +
4 - ����� ��������� ����������������� ���������� +
5 - ����� � ������� ��������� � ����������� ��������� ��������� ����
6 - ����� � ������� �������� �������� � �������� ��������� ���� ��� � �������� ������� � ���� �� �������� +-
7 - �������� ��������� ��������
8 - ���������(��������������) ��������� ��������
9 - ���������� ������� �������� � ������� ����������� ��������� ���� +
	(��� ���������� ����� ������������ ��� ����, ��� � ��++ ����������� ������������ ����������������� ����������)
10 - ���������� � ��������� � �������������� ���� ��������� ������� �� ��������� ������� � �������
	(��������, ����� ����� �� ���� ������) - ������ ������������� 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <ctime>

typedef struct
{
	char firstName[80];
	char lastName[80];
	char *patronymic[80];
	bool isEmpty;
	unsigned long long id;
	unsigned long fundSum;
	long lasEdited;
	SYSTEMTIME systemTime;
} Account;

void time()
{
	Account getTime;
	getTime.systemTime.wMilliseconds = 0;
	GetSystemTime(&getTime.systemTime);
	printf("%d\n", getTime.systemTime.wMilliseconds);
}

void fillAcc(Account *accounts, int arrSize)
{
	Account getTime;
	getTime.systemTime.wMilliseconds = 0;
	for (int i = 0; i < arrSize; i++)
	{
		(accounts + i)->id = 10000000000000000 + rand() % 10000000000000000000;
		(accounts + i)->fundSum = 100000 + rand() % 10000000000000;
		GetSystemTime(&getTime.systemTime);
		//(accounts + i)->systemTime = getTime.systemTime.wMilliseconds;
	}
}

void printArrayTest(Account *accounts, int arrSize)
{
	printf("id		sum\n");
	for (int i = 0; i < arrSize; i++)
	{
		printf("%d	", (accounts + i)->id);
		printf("%d	", (accounts + i)->fundSum);
		printf("%d	", (accounts + i)->systemTime);
		printf("\n");
	}
	printf("\n\n");
}

void scanAcc(Account *accounts, int id)
{
	printf("please type a number:\n");
	scanf("%d", &(accounts + id)->test);
}

void printAcc(Account *accounts, int id)
{
	if ((accounts + id)->test != 0)
		printf("%d \n", (accounts + id)->test);
	else
		printf("account with this id doesent exist\n");
}

void clearingAcc(Account *accounts, int id, int arrSize)
{
	if (id < arrSize)
		(accounts + id)->test = 0;
}

void searchFreePlace(Account *accounts, int arrSize, int *acc)
{
	int i;
	for (i = 0; i < arrSize && (accounts + i)->test != 0; i++); 
	if ((accounts + i)->test == 0)
		(accounts + i)->test = *acc;
	else
		printf("there is no free places\n");
	
}

void searchAcc(Account *accounts, int arrSize, int *acc)
{
	int i;
	for (i = 0; i < arrSize && (accounts + i)->test != *acc; i++);
	i < arrSize? printf("%d\n", ((accounts + i)->test)): printf("no matches\n");
}

void sortAcc(Account *accounts, int arrsize)
{
	bool isSwap;
	do {
		isSwap = false;
		int lastSwap = 0;
		for (int i = 0; i < arrsize - 1; i++)
		{
			if ((accounts + i)->test >(accounts + i +1)->test)
			{
				int t = (accounts + i)->test;
				(accounts + i)->test = (accounts + i+1)->test;
				(accounts + i+1)->test = t;
				isSwap = true;
				lastSwap = i + 1;
			}
		}
		arrsize = lastSwap;
	} while (isSwap);
}

void main()
{
	int arrSize = 3;

	Account *accounts = (Account *)malloc(arrSize * sizeof(Account));

	//fillAcc(accounts, arrSize);
	//printArrayTest(accounts, arrSize);
	//searchAcc(accounts, arrSize, &acc);
	time();

	free(accounts);
}