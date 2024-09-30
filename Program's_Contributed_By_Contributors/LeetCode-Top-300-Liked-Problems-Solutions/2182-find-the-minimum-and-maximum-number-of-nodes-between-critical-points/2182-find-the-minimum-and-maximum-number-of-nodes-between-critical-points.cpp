class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);

        int firstPos = -1, prevPos = -1, currPos = 1;
        int mini = INT_MAX, maxi = -1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr && curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {
                if (firstPos == -1) {
                    firstPos = currPos;
                } else {
                    mini = min(mini, currPos - prevPos);
                }
                if (prevPos != -1) {
                    maxi = currPos - firstPos;
                }
                prevPos = currPos;
            }
            prev = curr;
            curr = curr->next;
            currPos++;
        }

        if (mini != INT_MAX && maxi != -1) {
            ans[0] = mini;
            ans[1] = maxi;
        }

        return ans;
    }
};
