#pragma once

#include <memory>

#include "examplesexportdefinitions.h"

class EXAMPLES_EXPORT Baz {
  private:
    int mX;
    Baz() = default;
    explicit Baz(int x);

  public:
    ~Baz();

    static std::shared_ptr<Baz> createShared();
    static std::shared_ptr<Baz> createShared(int x);

    void setX(int x);
    int x() const;
    static int add(int x, int y);
};
