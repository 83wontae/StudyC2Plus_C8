#pragma once

/*
*  Counter2 Ŭ���� ����
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

class Counter2
{
	int value;

public:
	Counter2(int count) : value{ count } {
	}
	Counter2(const Counter2& c) : value{ c.value } {
	}

	void reset() {
		value = 0;
	}

	void count() {
		value++;
	}

	int getValue() const {
		return value;
	}
};