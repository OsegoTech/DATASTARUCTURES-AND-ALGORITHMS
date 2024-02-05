def rotate (nums, k):#a function with a list parameter and a number
    #n has been assigned the length of the list in terms of indexes
    n= len(nums)
   #remainder of k when it is divided by n but if it is  less than 7 the value remains the same
    k = k % n 
    #list concatenation with the first value being the last numbers inthe list plus the first numbers upto the value of k
    nums[:]=nums[n-k:] + nums[:n-k]

nums =[1,2,3,4,5,6,7,8,9]
k = 13
rotate(nums,k)
print(nums)