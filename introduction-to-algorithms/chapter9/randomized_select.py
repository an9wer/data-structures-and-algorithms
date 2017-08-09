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

def randomized_select(A, p, r, i):
    """
    :param A: the list neet to be sorted
    :param p: the first index of A
    :param r: the last index of A
    :param i: the selected index of A, starting with 0
    :return: the value of selected index of A
    """
    if p == r:
        #print A[p]
        return A[p]
    q = partition(A, p ,r)
    k = q - p
    if i == k:
        #print A[q]
        return A[q]
    elif i < k:
        return randomized_select(A, p, q-1, i)
    else:
        return randomized_select(A, q+1, r, i-k-1)

if __name__ == '__main__':
    test = range(10)
    randomized_select(test[::-1], 0, 9, 5)

