#include <iostream>

using namespace std;

struct Storage
{
	int Potato;
	int Onion;
	int Carrot;

	// �Լ� �̸� : AddVege
	// �Ķ��Ÿ : int a, int b, int c
	// ��ȯ�� ����
	// �Լ� ��� Potato���� a ����, Onion���� b ����, Carrot���� c ����
	void AddVege(int a, int b, int c)
	{
		Potato += a;
		Onion += b;
		Carrot += c;
	}

	// �Լ� �̸� : MinuesVege
	// �Ķ��Ÿ : int a, int b, int c
	// ��ȯ�� ����
	// �Լ� ��� Potato���� a ����, Onion���� b ����, Carrot���� c ���� 
	// Potato, Onion, Carrot 0���� �۾����� ����
	void MinuesVege(int a, int b, int c)
	{
		Potato -= a;
		if (Potato < 0)
			Potato = 0;
		Onion -= b;
		if (Onion < 0)
			Onion = 0;
		Carrot -= c;
		if (Carrot < 0)
			Carrot = 0;
	}

	// �Լ� �̸� : MoveStorage
	// �Ķ��Ÿ : Storage& target
	// ��ȯ�� ����
	// �Լ� ��� Storage& target�� ä�ҵ��� ���� ����ü�� ����
	// Storage& target�� ���� ���� 0���� �ʱ�ȭ �մϴ�.
	void MoveStorage(Storage& target)
	{
		Potato += target.Potato;
		Onion += target.Onion;
		Carrot += target.Carrot;
		target.Potato = 0;
		target.Onion = 0;
		target.Carrot = 0;
	}

	bool Tick()
	{
		int Order = 0;
		cout << "���� : " << Potato << " ���� : " << Onion << " ��� : " << Carrot << endl;
		cout << "0) â�� �������� ���ư��ϴ�." << endl;
		cout << "1) â�� ä�Ҹ� �ֽ��ϴ�." << endl;
		cout << "2) â�� ä�Ҹ� �����ϴ�." << endl;
		cin >> Order;
		switch (Order)
		{
		case 0:
			return true; // TargetStorage ���� ó��
			break;
		case 1:
			int a, b, c = { 0 };
			cout << "���� ���� ��� ������� ���� ä�Ҹ� �Է��ϼ���." << endl;
			cin >> a >> b >> c;
			AddVege(a, b, c);
			break;
		}
		return false;
	}
};

int main()
{
	Storage s1 = { 50, 50, 50 };
	Storage s2 = { 100, 100, 100 };
	int TargetStorage = 0;
	int Order = 0;

	while (true)
	{
		system("cls");
		switch (TargetStorage)
		{
		case 1:
		{
			cout << "s1 â�� �Դϴ�." << endl;
			bool result = s1.Tick();
			if (result)
				TargetStorage = 0;
		}
		break;

		case 2:
		{
			cout << "s2 â�� �Դϴ�." << endl;
			bool result = s2.Tick();
			if (result)
				TargetStorage = 0;
		}
		break;

		default:
			cout << "1) s1 â��" << endl;
			cout << "2) s2 â��" << endl;
			cin >> TargetStorage;
			break;
		}
	}





	// ���� �ϳ��� �Է� �޾Ƽ� 
	int a, b, c = 0;
	cin >> a >> b >> c;

	// s2�� ä�Ҹ� s1���� �ȱ��.
	s1.MoveStorage(s2);
	cout << "Potato = " << s1.Potato << endl;
	cout << "Onion = " << s1.Onion << endl;
	cout << "Carrot = " << s1.Carrot << endl;
	cout << "Potato = " << s2.Potato << endl;
	cout << "Onion = " << s2.Onion << endl;
	cout << "Carrot = " << s2.Carrot << endl;
}