#include "bazza.h"

#include "base_p.h"

class Bazza::BazzaImpl: public Base::BaseImpl
{
public:
    int mX;
};

Bazza::Bazza()
    : Base(new Bazza::BazzaImpl()){
}

Bazza::Bazza(int x)
    : Base(new Bazza::BazzaImpl()){
    pFunc()->mX = x;
}

Bazza::~Bazza() {
    delete pFunc();
    printf("deleted\n");
}

Bazza::BazzaImpl *Bazza::pFunc()
{
    return reinterpret_cast<Bazza::BazzaImpl *>(Base::pFunc());
}

const Bazza::BazzaImpl *Bazza::pFunc() const
{
    return reinterpret_cast<Bazza::BazzaImpl const *>(Base::pFunc());
}

void Bazza::setX(int x) {
  pFunc()->mX = x;
}

int Bazza::x() const {
  return pFunc()->mX;
}

int Bazza::add(int x, int y) {
  return x + y;
}

std::shared_ptr<Bazza> Bazza::createShared() {
    return std::shared_ptr<Bazza>( new Bazza {});
}

std::shared_ptr<Bazza> Bazza::createShared(int x) {
    return std::shared_ptr<Bazza>( new Bazza {x});
}
