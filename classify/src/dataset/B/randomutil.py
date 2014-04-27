import random

setA = open('all+1', 'r')
setB = open('all-1', 'r')

train = open('train_B', 'w')
test = open('test_B', 'w')

for line in setA.readlines():
	if (random.randrange(0, 5) < 4):
		train.writelines(line)
	else:
		test.writelines(line)

for line in setB.readlines():
	if (random.randrange(0, 5) < 4):
		train.writelines(line)
	else:
		test.writelines(line)

setA.close()
setB.close()
train.close()
test.close()