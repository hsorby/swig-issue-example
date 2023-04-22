#pragma once

#include <memory>

#include "examplesexportdefinitions.h"
#include "base.h"

class EXAMPLES_EXPORT Bazza : public Base {
  private:
    Bazza();
    explicit Bazza(int x);

    class BazzaImpl; /**< Forward declaration for pImpl idiom, @private. */

    BazzaImpl *pFunc(); /**< Getter for private implementation pointer, @private. */
    const BazzaImpl *pFunc() const; /**< Const getter for private implementation pointer, @private. */

  public:
    ~Bazza();
    Bazza(const Bazza &rhs) = delete; /**< Copy constructor, @private. */
    Bazza(Bazza &&rhs) noexcept = delete; /**< Move constructor, @private. */
    Bazza &operator=(Bazza rhs) = delete; /**< Assignment operator, @private. */

    static std::shared_ptr<Bazza> createShared();
    static std::shared_ptr<Bazza> createShared(int x);

    void setX(int x);
    int x() const;
    static int add(int x, int y);
};
