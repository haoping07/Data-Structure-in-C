/*
Trie
*/

#include <iostream>
using namespace std;

const int branchNum = 26;

class Trie_node {
public:
	bool isStr;
	Trie_node* next[branchNum];
	Trie_node() : isStr(false) {
		for (int i = 0; i < branchNum; i++)
			next[i] = nullptr;
	}
};

class Trie {
private:
	Trie_node* root;
public:
	Trie() { root = new Trie_node(); }
	void insert(const char* word);
	bool search(char* word);
	Trie_node* getTrie() { return root; }
};

void Trie::insert(const char* word) {
	Trie_node* location = root;
	while (*word) {
		if (!location->next[*word - 'a']) {
			location->next[*word - 'a'] = new Trie_node();
		}
		location = location->next[*word - 'a'];
		word++;
	}
	location->isStr = true;
}

bool Trie::search(char* word) {
	Trie_node* location = root;
	while (*word && location) {
		location = location->next[*word - 'a'];
		word++;
	}
	return location && location->isStr;
}

int main()
{
	return 0;
}