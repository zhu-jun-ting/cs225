#include "Image.h"
#include "StickerSheet.h"

int main() {
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
  Image alma; alma.readFromFile("../tests/alma.png");
  Image i;    i.readFromFile("../tests/i.png");

  // StickerSheet sheet(alma, 5);
  // sheet.addSticker(i, 20, 200);

  Image expected;
  expected.readFromFile("../tests/expected.png");

  StickerSheet ss1(alma, 5);
  StickerSheet ss2(ss1);
  StickerSheet ss3(alma, 2);

  ss3 = ss1;

  ss1.addSticker(i, 0, 0);
  ss1.addSticker(i, 100, 0);
  // ss1.addSticker(i, 100, 200);
  // ss1.addSticker(i, 300, 500);

  ss1.render().writeToFile("../new_alma.png");

  // Image * new_alma = new Image(alma);
  // Image * new_i = new Image(i);
  // ss1.render_one_image(new_alma, new_i, 0, 0);

  // new_alma->writeToFile("../new_alma.png");

  // delete ss1;

  return 0;
}
