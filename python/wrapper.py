import time


def log(func):
    def wrapper(*args, **kwargs):
        print(f"Execution time: {time.asctime(time.localtime(time.time()))}")
        return func(*args, **kwargs)
    return wrapper


@log
def sum(*args):
    ret = 0
    for item in args:
        ret += item
    return ret


result = sum(1, 2, 3, 4)
print(result)