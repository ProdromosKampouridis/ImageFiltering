#include "image.h"
using namespace std;
using namespace math;


Image::Image(){
}

bool Image::load(const std::string & filename, const std::string & format) { // 
	float* raw_data = image::ReadPPM(filename.c_str(), (int*)&width, (int*)&height);
	if (raw_data != NULL) {
		setData((Color*)raw_data);
		delete[] raw_data;
		return true;
	}
	else return false;
}
bool Image::save(const std::string & filename, const std::string & format) {
	return image::WritePPM((float*)&buffer[0], width, height, filename.c_str());
}




	
