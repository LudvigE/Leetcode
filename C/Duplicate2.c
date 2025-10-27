#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int* list = (int*) calloc(numsSize+1, sizeof(int));
    int* listN = (int*) calloc(numsSize+1, sizeof(int));
    int i; 
    int x = nums[0];
    if(x < 0){
        listN[abs(x)] = 0;
    }else{ 
        list[x] = 0;
    }
    for(int i = 1; i < numsSize; i++){
        x = nums[i];
        if(x >=0) {
            if(0 == list[x]  && x != nums[0]){
                list[x] = i;
            }
            else{

                if(abs(i-list[x]) <= k){
                    return true;
                }
                else{
                    list[x] = i; //Kan komma igen duplicate senare som är närmare
                }
            } 
        }else {
            if(0 == listN[x]  && x != nums[0]){
                listN[x] = i;
            }
            else{
                if(abs(i-list[x]) <= k){
                    return true;
                }
                else{
                    listN[x] = i; //Kan komma igen duplicate senare som är närmare
                }
            }
        }
    }
    return false;  
}

int main () { 
    int nums[] = {-1,-1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;
    printf("Result: %d", containsNearbyDuplicate(nums, numsSize, k));
    printf("\n");
    return 0;
}