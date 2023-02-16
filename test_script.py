#!/usr/bin/env python

from bar import Bar
from baz import Baz

b1 = Bar()
b2 = Baz()
#b_shared = Baz.createShared()

b1.setX(7)
b2.setX(9)
#b_shared.setX(13)

#print(f"Bar value is: {b1.x()}, Baz value is: {b2.x()}, Baz shared value is: {b_shared.x()}.")
print(f"Bar value is: {b1.x()}, Baz value is: {b2.x()}.")

