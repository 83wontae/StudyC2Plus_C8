#include <iostream>
#include "Card.h"
#include "Common.h"
#include "Initialize.h"

/*
1. 52���� ī�带 ������ ����
2. ������ ���۵Ǹ� ī�� �ϳ��� ����
3. �÷��̾�� ����ī�尡
���µ� ī�庸�� ���� ī������
���� ī�������� ���Ͽ� ������ �Ѵ�
4. ���� �´ٸ� �¸� Ʋ���� �й�
5. ī��� 1�� ���� ���� K�� ���� ����
6. ������ ������Ʈ > ���̾� > ��Ʈ > Ŭ�ι�
������ ����.
*/

using namespace std;

void main()
{
	Initialize();

	// ī�� ����
	/*
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 52; i++)
	{
		int FirstNumber = rand() % 52;
		int SecondNumber = rand() % 52;

		stCard Temp = card[FirstNumber];
		card[FirstNumber] = card[SecondNumber];
		card[SecondNumber] = Temp;
	}
	*/

	// ī�� ���
	for (int i = 0; i < Max; ++i)
	{
		cout << "Mark = " << cards[i].mark << " Number = " << cards[i].number << endl;
	}
}