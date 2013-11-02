import os
import platform

if platform.platform(True, True).startswith('Windows'):
    env = Environment(tools=['mingw'])
else:
    env = Environment()

env.Append(LIBPATH='D:/util/MinGW/lib/gcc/mingw32/4.7.2/include/c++')

env.SConscript('data_structure/SConscript', exports=['env'], variant_dir='data_structure/build', duplicate=0)
