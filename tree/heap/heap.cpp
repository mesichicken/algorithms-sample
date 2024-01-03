#include <iostream>
#include <vector>
using namespace std;

struct Heap {
  vector<int> heap;
  Heap() {}

  void push(int x) {
    heap.push_back(x); // 最後尾に挿入
    int i = (int)heap.size() - 1; // 挿入するノードのインデックス
    while(i > 0) {
      int p = (i - 1) / 2; // 親のインデックス
      if(heap[p] >= x) break; // 逆転がなければ終了
      heap[i] = heap[p]; // 自分の値を親の値にする
      i = p; // 自分は上に行く
    }
    heap[i] = x; // xは最終的にはこの位置に持ってくる
  }

  int top() {
    if(!heap.empty()) return heap[0];
    else return -1;
  }

  void pop() {
    if (heap.empty()) return;
    int x = heap.back(); // 頂点に持ってくる値
    heap.pop_back(); // 頂点を削除
    int i = 0; // 根から降ろしていく
    while (i * 2 + 1 < (int)heap.size()) {
      // 子頂点同士を比較して大きい方をchild1とする
      int child1 = i * 2 + 1, child2 = i * 2 + 2;
      if (child2 < (int)heap.size() && heap[child2] > heap[child1]) child1 = child2;
      if (heap[child1] <= x) break; // 逆転がなければ終了
      heap[i] = heap[child1]; // 自分の値を子頂点の値にする
      i = child1; // 自分は下に行く
    }
    heap[i] = x; // xは最終的にはこの位置に持ってくる
  }
};

int main() {
  Heap h;
  h.push(5); h.push(3); h.push(7); h.push(1);

  cout << h.top() << endl; // 7

  h.pop();
  cout << h.top() << endl; // 5

  h.push(11);
  cout << h.top() << endl; // 11

  return 0;
}