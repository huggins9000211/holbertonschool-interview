#!/usr/bin/python3
"""
10 rain
"""
def rain(walls):
    """
    rain function
    """
    ans = 0
    size = len(walls)
    leftMax = [None] * size
    rightMax = [None] * size
    leftMax[0] = walls[0]
    i = 1
    while i < size:
        leftMax[i] = max([walls[i], leftMax[i - 1]])
        i += 1
    rightMax[size - 1] = walls[size - 1]
    i = size - 2
    while i >= 0:
        rightMax[i] = max([walls[i], rightMax[i + 1]])
        i -= 1
    i = 1
    while i < size - 1:
        ans += min([leftMax[i], rightMax[i]]) - walls[i]
        i += 1
    return ans
