#pragma once

/*
*  Counter Ŭ���� ����
*  
* �ɹ�����
*  int value //value ���� �����ڿ��� �ʱ�ȭ �Ѵ�.
* 
* �Լ�
* public:
* void reset(); //value ���� 0���� �ʱ�ȭ �Ѵ�
* void count(); //value ���� 1�� ���� ��Ų��
* int getValue() const; // value���� return �Ѵ�.
*/

class Counter
{
	int value;

public:
	Counter() : value{ 0 }	{
	}

	void reset()	{
		value = 0;
	}

	void count()	{
		value++;
	}

	int getValue() const	{
		return value;
	}
};

