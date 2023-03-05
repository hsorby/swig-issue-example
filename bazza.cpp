#include "bazza.h"

class Bazza::BazzaImpl
{
public:
    int mX;
};

Bazza::Bazza()
    : mPimpl(new Bazza::BazzaImpl()){
}

Bazza::Bazza(int x)
    : mPimpl(new Bazza::BazzaImpl()){
    mPimpl->mX = x;
}

Bazza::~Bazza() {
    delete mPimpl;
    printf("deleted\n");
}

//Bazza::BazzaImpl *Bazza::pFunc()
//{
//    return reinterpret_cast<Bazza::BazzaImpl *>(Entity::pFunc());
//}

//const Bazza::BazzaImpl *Bazza::pFunc() const
//{
//    return reinterpret_cast<Bazza::BazzaImpl const *>(Entity::pFunc());
//}

void Bazza::setX(int x) {
  mPimpl->mX = x;
}

int Bazza::x() const {
  return mPimpl->mX;
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
