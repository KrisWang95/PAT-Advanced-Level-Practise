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
	if (layer.size() == 0) // ������������ˣ���ʾ�ݹ�߽磬�������ع�
	{
		return NULL;
	}

	// ����ǰ�������
	node* root = newNode(layer[0]);

	int k; //�������л���
	for (k = inL; k <= inR; k++)
	{
		if (layer[0] == in[k])
		{
			break; //�ҵ�������ѭ��
		}
	}

	vector<int> leftLayer; // �����������������
	vector<int> rightLayer; // �����������������

	for (int i = 1; i < layer.size(); i++) // ������ǰ���򣬻������Ҵ洢����
	{
		bool isLeft = false;
		for (int j = inL; j < k; j++)
		{
			if (layer[i] == in[j])
			{
				isLeft = true;
				break; //ȷ��һ��������������ǰ�������Ĵ�ѭ����
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

	// ������Ҫע��������Ҫ��root������ָ��ȥ����һ��Ĺ���
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