#include<iostream>
#include<string>
using namespace std;
constexpr auto MAX = 1000;


// 显示菜单
void showMenu() {
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通信录*****" << endl;
	cout << "***********************" << endl;
}

// 添加联系人
// 联系人结构体
struct Person
{
	string name;
	int sex;
	int age;
	string phonenum;
	string address;
};

//通讯录结构体
struct Addressbooks
{
	Person books[MAX];
	int m_size;
};

void addPerson(Addressbooks* abs) {
	if (abs->m_size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
		// 添加名称
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->books[abs->m_size].name = name;
		// 添加性别
		int sex;
		cout << "请输入性别：" << endl;
		cout << "1------ 男" << endl;
		cout << "0------ 女" << endl;
		while (true) {
			cin >> sex;
			if (sex == 0 || sex == 1) {
				abs->books[abs->m_size].sex = sex;
				break;
			}
			else {
				cout << "输入性别有误，请重新输入！！" << endl;
			}
		}
		// 添加年龄
		int age;
		cout << "请输入年纪：" << endl;
		cin >> age;
		abs->books[abs->m_size].age = age;
		// 添加电话
		string phonenum;
		cout << "请输入电话：" << endl;
		cin >> phonenum;
		abs->books[abs->m_size].phonenum = phonenum;
		// 添加住址
		string address;
		cout << "请输入住址：" << endl;
		cin >> address;
		abs->books[abs->m_size].address = address;
		// 更新通讯录大小
		abs->m_size += 1;
	}
	cout << "添加联系人:" << abs->books[abs->m_size - 1].name << "成功！！";
	
}

// 显示联系人
void ShowPerson(Addressbooks* abs) {
	if (abs->m_size == 0) {
		cout << "通讯录为空..." << endl;
		return;
	}
	for (int i=0; i < abs->m_size; i++) {
		cout << "姓名： " << abs->books[i].name << " ";
		cout << "性别： " << abs->books[i].sex << " ";
		cout << "年龄： " << abs->books[i].age << " ";
		cout << "电话号码： " << abs->books[i].phonenum << " ";
		cout << "家庭住址： " << abs->books[i].address << endl;
	}
}

// 删除联系人
void DelPerson(Addressbooks* abs) {
	string name;
	cout << "请输入想要删除的联系人姓名：" << endl;
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
			cout << "删除联系人： " << name << "成功" << endl;
			abs->m_size -= 1;
			return;
		}
	}
	cout << "未找到联系人： " << name << endl;
}

// 查找联系人
void CheckPerson(Addressbooks* abs) {
	string name;
	cout << "请输入想要查找的联系人姓名：" << endl;
	cin >> name;
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->books[i].name == name) {
			cout << "查找成功！！！" << endl;
			cout << "姓名： " << abs->books[i].name << " ";
			cout << "性别： " << abs->books[i].sex << " ";
			cout << "年龄： " << abs->books[i].age << " ";
			cout << "电话号码： " << abs->books[i].phonenum << " ";
			cout << "家庭住址： " << abs->books[i].address << endl;
			return;
		}
	}
	cout << "未找到该联系人！！" << endl;
}

// 修改联系人
void ChangePerson(Addressbooks* abs) {
	string name;
	cout << "请输入想要修改的联系人姓名：" << endl;
	cin >> name;
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->books[i].name == name) {
			// 修改名称
			string name;
			cout << "姓名改为：" << endl;
			cin >> name;
			abs->books[i].name = name;
			// 添加性别
			int sex;
			cout << "性别改为：" << endl;
			cout << "1------ 男" << endl;
			cout << "0------ 女" << endl;
			while (true) {
				cin >> sex;
				if (sex == 0 || sex == 1) {
					abs->books[i].sex = sex;
					break;
				}
				else {
					cout << "输入性别有误，请重新输入！！" << endl;
				}
			}
			// 添加年龄
			int age;
			cout << "年龄改为：" << endl;
			cin >> age;
			abs->books[i].age = age;
			// 添加电话
			string phonenum;
			cout << "电话改为：" << endl;
			cin >> phonenum;
			abs->books[i].phonenum = phonenum;
			// 添加住址
			string address;
			cout << "住址改为：" << endl;
			cin >> address;
			abs->books[i].address = address;
			return;
		}
	}
	cout << "未找到该联系人！！" << endl;
}

int main() {
	// 创建通讯录结构体变量
	Addressbooks abs;
	abs.m_size = 0;
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 0:
			//退出通信录
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		case 1:
			//添加联系人
			addPerson(&abs);
			// 
			cout << "添加联系人成功！！" << endl;
			break;
		case 2:
			ShowPerson(&abs);
			break;
		case 3:
			//删除联系人
			DelPerson(&abs);
			break;
		case 4:
			//查找联系人
			CheckPerson(&abs);
			break;
		case 5:
			//修改联系人
			ChangePerson(&abs);
			break;
		case 6:
			//清空联系人
			abs.m_size = 0;
			cout << "联系人已清空！！！" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
}