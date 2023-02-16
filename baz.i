%module(package="bigbar") baz

#define EXAMPLES_EXPORT

%include <std_shared_ptr.i>

%shared_ptr(Baz)

%newobject Baz::create;

%{
#include "baz.h"
%}

%include "baz.h"

%extend Baz {
  std::shared_ptr<Baz> Baz() { return Baz::create(); }
};
