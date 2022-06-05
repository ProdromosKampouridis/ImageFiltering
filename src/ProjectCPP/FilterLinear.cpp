#include "FilterLinear.h"


FilterLinear::FilterLinear(Color a, Color c) {
	this->a = a;
	this->c = c;
}

FilterLinear::FilterLinear(const FilterLinear & src)
{
	a = src.a;
	c = src.c;
}


Image FilterLinear::operator<<(const Image& image) const {
	Image output(image);
	for ( int y = 0; y < output.getHeight(); y++) {
		for ( int x = 0; x < output.getWidth(); x++) {
			output(x, y) = (output(x, y) * a )+ c;
			output(x, y) = output(x, y).clampToLowerBound(0);
			output(x, y) = output(x, y).clampToUpperBound(1);
		}
	}
	return output;
}