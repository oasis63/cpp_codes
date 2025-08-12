class MedianFinder {
 public:
  priority_queue<int> mxHeap;                              // mxHeap
  priority_queue<int, vector<int>, greater<int>> minHeap;  // minHeap

  MedianFinder() {}

  void addNum(int num) {
    if (mxHeap.empty() || num <= mxHeap.top()) {
      mxHeap.push(num);
    } else {
      minHeap.push(num);
    }

    // balance the heaps
    if (mxHeap.size() > minHeap.size() + 1) {
      minHeap.push(mxHeap.top());
      mxHeap.pop();
    } else if (minHeap.size() > mxHeap.size()) {
      mxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  double findMedian() {
    double median = 0.0;

    int len = mxHeap.size() + minHeap.size();

    // even number of elements
    if (len % 2 == 0) {
      median = (minHeap.top() + mxHeap.top()) / 2.0;
      // cout << "Even ";
    } else {  // odd number of elements
      median = (double)mxHeap.top() * 1.0;
      // cout << "Odd ";
    }

    return median;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */