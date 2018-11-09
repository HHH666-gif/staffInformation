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
	string name;  // ����
	string address; // ��ַ
	int age;    // ����
	double wage; // ����
	string num; // ����
	char sex; //�Ա�
	string education;  // ѧ��
	string telephone;  // �绰

};


class WorkList
{
public:
	WorkList(){}
	~WorkList(){}
	void ScreenShow();   // ������ʾ
private:
	void DeleteWorker(); // ɾ��Ա����Ϣ
	void Modification(); // �޸�Ա����Ϣ
	void SortWorker();   // ����
	void UpSort();       // ����������
	void DownSort();     // �Խ�������
	void SaveInfoFile(); // �����ڴ���Ϣ���ļ�
	void ReadInfoFile(); // ��ȡ�ļ���Ϣ���ڴ���   
	void ShowWorker();   // ��ʾ����Ա����Ϣ
	void FindWorker();   // �鿴�뿴��Ա����Ϣ
	void AddWorker();    // ���Ա����Ϣ
	bool getById(string num);//�ж�¼��ְ����Ϣʱ�����Ƿ��ظ�
	vector<Worker> workerArray;
	Worker m_TmpWorker;
};
