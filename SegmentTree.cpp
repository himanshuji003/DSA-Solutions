#include <iostream>
#include <vector>
using namespace std;

void buildSegmentTree(int i, int l, int r, vector<int>& segmentTree, int arr[]) {
    if (l == r) {
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);

    segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
}

int Query(int start, int end, int i, int l, int r, vector<int>& segmentTree) {
    if (l > end || r < start) {
        return 0;
    }

    if (l >= start && r <= end) {
        return segmentTree[i];
    }

    int mid = l + (r - l) / 2;
    return Query(start, end, 2 * i + 1, l, mid, segmentTree) +
           Query(start, end, 2 * i + 2, mid + 1, r, segmentTree);
}

int main() {
    vector<int> arr = {2, 4, 3, 24, 68, 32};
    int n = arr.size();

    vector<int> segmentTree(4 * n);
    vector<int> result;

    buildSegmentTree(0, 0, n - 1, segmentTree, arr.data());

    int queries[] = {1, 5, 2, 5};

    for (int i = 0; i < 4; i += 2) {
        int start = queries[i];
        int end = queries[i + 1];

        if (start < 0 || end >= n || start > end) {
            cout << "Invalid query range: [" << start << ", " << end << "]\n";
            continue;
        }

        result.push_back(Query(start, end, 0, 0, n - 1, segmentTree));
    }

    for (int ch : result) {
        cout << ch << " ";
    }

    return 0;
}
