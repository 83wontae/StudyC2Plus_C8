#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

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
		int temp = source.find(" ", findKey);
		if (temp == string::npos)
			break;

		arrStr.push_back(source.substr(findKey, temp - findKey));
		findKey = temp + 1;
	}

	arrStr.push_back(source.substr(findKey));

	return arrStr;
}

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
		cout << "파일 저장을 실패했습니다." << endl;
	}
	*/

	vector<student> arrSd;
	string line;
	ifstream file("writeFile.txt");
	if (file.is_open()) {
		while (getline(file, line))
		{
			student st;
			vector<string> arrStr = StringCutByKey(line, ' ');

			for (string s : arrStr)
			{
				string left, right;
				StringCutHalfwithKey(s, '=', left, right);
				if (left == "name")	{
					st.name = right;
				}
				else if (left == "age")	{
					st.age = stoi(right);
				}
				else if (left == "score")	{
					st.score = stof(right);
				}
			}

			arrSd.push_back(st);
		}
		file.close();
	}
	else {
		cout << "파일 읽기를 실패했습니다." << endl;
	}

	for (student s : arrSd)
	{
		s.printInfo();
	}
}