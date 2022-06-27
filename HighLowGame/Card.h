#pragma once
#include <iostream>
#include <string>

#define Max 52

using namespace std;

enum CardMark
{
	Clover = 0,
	Heart,
	Dia,
	Spade
};

struct stCard
{
	CardMark mark;
	int number;

	// �Լ� �̸� : printCard
	// �Ķ��Ÿ : ����
	// ��ȯ�� : ����
	// Mark = Spade Number = 7 <--- �̷��� ȭ�鿡 ����ϴ� �Լ��� ����ÿ�
	void printCard()
	{
		cout << "Mark = " << GetStrMark() << " Number = " << number << endl;
	}

	string GetStrMark()
	{
		switch (mark)
		{
		case Clover:	return "Clover";	break;
		case Heart:	return "Heart";	break;
		case Dia:		return "Dia";		break;
		case Spade:	return "Spade";	break;
		default:		return "";			break;
		}
	}

	
};

