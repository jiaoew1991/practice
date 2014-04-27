train_file = open('train', 'r')
from numpy import *

MAX = 1741
label = []
multi_list = [[0 for col in range(80)] for row in range(MAX)]
col = row = 0

for line in train_file.readlines():
	label.append(line[:2])
	line = line[3:]
	for col in range(80):
		multi_list[row][col] = (line[line.find(':')+1:line.find(' ')])
		line = line[line.find(' ')+1:]
	row +=1

f = open('test_1','w')
for row in range(MAX):
	f.write(label[row] + ' ')
	for col in range(1, 81):
		f.write(str(col)+':'+multi_list[row][col-1]+' ')
	f.write('\n')

f.close()
train_file.close()