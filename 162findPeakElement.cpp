class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;

        // 🔹 Handle single element
        if (n == 1) return 0;

        // 🔹 Check boundaries
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int start = 1, end = n - 2;

        // 🔹 Binary Search
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid; // peak found
            } 
            else if (nums[mid] < nums[mid + 1]) {
                start = mid + 1; // move right
            } 
            else {
                end = mid - 1; // move left
            }
        }

        return -1; // should never happen
    }
}