#include <iostream>
#include "funcSum.h"
#include "funcMinues.h"
#include "funcMulti.h"
#include "funcDivid.h"
#include "funcSum3.h"
#include "funcRemain.h"
#include "funcAverage.h"
#include "funcFmulit.h"

using namespace std;

// multi2(5) == 5*5
// multi2(5+1) == 5+1*5+1
#define multi2(x) x*x

int main()
{
	int r = multi2(5 + 1);
	cout << r << endl;

	int Sum = 0;//Sum�̶�� int�� ������ �����ϰ� 0���� �ʱ�ȭ
	int a, b = 0;
	char c = 0;

	funcSum(Sum, 10);

	while (true)
	{
		//"1 + 1"�������� �Է� �޴´�.
		cin >> a >> c >> b;


		// c�� ��ȣ�� ���� ( + ,- ,* ,/ ,% ) ������ �ϵ��� ���弼�� 
		switch (c)
		{
		case '+':
			Sum = a + b;
			break;
		case '-':
			Sum = a - b;
			break;
		case '*':
			Sum = a * b;
			break;
		case '/':
			Sum = a / b;
			break;
		case '%':
			Sum = a % b;
			break;
		case '^':
			//�¼� ���ϱ�
			//2 ^ 5 = 2*2*2*2*2
			Sum = funcFmulit(a, b);
			break;
		default:
			break;
		}

		//�Է��� ���Ŀ� �´� Sum ���� ��� �ϼ���
		cout << a << c << b << "=" << Sum << endl;
	}
}