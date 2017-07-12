def merge(A, p, q, r):
    L = A[p:q+1]
    R = A[q+1:r+1]
    #print L, R
    i = j = 0
    for k in range(p, r+1):
        if i >= len(L):
            A[k] = R[j]
            j += 1
            continue
        elif j >= len(R):
            A[k] = L[i]
            i += 1
            continue
        elif L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        elif L[i] > R[j]:
            A[k] = R[j]
            j += 1
    #print A
    return A

def merge_sort(A, p, r):
    """
    :param A: target list need to be sorted
    :param p: first index of the list A
    :param r: last index of the list A
    
    for example:
        A = [4, 2, 5]
        p = 0
        r = 2
    """
    if p < r:
        q = (p+r) / 2
        merge_sort(A, p, q)
        merge_sort(A, q+1, r)
        merge(A, p, q, r)

if __name__ == '__main__':
    test = [3, 5, 22, 6, 4, 2, 3, 1, 2, 11, 2, 1, 9, 2]
    #test = sorted(range(1000), reverse=True)
    merge_sort(test, 0, len(test)-1)


