#include <iostream>
#include "Card.h"
#include "Common.h"
#include "Initialize.h"
#include "Shuffle.h"

/*
1. 52개의 카드를 가지고 시작
2. 게임이 시작되면 카드 하나를 오픈
3. 플레이어는 다음카드가
오픈된 카드보다 높은 카드인지
낮은 카드인지에 대하여 배팅을 한다
4. 선택 맞다면 승리 틀리면 패배
5. 카드는 1이 가장 낮고 K가 가장 높다
6. 문양은 스페이트 > 다이아 > 하트 > 클로버
순으로 높다.
*/

using namespace std;

void main()
{
	Initialize();
	Shuffle();

	// 카드 출력
	for (int i = 0; i < Max; ++i)
	{
		cout << "Mark = " << cards[i].mark << " Number = " << cards[i].number << endl;
	}
}