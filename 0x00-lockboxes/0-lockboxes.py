#!/usr/bin/python3
def canUnlockAll(boxes):
    avalBoxes = [boxes[0]]
    myBoxes = set(range(1, len(boxes)))
    while (len(avalBoxes) > 0):
        for i in avalBoxes:
            for j in i:
                if j in myBoxes:
                    avalBoxes.append(boxes[j])
                    myBoxes.remove(j)
                if len(myBoxes) == 0:
                    return True
        avalBoxes.pop(0)
        print(myBoxes)
        print("*** {} ***".format(avalBoxes))
    return False
