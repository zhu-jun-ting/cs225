#include "Image.h"
#include "../lib/cs225/PNG.h"
#include "../lib/cs225/HSLAPixel.h"
// #include <iostream>

using namespace std;

void Image::lighten() {
	lighten(0.1);
}

void Image::lighten(double amount) {
	for (unsigned i = 0; i < width(); i++) {
		for (unsigned j = 0; j < height(); j++) {
			getPixel(i, j).l = getPixel(i, j).l + amount <= 1.0 ? getPixel(i, j).l + amount : 1.0;
		}
	}
}

void Image::darken() {
	darken(0.1);
}

void Image::darken(double amount) {
	for (unsigned i = 0; i < width(); i++) {
		for (unsigned j = 0; j < height(); j++) {
			getPixel(i, j).l = getPixel(i, j).l - amount >= 0.0 ? getPixel(i, j).l - amount : 0.0;
		}
	}
}

void Image::saturate() {
	saturate(0.1);
}

void Image::saturate(double amount) {
	for (unsigned i = 0; i < width(); i++) {
		for (unsigned j = 0; j < height(); j++) {
			getPixel(i, j).s = getPixel(i, j).s + amount <= 1.0 ? getPixel(i, j).s + amount : 1.0;
		}
	}
}

void Image::desaturate() {
	desaturate(0.1);
}

void Image::desaturate(double amount) {
	for (unsigned i = 0; i < width(); i++) {
		for (unsigned j = 0; j < height(); j++) {
			getPixel(i, j).s = getPixel(i, j).s - amount >= 0.0 ? getPixel(i, j).s - amount : 0.0;
		}
	}
}

void Image::grayscale() {
	for (unsigned i = 0; i < width(); i++) {
		for (unsigned j = 0; j < height(); j++) {
			getPixel(i, j).s = 0.0;
		}
	}
}

void Image::rotateColor(double degrees) {
	for (unsigned i = 0; i < width(); i++) {
		for (unsigned j = 0; j < height(); j++) {
			getPixel(i, j).h = getPixel(i, j).h + degrees <= 360.0 ? getPixel(i, j).h + degrees : getPixel(i, j).h + get_hue(getPixel(i, j).h);
		}
	}
}

void Image::illinify() {
	for (unsigned i = 0; i < width(); i++) {
		for (unsigned j = 0; j < height(); j++) {
			getPixel(i, j).h = get_illini_color(getPixel(i, j).h);
		}
	}
}


void Image::scale(double factor) {
	unsigned new_width = (int) (width() * factor);
	unsigned new_height = (int) (height() * factor);
	Image original = Image(*this); 
	resize(new_width, new_height);

	for (unsigned i = 0; i < width(); i++) {
		for (unsigned j = 0; j < height(); j++) {
			getPixel(i, j) = original.getPixel((int) (i / factor), (int) (j / factor));
		}
	}
}

void Image::scale(unsigned w, unsigned h) {
	double width_factor = w / width();
	double height_factor = h / height();
	scale(min(width_factor, height_factor));
}

double Image::get_hue(double h) {
	while (h > 360) {
		h -= 360;
	}
	return h;
}

double Image::get_illini_color(double h) {
	double orange = 11;
	double blue = 216;
	return abs(h - orange) > abs(h - blue) ? blue : orange;
}
