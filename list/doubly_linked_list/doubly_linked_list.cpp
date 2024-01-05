#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  Node *prev, *next;
  string name;

  Node(string name_ = "") : prev(NULL), next(NULL), name(name_) {}
};

// 番兵を表すノードをグローバル領域に置いておく
Node* nil;

// 初期化
void init() {
  nil = new Node();
  nil->prev = nil;
  nil->next = nil;
}

// 連結リストを出力する
void printList() {
  Node* cur = nil->next; // 先頭から出発
  for(; cur != nil; cur = cur->next) {
    cout << cur->name << " -> ";
  }
  cout << endl;
}

// ノードpの直後にノードvを挿入する
void insert(Node* v, Node* p = nil) {
  v->next = p->next;
  p->next->prev = v;
  p->next = v;
  v->prev = p;
}

// ノードvを削除する
void erase(Node* v) {
  if(v == nil) return; // vが番兵の場合は処理しない
  v->prev->next = v->next;
  v->next->prev = v->prev;
  delete v; // メモリを開放
}

int main() {
  // 初期化
  init();

  // 作りたいノードの名前の一覧
  // 最後尾のノード（「山本」）から順に挿入することに注意
  vector<string> names = {
    "yamamoto",
    "watanabe",
    "ito",
    "takahashi",
    "suzuki",
    "sato"
  };

  // 連結リスト作成: 各ノードを生成して連結リストの先頭に挿入していく
  Node *watanabe;
  for(int i = 0; i < (int)names.size(); ++i) {
    // ノードを作成する
    Node* node = new Node(names[i]);

    // 作成したノードを連結リストの先頭に挿入する
    insert(node);

    // 渡辺のノードを保持しておく
    if(names[i] == "watanabe") watanabe = node;
  }

  // 渡辺のノードを削除する
  cout << "before: ";
  printList();
  erase(watanabe);
  cout << "after: ";
  printList();
}