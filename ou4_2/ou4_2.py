#!/usr/bin/env python3

from heltal import Heltal
from time import perf_counter as pc
import matplotlib.pyplot as plt


def fib_py(n):
	if n <= 1:
		return n
	else:
		return(fib_py(n-1)+fib_py(n-2))

def main():
	x = [n for n in range(30, 36)]
	y_py, y_c = [], []
	for n in x:
		start = pc()
		fib_py(n)
		end = pc()
		y_py.append(end-start)
	for n in x:
		start = pc()
		f = Heltal(n)
		f.fib() 
		end = pc()
		y_c.append(end-start)
	print (f"times py:{y_py}") #####################
	print(f"times c: {y_c}") #####################
	plt.plot(x, y_py, color="blue")
	plt.plot(x, y_c,color="red")
	plt.xlabel("n")
	plt.ylabel("processing speed")
	plt.title("Fibonacci speed for Python and C++")
	plt.show()
	plt.savefig("fib_speed.png")
	f = Heltal(47)
	print(f"47th fibonacci number: {f.fib()}")

if __name__ == '__main__':
	main()

