#include <iostream>
#include <vector>
using namespace std;

// 配列aの区間[left, right)をソートする
// [left, right)は, left, left+1, ..., right-1番目の区間を表す
void QuickSort(vector<int> &a, int left, int right) {
  if (right - left <= 1) return;

  int pivot_index = (left + right)/2; // 適当にpivot用の中点を選ぶ
  int pivot = a[pivot_index];
  swap(a[pivot_index], a[right -1]); // pivotと右端をswap
  
  int i = left; // iは以下の操作によって左詰めされたpivot未満要素の右端を表す(初期値:0)
  for (int j = left; j < right -1; ++j) {
    // j番目の要素がpivotよりも小さければiの左に移動
    if(a[j] < pivot) {
      swap(a[i++], a[j]);
    }
  }
  swap(a[i], a[right - 1]); // 右端に移動したpivotとi番目の要素をswap

  // 分割された部分を再帰的にソート
  QuickSort(a, left, i); // 右半分(pivot未満)
  QuickSort(a, i+1, right); // 左半分(pivot以上)
}

int main() {
  int N; // 要素数
  cout << "要素数: ";
  cin >> N;
  vector<int> a(N);
  for (int i=0; i < N; ++i) {
    cout << i+1 << "番目: ";
    cin >> a[i];
  }

  QuickSort(a, 0, N);

  for (int i=0; i < N; ++i) cout << a[i] << " ";
}
