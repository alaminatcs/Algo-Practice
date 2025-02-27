MOD = 1000000007

def matrix_mult(A, B):
    return [[(A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD, (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD], 
            [(A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD, (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD]]

def matrix_exponentiation(matrix, power):
    result = [[1, 0],
              [0, 1]]  # Identity matrix
    base = matrix
    
    while power:
        if power % 2:
            result = matrix_mult(result, base)
            power -= 1
        else:
            base = matrix_mult(base, base)
            power //= 2
    
    return result

def fibonacciNumber(n):
    if n == 1 or n == 2:
        return 1

    F = [[1, 1],
         [1, 0]]  # Transformation matrix
    result = matrix_exponentiation(F, n-1)
    
    return result[0][0]  # F(n) is stored in the top-left cell

test = int(input())

for _ in range(test):
    n = int(input())
    print(fibonacciNumber(n))
