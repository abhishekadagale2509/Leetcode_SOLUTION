class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];

        ans[0] = 1;
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }

        int right = 1;
        for(int i = n-1; i >= 0; i--) {
            ans[i] = ans[i] * right;
            right = right * nums[i];
        }

        return ans;
    }
}

/*
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;

        int[] right = new int[n];
        right[n-1] = 1;

        for(int i = n-2; i >= 0; i--) {
            right[i] = right[i+1] * nums[i+1];
        }

        int[] ans = new int[n];
        int left = 1;

        for(int i = 0; i < n; i++) {ac
            ans[i] = left * right[i];
            left = left * nums[i];
        }

        return ans;
    }
}*/