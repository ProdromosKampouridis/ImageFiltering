#pragma once
#ifndef FILTER_LINEAR_H
#include "filter.h"
class FilterLinear : public Filter {
private:
	Color a, c;
public:
	FilterLinear() : FilterLinear(Color(), Color()) {
	}

	FilterLinear(Color a, Color c);

	FilterLinear(const FilterLinear &src);


	~FilterLinear() override {
	}
	Image operator<<(const Image& image) const override;
};

#endif


