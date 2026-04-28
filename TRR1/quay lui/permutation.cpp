#include <bits/stdc++.h>
#define ll long long
using namespace std;
void printPermutation(vector<int> nums) {
    for (auto x:nums)
        cout << x;
    cout << endl;
}
void generatePermutations(vector<int>& nums, int start) {
    if (start == nums.size()) {
        printPermutation(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]); // doi cho tu trai sang phai
        generatePermutations(nums, start + 1);
        swap(nums[start], nums[i]); // doi cho tu phai sang trai
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 1; i <= n; i++)
        nums.push_back(i);
    generatePermutations(nums, 0);
}