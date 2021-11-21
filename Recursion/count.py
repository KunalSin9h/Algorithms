def f2(name):
    print(name)
    f3(name)
def f3(name):
    print(name)
    f4(name)
def f4(name):
    print(name)
    print("Last Call")


def f1(name):
    print(name)
    f2(name)
    
f1("Kunal")