class Solution
 {
    public int[] plusOne(int[] digits) 
    {
        int n=digits.length;
        if(digits[n-1]!=9)
        {
            digits[n-1]=digits[n-1]+1;
            return digits;

        }
        digits[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            if(digits[i]!=9)
            {
                digits[i]=digits[i]+1;
                return digits;
            }
            digits[i]=0;
        }

        int[] ans=new int[n+1];
        ans[0]=1;
        return ans;

    }

 }



/*class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;

        // Traverse from last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;   // add 1
                return digits; // no carry needed
            }
            digits[i] = 0; // set to 0 and carry forward
        }

        // If all digits were 9
        int[] result = new int[n + 1];
        result[0] = 1;
        return result;
    }
}*/
