#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
* �Լ��̸� : StringCutHalfwithKey
* �Ķ��Ÿ : const string& source, char key, string& leftstr, string& rightstr
* ��ȯ�� : ����
* �Լ����� : source ���ڸ� key ���ڱ������� ���� ���ڴ� leftstr�� �ְ� ������ ���ڴ� rightstr�� �ִ´�.
* 
* ex)	source�� "AAA=111"�̰�, key�� '=' �̶��
*		leftstr = AAA, rightstr = 111
*/
void StringCutHalfwithKey(const string& source, char key, string& leftstr, string& rightstr)
{
	int index = source.find(key);
	leftstr = source.substr(0, index);
	rightstr = source.substr(index + 1);
}

/*
* �Լ��̸�: StringCutByKey
* �Ķ��Ÿ: const string& source, char key
* ��ȯ��: vector<string>
* �Լ�����: source ���ڸ� key ���� �������� �ڸ� ������ vector<string>���� ��ȯ �Ѵ�.
* 
* ex) source�� "aaa bbb ccc ddd eee" key�� ' ' �̶��
* vector<string>[0] = "aaa"
* vector<string>[1] = "bbb"
* vector<string>[2] = "ccc"
* vector<string>[3] = "ddd"
* vector<string>[4] = "eee"
*/
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

struct student
{
	string name = "";
	float score = 0;
	int age = 0;

	void printInfo()
	{
		cout << "name = " << name << " score = " << score << " age = " << age << endl;
	}
};

int main()
{
	// strData�� ���� �л��� ������ st1�� �����ÿ�.
	student st1;
	string strData = "name=john score=3.6 age=20";
	vector<string> arrStr = StringCutByKey(strData, ' ');
	for (string s : arrStr)
	{
		string left = "";
		string right = "";
		StringCutHalfwithKey(s, '=', left, right);
		if (left == "name")
		{
			st1.name = right;
		}
		else if(left == "score")
		{
			st1.score = stof(right);
		}
		else if (left == "age")
		{
			st1.age = stoi(right);
		}
	}

	st1.printInfo();

	/*
	string str = "123+456";
	cin >> str;

	int point = str.rfind("+");
	cout << "point = " << point << endl;
	string leftstr = str.substr(0, point);
	string rightstr = str.substr(point + 1, str.length());
	int leftNum = stoi(leftstr);
	int rightNum = stoi(rightstr);
	cout << "leftNum + rightNum = " << leftNum + rightNum << endl;
	

	string str = "123-456";
	int point = str.rfind("-");
	cout << "point = " << point << endl;
	string leftstr = str.substr(0, point);
	string rightstr = str.substr(point + 1, str.length());
	int leftNum = stoi(leftstr);
	int rightNum = stoi(rightstr);

	cout << "leftNum - rightNum = " << leftNum - rightNum << endl;
	*/


	//arrString�� "AAA BBB CCC DDD EEE FFF GGG HHH"���ڸ� �߶� �Ʒ��� ���� �־��
	//arrString[0] = "AAA"
	//arrString[1] = "BBB"
	//arrString[2] = "CCC"
	//arrString[3] = "DDD"
	//arrString[4] = "EEE"
	//arrString[5] = "FFF"
	//arrString[6] = "GGG"
	//arrString[7] = "HHH"
	/*
	vector<string> arrString;
	string str = "AAA BBB CCC DDD EEE FFF GGG HHH";

	int findKey = 0;
	while (true)
	{
		int temp = str.find(" ", findKey);
		if (temp == string::npos)
			break;

		arrString.push_back(str.substr(findKey, temp - findKey));
		findKey = temp + 1;
	}

	for (string s : arrString)
	{
		cout << s << endl;
	}
	*/
	//arrString�� "AAA=111 BBB=222 CCC=333 DDD=444 EEE=555"���ڸ� �߶� �Ʒ��� ���� �־��
	//arrString[0] = "AAA", arrInt[0] = 111
	//arrString[1] = "BBB", arrInt[1] = 222
	//arrString[2] = "CCC", arrInt[2] = 333
	//arrString[3] = "DDD", arrInt[3] = 444
	//arrString[4] = "EEE", arrInt[4] = 555

	/*
	vector<string> arrString;
	vector<int> arrInt;
	string str = "AAA=111 BBB=222 CCC=333 DDD=444 EEE=555";

	vector<string> strs = StringCutByKey(str, ' ');

	for (string s : strs)
	{
		string subStr, strNum;
		StringCutHalfwithKey(s, '=', subStr, strNum);
		arrString.push_back(subStr);
		arrInt.push_back(stoi(strNum));
	}

	for (string s : arrString)
	{
		cout << s << endl;
	}

	for (int n : arrInt)
	{
		cout << n << endl;
	}
	*/
}