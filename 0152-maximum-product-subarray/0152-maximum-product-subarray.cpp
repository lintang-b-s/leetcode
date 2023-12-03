


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxNow= nums[0], minNow=nums[0], ans=nums[0];

        for (int i=1; i< nums.size(); i++){
            int maxTemp=maxNow, minTemp=minNow;

            maxNow = max({maxTemp*nums[i], nums[i], minTemp*nums[i]});
            minNow= min({maxTemp*nums[i], nums[i], minTemp*nums[i]});
            cout << "maxTemp: "<< maxTemp << " minTemp: " << minTemp << endl;
            cout << " maxNow: " << maxNow << " minNow: " << minNow << endl;
            
            ans = max(maxNow,ans);
        }
        return ans;
    }
};