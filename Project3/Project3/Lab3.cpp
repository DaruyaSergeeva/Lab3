/*
	������ :
�� ������� ������������������ ����� �����
	1) ��������� �������� ������.
	2) ����� ��� ������ ������� ����� �� �������

��������� : �������� �����
������� : 25

*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TreeNode
{
	int info;
	TreeNode* left, * right;
};


// ������� � ������ � ������ root ����� ������� � ������ k
// � ������ ���������� ����� �������� �����������
void InsertNode(TreeNode*& root, int k)
{
	if (root == NULL)
	{
		root = new TreeNode;
		root->info = k;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if (k < root->info)
			InsertNode(root->left, k);
		else
			if (k > root->info)
				InsertNode(root->right, k);
			else
				cout << "Duplicate number!" << endl;
	}
	return;
}

// ������������ �� � ������ root �� ������� ������������������
// ����� �����
void MakeTree(TreeNode*& root)
{
	int k;
	cout << "Input numbers for 0" << endl;
	cin >> k;
	while (k)
	{
		InsertNodeSim(root, k);
		cin >> k;
	}
	return;
}
void InsertNodeSim(TreeNode*& root, int k)
{
	if (root == NULL)
	{
		root = new TreeNode;
		root->info = k;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		srand(rand() + k);
		if ((rand() % 2) == 0) {
			InsertNodeSim(root->left, k);
		}
		else {
			InsertNodeSim(root->right, k);
		}
	}
	return;
}

// ������� ���������� ����� ������ ��������� ������
int sumTree(TreeNode* root)
{

	if (root)
		return root->info + sumTree(root->left) + sumTree(root->right);
	else
		return 0;
}
// ����� ��������� ������ �� �������
void PrintTree(TreeNode*& root, const int level)
{
	if (root)
	{
		PrintTree(root->left, level + 1);
		cout << setw(4 * level) << root->info << endl;
		PrintTree(root->right, level + 1);
	}
	return;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	TreeNode* root = NULL;
	
		MakeTree(root);
	
	cout << "������:" << endl;
	PrintTree(root, 0);
	cout << "����� ������ ������ = " << sumTree(root) << endl;
	cout << "������:" << endl;
	PrintTree(root, 0);

	system("pause");
	return 0;
}