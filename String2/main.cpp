#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
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


	//arrString에 "AAA BBB CCC DDD EEE FFF GGG HHH"문자를 잘라서 아래와 같이 넣어라
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
	//arrString에 "AAA=111 BBB=222 CCC=333 DDD=444 EEE=555"문자를 잘라서 아래와 같이 넣어라
	//arrString[0] = "AAA", arrInt[0] = 111
	//arrString[1] = "BBB", arrInt[1] = 222
	//arrString[2] = "CCC", arrInt[2] = 333
	//arrString[3] = "DDD", arrInt[3] = 444
	//arrString[4] = "EEE", arrInt[4] = 555

	vector<string> arrString;
	vector<int> arrInt;
	string str = "AAA=111 BBB=222 CCC=333 DDD=444 EEE=555";

	int findKey = 0;
	while (true)
	{
		int temp = str.find(" ", findKey);
		if (temp == string::npos)
			break;

		string subStr = str.substr(findKey, temp - findKey);
		int subTemp = subStr.find("=");
		arrString.push_back(subStr.substr(0, subTemp));
		string strNum = subStr.substr(subTemp + 1, subStr.length());
		arrInt.push_back(stoi(strNum));
		findKey = temp + 1;
	}

	for (string s : arrString)
	{
		cout << s << endl;
	}

	for (int n : arrInt)
	{
		cout << n << endl;
	}
}