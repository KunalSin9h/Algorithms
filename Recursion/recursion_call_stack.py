def count(n):
    if(n < 1):
        return
    print(n)
    count(n-1)


count(10)