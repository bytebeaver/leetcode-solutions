class NumArray {
public:

    vector<int> segTree;
    int n;

    void build( int node, int l , int r, vector<int>&nums)
    {
        if( l==r)
        {
            segTree[node] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;

        build( 2*node, l , mid, nums);
        build( 2*node+1, mid+1 , r, nums);

        segTree[node] = segTree[2*node] + segTree[2*node+1];

    }

    void  updateTree( int node, int l, int r , int idx , int val)
    {
        if( l == r)
        {
            segTree[node] = val;
            return;
        }

        int mid = l + (r-l)/2;

        if( idx <= mid)
        {
            updateTree( 2*node , l, mid , idx, val);
        }
        else
        {
            updateTree(2*node + 1, mid+1, r , idx , val);
        }

         segTree[node] = segTree[2*node] + segTree[2*node+1];
    }

    int queryTree(int node, int start, int end, int l, int r)
    {
        if( r< start || l > end)
        return 0;

        if( l>= start && r<= end)
        {
            return segTree[node];
        }

        int mid = l + (r-l)/2;

        return queryTree( 2*node, start, end, l , mid) + queryTree(2*node + 1, start, end, mid+1, r);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);

        build( 1, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        updateTree( 1, 0, n-1, index , val); //1 -- root index in segTre array |||| 0 , n-1 -- initial l, r
    }
    
    int sumRange(int left, int right) {
        int start = left;
        int end  = right;

        return queryTree( 1, start, end , 0 , n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */