import re

file = open("halla", "r")

beis = " halla walla balla halla allahuackbar halla"
reg = r"(halla)"
m = re.compile(reg)

result = m.findall(beis)

print(result)

