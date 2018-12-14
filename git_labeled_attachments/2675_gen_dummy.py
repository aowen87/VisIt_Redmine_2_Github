#!/usr/bin/env python2
import h5py
import numpy

NX = NY = 1536
NZ = 1297

shape = (NX, NY, NZ)

a = numpy.random.random(shape).astype(numpy.float32)

f = h5py.File('dummy.h5', 'w')

d = f.create_dataset('var_f4', data=a)

f.close()