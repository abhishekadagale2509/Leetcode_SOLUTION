class Solution {
    public boolean checkOnesSegment(String s) {
        boolean zeroFound = false;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') {
                zeroFound = true;
            }

            if (s.charAt(i) == '1' && zeroFound) {
                return false;
            }
        }

        return true;
    }
}