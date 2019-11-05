//
// Created by Admin on 2019/10/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int> > permute(vector<int>& nums){
        if(nums.size() == 0) return vector<vector<int> >();
        vector<vector<int> > ret;
        permute(nums,ret,nums.size());
        return ret;
    }
    void permute(vector<int>& nums,vector<vector<int> >& ret,int k){
        if(k == 1){
            ret.push_back(nums);
            return;
        }
        for(int i=0;i<k;++i){
            int tmp = nums[i];
            nums[i] = nums[k-1];
            nums[k-1] = tmp;
            permute(nums,ret,k-1);
            tmp = nums[i];
            nums[i] = nums[k-1];
            nums[k-1] = tmp;
        }
    }
};

class Solution2{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums){
        if(0 == nums.size()) return vector<vector<int>> ();
        vector<vector<int>> rets;
        sort(nums.begin(),nums.end());
        vector<int> ret;
        vector<bool> visited(nums.size(),false);
        permuteUnique(nums,rets,ret,0,visited);
        return rets;
    }
    void permuteUnique(vector<int>& nums,vector<vector<int>>& rets,vector<int>& ret,int k,vector<bool>& visited){
        if(nums.size() == k){
            vector<int> tmp(ret.begin(),ret.end());
            rets.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]== false) {
                if (i != 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) continue;
                visited[i] = true;
                ret.push_back(nums[i]);
                permuteUnique(nums, rets, ret, k + 1, visited);
                ret.pop_back();
                visited[i] = false;
            }
        }
    }
};

int main(){
    Solution2 sol;
    vector<int> nums{2,2,1,1};
    vector<vector<int>> rets;
    rets = sol.permuteUnique(nums);
    for(auto ret:rets){
        for(auto num:ret){
            cout << num << " ";
        }
        cout << endl;
    }
}

