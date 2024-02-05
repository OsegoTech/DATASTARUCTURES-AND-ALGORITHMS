def removeDuplicates(nums):
    if not nums:
        return 0
    nums.sort()
    i = 0
    for j in range(1, len(nums)):
        if nums[j] != nums[i]:
            i += 1
            nums[i] = nums[j]
    
    return nums[:i+1]
print(removeDuplicates([1,1,2,2,3,3,4,4,5,6,5,4]))