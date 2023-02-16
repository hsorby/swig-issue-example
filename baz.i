%module(package="bigbar") baz

#define EXAMPLES_EXPORT

%include <std_shared_ptr.i>

%shared_ptr(Baz)

%newobject Baz::createShared;

%ignore Baz::create;

%{
#include "baz.h"
%}

%include "baz.h"

%extend Baz {
  Baz() { return Baz::createShared(); }
  // Alternates
  // Baz() { return Baz::create(); }
  // Baz() { return Baz::createShared().get(); }
};
