def sort(arr):
    sorted = arr.copy()
    for i in range(len(sorted)):
        for j in range(len(sorted)-i-1):
            if sorted[j] > sorted[j+1]:
                sorted[j], sorted[j+1] = sorted[j+1], sorted[j]
    return sorted
