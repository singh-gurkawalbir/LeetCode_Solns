# 1. The method `bagOfTokensScore` takes an array of tokens and an initial power value as input parameters.
# 2. It sorts the tokens array in ascending order.
# 3. It initializes two pointers, `left` at the beginning of the array and `right` at the end of the array.
# 4. It initializes `max_score` and `score` variables to keep track of the maximum score and the current score.
# 5. It enters a while loop that continues as long as `left` is less than or equal to `right`.
# 6. If the current power is greater than or equal to the token at `left`, it consumes that token, increments the score, updates the `max_score` if needed, moves `left` forward, and continues to the next iteration.
# 7. If the current power is less than the token at `left`, it checks if the current score is greater than or equal to 1. If so, it exchanges the token at `right` for power, decrements the score, moves `right` backward, and continues to the next iteration.
# 8. If none of the above conditions are met, the loop breaks.
# 9. Finally, the method returns the maximum score achieved.

# This code essentially simulates a game where tokens can be used to increase the score by consuming them or increase power by exchanging tokens for power. The goal is to maximize the score based on the rules provided.

class Solution(object):
    def bagOfTokensScore(self, tokens, power):
        tokens.sort()
        n = len(tokens)
        score = 0
        max_score = 0
        left = 0
        right = n - 1
        
        while left <= right:
            if power >= tokens[left]:
                power -= tokens[left]
                score += 1
                left += 1
                max_score = max(max_score, score)
            elif score > 0:
                power += tokens[right]
                score -= 1
                right -= 1
            else:
                break
                
        return max_score
