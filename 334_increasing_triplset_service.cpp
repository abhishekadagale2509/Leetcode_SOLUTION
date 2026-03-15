#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int first = INT_MAX;
        int second = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {

            int ele = nums[i];

            if(ele <= first)
                first = ele;

            else if(ele <= second)
                second = ele;

            else
                return true;
        }

        return false;
    }
};

/*
Let’s understand the code step by step.
The goal is to check if there exists three increasing numbers in the array:

𝑛
𝑢
𝑚
𝑠
[
𝑖
]
<
𝑛
𝑢
𝑚
𝑠
[
𝑗
]
<
𝑛
𝑢
𝑚
𝑠
[
𝑘
]
where 
𝑖
<
𝑗
<
𝑘
nums[i]<nums[j]<nums[k]where i<j<k

Example:
[1, 3, 5] → increasing triplet exists.

1. Header Files
#include <vector>
#include <climits>

vector → used for dynamic array (vector<int>)

climits → gives constant INT_MAX (maximum integer value)

2. Function Definition
bool increasingTriplet(vector<int>& nums)

Function returns true or false

nums → input array

& → pass by reference (no copying of vector)

3. Initialize Variables
int first = INT_MAX;
int second = INT_MAX;

We track the smallest two numbers.

Variable	Meaning
first	smallest number found
second	second smallest number

Initially we set them to very large value.

4. Traverse Array
for(int i = 0; i < nums.size(); i++)

Loop through each element of the array.

5. Store Current Element
int ele = nums[i];

Take the current number.

6. Condition 1
if(ele <= first)
    first = ele;

If the current number is smaller than first, update first.

Example:

first = 10
ele = 3

Now

first = 3
7. Condition 2
else if(ele <= second)
    second = ele;

If the number is greater than first but smaller than second, update second.

Example:

first = 3
second = 10
ele = 5

Now

second = 5
8. Condition 3 (Triplet Found)
else
    return true;

This means:

ele > second

So we found:

first < second < ele

Which is an increasing triplet.

Return true.

Example Walkthrough

Input:

nums = [2,1,5,0,4,6]
Element	first	second	Explanation
2	2	INF	update first
1	1	INF	update first
5	1	5	update second
0	0	5	update first
4	0	4	update second
6	0	4	6 > second → triplet found

Triplet:

0 < 4 < 6

Return true.

9. If No Triplet Found
return false;

If loop finishes and no triplet found.

Time Complexity
O(n)

Only one pass through the array.

Space Complexity
O(1)

Only two variables used.

✅ Important Interview Insight

We do not need to store the whole triplet, only track the two smallest values.

Because when we find a number greater than second, the triplet automatically exists.*/