#include "tet25new\tetras.h"

void title (void)
{
	KEY k;
	char bak [16] [3];
	for (int i = 0; i < 16; i++)
		for (int t = 0; t < 3; t++)
			bak [i] [t] = Palettes [i] [t];
	MagHeader mag;
	char *buf;
	char *ptr;
	int y;
	mag_load_pack ("tetras.mag", &mag, (void **) &buf);
	palette_set_all_16 (&mag.palette);
	palette_show ();
	ptr = buf;
	for (y = mag.y1; y <= mag.y2; ++y)
	{
		graph_pack_put_8 (mag.x1 & ~7, y, ptr, mag.xsize);
		ptr = (char *) FPADD (ptr, mag.xsize / 2);
	}
	mag_free (&mag, buf);

	// mfxddn_bgm_play ("UEHR.MUD");
	// mfxddn_bgm_play_mtlib ("UEHR.MUD");
	for (k.key (); k.t [SPACE] == 0; k.key ()){}
	// mfxddn_bgm_fadeout (2);

	palette_set_all (bak);
}
