
# scope
# End of file


unit = int(input())
# 350

cost = 0

# First 100
if unit >= 100:
    unit = unit-100
    cost = cost + 100 * 0
else:
    print("cost :", cost)
    exit()

# Second 100
if unit >= 100:
    cost = cost + 100 * 5
    unit = unit-100
else:
    cost = cost + unit * 5
    print("cost :", cost)
    exit()

# baki gula
cost = cost + unit * 10
print("cost :", cost)



