#include <stdio.h>
#include <stdlib.h>
int  summation(int nums[], int n);
int maximum (int nums[],int n);


int main()
{
    int n;

    //Get the length of the array from the user
    printf("Enter the length of the array: ");
    scanf("%d", &n);//The length of the array is stored in

    //declare an array of length n
    int nums[n];

    //allow the user to enter them and store them in the array
    printf("Enter %d integers: ", n);
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&nums[i]);
    }
    for (int i= 0; i<n; i++)
    {
        printf("%d\n",nums[i]);
    }

    //call the summation function
    int sum_results = summation(nums,n);


    //call the maximum function
    int max_result = maximum(nums, n);


    return 0;



}

//function definition
int  summation(int nums[], int n)
{
   int sum = 0;
   for (int i = 0; i<n; i++)
   {
       sum +=nums[i];
   }
   printf("The sum of the array is: %d\n",sum);
   return sum;
}
int maximum (int nums[],int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    printf("The maximum number is :%d\n",max);
    return max;
}



