#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int* list = (int*) calloc(numsSize, sizeof(int));

    int i; 
    int x; 
    list[nums[0]] = 0;
    for(int i = 1; i < numsSize; i++){
        x = nums[i]; 
        if(0 == list[x] && x != nums[0]){
            list[x] = i;
        }
        else{
            //list[x] = i;
            if(i-list[x] <= k){
                //printf("%d", i );
                //printf("\n");
                //printf("%d", list[x]);
                //printf("\n");
                return true;
            }
        } 
        //printf("%d", x );
        //printf("\n");
        //printf("%d", i );
        //printf("\n");
        //printf("%d", list[x]);
        //printf("\n");
        //printf("\n");
    }
    return false;
} 

int main () { 
    int nums[] = {1,2,3,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;
    printf("Result: %d", containsNearbyDuplicate(nums, numsSize, k));
    printf("\n");
    return 0;
}