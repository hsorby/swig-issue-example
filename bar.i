%module(package="bigbar") bar

#define EXAMPLES_EXPORT

%newobject Bar::create;

%ignore Bar::create;

%{
#include "bar.h"
%}

%include "bar.h"

%extend Bar {
  Bar() { return Bar::create(); }
};
