n = int(input())
inf = 1e14

sus = []
jos = []
dreapta = []
stanga = []

for i in range(n):
    x = input().split()
    a = float(x[0])
    b = float(x[1])
    c = float(x[2])

    if b > 0:
        jos.append(-c/b)
    if b < 0:
        sus.append(-c/b)
    if b == 0:
        if a > 0:
            stanga.append(-c/a)
        else:
            dreapta.append(-c/a)

sus.sort()
jos.sort()
dreapta.sort()
stanga.sort()

def find_upper(st, dr, x, v):
    if st > dr:
        return inf

    mij = int((st + dr) / 2)

    if x < v[mij]:
        aux = find_upper(st, mij - 1, x, v)
        if mij < aux:
            return mij
        else:
            return aux

    return find_upper(mij + 1, dr, x, v)


def find_lower(st, dr, x, v):
    if st > dr:
        return -inf

    mij = int((st + dr) / 2)

    if x > v[mij]:
        aux = find_lower(mij + 1, dr, x, v)
        if mij > aux:
            return mij
        else:
            return aux

    return find_lower(st, mij - 1, x, v)

m = int(input())

for i in range(m):
    x = input().split()
    a = float(x[0])
    b = float(x[1])


    c = find_upper(0, len(jos) - 1, b, jos)
    d = find_lower(0, len(sus) - 1, b, sus)
    e = find_upper(0, len(stanga) - 1, a, stanga)
    f = find_lower(0, len(dreapta) - 1, a, dreapta)

    if c == inf or e == inf or d == -inf or f == -inf:
        print("NO")
    else:
        print("YES")


        lungime = jos[c] - sus[d]
        latime = stanga[e] - dreapta[f]

        print("{:.6f}".format(lungime * latime))


# print(sus)
# print(jos)
# print(stanga)
# print(dreapta)