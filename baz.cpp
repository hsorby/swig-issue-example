#include "baz.h"

void Baz::setX(int x) {
  mX = x;
}

int Baz::x() const {
  return mX;
}

int Baz::add(int x, int y) {
  return x + y;
}

std::shared_ptr<Baz> Baz::createShared() {
    return std::shared_ptr<Baz>( new Baz {});
}
