# coding: utf-8

import os
import shutil


output = open("1.txt", "w")
i=0
def Test(rootDir):
	global i
	for lists in os.listdir(rootDir):
		path = os.path.join(rootDir,lists)
		if os.path.isdir(path):
			Test(path)
		elif os.path.isfile(path):
			if (path.find('1_') != -1):
				output.writelines(path)
				shutil.copy(path, os.path.normcase('E:/DatasetC/origin_C/_'+str(i)+path[path.index('\im')+1:]))
				i += 1
			elif (path.find('2_') != -1):
				shutil.copy(path, os.path.normcase('E:/DatasetC/recap_C/_'+str(i)+path[path.index('\im')+1:]))
				output.writelines(path)
				i += 1
			else:
				output.writelines("fail:"+path)

if __name__ == '__main__':
	Test(r'E:\DatasetC')