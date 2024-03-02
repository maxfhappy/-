#include<iostream>
#include<string>
using namespace std;
constexpr auto MAX = 1000;


// ��ʾ�˵�
void showMenu() {
	cout << "***********************" << endl;
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2����ʾ��ϵ��*****" << endl;
	cout << "*****3��ɾ����ϵ��*****" << endl;
	cout << "*****4��������ϵ��*****" << endl;
	cout << "*****5���޸���ϵ��*****" << endl;
	cout << "*****6�������ϵ��*****" << endl;
	cout << "*****0���˳�ͨ��¼*****" << endl;
	cout << "***********************" << endl;
}

// �����ϵ��
// ��ϵ�˽ṹ��
struct Person
{
	string name;
	int sex;
	int age;
	string phonenum;
	string address;
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	Person books[MAX];
	int m_size;
};

void addPerson(Addressbooks* abs) {
	if (abs->m_size == MAX) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else {
		// �������
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->books[abs->m_size].name = name;
		// ����Ա�
		int sex;
		cout << "�������Ա�" << endl;
		cout << "1------ ��" << endl;
		cout << "0------ Ů" << endl;
		while (true) {
			cin >> sex;
			if (sex == 0 || sex == 1) {
				abs->books[abs->m_size].sex = sex;
				break;
			}
			else {
				cout << "�����Ա��������������룡��" << endl;
			}
		}
		// �������
		int age;
		cout << "��������ͣ�" << endl;
		cin >> age;
		abs->books[abs->m_size].age = age;
		// ��ӵ绰
		string phonenum;
		cout << "������绰��" << endl;
		cin >> phonenum;
		abs->books[abs->m_size].phonenum = phonenum;
		// ���סַ
		string address;
		cout << "������סַ��" << endl;
		cin >> address;
		abs->books[abs->m_size].address = address;
		// ����ͨѶ¼��С
		abs->m_size += 1;
	}
	cout << "�����ϵ��:" << abs->books[abs->m_size - 1].name << "�ɹ�����";
	
}

// ��ʾ��ϵ��
void ShowPerson(Addressbooks* abs) {
	if (abs->m_size == 0) {
		cout << "ͨѶ¼Ϊ��..." << endl;
		return;
	}
	for (int i=0; i < abs->m_size; i++) {
		cout << "������ " << abs->books[i].name << " ";
		cout << "�Ա� " << abs->books[i].sex << " ";
		cout << "���䣺 " << abs->books[i].age << " ";
		cout << "�绰���룺 " << abs->books[i].phonenum << " ";
		cout << "��ͥסַ�� " << abs->books[i].address << endl;
	}
}

// ɾ����ϵ��
void DelPerson(Addressbooks* abs) {
	string name;
	cout << "��������Ҫɾ������ϵ��������" << endl;
	cin >> name;
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->books[i].name == name) {
			if (abs->m_size == 1) {
				abs->books[i] = {};
			}
			else {
				for (int j = i; j < abs->m_size; j++) {
					abs->books[j] = abs->books[j + 1];
				}
			}
			cout << "ɾ����ϵ�ˣ� " << name << "�ɹ�" << endl;
			abs->m_size -= 1;
			return;
		}
	}
	cout << "δ�ҵ���ϵ�ˣ� " << name << endl;
}

// ������ϵ��
void CheckPerson(Addressbooks* abs) {
	string name;
	cout << "��������Ҫ���ҵ���ϵ��������" << endl;
	cin >> name;
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->books[i].name == name) {
			cout << "���ҳɹ�������" << endl;
			cout << "������ " << abs->books[i].name << " ";
			cout << "�Ա� " << abs->books[i].sex << " ";
			cout << "���䣺 " << abs->books[i].age << " ";
			cout << "�绰���룺 " << abs->books[i].phonenum << " ";
			cout << "��ͥסַ�� " << abs->books[i].address << endl;
			return;
		}
	}
	cout << "δ�ҵ�����ϵ�ˣ���" << endl;
}

// �޸���ϵ��
void ChangePerson(Addressbooks* abs) {
	string name;
	cout << "��������Ҫ�޸ĵ���ϵ��������" << endl;
	cin >> name;
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->books[i].name == name) {
			// �޸�����
			string name;
			cout << "������Ϊ��" << endl;
			cin >> name;
			abs->books[i].name = name;
			// ����Ա�
			int sex;
			cout << "�Ա��Ϊ��" << endl;
			cout << "1------ ��" << endl;
			cout << "0------ Ů" << endl;
			while (true) {
				cin >> sex;
				if (sex == 0 || sex == 1) {
					abs->books[i].sex = sex;
					break;
				}
				else {
					cout << "�����Ա��������������룡��" << endl;
				}
			}
			// �������
			int age;
			cout << "�����Ϊ��" << endl;
			cin >> age;
			abs->books[i].age = age;
			// ��ӵ绰
			string phonenum;
			cout << "�绰��Ϊ��" << endl;
			cin >> phonenum;
			abs->books[i].phonenum = phonenum;
			// ���סַ
			string address;
			cout << "סַ��Ϊ��" << endl;
			cin >> address;
			abs->books[i].address = address;
			return;
		}
	}
	cout << "δ�ҵ�����ϵ�ˣ���" << endl;
}

int main() {
	// ����ͨѶ¼�ṹ�����
	Addressbooks abs;
	abs.m_size = 0;
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 0:
			//�˳�ͨ��¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		case 1:
			//�����ϵ��
			addPerson(&abs);
			// 
			cout << "�����ϵ�˳ɹ�����" << endl;
			break;
		case 2:
			ShowPerson(&abs);
			break;
		case 3:
			//ɾ����ϵ��
			DelPerson(&abs);
			break;
		case 4:
			//������ϵ��
			CheckPerson(&abs);
			break;
		case 5:
			//�޸���ϵ��
			ChangePerson(&abs);
			break;
		case 6:
			//�����ϵ��
			abs.m_size = 0;
			cout << "��ϵ������գ�����" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
}