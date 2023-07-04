// Author: SUYASH SINGH

// Problem Statement :
// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

// Example 1;

// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].


// Example 2:

// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted.


#include <vector>
#include <queue>
#include <cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // Create a priority queue using the given points and the custom comparison struct
        priority_queue<vector<int>, vector<vector<int>>, compare> pq(points.begin(), points.end());
        
        // Create a vector to store the K closest points
        vector<vector<int>> ans;
        
        // Retrieve the K closest points from the priority queue
        for (int i = 0; i < K; i++) {
            // Push the top element (closest point) into the answer vector
            ans.push_back(pq.top());
            
            // Remove the top element from the priority queue
            pq.pop();
        }
        
        // Return the vector of K closest points
        return ans;
    }
    
private:
    // Custom struct to define the comparison logic for the priority queue
    struct compare {
        // Comparison operator to compare the distance of two points from the origin
        bool operator()(const vector<int>& p, const vector<int>& q) {
            // Calculate the squared Euclidean distances for the points
            int distP = p[0] * p[0] + p[1] * p[1];
            int distQ = q[0] * q[0] + q[1] * q[1];
            
            // Compare the distances in reverse order to prioritize the smaller distances
            return distP > distQ;
        }
    };
};

int main() {
    // Create an instance of the Solution class
    Solution solution;
    
    // Create a vector of points
    vector<vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    
    // Define the value of K
    int K = 3;
    
    // Call the kClosest function to get the K closest points
    vector<vector<int>> closestPoints = solution.kClosest(points, K);
    
    // Print the K closest points
    for (const auto& point : closestPoints) {
        cout << point[0] << ", " << point[1] << endl;
    }
    
    return 0;
}


// Time Complexity:

// Building the priority queue using the range constructor takes O(N log N) time, where N is the number of points.
// Retrieving the top K points from the priority queue takes O(K log N) time.
// Overall, the time complexity of the kClosest function is O(N log N + K log N), which simplifies to O((N + K) log N) in the worst case.
// Space Complexity:

// The space complexity of the code is O(N) because the priority queue stores N points, and the ans vector stores K points.
// The size of the priority queue is determined by the number of points, so it contributes O(N) space.
// The ans vector stores K points, so it contributes O(K) space.
// Therefore, the total space complexity is O(N + K).
// Note: The time and space complexities mentioned here are based on the provided code.