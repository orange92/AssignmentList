#pragma once
#include <stdlib.h>
#include "text.h"
class texteditor
{
public:
	texteditor(void);
	texteditor(text buf);
	~texteditor(void);
	int NumbersOfWhiteSpaces();
	void operator+= (const char line[]);
	void operator+= (texteditor &classObiect);
	texteditor operator+ (texteditor &classObiect);
	void operator= (texteditor &classObiect);
	text m_text;
};

