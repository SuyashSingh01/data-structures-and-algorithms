// Author:SUYASH SINGH 
// Problem statement:Find First and Last Position of Element in Sorted Array

// Explanation:
// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]


var searchRange = function(nums, target) {
    // Initialize the result array with default values [-1, -1]
    let ans = [-1, -1];

    // Binary search for the first occurrence
    let start = 0, end = nums.length - 1, mid;
    while (start <= end) {
        // Calculate the middle index
        mid = Math.floor((start + end) / 2);

        if (target == nums[mid]) {
            // If target is found, update the first occurrence index and continue searching on the left side
            ans[0] = mid;
            end = mid - 1;
        } else if (target < nums[mid]) {
            // If target is less than the middle element, search on the left side
            end = mid - 1;
        } else {
            // If target is greater than the middle element, search on the right side
            start = mid + 1;
        }
    }

    // Binary search for the last occurrence
    start = 0;
    end = nums.length - 1;
    while (start <= end) {
        // Calculate the middle index
        mid = Math.floor((start + end) / 2);

        if (target == nums[mid]) {
            // If target is found, update the last occurrence index and continue searching on the right side
            ans[1] = mid;
            start = mid + 1;
        } else if (target < nums[mid]) {
            // If target is less than the middle element, search on the left side
            end = mid - 1;
        } else {
            // If target is greater than the middle element, search on the right side
            start = mid + 1;
        }
    }

    // Return the result array with first and last occurrence indices
    return ans;
};

// Example usage in the main function
function main() {
    // Example input array and target value
    let nums = [5, 7, 7, 8, 8, 10];
    let target = 8;

    // Call the searchRange function with the input array and target value
    let result = searchRange(nums, target);

    // Print the result array
    console.log(result);
}

// Call the main function
main();
