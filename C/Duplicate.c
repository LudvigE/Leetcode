#include <stdio.h>
#include <stdbool.h>
bool containsDuplicate(int* nums, const int numsSize) {
    
    int list[numsSize+1]; 

    int i; 
    int x; 
    for(int i = 0; i < numsSize+1; ++i){
        x = nums[i]; 
        if(1 != list[x]){
            list[x] = 1;
        }
        else{
            return true;
        }
    }
    return false;
}

int main () { 
    int nums[] = {1,2,3,4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d", containsDuplicate(nums, numsSize));
    printf("\n");
    return 0;
}