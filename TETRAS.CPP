#include "tet25new\\tetras.h"

extern unsigned _stklen = 17000;

int main (void)
{
	try
	{
		MACHINE m;
		TETRAS *tetras;

		switch (m.machine)
		{
			case PC9801:
				tetras = new TETRAS98;
				break;

			default:
				printf ("残念ながら、現バージョンではこの機種には対応していません。\n");
				exit (5);
				break;
		}

		tetras->go ();
		delete tetras;
	}
	catch (xalloc)
	{
		printf ("mainにおいて、Ｘａｌｌｏｃ例外発生\n");
	}
	catch (...)
	{
		printf ("mainにおいて、謎の例外発生\n");
	}
	return 0;
}
