%module(package="bigbar") baz

#define EXAMPLES_EXPORT

%include <std_shared_ptr.i>

%shared_ptr(Baz)

%ignore Baz::createShared;

%{
#include "baz.h"

Baz *createRawFromNoDeleteShared() {
    return std::shared_ptr<Baz>( new Baz {}, [](Baz *) {}/*No-Op Deleter*/).get();
}

%}

%include "baz.h"

%extend Baz {
   Baz()
   {
       return createRawFromNoDeleteShared();
   }
};
