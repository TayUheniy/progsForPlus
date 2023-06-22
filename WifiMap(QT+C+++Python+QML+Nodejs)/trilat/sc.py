import os
import sys
import re
import subprocess
from math import pi, cos,sin
from random import random
def tril(strs):
	if len(strs) == 1:
		theta = random()*2*pi
		resul = [strs[0][0]+cos(theta)*strs[0][2],strs[0][1]+sin(theta)*strs[0][2]]
		return resul
	if len(strs) == 2:
		strs.append(strs[1])
	os.system("rm /home/ubuntu/trilat/trilat/sample.js")
	f = open('/home/ubuntu/trilat/trilat/sample.js','w')
	str1 = "var trilat = require('./index');\n"
	str2 = "var input = [["
	f.write(str1)
	f.write(str2)
	inde1 = 0
	for indexx in strs:
		inde = 0
		f.write(str(indexx).strip('[]'))
		if inde1 == 2:
			f.write("]];\n")
		else:
			f.write("],[")
		inde1 = inde1 + 1
	f.write("var output = trilat(input);\n")
	f.write("console.log(output);")
	f.close()
	consolestr = subprocess.run(["node", "/home/ubuntu/trilat/trilat/sample.js"],stdout = subprocess.PIPE)
	tex = consolestr.stdout
	tex1 = str(tex)
	tex2 = re.findall(r'\d+[.]*\d*',tex1)
	resul =list(map(float,tex2))
	return resul
