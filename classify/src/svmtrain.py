from svm import *
from svmutil import *

y, x = svm_read_problem("tran_A_uniform")

prob = svm_problem(y,x)
param = svm_parameter('-v 5 -g 2 -c 8192')
m = svm_train(prob , param)

# oy, ox = svm_read_problem("dataset\\test_+1")
# p_label, p_acc, p_val = svm_predict(oy, ox, m)
# py, px = svm_read_problem("dataset\\test_-1")
# p_label, p_acc, p_val = svm_predict(py, px, m)

# print p_label, p_acc, p_val

# train_file = open('all', 'r')
# MAX = 2835
# label = []
# multi_list = [[0 for col in range(80)] for row in range(MAX)]
# col = row = 0

# for line in train_file.readlines():
# 	label.append(line[:2])
# 	line = line[3:]
# 	for col in range(80):
# 		multi_list[row][col] = (line[line.find(':')+1:line.find(' ')])
# 		line = line[line.find(' ')+1:]
# 	row +=1

# fileA = open('a.txt', 'w')
# fileB = open('b.txt', 'w')

# for i in range(len(label)):
# 	fileA.writelines(label[i])
# 	fileA.writelines('\n')

# for i in range(MAX):
# 	for j in range(80):
# 		fileB.writelines(multi_list[i][j])
# 		fileB.writelines(' ')
# 	fileB.writelines('\n')

# fileA.close()
# fileB.close()
# train_file.close()