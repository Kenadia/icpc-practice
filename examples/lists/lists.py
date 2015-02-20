def f(x):
    return x != 0
v = []
x = 0
v.append(x)
print len(v)
v = filter(f, v)
print len(v)
