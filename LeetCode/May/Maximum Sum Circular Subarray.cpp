/*Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000*/
class Solution 
{
    public:
            int maxSubarraySumCircular(vector<int>& A) 
            {
                ios_base::sync_with_stdio(false);
                cin.tie(NULL);

                int n = A.size();
                
                int max_straight_SUM = INT_MIN;
                int min_straight_SUM = INT_MAX;
                
                int array_SUM = 0;

                int temp_maxSUM = 0;
                int temp_minSUM = 0;

                for(int i=0; i<n; ++i)
                {
                    array_SUM += A[i];

                    temp_maxSUM += A[i];
                    max_straight_SUM = max_straight_SUM < temp_maxSUM ? temp_maxSUM : max_straight_SUM;
                    temp_maxSUM = temp_maxSUM < 0 ? 0 : temp_maxSUM;

                    temp_minSUM += A[i];
                    min_straight_SUM = min_straight_SUM > temp_minSUM ? temp_minSUM : min_straight_SUM;
                    temp_minSUM = temp_minSUM > 0 ? 0 : temp_minSUM;
                }
                
                if(array_SUM == min_straight_SUM)
                    return max_straight_SUM;
                
                return max(max_straight_SUM, (array_SUM - min_straight_SUM));
            }
};