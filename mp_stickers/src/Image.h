/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#include "../lib/cs225/PNG.h"

#pragma once

class Image : public cs225::PNG {
	public:
		void lighten();	
		void lighten(double amount);
		void darken();
		void darken(double amount);
		void saturate();
		void saturate(double amount);
		void desaturate();
		void desaturate(double amount);
		void grayscale();
		void rotateColor(double degrees);
		void illinify();
		void scale(double factor);
		void scale(unsigned w, unsigned h);

	private:
		double get_hue(double h);
		double get_illini_color(double h);
};

