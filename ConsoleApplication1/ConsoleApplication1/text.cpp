#include "text.h"

text::text(text &elemnetToCopy)
{
	for(int i = 0; i < elemnetToCopy.Count(); i++)	
	{
		AddLine(elemnetToCopy.GetLine(i));
	}
}

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
	if(buf == NULL)
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

void text::operator+= (text &lines)
{
	RowsList *buf;
	for (int i = 0; i < lines.Count; i++)
	{
		buf = m_rowsRoot;
		if(buf == NULL)
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
		buf->line->Append(lines.GetLine(i));
	}
}

void text::operator+= (const char line[])
{
	AddLine(line);
}

void text::AddLine(const char line[])
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

int text::Count()
{
	RowsList *buf = m_rowsRoot;	
	int n = 0;
	while(buf != NULL)
	{
		buf = buf->next;
		n++;
	}
	return n;
}

char* text::GetLine(int id)
{
	RowsList *buf = m_rowsRoot;
	for(int i = 0; i < id; i++)
	{
		buf = buf->next;	
	}
	return buf->line->Get();
}