#include "foo.h"

void Foo::setX(int x) {
  mX = x;
}

int Foo::x() const {
  return mX;
}

int Foo::add(int x, int y) {
  return x + y;
}
