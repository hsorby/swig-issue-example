#pragma once

#include "examplesexportdefinitions.h"

class EXAMPLES_EXPORT Foo {
  private:
    int mX;
  public:
    Foo() = default;
    ~Foo() = default;
    void setX(int x);
    int x() const;
    static int add(int x, int y);
};
