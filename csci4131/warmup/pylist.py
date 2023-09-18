result = "<ol>\n"
usrinput = input()
while len(usrinput) != 0:
    result += ("<li>" + usrinput + "</li>\n")
    usrinput = input()
result += "</ol>"
print(result)