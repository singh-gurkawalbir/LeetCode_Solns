class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        ones = s.count('1')
        return ('1' * (ones - 1)) + ('0' * (len(s) - ones)) + '1'

#s = "010110"
# Let's just count no. of 1's and 0's.
#             cnt1 = 3 and cnt0 = 3
# Since we need the greatest odd number we need one 1 
# at the last to make it odd and best chances to make it greatest 
# is by putting rest every 1's at the front.

#             ans = "11" + "000" + "1"

#             ans = "110001"

# Will work for all cases, try it out:)
