#!/usr/bin/env python

from bar import Bar
from baz import Baz

b1 = Bar()
b2 = Baz.create()

b1.setX(7)
b2.setX(9)

print(f"Bar value is: {b1.x()}, Baz value is: {b2.x()}.")

