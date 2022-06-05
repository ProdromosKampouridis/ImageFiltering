#pragma once
#include "vec3.h"
#include "array2d.h"
#include "ppm.h"
#include "imageio.h"
#define Color math::Vec3<float>


class Image : public image::ImageIO, public math::Array2D<Color> {
public:
	Image();

	Image(unsigned int width, unsigned int height, const Color*const& data_ptr) : Array2D<Color>(width, height, data_ptr) {}

	~Image() {
	}

	bool load(const std::string& filename, const std::string& format) override;
	bool save(const std::string& filename, const std::string& format) override;
};



