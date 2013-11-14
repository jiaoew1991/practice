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

config = json.load(open('./scons.config'))
env.Append(CPPPATH=[currentPath])
env.Append(CPPPATH=[os.path.join(config['gmock_path'], 'include'), config['gmock_path']])
env.Append(CPPPATH=[os.path.join(config['gmock_path'], 'gtest/include'), os.path.join(config['gmock_path'], 'gtest')])

libs = [
    File(os.path.join(config['gmock_path'], 'make/gmock_main.a')),
    File(os.path.join(config['gmock_path'], 'gtest/make/gtest_main.a')),
]

env.SConscript('data_structure/SConscript', exports=['env', 'libs'], variant_dir='data_structure/build', duplicate=0)
