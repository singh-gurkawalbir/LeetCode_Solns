# The code is trying to calculate the total amount of time required to buy tickets.
#  It takes in a list of ticket prices and an integer k, which represents the maximum number of tickets that can be bought at a discounted price.
#  To start, the variable "total" is initialized to 0.
#  This will keep track of the total time required.
#  Next, there is a for loop that iterates through each element in the list of ticket prices.
#  The enumerate function allows us to access both the index and value of each element in the list.
#  So for example, if we have [10, 20, 30], then when i = 0 and x = 10; when i = 1 and x = 20; etc.
#  Inside this loop, there is an if statement that checks if i (the current index) is less than or equal to k (the maximum number of discounted tickets).
#  If it is true, then we add min(tickets[i], tickets[k]) to our total.
#  The min function returns the smaller value between two numbers - so here we are essentially saying "take whichever value is smaller: either tickets[i] or tickets[k]".
#  This makes sense because if we are still within our limit for discounted tickets (k), then we want to take advantage of those lower prices as much as possible.
#  If i > k (meaning we have exceeded our limit for discounted tickets), then instead we subtract one from k before adding it back into our total calculation.
#  This
#  The code calculates the minimum amount of time required to buy k tickets, taking into account the number of tickets available at each index and adjusting for the number of tickets already bought.class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        total = 0

        for i, x in enumerate(tickets):
            if i <= k:
                total += min(tickets[i], tickets[k])
            else:
                total += min(tickets[i], tickets[k] - 1)

        return total
