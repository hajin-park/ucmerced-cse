def findElementsInCommon(listOne, listTwo):
    one_set = set(listOne)
    two_set = set(listTwo)
    return [*set(one_set & two_set)]