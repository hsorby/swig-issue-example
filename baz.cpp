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

namespace {

struct PublicBaz: public Baz {};

}

std::shared_ptr<Baz> Baz::create() {
    return std::make_shared<PublicBaz>();
}
