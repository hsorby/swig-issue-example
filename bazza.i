%module(package="bigbar") bazza

#define EXAMPLES_EXPORT

%include <std_shared_ptr.i>

%shared_ptr(Bazza)

%import "base.i"

%ignore Bazza::createShared;

%{
#include "bazza.h"
%}


%typemap(out) Bazza *Bazza() {
  /*
  Here we take the returned value from the Constructor for this object and cast it
  to the pointer that it actually is.  Once that is done we can set the required resultobj.
  */
  std::shared_ptr<  Bazza > *smartresult = reinterpret_cast<std::shared_ptr<  Bazza > *>(result);
  %set_output(SWIG_NewPointerObj(%as_voidptr(smartresult), $descriptor(std::shared_ptr< Bazza > *), SWIG_POINTER_OWN));
  printf("use count: %ld\n", smartresult->use_count());
}

%include "bazza.h"

%extend Bazza {
    Bazza() {
        /*
        Provide a fake Constructor for the class and return a shared pointer
        as an actual class pointer because that is what we have to return from
        this fake Constructor.  The intention here is that this method is
        only used in one place so there we know it is actually a pointer
        to a shared pointer and cast it back to its proper form then.
        */
        auto ptr = new std::shared_ptr<  Bazza >(Bazza::createShared());
        return reinterpret_cast<Bazza *>(ptr);
    }
}

%extend Bazza {
    Bazza(int x) {
        /*
        Provide a fake Constructor for the class and return a shared pointer
        as an actual class pointer because that is what we have to return from
        this fake Constructor.  The intention here is that this method is
        only used in one place so there we know it is actually a pointer
        to a shared pointer and cast it back to its proper form then.
        */
        auto ptr = new std::shared_ptr<  Bazza >(Bazza::createShared(x));
        return reinterpret_cast<Bazza *>(ptr);
    }
}
