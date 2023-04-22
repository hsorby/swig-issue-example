%module(package="") base

#define EXAMPLES_EXPORT

%include <std_shared_ptr.i>
%include <std_vector.i>
%include <std_string.i>


%shared_ptr(Base)

%{
#include <memory>
#include "base.h"
%}

%include "base.h"
