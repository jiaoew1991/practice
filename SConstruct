import os
import platform

if platform.platform(True, True).startswith('Windows'):
    env = Environment(tools=['mingw'])
else:
    env = Environment()
currentPath = os.getcwd()

env.Append(CPPPATH=[currentPath])
env.Append(CPPPATH=["/Users/jiaoew/thirdparty/googlemock-read-only/include", "/Users/jiaoew/thirdparty/googlemock-read-only"])
env.Append(CPPPATH=["/Users/jiaoew/thirdparty/googlemock-read-only/gtest/include", "/Users/jiaoew/thirdparty/googlemock-read-only/gtest"])

libs = [
    File('/Users/jiaoew/thirdparty/googlemock-read-only/make/gmock_main.a'),
    File('/Users/jiaoew/thirdparty/googlemock-read-only/gtest/make/gtest_main.a'),
]

env.SConscript('data_structure/SConscript', exports=['env', 'libs'], variant_dir='data_structure/build', duplicate=0)
