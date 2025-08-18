a = range(2, 101)
b = range(2, 101)

appeared = []

for i in a:
	res = i
	for j in b:
		found = False
		res *= i
		for k in appeared:
			if res == k:	found = True
		if found:	continue
		appeared += [res]

print(len(appeared), "distinct terms are in the sequence")