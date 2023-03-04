%module(package="bigbar") baz

#define EXAMPLES_EXPORT

%include <std_shared_ptr.i>

%shared_ptr(Baz)

%ignore Baz::createShared;
%ignore createRaw;

%{
#include "baz.h"
%}


%typemap(out) Baz *Baz() {
  /*
  Here we take the returned value from the Constructor for this object and cast it
  to the pointer that it actually is.  Once that is done we can set the required resultobj.
  */
  std::shared_ptr<  Baz > *smartresult = reinterpret_cast<std::shared_ptr<  Baz > *>(result);
  printf("use count: %ld\n", smartresult->use_count());
  %set_output(SWIG_NewPointerObj(%as_voidptr(smartresult), $descriptor(std::shared_ptr< Baz > *), SWIG_POINTER_OWN));
}

%include "baz.h"

%extend Baz {
    Baz() {
        /*
        Provide a fake Constructor for the class and return a shared pointer
        as an actual class pointer because that is what we have to return from
        this fake Constructor.  The intention here is that this method is
        only used in one place so there we know it is actually a pointer
        to a shared pointer and cast it back to its proper form then.
        */
        auto ptr = new std::shared_ptr<  Baz >(Baz::createShared());
        return reinterpret_cast<Baz *>(ptr);
    }
}

%extend Baz {
    Baz(int x) {
        /*
        Provide a fake Constructor for the class and return a shared pointer
        as an actual class pointer because that is what we have to return from
        this fake Constructor.  The intention here is that this method is
        only used in one place so there we know it is actually a pointer
        to a shared pointer and cast it back to its proper form then.
        */
        auto ptr = new std::shared_ptr<  Baz >(Baz::createShared(x));
        return reinterpret_cast<Baz *>(ptr);
    }
}
