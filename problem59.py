M = list(map(int, open("0059_cipher.txt", "r").read().split(',')))
L = [[M[(3*i)], M[(3*i)+1], M[(3*i)+2]] for i in range(len(M)//3)]

key = ['e', 'a', 'a']

for i in range(len(key)):
	while key[i] < 'z':
		hh = False
		S = ([l[i]^ord(key[i]) for l in L])
		for j in S:
			if j < 32 or j > 123:
				key[i] = chr(ord(key[i]) + 1)
				hh = True
				break
		if not hh:	break

sum = 0
for i in range(len(M)):
	sum += M[i]^ord(key[i%3])
print("sum of ASCII characters is", sum)

print("key:", "".join(key))
S = ([ chr(l[0]^ord(key[0])) + chr(l[1]^ord(key[1])) + chr(l[2]^ord(key[2])) for l in L])
print("".join(S))