#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int> &a) {
  int N = (int)a.size();
  for (int i = 1; i < N; ++i) {
    int v = a[i]; // 挿入したい値

    // vを挿入する適切な場所jを探す
    int j = i;
    for(; j > 0; --j) {
      if(a[j - 1] > v) {
        // vより大きいものは1つ後ろに移す
        a[j] = a[j - 1];
      } else break; // v以下だったら止める
    }
    a[j] = v; // j番目にvをもってくる
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

  InsertionSort(a);

  cout << "挿入ソートによるソート後: ";
  for (int i=0; i < N; ++i) cout << a[i] << " ";
}
