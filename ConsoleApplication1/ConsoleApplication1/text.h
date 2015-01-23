#pragma once
#include "row.h"
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

	void operator+= (const char line[]);
private:
	RowsList *m_rowsRoot;

};

