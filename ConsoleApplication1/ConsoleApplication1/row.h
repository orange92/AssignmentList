#pragma once
#include <stdlib.h>
class row
{
public:
	row(void);
	~row(void);
	void Add(const char buf[]);
	void Append(const char buf[]);
	char* Get();
private:
	char *m_line;
};

