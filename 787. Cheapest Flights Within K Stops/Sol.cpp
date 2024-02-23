// Inside the function, we first create an adjacency list adj to represent the flights. Each element in the adj vector is a pair containing the destination city and the price of the flight.

// We then initialize a queue q to store the flights. Each element in the queue is a pair containing the number of stops made so far, the current city, and the cost to reach that city.

// We also initialize a vector dist to store the minimum cost to reach each city. We set the initial cost to reach the source city as 0 and all other cities as infinity.

// Next, we start a while loop that continues until the queue is empty. Inside the loop, we extract the front element from the queue and store the number of stops, the current city, and the cost.

// If the number of stops exceeds the maximum allowed stops k, we skip the current iteration.

// We then iterate through the flights from the current city and update the minimum cost to reach each adjacent city if the cost of the current flight plus the cost to reach 
// the current city is less than the current minimum cost to reach the adjacent city. We also push the updated cost and the number of stops plus one into the queue.

// Finally, after the while loop, we check if the minimum cost to reach the destination city is still infinity. If it is, we return -1 as it is not possible to reach the destination within the given number of stops. 
// Otherwise, we return the minimum cost to reach the destination.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int, int>>adj[n];
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1] , it[2]});
        }

        queue<pair<int, pair<int, int>>>q;  //{stops, {node, cost}}
        q.push({0, {src, 0}});

        vector<int>dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty())
        {
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            q.pop();

            if(stops > k){
                continue;
            }

            for(auto x : adj[node])
            {
                int adjNode = x.first;
                int edW = x.second;

                if(cost + edW < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = cost + edW;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }

        }

        if(dist[dst] == 1e9)return -1;   //not reachable within k stops
        return dist[dst];
    }


    //TC = O(N) AS we are using a queue
    //SC = O(E + V)
};
