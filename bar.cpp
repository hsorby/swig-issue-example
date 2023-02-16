#include "bar.h"

void Bar::setX(int x) {
  mX = x;
}

int Bar::x() const {
  return mX;
}

int Bar::add(int x, int y) {
  return x + y;
}

Bar *Bar::create() {
    return new Bar();
}
