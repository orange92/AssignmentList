#pragma once
#include "row.h"
#include <stdlib.h>
class text
{
public:
	text(void);
	text(text &elemnetToCopy);
	~text(void);
	typedef struct RowsList
	{
		row *line;
		RowsList *next;
	} RowsList;

	void operator>> (const char line[]);

	void operator+= (text &lines);

	void operator+= (const char line[]);

	int Count();

	char *GetLine(int i);

private:
	void text::AddLine(const char line[]);
	RowsList *m_rowsRoot;

};

