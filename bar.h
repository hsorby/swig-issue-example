#pragma once

#include "examplesexportdefinitions.h"

class EXAMPLES_EXPORT Bar {
  private:
    int mX;
    Bar() = default;
  public:
    ~Bar() = default;
    static Bar *create();
    void setX(int x);
    int x() const;
    static int add(int x, int y);
};
