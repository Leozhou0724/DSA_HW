l1 = [1, 2, 3, 4]
l2 = [5, 6, 7, 8, 9, 10, 11]
i = 0  # pointer for l1
j = 0  # pointer for l2
l = []
while (i + j) < len(l1 + l2):
    if i < len(l1) and j < len(l2):
        l.append(l1[i])
        i += 1
        l.append(l2[j])
        j += 1
    elif j >= len(l2):  # l2 is done
        l.append(l1[i])
        i += 1
    else:
        l.append(l2[j])
        j += 1
print(l)
