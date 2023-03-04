#include "baz.h"

Baz::Baz(int x) : mX(x) {
}

Baz::~Baz() {
    printf("deleted\n");
}

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

std::shared_ptr<Baz> Baz::createShared(int x) {
    return std::shared_ptr<Baz>( new Baz {x});
}
