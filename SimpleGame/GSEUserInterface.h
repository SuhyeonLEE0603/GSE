#pragma once

#include "GSEGlobal.h"

class GSEUserInterface
{
public:
	GSEUserInterface();
	~GSEUserInterface();

	void KeyDown(char key, int id);
	void KeyUp(char key, int id);

	bool Is_SP_Arrow_Up_Down();
	bool Is_SP_Arrow_Down_Down();
	bool Is_SP_Arrow_Left_Down();
	bool Is_SP_Arrow_Right_Down();
	bool Is_Spacebar_Down();

private:
	bool m_SP_Arrow_Up = false;
	bool m_SP_Arrow_Down = false;
	bool m_SP_Arrow_Left = false;
	bool m_SP_Arrow_Right = false;

	bool m_Spacebar = false;
};

