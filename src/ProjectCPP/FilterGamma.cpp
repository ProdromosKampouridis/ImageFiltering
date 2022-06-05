#include "FilterGamma.h"
#include <math.h>
FilterGamma::FilterGamma(const FilterGamma & src){
	gamma = src.gamma; 
}
Image FilterGamma::operator<<(const Image& image) const{
	Image output(image);
	for ( int y = 0; y < image.getHeight(); y++) {
		for ( int x = 0; x < image.getWidth(); x++) {
			Color out = output(x, y); 
			out.x = pow(out.x, gamma);
			out.y = pow(out.y, gamma);
			out.z = pow(out.z, gamma);
			output(x, y) = out;
		}
	}
	return output;
}