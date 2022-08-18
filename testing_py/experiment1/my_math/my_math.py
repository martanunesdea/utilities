def sum(arg):
    total = 0
    for val in arg:
        if type(val) != int:
            return False
        total += val
    return total


def multiply(arg):
    total = 0
    for val in arg:
        if type(val) != int:
            return False
        total *= val
    return total
