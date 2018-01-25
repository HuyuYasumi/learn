L = [('bob', 75), ('adam', 92), ('bart', 66), ('lisa', 88)]

def by_name(t):
    return t[0]

def by_sorce(t):
    return t[1]

print(sorted(L, key = by_name), sorted(L, key = by_sorce, reverse = True))
