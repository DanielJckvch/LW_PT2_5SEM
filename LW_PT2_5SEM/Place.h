#pragma once
#include "Sign.h"

class place
{
public:
	place* prev;
	place* next;
	sign* note;
	place(sign* veh);
	place(void);
	place(const place& toCopy);
	~place();
};
