def pt():
    print("Yes")
    print(ansa,'+',ansb,'=',ansc)
    quit()


s = input()
valid = False
lst = list(s.split())
a = lst[0]
b = lst[2]
c = lst[4]
ansa = a
ansb = b
ansc = c
for i in range(len(a)):
    for it in range(10):
        ta = a[0:i] + str(it) + a[i :]
        if int(ta) + int(b) == int(c):
            valid = True
            ansa = ta
            pt()
            
for it in range(10):
    ta = a + str(it)
    if int(ta) + int(b) == int(c):
        valid = True
        ansa = ta
        pt()


for i in range(len(b)):
    for it in range(10):
        tb = b[0:i] + str(it) + b[i :]
        if int(a) + int(tb) == int(c):
            valid = True
            ansb = tb
            pt()

for it in range(10):
    tb = b + str(it)
    if int(a) + int(tb) == int(c):
        valid = True
        ansb = tb
        pt()


for i in range(len(c)):
    for it in range(10):
        tc = c[0:i] + str(it) + c[i :]
        if int(a) + int(b) == int(tc):
            valid = True
            ansc = tc
            pt()

for it in range(10):
    tc = c + str(it)
    if int(a) + int(b) == int(tc):
        valid = True
        ansc = tc
        pt()

if valid == False:
    print("No")
