#pragma once
#include "Libraries.h"
template <class T>
class  Iterator {
public:
	virtual bool hasMore() = 0;
	virtual  void next() = 0;
	virtual  T* currenItem() = 0;
	virtual  void first() = 0;
};

