#include <iostream>

using namespace std;

//�Լ� �̸� : standardWeight
//�ɹ� ���� : float height
//���� �� : float
//���� : (height - 100) * 0.9
float standardWeight(float hegiht)
{
	return (hegiht - 100) * 0.9;
}

//�Լ� �̸� : GetBMI
//�ɹ� ���� : float weight, float standardWeight
//���� �� : float
//���� : (weight - standardWeight)  * 100 / standardWeight
float GetBMI(float weight, float standardWeight)
{
	return (weight - standardWeight) * 100 / standardWeight;
}

int main()
{
	/*
	//�ʸ� �Է¹޾� �� / �� / ���� ���·� ��Ÿ���ÿ�.
	int gSec = 0;
	cin >> gSec;

	int hour = gSec / 3600;
	int min = gSec / 60 % 60;
	int sec = gSec % 60;

	cout << hour << "�� " << min << "�� " << sec << "��" << endl;
	*/

	float weight, height;
	cin >> weight >> height;

	//standardWeight, GetBMI�� ����ؼ� bmi�� ���ϱ�
	float bmi = GetBMI(weight, standardWeight(height));

	/*
	*	bmi�� ���� ��� ����
		���	�񸸵� ��ġ
		10����				����
		10�ʰ� 20����	��ü��
		20 �ʰ�			��
	*/
	cout << "bmi = "  << int(bmi) << endl;
	if (10 >= bmi)
	{
		cout << "����" << endl;
	}
	else if (20 >= bmi && bmi > 10)
	{
		cout << "��ü��" << endl;
	}
	else// ������ ���� 20 �ʰ� �ϼ� �ۿ� ����
	{
		cout << "��" << endl;
	}
}