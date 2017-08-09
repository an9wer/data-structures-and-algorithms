def partition(A, p, r):
    """
    :param A: the list neet to be sorted
    :param p: the first index of A
    :param r: the last index of A
    :return: the sorted index of A
    """
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= A[r]:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[r] = A[r], A[i+1]
    return i + 1


def quicksort(A, p, r):
    """
    :param A: the list neet to be sorted
    :param p: the first index of A
    :param r: the last index of A
    :return: the sorted A
    """
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q-1)
        quicksort(A, q+1, r)
    return A


if __name__ == '__main__':
    test = range(10, -5, -1)
    quicksort(test, 0, len(test)-1)
        

