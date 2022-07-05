#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>

using namespace std;

struct student
{
	string name = "";
	int age = 0;
	float score = 0;

	void printInfo()
	{
		cout << "name = " << name << " score = " << score << " age = " << age << endl;
	}
};

void StringCutHalfwithKey(const string& source, char key, string& leftstr, string& rightstr)
{
	int index = source.find(key);
	leftstr = source.substr(0, index);
	rightstr = source.substr(index + 1);
}

vector<string> StringCutByKey(const string& source, char key)
{
	vector<string> arrStr;

	int findKey = 0;
	while (true)
	{
		int temp = source.find(key, findKey);
		if (temp == string::npos)
			break;

		string out = source.substr(findKey, temp - findKey);
		out.erase(remove(out.begin(), out.end(), ' '), out.end());
		arrStr.push_back(out);
		findKey = temp + 1;
	}

	string out = source.substr(findKey);
	out.erase(remove(out.begin(), out.end(), ' '), out.end());
	arrStr.push_back(out);

	return arrStr;
}

/*
* �Լ��̸� : ReadStudent
* �Ķ��Ÿ : student& st, const string& str
* ��ȯ�� : ����
* �Լ����� : str�� ���� �о st�� �ִ´�.
* ex) str�� "name=aaa, age=20, score=1.1"�̶��
* st.name = "aaa"
* st.age = 20
* st.score = 1.1
*/
void ReadStudent(student& st, const string& str)
{
	vector<string> arrStr = StringCutByKey(str, ',');

	for (string s : arrStr)
	{
		string left, right;
		StringCutHalfwithKey(s, '=', left, right);
		if (left == "name") {
			st.name = right;
		}
		else if (left == "age") {
			st.age = stoi(right);
		}
		else if (left == "score") {
			st.score = stof(right);
		}
	}
}
/*
bool compare(student a, student b)
{
	return a.age < b.age;
}
*/
int main()
{
	/*
	string str = "ddddddddddd";
	ofstream file("writeFile.txt");
	if (file.is_open()) {
		file << "aaaaaaaaaa\n";
		file << "bbbbbbbbbbb" << endl;
		file << "ccccccccccc" << endl;
		file << str;
		file.close();
	}
	else	{
		cout << "���� ������ �����߽��ϴ�." << endl;
	}
	*/

	vector<student> arrSd;
	string line;
	ifstream file("writeFile.txt");
	if (file.is_open()) {
		while (getline(file, line))
		{
			student st;
			ReadStudent(st, line);
			arrSd.push_back(st);
		}
		file.close();
	}
	else {
		cout << "���� �б⸦ �����߽��ϴ�." << endl;
	}

	sort(arrSd.begin(), arrSd.end(), 
		[](student a, student b) {
			return a.age > b.age;
		}
	);

	for (student s : arrSd)
	{
		s.printInfo();
	}
}