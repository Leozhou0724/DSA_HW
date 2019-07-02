import csv
import numpy as np
import matplotlib.pyplot as plt
import random
'''
dest_x = []
dest_y = []
with open("data.csv", 'r') as f:
    reader = csv.reader(f)
    fieldnames = next(reader)
    csv_reader = csv.DictReader(f, fieldnames=fieldnames)
    for row in csv_reader:
        d = {}
        for k, v in row.items():
            d[k] = float(v)
        dest_x.append(d['x'])
        dest_y.append(d['y'])

print(dest_x)
print(dest_y)

x = [[1, 3], [3, 5]]
y = [[4, 7], [7, 3]]
plt.plot(x, y, 'grey')
plt.plot(x, y, 'ok')
plt.show()
'''
f = open("data8.csv", 'w')
f.write('x,y\n')
for i in range(512):
    a = random.randint(-100, 100)
    b = random.randint(-100, 100)
    c = "{},{}\n".format(a, b)
    f.write(c)
f.close()
