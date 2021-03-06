train_file = open('train_C', 'r')
from numpy import *

MAX = 1174
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

f = open('train_C_uniform','w')
for row in range(MAX):
	f.write(label[row] + ' ')
	total = 0.0
	for i in range(10):
		total += float(multi_list[row][i])
	print total
	for col in range(1, 81):
		tmp = float(multi_list[row][col-1])
		f.write(str(col)+':'+str(tmp/total)+' ')
	f.write('\n')

f.close()
train_file.close()