#include "checkers.h"

TreeNode::TreeNode(const Game & game) {
	// Przypisanie wartosci do zmiennych
	_children = 0;
	_game = game;
	_treeNodes = nullptr;
}

TreeNode::~TreeNode() {
	clear(); // Wyczyszczenie pamieci
}

int TreeNode::append(const Game & game) {
	// Skopiowanie 'dzieci' do tymczasowej tablicy
	TreeNode** temp = new TreeNode * [_children];
	for (int i = 0; i < _children; i++) {
		temp[i] = _treeNodes[i];
	}

	// Zwolnienie pamieci przeznaczonej na tablice 'dzieci'
	delete[] _treeNodes;

	// Skopiowanie 'dzieci' z tablicy tymczasowej do nowej talibcy 'dzieci' zwiekszonej o 1
	_treeNodes = new TreeNode * [_children + 1];
	for (int i = 0; i < _children; i++) {
		_treeNodes[i] = temp[i];
	}
	// Dodanie nowego elementu do tablicy 'dzieci'
	_treeNodes[_children] = new TreeNode(game);

	// Zwolnienie pamieci przeznaczonej na tablice tymczasowa
	delete[] temp;

	// Powiekszenie i zwrocenie liczby 'dzieci'
	return ++_children;
}

void TreeNode::clear() {
	// Wyczyszczenie pamieci ze wszystkich 'dzieci'
	for (int i = 0; i < _children; i++)
		delete _treeNodes[i];
	if (_children > 0)
		delete[] _treeNodes;
	_children = 0;
}

int TreeNode::children() const {
	return _children;
}

TreeNode& TreeNode::getChildNode(int index) {
	return *(_treeNodes[index]);
}

Game& TreeNode::getChildGame(int index) {
	return _treeNodes[index]->_game;
}

Game& TreeNode::getGame() {
	return _game;
}
