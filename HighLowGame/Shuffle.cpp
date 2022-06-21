#include "Shuffle.h"
#include <iostream>
#include "Common.h"

void Shuffle()
{
	// Ä«µå ¼¯±â
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 52; i++)
	{
		int FirstNumber = rand() % 52;
		int SecondNumber = rand() % 52;

		stCard Temp = cards[FirstNumber];
		cards[FirstNumber] = cards[SecondNumber];
		cards[SecondNumber] = Temp;
	}
}