#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
// TC:O(n^3)
// SC:O(1)


#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum1(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum1(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
// TC:O(n^2)
// SC:O(1)



#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum2(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum2(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
// TC:O(n)
// SC:O(1)

//Follow up: there are mutiple subarrays with max sum. print any.

/*
Intuition: Our approach is to store the starting index and the ending index of the subarray. 
Thus we can easily get the subarray afterward without actually storing the subarray elements.

If we carefully observe our algorithm, 
we can notice that the subarray always starts at the particular index where the sum variable is equal to 0, 
and at the ending index, the sum always crosses the previous maximum sum(i.e. maxi).

So, we will keep a track of the starting index inside the loop using a start variable.
We will take two variables ansStart and ansEnd initialized with -1. 
And when the sum crosses the maximum sum, we will set ansStart to the start variable and ansEnd to the current index i.e. i.
*/


#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum3(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum3(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

// TC:O(n)
// SC:O(1)