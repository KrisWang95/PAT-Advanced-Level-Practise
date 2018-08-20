#include<iostream>
#include<vector>
using namespace std;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
int numNode, num = 0;
vector<int> level, in;
node* newNode(int data) {
	node* Node = new node;
	Node->data = data;
	return Node;
}

node* createFromLevelInOrder(vector<int> layer, int inL, int inR)
{
	if (layer.size() == 0) // 如果层序用完了，表示递归边界，可以往回归
	{
		return NULL;
	}

	// 处理当前层的问题
	node* root = newNode(layer[0]);

	int k; //在中序中划分
	for (k = inL; k <= inR; k++)
	{
		if (layer[0] == in[k])
		{
			break; //找到就跳出循环
		}
	}

	vector<int> leftLayer; // 左子树层序遍历序列
	vector<int> rightLayer; // 右子树层序遍历序列

	for (int i = 1; i < layer.size(); i++) // 遍历当前层序，划分左右存储起来
	{
		bool isLeft = false;
		for (int j = inL; j < k; j++)
		{
			if (layer[i] == in[j])
			{
				isLeft = true;
				break; //确定一个就跳出来，当前是在外层的大循环下
			}
		}
		if (isLeft)
		{
			leftLayer.push_back(layer[i]);
		}
		else
		{
			rightLayer.push_back(layer[i]);
		}
	}

	// 尤其需要注意这里需要用root的左右指针去接下一层的构造
	root->lchild = createFromLevelInOrder(leftLayer, inL, k - 1);
	root->rchild= createFromLevelInOrder(rightLayer, k + 1, inR);

	return root;
}

void pre(node* n) {
	if (!n) return;
	printf("%d", n->data);
	num++;
	if (num < numNode) printf(" ");
	pre(n->lchild);
	pre(n->rchild);
}

void post(node* n) {
	if (!n) return;
	post(n->lchild);
	post(n->rchild);
	printf("%d", n->data);
	num++;
	if (num < numNode) printf(" ");
}

int main() {
	cin >> numNode;
	int temp;
	for (int i = 0; i < numNode; i++) {
		cin >> temp;
		level.push_back(temp);
	}
	for (int i = 0; i < numNode; i++) {
		cin >> temp;
		in.push_back(temp);
	}
	node* root = createFromLevelInOrder(level, 0, numNode - 1);

	num = 0;
	pre(root);
	cout << endl;
	num = 0;
	post(root);

	system("pause");
	
	return 0;
}