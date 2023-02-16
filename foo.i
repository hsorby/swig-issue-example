%module(package="bigfoo") foo

#define EXAMPLES_EXPORT

%{
#include "foo.h"
%}

%include "foo.h"

