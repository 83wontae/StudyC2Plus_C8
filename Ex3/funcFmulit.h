#pragma once

//�Լ��̸� funcFmulit
//�Ķ��Ÿ int a, int b
//��ȯ�� int
//a�� b�¿� ���� ���ؼ� ��ȯ �Ѵ�.
inline int funcFmulit(int a, int b)
{
	int result = 1;
	for (int i = 0; i < b; ++i)
	{
		result *= a;
	}
	return result;
}

