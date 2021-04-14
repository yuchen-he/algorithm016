def lastSearch(nums, target):
    i, j = 0, len(nums) - 1
    while i < j:
        mid = (i + j + 1) >> 1
        if nums[mid] > target:
            j = mid - 1
        else:
            i = mid

    return i if (nums[i] == target) else -1


def firstSearch(nums, target):
    i, j = 0, len(nums) - 1
    while i < j:
        mid = (i + j) >> 1
        if nums[mid] < target:
            i = mid + 1
        else:
            j = mid

    return j if (nums[j] == target) else -1


def main(nums, target):
    if len(nums) == 0:
        return [-1, -1]

    first = firstSearch(nums, target)
    last = lastSearch(nums, target)
    return [first, last]


if __name__ == '__main__':
    nums = [1, 2, 2, 2, 3, 5, 7, 8]
    target = 2
    print(main(nums, target))
