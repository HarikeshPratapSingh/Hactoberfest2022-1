/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.*/

/*
->sort the array using std::sort
->run a for loop from 0 to n-2
->check for duplicate elements
->make a low (i+1) and a high (n-1) marker
->while low < high check for nums[i] + nums[low] + nums[high](three sum)
->if three sum is less than 0 increment low
->if three sum is more than 0 decrement high
->if a desirable three sum is found then push in in the vector
->until low+1==low, increment low
->until high-1==high, decrement high
*/
#include<bits/stdc++.h>
vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++){
               if(i>0 && (nums[i]==nums[i-1]) )continue;
               int low=i+1, high= n-1;
               while(low<high){
                   int s = nums[i]+nums[low]+nums[high];
                   
                   if(s<0) low++;
                   else if(s>0)high--;
                   else {
                       res.push_back(vector<int>{nums[i],nums[low],nums[high]});
                       while(low+1<high && nums[low]==nums[low+1])low++;
                       while(low<high-1 && nums[high]==nums[high-1]) high--;
                       low++; high--;
                   }
               }
        }
       
        return res;
    }
using namespace std;
 int main() { 
   
return 0; 
}