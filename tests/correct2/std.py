
import os

files = os.listdir(".")

for f in files:
	f_in = open(f)
	text = f_in.read()
	if "::" not in text:
		print f
		fname = f[:-3]
		out = os.popen("python " + fname + ".py").read()
		fout = open(fname + ".std","w")
		fout.write(out)
		fout.close()
