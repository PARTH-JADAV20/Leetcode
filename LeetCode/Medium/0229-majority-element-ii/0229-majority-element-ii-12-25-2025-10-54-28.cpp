class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int freq1 = 0; 
        int freq2 = 0;
        int ans1 = 0;
        int ans2 = 0;

        for(int i : nums){
            if (i == ans1)
                freq1++;
            else if (i == ans2)
                freq2++;
            else if (freq1 == 0 && i!=ans2) {
                ans1 = i;
                freq1 = 1;
            }
            else if (freq2 == 0 && i!=ans1) {
                ans2 = i;
                freq2 = 1;
            }
            else {
                freq1--;
                freq2--;
            }
        }
        
        vector<int> arr;
        freq1 = 0, freq2 = 0;
        int n = nums.size();
        for(int i : nums){
            if(i==ans1) freq1++;
            else if(i==ans2) freq2++;
        }
        int min = (int)n/3+1;
        if(freq1>=min) arr.push_back(ans1);
        if(freq2>=min) arr.push_back(ans2);
        
        return arr;
    }
};