﻿/*
По входной последовательности целых чисел построить бинарное дерево. Найти для
каждой вершины дерева сумму её предков.

Автор : Сергеева Д.В.
Дата  : 29.11.2020
*/

#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

struct TreeNode
{
	int info;
	int sum; 
	TreeNode* left, * right, *back;
};

// Прототипы функций
TreeNode* makeTree(int level, int s);
void printTree(TreeNode*& root, const int level = 0);


void main()
{
	setlocale(LC_ALL, "Russian");

	int s = 0;

	cout << "Введите дерево" << endl;
	TreeNode* root = makeTree(0,s);

	cout << "Введенное дерево:" << endl;
	printTree(root);

	system("pause");
	return;
}

// Создание бинарного дерева вводом с клавиатуры
TreeNode* makeTree(int level, int s)
{
	char c;
	cout << setw(4 * level) << "" << "Создать вершину? (y/n)";
	cin >> c;
	if (c == 'y')
	{
		TreeNode* p = new TreeNode;
		
		cout << setw(4 * level) << "" << "Введите значение вершины:";
		cin >> p->info;
		s = s + p->info; 
		p->sum = s;
		cout << setw(4 * level) << "" << "Левое поддерево вершины " << p->info << endl;
		p->left = makeTree(level + 1,s);

		cout << setw(4 * level) << "" << "Правое поддерево вершины " << p->info << endl;
		p->right = makeTree(level + 1,s);
		return p;
	}
	else
		return NULL;


}


// Вывод бинарного дерева на консоль
void printTree(TreeNode*& root, const int level)
{
	if (root)
	{
		printTree(root->left, level + 1);
		cout << setw(4 * level) << "" << root->info << "("<< "Sum = " << root->sum - root->info << ")" << endl;
		printTree(root->right, level + 1);
	}
	return;
}


