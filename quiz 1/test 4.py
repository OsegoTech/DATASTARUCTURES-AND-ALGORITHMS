def find_single_number(nums):
    result = 0
    for num in nums:
        result ^= num
    return result
nums = [4, 2, 1, 2, 1]
single_number = find_single_number(nums)
print(f"The single number is: {single_number}")