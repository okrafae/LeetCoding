class Solution {
public:
<<<<<<< HEAD
    //added comment in master
=======
    //comments in mybranch
>>>>>>> mybranch
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while( slow != fast )
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while( slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};