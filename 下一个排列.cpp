 
void nextPermutation(vector<int>& nums) {
	int len=nums.size();
    int t;
    if(len!=0&&len!=1)
    {
        int i=len-1;
        if(nums[i]>nums[i-1])
        {
            t=nums[i];
            nums[i]=nums[i-1];
            nums[i-1]=t;
        }
        else
        {
            while(nums[i]<=nums[i-1])
            {
                i--;
                if(i==0)
                {
                    sort(nums.begin(),nums.end());
                    return;
                }
            }   
            t=nums[i];
            int serial=i;
            for(int j=i;j<len;j++)
            {
                if(nums[j]>nums[i-1])
                {
                    if(nums[j]<t)
                    {
                       t=nums[j];
                       serial=j; 
                    }
                }
            }
            t=nums[i-1];
            nums[i-1]=nums[serial];
            nums[serial]=t;
            sort(nums.begin()+i,nums.end());                        
        }
    }
}     
