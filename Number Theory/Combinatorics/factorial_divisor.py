def fact_pow(n, k):
    res = 0
    while(n > 0):
        n //= k
        res += n
    return res

print(fact_pow(6, 2))