#include <iostream>
#include "Card.h"
#include "Common.h"
#include "Initialize.h"
#include "Shuffle.h"

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

// �Լ��̸� : CompareCard
// �Ķ��Ÿ : const stCard& CardA, const stCard& CardB
// ��ȯ�� : bool
// �Լ���� : CardA�� CardB�� ���Ͽ� CardA�� ũ�ٸ� true ������ false ��ȯ
bool CompareCard(const stCard& CardA, const stCard& CardB)
{
	// CardA�� CardB�� ���Ͽ� CardA�� ũ�ٸ� true ������ false ��ȯ
	// ���� ���� ����Ѵ�.
	// (ũ�� �� ����) Number : 1 ~ 13 ���ڰ� �������� ���� ī��
	// (ũ�� �� ����) Number�� ���ٸ� 
	// ������Ʈ > ���̾� > ��Ʈ > Ŭ�ι� ������ �������� ���� ī��
	if (CardA.number == CardB.number) {
		if (CardA.mark > CardB.mark) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (CardA.number > CardB.number) {
		return true;
	}
	else {
		return false;
	}
}

void main()
{
	Initialize(); // ī�� 52���� ������ �־��ش�.
	Shuffle(); // ī�带 ���´�.

	// 0�� ī�� ���
	cards[0].printCard();
	char chChoose = ' ';
	cin >> chChoose;
	// chChoose�� 'H'�� (cards[1] > cards[0]) �̸� "�¸�" ��� �ƴϸ� "�й�" ���
	// chChoose�� 'L'�� (cards[1] < cards[0]) �̸� "�¸�" ��� �ƴϸ� "�й�" ���
	switch (chChoose)
	{
	case 'H' :
		if (CompareCard(cards[0], cards[1]))	{
			cout << "�й�" << endl;
		}
		else {
			cout << "�¸�" << endl;
		}
		break;
	case 'L' :
		if (CompareCard(cards[0], cards[1])) {
			cout << "�¸�" << endl;
		}
		else {
			cout << "�й�" << endl;
		}
		break;
	}



	cards[1].printCard();
	// ī�� ���
	/*
	for (int i = 0; i < Max; ++i)
	{
		cout << "Mark = " << cards[i].mark << " Number = " << cards[i].number << endl;
	}
	*/
}