# 一个小组件, 通过代码生成一个完整的shim字符串
# 注意tmp是包含所有的代码的（含换行空格等)
# 拓展项 ： 传入参数配合正则表达式实现 tab stop (UNDONE)
def genShim(name : str, code : list, prefix : str) -> str:
    head = addQuot(name) + " : "
    pre = comb(['"prefix"',addQuot(prefix)],' : ')
    body = comb(['"body"',comb(list(map(addQuot,code)))],' : \n')
    return head + addQuot(comb([pre,body]),'{\n','\n}')

# 为字符串两端添加(双引号)
def addQuot(s : str, split : str = '"',splr : str = None) -> str:
    return split + s + (splr if splr else split)

# 将列表内的字符串组合成一个大字符串
def comb(lst : list, split : str = ",\n") -> str:
    return split.join(lst)

# 这些是测试样例 实际使用的时候可以
# 构建设计一个对象配合
# 文件IO流来一键(或者带参数的)操作
if __name__ == "__main__":
    lst = []
    s = input()
    while s:
        lst.append(s)
        s = input()
    print(genShim("Test", lst, "T test"))
