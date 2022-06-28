#pragma once
#include <iostream>


using namespace std;
// Ŭ���� �̸� : Student
// �ɹ����� :
// private:
// string mName, int mClassNum, int mScore;
// ��� �ɹ� ������ �����ڿ��� 
// string name, int classNum, int score �Ķ��Ÿ�� �޾Ƽ� �ʱ�ȭ �մϴ�.

class Student
{
	string mName;
	int mClassNum;
	int nScore;

public:
	Student(string name, int classNum, int score) :
		mName(name), mClassNum(classNum), nScore(score) {};

	//�Լ� �̸� : PrintInfo
	//�Ķ��Ÿ : ����
	//��ȯ�� : ����
	//�Լ� ��� : cout << "�̸� : " << mName << ", " << mClassNum << " ����: " << nScore << endl;
	void PrintInfo()
	{
		cout << "�̸� : " << mName << ", " << mClassNum << " ����: " << nScore << endl;
	}

	string GetName() { return mName; };
	int GetClassNum() { return mClassNum; };
	int GetScore() { return nScore; };

};

