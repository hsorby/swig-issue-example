#pragma once

#include <string>
#include <vector>

#include "examplesexportdefinitions.h"

class EXAMPLES_EXPORT Base
{
public:
    virtual ~Base() = 0; /**< Destructor, @private. */
    Base(const Base &rhs) = delete; /**< Copy constructor, @private. */
    Base(Base &&rhs) noexcept = delete; /**< Move constructor, @private. */

    int y() const;

    size_t errorCount() const;

    void addError(const std::string &err);

protected:
    class BaseImpl; /**< Forward declaration for pImpl idiom, @private. */

    explicit Base(BaseImpl *derivedPimpl); /**< Constructor, @private. */

    BaseImpl *pFunc();
    const BaseImpl *pFunc() const;

private:
    BaseImpl *mPimpl; /**< Private member to implementation pointer, @private. */
};
