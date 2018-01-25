def triangles():
    l = [1]
    while True:
        yield l
        l= [l[i] + l[i+1] for i in range(0, len(l)-1)]
        l.insert(0, 1)
        l.append(1)

n = 0
for i in triangles():
    print(i)
    n = n + 1
    if n == 10:
        break
