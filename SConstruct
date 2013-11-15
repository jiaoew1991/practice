#coding: utf-8
import os
import json
import platform

if platform.platform(True, True).startswith('Windows'):
    env = Environment(tools=['mingw'])
else:
    env = Environment()
currentPath = os.getcwd()

##scons.config包含不同工作平台的配置信息
#    gmock_path:  gmock库的位置
#    lib4cplus_path: lib4cplus库的路径

config = json.load(open('./scons.config'))
env.Append(CPPPATH=[currentPath])
env.Append(CPPPATH=[os.path.join(config['gmock_path'], 'include'), config['gmock_path']])
env.Append(CPPPATH=[os.path.join(config['gmock_path'], 'gtest/include'), os.path.join(config['gmock_path'], 'gtest')])
env.Append(CPPPATH=[os.path.join(config['log4cplus_path'], 'include')])

env.Append(LIBPATH=[os.path.join(config['log4cplus_path'], 'src/.libs')])

libs = [
    File(os.path.join(config['gmock_path'], 'make/gmock_main.a')),
    File(os.path.join(config['gmock_path'], 'gtest/make/gtest_main.a')),
    'log4cplus',
    #File(os.path.join(config['log4cplus_path'], 'src/.libs/liblog4cplus.a')),
]
env.Append(LIBS=['log4cplus'])

env.SConscript('data_structure/SConscript', exports=['env', 'libs'], variant_dir='data_structure/build', duplicate=0)
