import timeit
import os

data = 'x' * 10**9 

start = timeit.default_timer()
with open('OS_IOtime.txt', 'w') as file:
    file.write(data)
end = timeit.default_timer()
print(f"I/O time : {end - start} s")

os.remove('OS_IOtime.txt')

fac = [0] * 1000
def factorial(n):
    if (n == 0 or n == 1) : 
        fac[n] = 1
        return 1
    fac[n] = factorial(n-1) * n
    return fac[n]

start = timeit.default_timer()
factorial(500)
end = timeit.default_timer()
print(f"CPU time: {end - start} s")
