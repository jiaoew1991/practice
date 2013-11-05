import os
import platform

if platform.platform(True, True).startswith('Windows'):
    env = Environment(tools=['mingw'])
else:
    env = Environment()
currentPath = os.getcwd()

env.Append(CPPPATH=currentPath)

env.SConscript('data_structure/SConscript', exports=['env'], variant_dir='data_structure/build', duplicate=0)
