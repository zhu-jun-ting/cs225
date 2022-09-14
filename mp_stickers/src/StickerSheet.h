/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#include "../lib/cs225/PNG.h"
#include "Image.h"
#include "../lib/cs225/PNG.h"
#include "../lib/cs225/HSLAPixel.h"
#include <vector>
#include <utility>
#pragma once
using namespace std;

struct stk {
	Image* image;
	unsigned x;
	unsigned y;
};

class StickerSheet {
	public:
		StickerSheet (const Image &picture, unsigned max);
		StickerSheet (const StickerSheet & other);
		~StickerSheet ();

		StickerSheet const & operator= (const StickerSheet &other);
		void changeMaxStickers (unsigned max);
		int addSticker (Image &sticker, unsigned x, unsigned y);
		// bool translate (unsigned index, unsigned x, unsigned y);
		// void removeSticker (unsigned index);
		// Image *	getSticker (unsigned index);
		Image render () const;
		void render_one_image(Image * base, const Image * added, unsigned ori_x, unsigned ori_y) const;


	private:
		vector<stk>* stickers_;
		unsigned max_stickers_;
		Image* picture_;

		void copy_(const StickerSheet & other);
		void clear_();

};

