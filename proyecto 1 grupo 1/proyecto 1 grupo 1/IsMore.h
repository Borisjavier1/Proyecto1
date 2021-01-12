#pragma once
#include "Libraries.h"
template <class T>
class IsMore {
public:
	bool operator() (T* t1, T* t2) {
		return *t1 > *t2;
	}
};