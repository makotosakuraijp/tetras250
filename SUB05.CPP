#include "tet25new\\tetras.h"

int DRAW::XY_to_x (XY a, int player, int mode)
{
	//���_���W��������W�ւ̕ϊ��B
	if (mode == 1)
		if (player == 1)
			return ((a.x * 16) +  40);
	if (mode == 2)
	{
		if (player == 1)
			return ((a.x * 16) +  40);
		if (player == 2)
			return ((a.x * 16) + 440);
	}
	if (mode == 3)
	{
		if (player == 1)
			return ((a.x * 16) +  40);
		if (player == 2)
			return ((a.x * 16) + 240);
		if (player == 3)
			return ((a.x * 16) + 440);
	}
	printf ("�s���Ȓl�ɂȂ�܂����B\n");
	printf ("mode:%d player:%d\n", mode, player);
	exit (11);
	return 0; //���s����Ȃ�
}

int DRAW::XY_to_y (XY a)
{
	//���_���W��������W�ւ̕ϊ��B
	return (304 - (a.y * 16));
}

void DRAW::enter (XY a, int bfnt, int player, int mode)
{
	XY k [4];
	block_data (k, bfnt);
	int s;
	int t;
	int i;
	int bfnt_new = bfnt;
	bfnt_new /= 4;
	bfnt_new += 28;

	for (i = 0; i < 4; i++)
	{
		k [i].x += a.x;
		k [i].y += a.y;
		if (k [i].y <= 18 && k [i].y >= 0)
		{
			s = XY_to_x (k [i], player, mode);
			t = XY_to_y (k [i]);
			super_put_8 (s, t, bfnt_new);
		}
	}
}

void DRAW::in (int x, int y, int bfnt)
{
	super_put_8 (x, y, bfnt);
}

void DRAW::in (XY a, int bfnt, int player, int mode)
{
	//player�͂ǂ̃v���C���[�ł��邩�ŁA
	//mode�͉��l�ΐ탂�[�h�ł��邩
	int s = XY_to_x (a, player, mode);
	int t = XY_to_y (a);
	super_put_8 (s, t, bfnt);
}

void DRAW::out (int x, int y, int bfnt)
{
	super_repair (x, y, bfnt);
}

void DRAW::out (XY a, int bfnt, int player, int mode)
{
	//player�͂ǂ̃v���C���[�ł��邩�ŁA
	//mode�͉��l�ΐ탂�[�h�ł��邩
	XY k [4];
	block_data (k, bfnt);
	int s;
	int t;
	int i;

	for (i = 0; i < 4; i++)
	{
		k [i].x += a.x;
		k [i].y += a.y;
		if (k [i].y <= 18 && k [i].y >= 0)
		{
			s = XY_to_x (k [i], player, mode);
			t = XY_to_y (k [i]);
			super_repair (s, t, 28);
		}
	}
}