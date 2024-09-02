# Algorithm-cpp
### 以cpp写的排序算法
1. quickSort(vector<int>&arr, int l, int r) 快速排序
2. mergeSort(vector<int>, int size) 归并排序
3. heapSort类最小堆MinHeap,包括以下公有成员函数
   1. 构造函数Constructor MinHeap()
   2. 用于初始化 void init(vector<int> v) or init(int* arr, int len)
   3. 插入一个数 void insert(int x)
   4. 获取堆顶元素 int getTop(),注意堆未初始化不要调用
   5. 打印 void print()，打印样式为阶梯状
