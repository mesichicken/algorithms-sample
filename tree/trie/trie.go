package main

import "fmt"

func main() {
	trie := Constructor()
	trie.Insert("apple")
	result := trie.Search("apple")
	fmt.Println(result) // true
	result = trie.Search("app")
	fmt.Println(result) // false
	result = trie.StartsWith("app")
	fmt.Println(result) // true
	trie.Insert("app")
	result = trie.Search("app") // true
	fmt.Println(result)
}

type Trie struct {
	value    byte
	children []*Trie
	isEnd    bool
}

func Constructor() Trie {
	return Trie{
		value:    0,
		children: []*Trie{},
	}
}

func (this *Trie) findChild(w byte) *Trie {
	for _, child := range this.children {
		if child.value == w {
			return child
		}
	}
	return nil
}

func (this *Trie) Insert(word string) {
	node := this
	for i := 0; i < len(word); i++ {
		w := word[i]

		child := node.findChild(w)

		if child == nil {
			child = &Trie{
				value:    w,
				children: []*Trie{},
			}
			node.children = append(node.children, child)
		}
		node = child
	}

	node.isEnd = true
}

func (this *Trie) Search(word string) bool {
	result := this.findTarget(word)

	if result == nil {
		return false
	}
	return result.isEnd
}

func (this *Trie) StartsWith(prefix string) bool {
	return this.findTarget(prefix) != nil
}

func (this *Trie) findTarget(target string) *Trie {
	node := this
	for i := 0; i < len(target); i++ {
		w := target[i]
		child := node.findChild(w)
		if child == nil {
			return nil
		}
		node = child
	}

	return node
}
