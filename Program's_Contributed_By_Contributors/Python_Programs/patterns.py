for row in range(7):
    for col in range(6):
        if ((col == 0 or col == 3) and (row > 0)) or ((row == 0 or row == 3) and (col == 1 or col == 2)):  # PRINT A
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if ((col == 0) or ((col == 3) and (row != 0 and row != 3 and row != 6))) or (  # PRINT B
                (row == 0 or row == 3 or row == 6) and (0 < col < 3)):
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if ((col == 0) and (row != 0 and row != 6)) or ((row == 0 or row == 6) and (0 < col < 5)):  # PRINT C
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if ((col == 0) or ((col == 3) and (row != 0 and row != 6))) or (
                (row == 0 or row == 6) and (0 < col < 3)):  # PRINT D
            print('*', end=' ')
        else:
            print(' ', end=' ')

    print()

for row in range(7):
    for col in range(6):
        if (col == 0) or ((row == 0 or row == 3 or row == 6) and (0 < col < 3)):  # PRINT E
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if (col == 0) or ((row == 0 or row == 3) and (0 < col < 5)):  # PRINT F
            print('*', end=' ')
    else:
        print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if ((col == 0) or (col == 3 and (row != 1 and row != 2))) or ((row == 3) and (col == 2 or col == 4)) or (
        # PRINT G
                (row == 6 or row == 0) and (0 < col < 3)):
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if ((col == 0 or col == 3) and (row > 0)) or ((row == 3) and (col == 1 or col == 2)):  # PRINT h
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if ((row == 0 or row == 6) and (col > 0)) or (col == 3):  # PRINT I
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if (col == 4 and row != 6) or (row == 0 and 2 < col < 6) or (row == 6 and col == 3) or (
                row == 5 and col == 2):  # PRINT J
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if (col == 0) or ((col == 1) and (row == 3 or row == 4)) or ((col == 2) and (row == 2 or row == 5)) or (
        # PRINT K
                (col == 3) and (row == 1 or row == 6)):
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if (col == 0) or ((row == 6) and (0 < col < 6)):  # PRINT L
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if col == 1 or col == 5 or (row == 2 and (col == 2 or col == 4)) or (row == 3 and col == 3):  # PRINT M
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if ((col == 1 or col == 5) and (row >= 0)) or (row == 1 and (col == 1)) or (row == 2 and col == 2) or (
        # PRINT N
                row == 3 and (col == 3)) or (row == 4 and (col == 4)):
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if (col == 0 or col == 5) and (row != 0 and row != 6) or (
                (row == 0 or row == 6) and (col != 0 and col != 5)):  # PRINT O
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(0, 7):
    for col in range(0, 7):
        if col == 1 or ((row == 0 or row == 3) and 0 < col < 5) or (
                (col == 5 or col == 1) and (row == 1 or row == 2)):  # PRINT P
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if ((col == 0 or col == 5) and (row != 0 and row != 6) or (
                (row == 0 or row == 6) and (col != 0 and col != 5)) or (row == 5 and col == 4) or (  # PRINT Q
                row == 6 and col == 5) or (row == 4 and col == 3)):
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(0, 7):
    for col in range(0, 7):
        if col == 1 or ((row == 0 or row == 3) and 0 < col < 5) or (
                (col == 5 or col == 1) and (row == 1 or row == 2)) or (row == 4 and col == 2) or (  # PRINT R
                row == 5 and col == 3) or (row == 6 and col == 4):
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for column in range(6):
        if ((column == 0) and (row == 1 or row == 2 or row == 6)) or (
                (column == 3) and (row == 0 or row == 4 or row == 5)) or (
                (row == 0 or row == 3 or row == 6) and (0 < column < 3)):  # PRINT S
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if ((row == 0) and (col > 0)) or (col == 3):  # PRINT T
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if (col == 0 or col == 5) and (row != 0 and row != 6) or ((row == 6) and (col != 0 and col != 5)):  # PRINT U
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(7):
        if (row == 0 and (col == 0 or col == 6)) or (row == 1 and (col == 1 or col == 5)) or (  # PRINT V
                row == 2 and (col == 2 or col == 4)) \
                or (row == 3 and (col == 3)):
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(5):
    for col in range(7):
        if (col == 0 or col == 6 or (row == 3 and (col == 1 or col == 5)) or (row == 2 and (col == 2 or col == 4)) or (
                row == 1 and (col == 3))):  # PRINT W
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(6):
        if (col == 0 or col == 5) and (row == 0 or row == 5) or (col == 1 or col == 4) and (row == 1 or row == 4) or (
        # PRINT X
                col == 2 or col == 3) and (row == 2 or row == 3):
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(7):
        if (col == 0 or col == 6) and (row == 0) or (col == 1 or col == 5) and (row == 1) or (
                col == 2 or col == 4) and (row == 2) or (row == 3 and col == 3) or (row == 4 and col == 3) \
                or (row == 5 and col == 3) or (row == 6 and col == 3):  # PRINT Y
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()

for row in range(7):
    for col in range(7):
        if ((row == 0 or row == 5) and col < 6) or (row == 1 and col == 4) or (row == 2 and col == 3) or (  # PRINT Z
                row == 3 and col == 2) \
                or (row == 4 and col == 1):
            print('*', end=' ')
        else:
            print(' ', end=' ')
    print()


