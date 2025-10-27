#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int* list = (int*) calloc(numsSize, sizeof(int));

    int i; 
    int x; 
    list[nums[0]] = 0;
    for(int i = 1; i < numsSize; ++i){
        x = nums[i]; 
        if(0 == list[x]){
            list[x] = i;
        }
        else{
            if(i-list[x] <= k){
                //printf("%d", i );
                //printf("\n");
                //printf("%d", list[x]);
                //printf("\n");
                return true;
            }
        }
    }
    return false;
} 

int main () { 
    int nums[] = {1,2,3,1,2,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    printf("%d", containsNearbyDuplicate(nums, numsSize, k));
    printf("\n");
    return 0;
}