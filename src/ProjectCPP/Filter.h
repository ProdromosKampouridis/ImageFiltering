#pragma once
#ifndef FILTER_H
#define FILTER_H
#include "image.h"

class Filter {
public:
	virtual ~Filter() {}
	virtual Image operator<<(const Image& image) const = 0;
};

#endif
