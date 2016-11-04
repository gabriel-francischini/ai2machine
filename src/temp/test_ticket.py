import os

index = 0
prefix = "log"

for i in range(1000000):
	index += 1
	namefile = prefix + str(index) + ".txt"
	command = "./test_getTicket > " + namefile
	os.system(command)