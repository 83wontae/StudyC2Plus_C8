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

// 함수이름 : CompareCard
// 파라메타 : const stCard& CardA, const stCard& CardB
// 반환값 : bool
// 함수기능 : CardA와 CardB를 비교하여 CardA가 크다면 true 작으면 false 반환
bool CompareCard(const stCard& CardA, const stCard& CardB)
{
	// CardA와 CardB를 비교하여 CardA가 크다면 true 작으면 false 반환
	// 위와 같이 출력한다.
	// (크기 비교 조건) Number : 1 ~ 13 숫자가 높을수록 높은 카드
	// (크기 비교 조건) Number가 같다면 
	// 스페이트 > 다이아 > 하트 > 클로버 순으로 높을수록 높은 카드
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
	Initialize(); // 카드 52장의 정보를 넣어준다.
	Shuffle(); // 카드를 섞는다.

	// 0번 카드 출력
	cards[0].printCard();
	char chChoose = ' ';
	cin >> chChoose;
	// chChoose가 'H'고 (cards[1] > cards[0]) 이면 "승리" 출력 아니면 "패배" 출력
	// chChoose가 'L'고 (cards[1] < cards[0]) 이면 "승리" 출력 아니면 "패배" 출력
	switch (chChoose)
	{
	case 'H' :
		if (CompareCard(cards[0], cards[1]))	{
			cout << "패배" << endl;
		}
		else {
			cout << "승리" << endl;
		}
		break;
	case 'L' :
		if (CompareCard(cards[0], cards[1])) {
			cout << "승리" << endl;
		}
		else {
			cout << "패배" << endl;
		}
		break;
	}



	cards[1].printCard();
	// 카드 출력
	/*
	for (int i = 0; i < Max; ++i)
	{
		cout << "Mark = " << cards[i].mark << " Number = " << cards[i].number << endl;
	}
	*/
}