#include <key.h>

void KEY::key (int *scan, int *shift)
{
	switch (m.machine)
	{
		case PC9801:
			/*DOS�t�@���N�V�����ƃL�[BIOS�𕹗p����ꍇ�́A*/
			/*BREAK�`�F�b�N���I�t�ɂ��邱��*/
			*scan  = (int) (pc98key (0) >> 8);
			*shift = (int) (pc98key (2));
			break;

		case PC_AT:
			break;

		case FMR:
			break;
	}
}