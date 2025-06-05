class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int min_ = INT_MAX , max_ = INT_MIN ;
        int l = nums.size() ;
        if ( l < 2 ) return 0 ;
        for ( int i = 0 ; i < nums.size() ; ++i) {
            min_ = min(min_ , nums[i]) ;
            max_ = max(max_ , nums[i]) ;
            
        }
        
        int gap = ceil((max_ - min_)/((l-1)*1.0)) ;
        vector<int> m(nums.size() , INT_MAX);
        vector<int> n(nums.size() , INT_MIN) ;
        
        for(int i = 0 ; i < l ; ++i) {
            if (nums[i] == min_ || nums[i] == max_ ) continue ;
            
            int ind = ( nums[i] - min_ ) / (gap);
            m[ind] = min(m[ind] , nums[i]) ;
            n[ind] = max(n[ind] , nums[i]) ;
            
            
            
            
        }
        int ans = 0 ;
        for(int i = 0 ; i< m.size() ; ++i) {
            if (m[i] == INT_MAX) continue ;
            ans = max(ans , m[i] - min_ ) ;
            min_ = n[i] ;
        }
        
        ans = max(ans , max_ - min_ ) ;
        return ans ;
    }
};
