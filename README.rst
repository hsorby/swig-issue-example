
SWIG Issue Example
==================

This repository contains an example using SWIG to map a creator method in a C++ class to a Python constructor.

This works well for raw pointers, but I am wanting to know if the same or similar can be achieved with smart pointers.

This example shows three simple cases:

1. Foo - A simple standard C++ class
2. Bar - A C++ class with a private constructor and a create method returning a raw pointer.
3. Baz - A C++ class with a protected constructor and a create method returning a smart pointer.

The Foo and Bar classes work as expected, the :code:`%extend Bar` macro (in :code:`bar.i`) works to map the create method to a Python constructor.
The current implementation of the Baz class does not work as intended.

There is also a test python script (:code:`test_script.py`) that makes use of :code:`Baz.create()`, which is not the desired process for creating a Baz object in Python.
