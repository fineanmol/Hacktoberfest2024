def minmaxarray(nums):
    # initialize minimum and maximum element with the first element
    max=min=nums[0]

    for i in range(1, len(nums)):  # do for each element in the list

        if nums[i] > max:  # if the current element is greater than the maximum found so far
            max=nums[i]

        elif nums[i] < min:  # if the current element is smaller than the minimum found so far
            min=nums[i]

    print('The minimum element in the list is', min)
    print('The maximum element in the list is', max)


if __name__ == '__main__':

    nums = [1, 33, 2, 14, 9, 0]
    minmaxarray(nums)
