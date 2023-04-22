
#include "base.h"

#include "base_p.h"

Base::BaseImpl *Base::pFunc()
{
    return mPimpl;
}

const Base::BaseImpl *Base::pFunc() const
{
    return mPimpl;
}

Base::Base(BaseImpl *derivedPimpl)
    : mPimpl(derivedPimpl)
{
}

Base::~Base() = default;

int Base::y() const
{
    return pFunc()->mY;
}

size_t Base::errorCount() const
{
    return pFunc()->mErrors.size();
}

void Base::addError(const std::string &err)
{
    pFunc()->mErrors.push_back(err);
}
