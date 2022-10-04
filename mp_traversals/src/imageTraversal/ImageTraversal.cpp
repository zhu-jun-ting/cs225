#include <cmath>
#include <iterator>
#include <iostream>

#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  _it = nullptr;
}

/**
 * Parameter iterator constructor.
 */
ImageTraversal::Iterator::Iterator(ImageTraversal * it, PNG & png, Point & start, double tolerance) {
  _it = it;
  _png = png;
  _start = start;
  _cur = start;
  _tolerance = tolerance;
  _visited.resize(_png.width());
  for (unsigned i = 0; i < _visited.size(); i++) {
    _visited[i].resize(_png.height());
    for (unsigned j = 0; j < _visited[i].size(); j++) {
      _visited[i][j] = false;
    }
  }
}


/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  _visited[_cur.x][_cur.y] = true;
  std::cout << Point(_cur.x, _cur.y) << std::endl;
  std::cout << "png-" << Point( _png.width(),_png.height()) << std::endl;
  // find to the next avalible point in interator
  while (!_it->empty() && _visited[_it->peek().x][_it->peek().y] == true) {
    _it->pop();
  }

  // add its right, down, left, up point in order
  Point right = Point(_cur.x + 1, _cur.y);
  if ((right.x < _png.width() && right.y < _png.height())) {
    std::cout << "right" << Point(right.x, right.y) << std::endl;
    if (_visited[right.x][right.y] == false) {
      add_if_tolerate(right);
    }
  }

  Point down = Point(_cur.x, _cur.y + 1);
  if ((down.x < _png.width() && down.y < _png.height())) {
    std::cout << "down" << Point(down.x, down.y) << std::endl;
    if (_visited[down.x][down.y] == false) {
      add_if_tolerate(down);
    }
  }
  

  Point left = Point(_cur.x - 1, _cur.y);
  if ((left.x < _png.width() && left.y < _png.height())) {
    std::cout << "left" << Point(left.x, left.y) << std::endl;
    if (_visited[left.x][left.y] == false) {
      add_if_tolerate(left);
    }
  } 

  Point up = Point(_cur.x, _cur.y - 1);
  if ((up.x < _png.width() && up.y < _png.height())) {
    std::cout << "up" << Point(up.x, up.y) << std::endl;
    if (_visited[up.x][up.y] == false) {
      add_if_tolerate(up);
    }
  } 

  // update the _cur, check if end
  if (!_it->empty()) {
    _cur = _it->peek();
  } else {
    _it = nullptr;
  }
 
  return *this;
}

void ImageTraversal::Iterator::add_if_tolerate(Point p) {

  HSLAPixel p1 = _png.getPixel(_start.x, _start.y);
  HSLAPixel p2 = _png.getPixel(p.x, p.y);
  double delta = calculateDelta(p1, p2);
  if (delta <= _tolerance) {
    _it->add(p);
  }
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return _cur;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  return this->_it != nullptr || other._it != nullptr;
}

