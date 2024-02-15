from math import gcd
from fractions import Fraction

def nth_root_of_unity(n):
    return complex(cos(2*pi/n), sin(2*pi/n))

def solve_sequence(x, n):
    w = nth_root_of_unity(n)
    result_real = 1.0
    result_imag = 0.0
    term_real = 1.0
    term_imag = 0.0

    for i in range(n):
        result_real *= x
        term_real = term_real * w.real - term_imag * w.imag
        term_imag = term_real * w.imag + term_imag * w.real
        result_real -= term_real
        result_imag -= term_imag

    common_divisor = gcd(int(result_real), int(result_imag))
    result_real = int(result_real) // common_divisor
    result_imag = int(result_imag) // common_divisor

    if result_imag == 0:
        return str(result_real)
    else:
        return f"{result_real}/{result_imag}"

t = int(input())
for _ in range(t):
    x, n = map(int, input().split())
    result = solve_sequence(x, n)
    print(result)
