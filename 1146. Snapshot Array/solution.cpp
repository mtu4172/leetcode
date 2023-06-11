// Link : https://leetcode.com/problems/snapshot-array/

// SPACE INEFFICIENT SOLUTION - DOES NOT PASS ALL CASES
#include <vector>
using namespace std;
class SnapshotArray {
    vector<int> arr;
    vector<vector<int>> snaps;
public:
    SnapshotArray(int length) {
        arr = vector<int>(length, 0);
    }
    
    void set(int index, int val) {
        arr[index] = val;
    }
    
    int snap() {
        snaps.push_back(arr);
        return snaps.size()-1;
    }
    
    int get(int index, int snap_id) {
        return snaps[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */