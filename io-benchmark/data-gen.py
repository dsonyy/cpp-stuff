from random import randrange

f = open("data.txt", "w")

sz = 0
for i in range(2000000):
    sz += f.write(str(randrange(1000, 10000)) + " ")

print("SIZE =", sz)
f.close()
