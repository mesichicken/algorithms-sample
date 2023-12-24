#include <iostream>
#include <vector>
using namespace std;

// 配列aの区間[left, right)をソートする
// [left, right)はleft, left+1, ..., right-1を表す
void MergeSort(vector<int> &a, int left, int right) {
  if(right - left == 1) return;
  int mid = left + (right - left) / 2;

  // 左半分[left, mid)を再帰的にソート
  MergeSort(a, left, mid);

  // 右半分[mid, right)を再帰的にソート
  MergeSort(a, mid, right);

  // 左半分と右半分の結果を一時的にコピー
  vector<int> buf;
  for (int i = left; i < mid; ++i) buf.push_back(a[i]);
  for (int i = right - 1; i >= mid; --i) buf.push_back(a[i]); // 右側は順番をひっくり返す

  // 分割した左右を合併
  int index_left = 0;
  int index_right = (int)buf.size() - 1;
  // 左と右の最小値を比較して小さい方を選んで抜き出すことを繰り返す
  for (int i = left; i < right; ++i) {
    if(buf[index_left] <= buf[index_right]) {
      // 左側採用
      a[i] = buf[index_left++];
    } else {
      // 右側採用
      a[i] = buf[index_right--];
    }
  }
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

  MergeSort(a, 0, N);

  cout << "マージソートによるソート後: ";
  for (int i=0; i < N; ++i) cout << a[i] << " ";
}
