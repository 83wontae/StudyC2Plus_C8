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
	int CardAScore = CardA.number * 10 + CardA.mark;
	int CardBScore = CardB.number * 10 + CardB.mark;
	// if (CardA.number * 10 + CardA.mark > CardB.number * 10 + CardB.mark) {
	if (CardAScore > CardBScore) {
		return true;
	}
	else {
		return false;
	}
}

// �Լ��̸� : GameResult
// �Ķ��Ÿ : 
// const stCard& CardA = ���� stCard�� ���� 
// const stCard& CardB = ����� stCard�� ����
// const char& chChoose = ������ ����
// ��ȯ�� : ����
// �Լ���� 
// chChoose�� 'H'�� (CardB > CardA) �̸� "�¸�" ��� �ƴϸ� "�й�" ���
// chChoose�� 'L'�� (CardB < CardA) �̸� "�¸�" ��� �ƴϸ� "�й�" ���
void GameResult(const stCard& CardA, const stCard& CardB, const char& chChoose)
{
	switch (chChoose)
	{
	case 'H':
		if (CompareCard(CardA, CardB)) {
			cout << "�й�" << endl;
		}
		else {
			cout << "�¸�" << endl;
		}
		break;
	case 'L':
		if (CompareCard(CardA, CardB)) {
			cout << "�¸�" << endl;
		}
		else {
			cout << "�й�" << endl;
		}
		break;
	}

}

void main()
{
	Initialize(); // ī�� 52���� ������ �־��ش�.
	
	while (true)
	{
		Shuffle(); // ī�带 ���´�.

		// 0�� ī�� ���
		cout << "ù��° ī�� : ";
		cards[0].printCard();
		char chChoose = ' ';
		cin >> chChoose;

		GameResult(cards[0], cards[1], chChoose);

		cout << "�ι�° ī�� : ";
		cards[1].printCard();
	}
}