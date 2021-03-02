# 闭包能够保存传入函数中的局部变量, 但是如果局部变量后续值被更改的话, 闭包得到的函数中引用的局部变量的值也会改变。
def func1(i):
    return lambda x: x+i

def func2(i):
    return i

func_list = [lambda x: x + i for i in range(4)]
func_list_ = [func1(i) for i in range(4)]
func_list__ = [func2(i) for i in range(4)]

print(func_list[0](0), func_list[1](0))
print(func_list_[0](0), func_list_[1](0))
print(func_list__[0], func_list__[1])


def func3():
    fs = []
    collect = []
    for i in range(1, 4):
        collect.append(i)
        def sub_func():
            j = collect[-1]
            return j * j
        fs.append(sub_func)
    return fs


def func4():
    fs = []
    collect = []
    for i in range(1, 4):
        collect.append(i)
    
    for i in range(3):
        def sub_func():
            j = collect[i]
            return j * j
        fs.append(sub_func)
    return fs


a, b, c = func3()
print(a(), b(), c())
a, b, c = func4()
print(a(), b(), c())



