#include "text.h"


text::text(void)
{
	m_rowsRoot = NULL;
}


text::~text(void)
{
}

void text::operator>> (const char line[])
{
	RowsList *buf = m_rowsRoot;
	if(buf == nullptr)
		buf = (RowsList*)malloc(sizeof(RowsList));
	else
	{
		while(buf->next != NULL)
		{
			buf = buf->next;
		}
		buf->next = (RowsList*)malloc(sizeof(RowsList));
		buf = buf->next;
	}
	buf->next = NULL;
	buf->line->Append(line);
}

void text::operator+= (text &line)
{

}

void text::operator+= (const char line[])
{
	RowsList *buf = m_rowsRoot;
	if(buf == nullptr)
		buf = (RowsList*)malloc(sizeof(RowsList));
	else
	{
		while(buf->next != NULL)
		{
			buf = buf->next;
		}
		buf->next = (RowsList*)malloc(sizeof(RowsList));
		buf = buf->next;
	}
	buf->next = NULL;
	buf->line->Append(line);
}