#include <iostream>
#include <vector>
using namespace std;
void quickSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int i = l;
    int j = r;
    int mid = arr[l];
    while (i < j) {
        while (i < j && arr[j] >= mid) {
            j--;
        }
        while (i < j && arr[i] <= mid) {
            i++;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[i]);
    quickSort(arr, l, i-1);
    quickSort(arr, i+1, r);
}

vector<int> myMergeSort(vector<int> arr, int size) {
    if (size < 2) {
        return arr;
    }
    int mid = size / 2;
    vector<int> l, r;
    for (int i = 0; i < mid; ++i) {
        l.push_back(arr[i]);
    }
    for (int i = mid; i < size; ++i) {
        r.push_back(arr[i]);
    }
    vector<int> res;
    l = myMergeSort(l, mid);
    r = myMergeSort(r, size - mid);
    int i = 0, j = 0;
    while (i < mid && j < size - mid) {
        if (l[i] <= r[j]) {
            res.push_back(l[i]);
            ++i;
        } else {
            res.push_back(r[j]);
            ++j;
        }
    }
    while (i < mid) {
        res.push_back(l[i]);
        ++i;
    }
    while (j < size - mid) {
        res.push_back(r[j]);
        ++j;
    }
    return res;
}


// 最小堆
class MinHeap {
private:
    int* root;
    int len;

    // 初始化向下调整一次,index为该元素下标,如果发生交换则递归调整
    void adjust(int index) {
        if (index >= len) return;
        int l = index * 2 + 1;
        int r = index * 2 + 2;
        int rootIndex = index;  // 三个值中应该处于最高位置的值的下表
        if (l < len && root[l] < root[rootIndex]) {
            rootIndex = l;
        }
        if (r < len && root[r] < root[rootIndex]) {
            rootIndex = r;
        }
        if (rootIndex != index) {
            swap(root[index], root[rootIndex]);
            adjust(rootIndex);
        }
    }
public:
    MinHeap():root(nullptr), len(0) {

    }

    ~MinHeap() {
        delete[] root;
        root = nullptr;
    }

    void init(vector<int> v) {
        len = v.size();
        // 复制数组
        root = new int[len];
        for (int i = 0; i < len; ++i) root[i] = v[i];
        int startIndex = len / 2 - 1;
        while (startIndex >= 0) {
            adjust(startIndex);
            startIndex--;
        }
    }

    void init(int* arr, int len) {
        root = new int[len];
        memcpy(root, arr, sizeof(int) * len);
        this->len = len;
        int startIndex = len / 2 - 1;
        while (startIndex >= 0) {
            adjust(startIndex);
            startIndex--;
        }
    }

    void insert(int x) {
        // 数组大小+1
        int* temp = new int[len + 1];
        memcpy(temp, root, sizeof(int) * len);
        len = len + 1;
        delete[] root;
        root = temp;
        int index = len - 1;
        root[index] = x;
        // 向上调整，直接和父亲交换
        while (index >= 0) {
            int fatherIndex = (index - 1) / 2;
            if (root[fatherIndex] > root[index]) {
                swap(root[fatherIndex], root[index]);
                index /= 2;
            } else break;
        }
    }

    int getTop() {
        if (root)
            return root[0];
    }

    void print() {
        int count = 0;
        int total = 1;
        for (int i = 0; i < len; ++i) {
            cout << root[i] << " ";
            ++count;
            if (count == total) {
                cout << endl;
                total *= 2;
                count = 0;
            }
        }
    }
};


int main() {
    vector<int> arr = {1, 2, 21, 123, 213, 312, 13, 3214231, 32, 65, 453, 34, 5, 32, 5342 };
    // quickSort(arr, 0, arr.size() - 1);
    // arr = myMergeSort(arr, arr.size());
    // for (int x: arr) {
    //     cout << x << " ";
    // }
    MinHeap minHeap;
    minHeap.init(arr);
    minHeap.print();
    minHeap.insert(-100);
    minHeap.print();
    return 0;
}