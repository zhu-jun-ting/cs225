#include "StickerSheet.h"
#include "Image.h"
#include "../lib/cs225/PNG.h"
#include "../lib/cs225/HSLAPixel.h"
// #include <iostream>

using namespace std;

StickerSheet::StickerSheet(const Image &picture, unsigned max) {
	picture_ = new Image(picture);
	max_stickers_ = max;
	stickers_ = new vector<stk>;
}

StickerSheet::StickerSheet(const StickerSheet &other) {
	copy_(other);
}

StickerSheet::~StickerSheet() {
	clear_();
}

void StickerSheet::copy_(const StickerSheet & other) {

	// if(picture_ != nullptr) delete picture_;
	picture_ = new Image(*(other.picture_));
	stickers_ = new vector<stk>(other.stickers_ -> begin(), other.stickers_ -> end());
	max_stickers_ = other.max_stickers_;

	// if(stickers_ != nullptr) {
	// 	stickers_ -> clear();
	// } else {
	// 	stickers_ = new vector<sticker>;
	// }

	// for(sticker s: *(other.stickers_)) {
	// 	stickers_ -> push_back(s);
	// }
}

void StickerSheet::clear_() {
	if (picture_ != nullptr) {
		delete picture_;
		picture_ = nullptr;
	}
	if (stickers_ != nullptr) {
		for (unsigned i = 0; i < stickers_->size(); i++) {
			if ((*stickers_)[i].image != nullptr) {
				delete (*stickers_)[i].image;
			}
		}
		delete stickers_;
		stickers_ = nullptr;
	}
}

const StickerSheet &StickerSheet::operator=(const StickerSheet &other) {
	if (this != &other) {
		clear_();
		copy_(other);
	}
	return *this;
}

void StickerSheet::changeMaxStickers (unsigned max) {
	max_stickers_ = max;
}

int StickerSheet::addSticker (Image &sticker, unsigned x, unsigned y) {
	stk s; 
	s.image = new Image(sticker);
	s.x = x;
	s.y = y;
	stickers_->push_back(s);
	return 0;
}

Image StickerSheet::render () const {
	Image * im = new Image(*picture_);
	for (unsigned i = 0; i < min(max_stickers_, (unsigned)stickers_->size()); i++) {
		render_one_image(im, (*stickers_)[i].image, (*stickers_)[i].x, (*stickers_)[i].y);
	}
	Image result = Image(*im);
	delete im;
	return result;
}

void StickerSheet::render_one_image(Image * base, const Image * added, unsigned ori_x, unsigned ori_y) const {
	for (unsigned x = 0; x < added->width(); x++) {
		for (unsigned y = 0; y < added->height(); y++) {
			cs225::HSLAPixel p = added->getPixel(x, y);
			if (p.a == 0) {
				continue;
			} else {
				base->getPixel(ori_x + x, ori_y + y) = added->getPixel(x, y);
			}
		}
	}
}