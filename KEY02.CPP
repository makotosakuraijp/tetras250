#include <key.h>

KEY::KEY (void)
{
	int a;

	switch (m.machine)
	{
		case PC9801:
			for (a = 0; a <= 119; a++)
			{
				t [a] = 0;
			}
			break;

		case PC_AT:
			break;

		case FMR:
			break;
	}
	save_cbrk = getcbrk ();
	setcbrk (0);
	key_beep_off ();
}
