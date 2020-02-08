#include "tet25new\tetras.h"

void logo (void)
{
	//char p [48] = {0, 0, 0,  8, 0, 0,  0, 8, 0,  8, 8, 0,  0, 0, 8,  8, 0, 8,  0, 8, 8,	12,12,12,
	//			   8, 8, 8, 15, 0, 0,  0,15, 0, 15,15, 0,  0, 0,15, 15, 0,15,  0,15,15, 15,15,15};
	graph_start ();
	palette_init ();
	char bak [16] [3];
	for (int i = 0; i < 16; i++)
		for (int t = 0; t < 3; t++)
			bak [i] [t] = Palettes [i] [t];
	MagHeader mag;
	char *buf;// = new char [6000];
	char *ptr;
	int y;
	mag_load_pack ("mirage.mag", &mag, (void **) &buf);
	palette_set_all_16 (&mag.palette);
	//palette_set_all_16 (p);
	palette_show ();
	ptr = buf;
	palette_black ();
	for (y = mag.y1; y <= mag.y2; ++y)
	{
		graph_pack_put_8 (mag.x1 & ~7, y, ptr, mag.xsize);
		ptr = (char *) FPADD (ptr, mag.xsize / 2);
	}
	mag_free (&mag, buf);
    mfxddn_bgm_play_mtlib ("IFLOGO.MUD");
	palette_black_in (6);
	for (i = 0; i < 90; i++)
		vsync_wait ();
	palette_black_out (3);
	graph_clear ();
	palette_100 ();
	palette_set_all (bak);
	palette_show ();
}
