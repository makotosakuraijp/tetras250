#include "tet25new\\tetras.h"

long RECORD::comp (RECORD s1, RECORD s2)
{
	return (s1.point - s2.point);
}

RECORD::RECORD (void)
{
	point = 10000;
	strcpy (name, "MIRAGE");
	strcpy (date, "96/04/17");
}

int RECORD_LIST::members = 0;

void RECORD_LIST::load (char *filename, RECORD_LIST *a)
{
	if (members <= 0)
		exit (6);

	if (!file_exist (filename))
		save (filename);

	if (!file_ropen (filename))
		exit (3);

	int r; //���[�h�f�[�^
	int i;
	int k;

	char ***ch; //ch [members] [10] [50]�ɑ������鑀����s���B
	try
	{
		ch = new char **[members];
		for (i = 0; i < members; i++)
		{
			ch [i] = new char *[10];
			for (k = 0; k < 10; k++)
			{
				ch [i] [k] = new char [50];
				strcpy (ch [i] [k], ""); //ch�̓��e��S�Ă��ꂢ�ɂ���B
			}
		}
	}
	catch (xalloc)
	{
		printf ("RECORD_LIST::load�Fch�ŃG���[\n");
		exit (10);
	}

	for (i = 0; i < members; i++)
		for (k = 0; k < 10; k++)
			for (r = -2; r != -1 && r != '\n'; )
			{
				r = file_getc ();

				switch (r)
				{
					case -1: //EOF�ɒB���Ă���Ƃ�
						if (strlen (ch [members - 1] [9]) == 0)
							exit (4);
						break;

					case '\n':
					case '\r':
						break;

					default:
						strcat (ch [i] [k], (char) r);
				}
			}

	file_close (); //�����܂łŃt�@�C������̓ǂݏo����Ƃ͏I��

	char *p;
	char *q;
	char j [3] [9]; //�ϊ���������O�̏�Ԃŕۑ�
	int f;

	for (i = 0; i < members; i++)
		for (k = 0; k < 10; k++)
		{
			p = ch [i] [k];

			for (f = 0; f <= 2; f++) //�R�̗v�f�ɕ���
			{
				while (isspace (*p) || (*p) == NULL) p++;

				q = p;

				while (!isspace (*q) && (*q) != NULL) q++;

				if (q - p + 1 >= 10)
					exit (7);

				strcpy (j [f], "");

				for ( ; p != q; p++)
					strcat (j [f], *p);
			}

			if (strlen (j [0]) >= 7)
				exit (8);

			a [i].t [k].point = atol (j [0]); //�����ŕϊ�
			strcpy (a [i].t [k].name, j [1]);
			strcpy (a [i].t [k].date, j [2]);
		}

	for (i = 0; i < members; i++)
		for (k = 0; k < 10; k++)
			delete [] ch [i] [k];

	for (i = 0; i < members; i++)
		delete [] ch [i];
	delete [] ch;
}

void RECORD_LIST::save (char *filename) //�f�t�H���g�̒l�Ń\�R�A�t�@�C�������B
{
	if (file_exist (filename))
		if (!file_delete (filename))
			exit (1);

	if (!file_create (filename))
	{
		printf ("�t�@�C�����������߂܂���B\n");
		printf ("�ُ�I�����܂��B\n");
		exit (2);
	}

	char ch [50];
	RECORD_LIST q;
	int r; //�P�O��@�Ƃ���i�ɍ����ȂO�ȏ�̐����̒��ōł����������B

	for (int i = 0; i <= 29; i++)
	{
		r = (i % 10);
		sprintf (ch, "%ld %s %s\n", q.t [r].point, q.t [r].name, q.t [r].date);
		file_write (ch, strlen (ch));
	}

	file_close ();
}

void RECORD_LIST::save (char *filename, RECORD_LIST *a)
{
	if (members <= 0)
		exit (6);

	if (file_exist (filename))
		if (!file_delete (filename))
			exit (1);

	if (!file_create (filename))
	{
		printf ("�t�@�C�����������߂܂���B\n");
		printf ("�ُ�I�����܂��B\n");
		exit (2);
	}

	int i;
	int k;

	char ch [50];//�Վ�������ϐ�

	for (i = 0; i < members; i++)
		for (k = 0; k < 10; k++)
		{
			sprintf (ch, "%ld %s %s\n", a [i].t [k].point, a [i].t [k].name, a [i].t [k].date);
			file_write (ch, strlen (ch));
		}

	file_close ();
}