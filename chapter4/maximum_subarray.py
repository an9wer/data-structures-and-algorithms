def find_max_crossing_subarray(A, low, mid, high):
    """
    :param A: target list neet to find maximum sublist
    :param low: first index of the list A
    :param mid: middle index of the list A
    :param high: last index of the list A
    """
    max_left = mid
    summary = left_sum = A[mid]
    for i in range(mid-1, low-1, -1):
        summary += A[i]
        if summary > left_sum:
            left_sum = summary

    max_right = mid + 1
    summary = right_sum = A[mid+1]
    for j in range(mid+2, high+1):
        summary += A[j]
        if summary > right_sum:
            right_sum = summary
            max_right = j

    #print max_left, max_right, left_sum + right_sum
    return max_left, max_right, left_sum + right_sum

def find_maximum_subarray(A, low, high):
    """
    :param A: target list neet to find maximum sublist
    :param low: first index of the list A
    :param high: last index of the list A
    """
    if high == low:
        return low, high, A[low]
    else:
        mid = (low+high) / 2
        left_low, left_high, left_sum = find_maximum_subarray(A, low, mid)
        right_low, right_high, right_sum = find_maximum_subarray(A, mid+1, high)
        cross_low, cross_high, cross_sum = find_max_crossing_subarray(A, low, mid, high)
        if left_sum >= right_sum and left_sum >= cross_sum:
            #print left_low, left_high, left_sum
            return left_low, left_high, left_sum
        elif right_sum >= left_sum and right_sum >= cross_sum:
            #print right_low, right_high, right_sum
            return right_low, right_high, right_sum
        else:
            #print cross_low, cross_high, cross_sum
            return cross_low, cross_high, cross_sum

if __name__ == '__main__':
    test = [-10, 2, 5, -1, 6, 9, -3, -4, 7]
    test = range(5, -10, -1)
    print test
    #find_max_crossing_subarray(test, 0, 4, 8)
    a = find_maximum_subarray(test, 0, len(test)-1)
    print a

