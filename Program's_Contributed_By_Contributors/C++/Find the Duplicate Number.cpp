// naive method
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        map<int, int> m;
        int n = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        for (auto it : m)
        {
            if (it.second >= 2)
                n = it.first;
        }

        return n;
    }
};

// Tortoise method using 2 pointers to traverse
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        int slow = nums[0];
        int fast = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};