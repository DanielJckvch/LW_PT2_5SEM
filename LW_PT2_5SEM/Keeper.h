#pragma once
#include "Place.h"
#include "Sign.h"

class keeper
{
private:
	place* head;
	place* tail;
	int amount;
protected:
	place* operator[](int i);
public:
	void add(sign* toInsert);
	void addToEnd(sign* toInsert);
	void insert(int pos, sign* toInsert);
	void copy(int sou, int dest);
	void del(int num);
	void changeEl(int num);
	void show(void);
	void search(char* s, int f);
	void search(int perVal, int perNum);
	void clear(void);
	void sort(int mode = 0);
	keeper();
	keeper(sign* ob);
	keeper(const keeper& ob);
	~keeper();
	void loadToFile(char* name);
	void loadFromFile(char* name);
	friend ostream& operator<<(ostream& stream, const keeper& cont);
	friend istream& operator>>(istream& stream, keeper& cont);
	
};
