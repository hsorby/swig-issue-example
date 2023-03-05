#pragma once

#include <memory>

#include "examplesexportdefinitions.h"

class EXAMPLES_EXPORT Bazza {
  private:
    Bazza();
    explicit Bazza(int x);

    class BazzaImpl; /**< Forward declaration for pImpl idiom, @private. */
    BazzaImpl *mPimpl; /**< Private member to implementation pointer, @private. */

//    BazzaImpl *pFunc(); /**< Getter for private implementation pointer, @private. */
//    const BazzaImpl *pFunc() const; /**< Const getter for private implementation pointer, @private. */

  public:
    ~Bazza();

    static std::shared_ptr<Bazza> createShared();
    static std::shared_ptr<Bazza> createShared(int x);

    void setX(int x);
    int x() const;
    static int add(int x, int y);
};
