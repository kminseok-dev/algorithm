#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> set;
    for(int i=0;i<nums.size();i++){
        set.insert(nums[i]);
    }
    int result = 0;
    if(set.size()>nums.size()/2){
        result = nums.size()/2;
        return result;
    }
    
    return set.size();
}