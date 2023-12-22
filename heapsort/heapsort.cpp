#include <iostream>
#include <vector>
using namespace std;

// i番目の頂点を根とする部分木について、ヒープ条件を満たすようにする
// aのうち0番目からN-1番目までの部分、a[0:N]についてのみ考える
void Heapify(vector<int> &a, int i, int N) {
  int child1 = 2 * i + 1;    // 左の子供
  if (child1 >= N) return;   // 子供がないなら終了
                             //
  // 子供同士を比較して大きい方をchild1とする
  if (child1 + 1 < N && a[child1 + 1] > a[child1]) {
    // 右の子供があり、かつ左の子供より右の子供の方が大きい
    ++child1;
  }
  if (a[child1] <= a[i]) return;  // 逆転がなければ終了
  swap(a[i], a[child1]);          // 自分と子供を入れ替える
  Heapify(a, child1, N);          // 再帰的に下の部分もヒープにする

}

// aをソートする
void HeapSort(vector<int> &a) {
  int N = (int)a.size();

  // ステップ１: a全体をヒープにする
  for (int i = N / 2 - 1; i >= 0; --i) {
    Heapify(a, i, N);    // a[i]を根とする部分木をヒープにする
  }

  // ステップ２: ヒープから１個ずつ最大値をpopする
  for (int i = N - 1; i > 0; --i) {
    swap(a[0], a[i]);    // ヒープの最大値を右詰め
    Heapify(a, 0, i);    // a[0]を根とする部分木をヒープにする
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

  HeapSort(a);

  cout << "ヒープソートによるソート後: ";
  for (int i=0; i < N; ++i) cout << a[i] << " ";
}
