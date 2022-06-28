#include <iostream>
#include "Student.h"
#include <vector>
#include <map>

using namespace std;

unsigned int UniqueID = 0;

unsigned int CreateUniqueID()
{
	return ++UniqueID;
}

int main()
{
	int mgrType = 0;
	vector<Student> vecStudent;
	map<unsigned int, Student> mapStudent;

	string name = "";
	int classNum = 0;
	int score = 0;

	while (true)
	{
		switch (mgrType)
		{
		case 1:
		{
			//���� 3�� ���� �Է� �޾Ƽ� vecStudent�� ���� �߰��ϵ��� ����� ������
			cout << "�̸��� �Է��ϼ���" << endl;
			cin >> name;
			cout << "���� �Է��ϼ���" << endl;
			cin >> classNum;
			cout << "������ �Է��ϼ���" << endl;
			cin >> score;
			Student aaa = { name, classNum, score };
			//vecStudent.push_back(aaa);
			mapStudent.insert({ CreateUniqueID(), aaa });
			mgrType = 0;
		}
		break;

		case 2:
		{
			unsigned int index = 0;
			// int index ���� �ϳ� �޾Ƽ� �ش� index�� �л� ������ �����ϵ��� �����մϴ�.
			cout << "������ �л��� �̸��� �Է��ϼ���" << endl;
			cin >> index;
			//vecStudent.erase(vecStudent.begin() + index);

			if (mapStudent.find(index) != mapStudent.end())
			{
				mapStudent.erase(index);
			}

			mgrType = 0;
		}
		break;

		case 3:
		{
			unsigned int uniqueID = 0;
			cout << "ã�� �л��� UniqueID�� �Է��ϼ���" << endl;
			// string name ���� �޾Ƽ� �̸��� ���� �л��� ã�Ƽ� ����Ͻÿ�.
			cin >> uniqueID;
			/*
			for (int i = 0; i < vecStudent.size(); ++i)
			{
				if (vecStudent[i].GetName() != name)
					continue;

				cout << "index = " << i << " ";
				vecStudent[i].PrintInfo();
			}
			*/

			//find�� ���� �ߴٸ� ã�� ��ü�� map �ּ� ��ȯ 
			//find�� ���� �ߴٸ� map�� ������ �ּ� ��ȯ
			auto iter = mapStudent.find(uniqueID);
			if (iter != mapStudent.end())
			{
				iter->second.PrintInfo();
			}
			mgrType = 0;
		}
		break;

		case 4:
		{
			//for (auto iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
			for (auto iter : mapStudent)
			{
				cout << "UniqueID = " << iter.first << " ";
				iter.second.PrintInfo();
			}
			/*
			for (int i = 0; i < vecStudent.size(); ++i)
			{
				cout << "index = " << i << " ";
				vecStudent[i].PrintInfo();
			}
			*/
			/*
			for (Student s : vecStudent)
			{
				s.PrintInfo();
			}
			*/
			mgrType = 0;
		}
		break;

		default:
			cout << "[StudentManager]" << endl;
			cout << "1) Add Student" << endl;
			cout << "2) Delete Student" << endl;
			cout << "3) Find Student" << endl;
			cout << "4) Print All Student" << endl;
			cin >> mgrType;
			break;
		}
		

		
	}
}