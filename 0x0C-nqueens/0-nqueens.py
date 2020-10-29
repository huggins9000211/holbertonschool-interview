#!/usr/bin/python3
import sys
class Board:
    def __init__(self, n):
        self.cols = set()
        self.right_diags = set()
        self.left_diags = set()
        self.queen_locations = []
        self.n = n
    def add(self, row, col):
        self.cols.add(col)
        self.right_diags.add(row + col)
        self.left_diags.add(row - col)
        self.queen_locations.append(col)
    def remove(self, row, col):
        self.cols.remove(col)
        self.right_diags.remove(row + col)
        self.left_diags.remove(row - col)
        self.queen_locations.pop()
    def isValidPlacement(self, row, col):
        return col not in self.cols and \
                row + col not in self.right_diags and \
                row - col not in self.left_diags
    def outputFormat(self):
        return ['.'*x + 'Q' + '.'*(self.n-x-1) for x in self.queen_locations]

try:
    n = int(sys.argv[1])
except Exception:
    print("N must be a number")
    exit(1)
if (isinstance(n, int)):
    if (n >= 4):
        output = []
        def dfs(row, queens, diags):
            if row == n:
                output.append(queens)
                return
            for col in range(n):
                if not any([row+col in diags, row-col-n-1 in diags, col in queens]):
                    dfs(row + 1, queens + [col], diags | {row+col, row-col-n-1})
        dfs(0, [], set())

        counter = 0
        for p in output:
            final = []
            for o in p:
                final.append([counter, o])
                counter += 1
            counter = 0
            print(final)
    else:
        print("N must be at least 4")
        exit(1)
else:
    print("N must be a number")
    exit(1)
