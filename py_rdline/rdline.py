import os 
import io
import glob 

txtlst = glob.glob('./texts/*txt')
print(txtlst)

for txt in txtlst:
	with io.open(txt, 'r', encoding='utf-8') as fd:
		lines = fd.readlines()
		for line in lines:
			if line == '\n':
				continue
			print(line)