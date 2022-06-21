#include "Initialize.h"
#include "Common.h"

void Initialize()
{
	//ī�� ���� �־��ֱ�
	//0��--> ũ1, ũ2, ũ3, ũ4, ũ5, ũ6, ũ7, ũ8, ũ9, ũ10, ũ11, ũ12, ũ13
	// ��1, ��2, ��3, ��4, ��5, ��6, ��7, ��8, ��9, ��10, ��11, ��12, ��13
	// ��1, ��2, ��3, ��4, ��5, ��6, ��7, ��8, ��9, ��10, ��11, ��12, ��13	
	// ��1, ��2, ��3, ��4, ��5, ��6, ��7, ��8, ��9, ��10, ��11, ��12, ��13<--51��
	for (int i = 0; i < 52; ++i)
	{
		int j = i / 13;
		switch (j)
		{
		case 0:
			cards[i].mark = Clover;
			break;
		case 1:
			cards[i].mark = Heart;
			break;
		case 2:
			cards[i].mark = Dia;
			break;
		case 3:
			cards[i].mark = Spade;
			break;
		}

		cards[i].number = (i % 13) + 1;
	}
}