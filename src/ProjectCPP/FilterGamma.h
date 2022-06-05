#pragma once
#ifndef FILTER_GAMMA_H
#define FILTER_GAMMA_H
#include "filter.h"
class FilterGamma : public Filter {
private:
	float gamma;
public:
	FilterGamma(float a):gamma(a){
	}
	FilterGamma(const FilterGamma &src);
	~FilterGamma() {}
	Image operator<<(const Image & image) const override;
};

#endif
