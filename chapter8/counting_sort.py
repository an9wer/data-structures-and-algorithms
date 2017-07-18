def counting_sort(A, B, k):
    """
    :param A: the list need to be sorted
    :param B: the sorted output
    :param k: the maximum value in A
    """
    C = [0] * (k+1)
    for j in range(0, len(A)):
        C[A[j]] = C[A[j]] + 1
    for i in range(1, k+1):
        C[i] = C[i] + C[i-1]
    for j in range(len(A)-1, -1, -1):
        B[C[A[j]]-1] = A[j]
        C[A[j]] = C[A[j]] - 1
    return B

if __name__ == '__main__':
    test = range(9, -1, -1)
    #test = [2, 5, 3, 0, 2, 3, 0, 3]
    counting_sort(test[:], test[:], max(test))

    
