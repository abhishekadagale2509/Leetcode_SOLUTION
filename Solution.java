class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        
        int start = 0;
        int end = n - 1;
        int ptr = n - 1;

        while (start <= end) {
            int leftSquare = nums[start] * nums[start];
            int rightSquare = nums[end] * nums[end];

            if (leftSquare > rightSquare) {
                ans[ptr] = leftSquare;
                start++;
            } else {
                ans[ptr] = rightSquare;
                end--;
            }
            ptr--;
        }
        
        return ans;
    }
}