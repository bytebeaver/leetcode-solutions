class NumArray {
public:

    vector<int> segTree;
    int n;

    // Build the Segment Tree
    void build(int node, int l, int r, vector<int>& nums)
    {
        // Leaf node: store the array element
        if(l == r)
        {
            segTree[node] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        // Build left and right subtrees
        build(2 * node, l, mid, nums);
        build(2 * node + 1, mid + 1, r, nums);

        // Store sum of both children
        segTree[node] =
            segTree[2 * node] + segTree[2 * node + 1];
    }


    // Update one element: nums[idx] = val
    void updateTree(int node, int l, int r, int idx, int val)
    {
        // Reached the element to update
        if(l == r)
        {
            segTree[node] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        // Move to the child containing idx
        if(idx <= mid)
        {
            updateTree(2 * node, l, mid, idx, val);
        }
        else
        {
            updateTree(2 * node + 1, mid + 1, r, idx, val);
        }

        // Recalculate sum after updating the child
        segTree[node] =
            segTree[2 * node] + segTree[2 * node + 1];
    }


    // Return sum of elements in [start, end]
    int queryTree(int node, int start, int end, int l, int r)
    {
        // No overlap
        if(r < start || l > end)
            return 0;

        // Complete overlap: use stored sum
        if(l >= start && r <= end)
        {
            return segTree[node];
        }

        int mid = l + (r - l) / 2;

        // Partial overlap: query both children
        return queryTree(2 * node, start, end, l, mid)
             + queryTree(2 * node + 1, start, end, mid + 1, r);
    }


    // Constructor: build the Segment Tree
    NumArray(vector<int>& nums)
    {
        n = nums.size();
        segTree.resize(4 * n);

        // Root = 1, range = [0, n-1]
        build(1, 0, n - 1, nums);
    }
    

    // Public function for point update
    void update(int index, int val)
    {
        // 1 = root of Segment Tree
        // [0, n-1] = complete array range
        updateTree(1, 0, n - 1, index, val);
    }
    

    // Public function for range sum query
    int sumRange(int left, int right)
    {
        return queryTree(1, left, right, 0, n - 1);
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 *
 * NumArray* obj = new NumArray(nums);
 * obj->update(index, val);
 * int param_2 = obj->sumRange(left, right);
 */