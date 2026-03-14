#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void merge(vector<int>&nums, int L, int M,int H )
    {
        vector<int> temp;
        int i = L;
        int j = M+1;
        while(i<=M && j<=H)
        {
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=M)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=H)
        {
            temp.push_back(nums[j]);
            j++;
        }
        for(int k=0;k<temp.size();k++)
        {
            nums[L + k] = temp[k];
        }

    }
    void Mergesort(vector<int>&nums, int L,int H )
    {
        if(L>=H)
        return;
        int M=(L+H)/2;
        Mergesort(nums,L,M);
        Mergesort(nums,M+1,H);
        merge(nums,L,M,H);
    }

    vector<int> sortArray(vector<int>& nums) 
    {
        Mergesort(nums,0,nums.size()-1);
        return nums;
    }
};

