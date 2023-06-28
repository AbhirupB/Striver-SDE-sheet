#include<bits/stdc++.h>

using namespace std;
int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      return arr[i];
    }
  }
}
int main() {
  vector < int > arr;
  arr = {1,3,4,2,2};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
}
// TC:O(nlogn)
// SC:O(1)


#include<bits/stdc++.h>

using namespace std;
int findDuplicate(vector < int > & arr) {
  int n = arr.size();

  //to store the frequency of each character so that if frequency is > 1, then that is the duplicate element.
  int freq[n + 1] = {0};

  for (int i = 0; i < n; i++) {
    if (freq[arr[i]] == 0) {
      freq[arr[i]] += 1;
    } else {
      return arr[i];
    }
  }
  return 0;
}
int main() {
  vector < int > arr;
  arr = {1,3,4,2,3};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
}

// TC:O(n)
// SC:O(n)

//this solution may not be accepted as it modifies the array elements temporarily.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate = -1;

        for (int i = 0; i < nums.size(); i++) {

            //store the element, then check if the number at array[element] has been seen before.
            //if yes, it is duplicate.
            //else mark it as negative.
            int cur = abs(nums[i]);
            if (nums[cur] < 0) {
                duplicate = cur;
                break;
            }
            nums[cur] *= -1;
        }
        
        // Restore numbers
        for (auto& num : nums)
            num = abs(num);
        
        return duplicate;
    }
};

// TC:O(n)
// SC:O(1)

