#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<fstream>
using namespace std;

//const size_t maxNum = 100;

class Worker
{
public:
	Worker(){}
	~Worker(){}
	string GetName(){
		return this->name;
	}
	void SetName(string name){
		this->name = name;
	}
	string GetAddress(){
		return this->address ;
	}
	void SetAddress(string address){
		this->address = address;
	}
	int GetAge(){
		return this->age;
	}
	void SetAge(int age){
		this->age = age;
	}
	double GetWage(){
		return this->wage;
	}
	void SetWage(double wage){
		this->wage = wage;
	}
	string GetNumber(){
		return this->num = num;
	}
	void SetNumber(string num){
		this->num = num ;
	}
	char GetSex(){
		return this->sex;
	}
	void SetSex(char sex){
		this->sex = sex;
	}
	string GetEducation(){
		return this->education;
	}
	void SetEducation(string education){
		this->education = education;
	}
	string GetTelephone(){
		return this->telephone ;
	}
	void SetTelephone(string telephone){
		 this->telephone = telephone;
	}
	
private:
	string name;  // 姓名
	string address; // 地址
	int age;    // 年龄
	double wage; // 工资
	string num; // 工号
	char sex; //性别
	string education;  // 学历
	string telephone;  // 电话

};


class WorkList
{
public:
	WorkList(){}
	~WorkList(){}
	void ScreenShow();   // 界面显示
private:
	void DeleteWorker(); // 删除员工信息
	void Modification(); // 修改员工信息
	void SortWorker();   // 排序
	void UpSort();       // 以升序排序
	void DownSort();     // 以降序排序
	void SaveInfoFile(); // 保存内存信息到文件
	void ReadInfoFile(); // 读取文件信息到内存中   
	void ShowWorker();   // 显示所有员工信息
	void FindWorker();   // 查看想看的员工信息
	void AddWorker();    // 添加员工信息
	bool getById(string num);//判断录入职工信息时工号是否重复
	vector<Worker> workerArray;
	Worker m_TmpWorker;
};
