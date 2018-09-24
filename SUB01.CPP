#include "tet25new\\tetras.h"

TETRAS98::TETRAS98 (void)
{
	super_entry_bfnt ("tet01.bft");
	super_entry_bfnt ("tet02.bft");
	super_entry_bfnt ("tet03.bft");
	super_entry_bfnt ("tet04.bft");
	super_entry_bfnt ("tet05.bft");
	super_entry_bfnt ("tet06.bft");
	super_entry_bfnt ("tet07.bft");
	super_entry_bfnt ("enter.bft");
	super_entry_bfnt ("tet_next.bft");
	text_systemline_hide ();
	_text_cursor_off (); //�J�[�\���������B�i�o�b�X�W��p�Łj
	text_clear ();
	key_beep_off ();
	//vsync_start ();
	// musicbuf = new char [MFXDDN_MAXMUDSIZE];
	// mfxddn_bgm_init2 (musicbuf);
	gaiji_entry_bfnt ("CHARACT.BFT");
	logo (); //logo���ł́A���O��MACHINE�ϐ���p�ӂ���B
	title ();
}

TETRAS98::~TETRAS98 ()
{
	delete [] musicbuf;
	key_beep_on ();
	//vsync_end ();
	_text_cursor_on (); //�J�[�\����߂��B�i�o�b�X�W��p�Łj
	text_systemline_show ();
}

void TETRAS98::go (void)
{
	try
	{
		STATUS_LIST st (new STATUS1 (), new STATUS1 (), new STATUS1 (), new STATUS2 ());
		st.go ();
	}
	catch (xalloc)
	{
		printf ("TETRAS98::go�Fst�ŃG���[\n");
		exit (9);
	}
}