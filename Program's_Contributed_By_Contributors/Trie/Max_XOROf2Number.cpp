int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0 || n == 1)
            return 0;
        if (n == 2)
            return nums.at(0) ^ nums.at(1);
        
        list<int> set0;
        list<int> set1;
        int i;
        int j;
        int maxValue;
        
        for (i = 30; i >= 0; i--) {
            for (j = 0; j < n; j++) {
                if ((nums.at(j) & (1<<i)) == 0)
                    set0.push_back(nums.at(j));
                else
                    set1.push_back(nums.at(j));
            }
            
            if (set0.size() != 0 && set1.size() != 0) {
                maxValue = pow(2, i);
                break;
            }
            else {
                set0.clear();
                set1.clear();
            }
        }
        
        if (i == -1)
            return 0;
        
        maxValue += getMaxXor(set0, set1, i-1);
        
        return maxValue;
}

int getMaxXor(list<int>& set0, list<int>& set1, int pos) {
        int maxValue;
        list<int> set0list0;
        list<int> set0list1;
        list<int> set1list0;
        list<int> set1list1;
        int i;
        list<int>::iterator it;
        
        if (set0.size() == 0 || set1.size() == 0 || pos < 0)
            return 0;
        
        for (it = set0.begin(); it != set0.end(); it++) {
            int value = *it;
            if ((value & (1<<pos)) == 0)
                set0list0.push_back(value);
            else
                set0list1.push_back(value);
        }
        
        for (it = set1.begin(); it != set1.end(); it++) {
            int value = *it;
            if ((value & (1<<pos)) == 0)
                set1list0.push_back(value);
            else
                set1list1.push_back(value);
        }
        
        if (set0list0.size() == 0 && set1list0.size() == 0)
            maxValue = getMaxXor(set0, set1, pos-1);
        else if (set0list1.size() == 0 && set1list1.size() == 0)
            maxValue = getMaxXor(set0, set1, pos-1);
        else {
            int maxValue1 = getMaxXor(set0list0, set1list1, pos-1);
            int maxValue2 = getMaxXor(set0list1, set1list0, pos-1);
            maxValue = pow(2, pos) + (maxValue1 > maxValue2 ? maxValue1 : maxValue2);
        }
        
        return maxValue;
 }