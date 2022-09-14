#include "Image.h"

#include <iostream>

int main() {
  Image alma;

  // std::cout << "Using Image::lighten to create `lighten.png`..." << std::endl;
  // alma.readFromFile("../alma.png");
  // alma.lighten(0.2);
  // alma.writeToFile("../lighten.png");

  // std::cout << "Using Image::saturate to create `saturate.png`..." << std::endl;
  // alma.readFromFile("../alma.png");
  // alma.saturate(0.2);
  // alma.writeToFile("../saturate.png");

  // std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  // alma.readFromFile("../alma.png");
  // alma.scale(2);
  // alma.writeToFile("../scale2x.png");

  // std::cout << "Using Image::scale with x,y to create `scaleXY.png`..." << std::endl;
  // alma.readFromFile("../alma.png");
  // alma.scale(1800, 5000);
  // alma.writeToFile("../scaleXY.png");

  // std::cout << "Using Image::rotate_coloe to create `rotate.png`..." << std::endl;
  // alma.readFromFile("../alma.png");
  // alma.rotateColor(500.0);
  // alma.writeToFile("../rotate.png");

  // std::cout << "Using Image::grayscale to create `gray.png`..." << std::endl;
  // alma.readFromFile("../alma.png");
  // alma.grayscale();
  // alma.writeToFile("../gray.png");

  std::cout << "Using Image::illini to create `illini.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.illinify();
  alma.writeToFile("../illini.png");

  return 0;
}
