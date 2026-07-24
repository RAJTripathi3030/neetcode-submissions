class KthLargest {
public:
    int k;
    vector<int> arr;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->arr = nums;
    }
    
    int add(int val) {
        arr.push_back(val);
        priority_queue<int> tempPQ(arr.begin(), arr.end());

        for(int i = 0; i < k-1; i++) {
            tempPQ.pop();
        }

        return tempPQ.top();
    }
};
