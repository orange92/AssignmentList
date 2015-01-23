#include "texteditor.h"


texteditor::texteditor(void)
{
}


texteditor::~texteditor(void)
{
}

int texteditor::NumbersOfWhiteSpaces()
{
	int numbersOfWhiteSpaces = 0;
	char *line;
	for(int i = 0; i < m_text.Count; i++)
	{
		line = m_text.GetLine(i);
		int n = 0;
		while(line[n] != '\0')
		{
			if(line[n] == ' ' || line[n] == '	' || line[n] == '\n') numbersOfWhiteSpaces++;
		}
	}
	return numbersOfWhiteSpaces;
}

void texteditor::operator+= (const char line[])
{
	m_text.AddLine(line);
}

void texteditor::operator+= (texteditor &classObiect)
{
	m_text+=classObiect.m_text;
}