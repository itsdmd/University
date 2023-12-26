def sort(arr):
    sorted = arr.copy()
    n = len(sorted)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if sorted[min_idx] > sorted[j]:
                min_idx = j
        sorted[i], sorted[min_idx] = sorted[min_idx], sorted[i]
    return sorted
