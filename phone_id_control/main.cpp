#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
//联系人结构体
struct Person
{
	string m_Name; //
	int m_Sex; //1男 2女
	int m_Age;
	string m_Phone;
	string m_Addr;

};
//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX]; //通讯录中存储MAX个联系人
	int m_Size=0; //通讯录中当前人员的个数
	};
//添加联系人函数
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//name
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//sex
		cout << "请输入性别：" << endl;
		cout << "1.男" << endl;
		cout << "2.女" << endl;
		int sex = 0;
		while (true)
		{
			//如果输入正确，可以退出。否则循环重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}
		//age
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//phone
		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//addr
		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
//显示联系人函数
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在
int isExist(Addressbooks * abs,string name )
{
	
	for(int i=0; i < abs->m_Size;i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
//查找联系人函数
void findPerson(Addressbooks* abs)
{
	cout << "请输入查找联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->personArray[ret].m_Addr << endl;
		}
	else
		{
		cout << "查找失败，未找到联系人" << endl;
	}
	system("pause");
	system("cls");
	}
//修改联系人函数
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入修改联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//name
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//sex
		cout << "请输入性别：" << endl;
		cout << "1.男" << endl;
		cout << "2.女" << endl;
		int sex = 0;
		while (true)
		{
			//如果输入正确，可以退出。否则循环重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}
		//age
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//phone
		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//addr
		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
		//更新通讯录人数
		cout << "修改成功" << endl;
		system("pause");
		system("cls");
	}
}
//清空联系人函数
void clearPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}
//菜单
void showMenu()
	{
	cout << "**********通讯录管理系统**********" << endl;
	cout << "*****      1.添加联系人      *****" << endl;
	cout << "*****      2.显示联系人      *****" << endl;
	cout << "*****      3.删除联系人      *****" << endl;
	cout << "*****      4.查找联系人      *****" << endl;
	cout << "*****      5.修改联系人      *****" << endl;
	cout << "*****      6.清空联系人      *****" << endl;
	cout << "*****      0.退出通讯录      *****" << endl;
	cout << "**********************************" << endl;    
		}
int main() 
{
	Addressbooks abs;
	int select = 0;
	while (true)
	{
	//调用菜单函数
	showMenu();
	cin>> select;
	switch (select)
	{
		case 1:
		    addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
		{
			cout << "请输入删除联系人姓名" << endl;
			string name;
			cin >> name;
			int ret = isExist(&abs, name);
			if (ret != -1)
			{
				for (int i = ret; i < abs.m_Size - 1; i++)
				{
					abs.personArray[i] = abs.personArray[i + 1];
				}
				abs.m_Size--;
				cout << "删除成功" << endl;
			}
			else
			{
				cout << "删除失败，未找到联系人" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			clearPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");			
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
	  }
	}
	system("pause");
	return 0;
}