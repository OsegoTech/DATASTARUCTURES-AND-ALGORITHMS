def duplicate(nums):
    nums.sort()
    for i in range(len(nums)-1):
        if nums[i] == nums[i+1]:
        
            return print(True)
        
    return print(False)

duplicate([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15])