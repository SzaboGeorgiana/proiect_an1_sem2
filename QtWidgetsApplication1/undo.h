#pragma once
#pragma once
#include "Magazin.h"
#include "Repository.h"
#include <vector>
#include <functional>
#include <iostream>

class undoAction {
public:
	
	virtual void doUndo() = 0;
	virtual ~undoAction() = default;
};

class undoRemove :public undoAction {
	Mag productToAdd;
	RepositoryAbstract& repo;
public:
	undoRemove(const Mag p, RepositoryAbstract& r) : productToAdd{ p }, repo{ r } {}
	void doUndo()override {
		repo.store(productToAdd);
		//cout << "a";
	}
};

class undoAdd :public undoAction {
	Mag productToRemove;
	RepositoryAbstract& repo;
public:
	undoAdd(const Mag p, RepositoryAbstract& r) : productToRemove{ p }, repo{ r } {}
	void doUndo() override {
			repo.del(productToRemove);
	}
};

class undoModifyBack :public undoAction {
	Mag productToModifyBack;
	RepositoryAbstract& repo;
public:
	undoModifyBack(const Mag p, RepositoryAbstract& r) :productToModifyBack{ p }, repo{ r } {}
	void doUndo()override {
		//repo.mod(productToModifyBack);
		repo.del(productToModifyBack);
		repo.store(productToModifyBack);
	}

};