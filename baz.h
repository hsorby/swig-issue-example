#pragma once

#include <memory>

#include "examplesexportdefinitions.h"

class EXAMPLES_EXPORT Baz {
  private:
    int mX;
  protected:
    Baz() = default;
  public:
    static std::shared_ptr<Baz> create();
    void setX(int x);
    int x() const;
    static int add(int x, int y);
};
