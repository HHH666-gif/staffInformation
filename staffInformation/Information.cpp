#include "Information.h"


// 界面显示
void WorkList::ScreenShow()
{
	this->ReadInfoFile();
	int number,flag=1;
	while(flag==1){
		cout<<"\t\t=========================================================="<<endl;
		cout<<"\t\t||                    职工管理系统              \t||"<<endl;
		cout<<"\t\t=========================================================="<<endl;
		cout<<"\t\t||\t 1、添加员工信息\t  2、展示所有员工信息 \t||"<<endl;
		cout<<"\t\t||\t 3、搜索员工信息\t  4、删除员工信息   \t||"<<endl;
		cout<<"\t\t||\t 5、修改员工信息\t  6、排序员工信息   \t||"<<endl;
		cout<<"\t\t=========================================================="<<endl;
		cout<<"\t\t输入你要执行的操作:";
		cin>>number;
		switch(number)
		{
			// 添加员工信息
			case 1:this->AddWorker();break;
			//展示所有员工信息
			case 2:this->ShowWorker();break;
			// 查看想看的员工信息
			case 3:this->FindWorker();break;
			// 删除员工信息
			case 4:this->DeleteWorker();break;
			//修改员工信息
			case 5:this->Modification();break;
			//排序
			case 6:this->SortWorker();break;
			default:cout<<"输入有误！"<<endl;
		}
		cout<<"\t\t<1-继续\t0-退出>"<<endl;
		cout<<"\t\t是否继续：";
		cin>>flag;
	}

}


// 添加员工信息
void WorkList::AddWorker()
{
	string name;  // 姓名
	string address; // 地址
	int age;    // 年龄
	double wage; // 工资
	string num; // 工号
	char sex; //性别
	string education;  // 学历
	string telephone;  // 电话
	bool flag = true;
	cout<<"\t\t输入员工的姓名:";
	cin>>name;
	this->m_TmpWorker.SetName(name);
	cout<<"\t\t输入员工的地址:";
	cin>>address;
	this->m_TmpWorker.SetAddress(address);
	cout<<"\t\t输入员工的年龄:";
	cin>>age;
	this->m_TmpWorker.SetAge(age);
	cout<<"\t\t输入员工的工资:";
	cin>>wage;
	this->m_TmpWorker.SetWage(wage);

	while(flag)
	{
		cout<<"\t\t输入员工的工号:";
		cin>>num;
		//判断工号是否重复
		flag = this->getById(num);
		if(flag){
			flag = false;
		}else{
			cout<<"\t\t职工工号重复，请重新输入!"<<endl;
			flag = true;
		}
	}

	this->m_TmpWorker.SetNumber(num);
	cout<<"\t\t输入员工的性别:";
	cin>>sex;
	this->m_TmpWorker.SetSex(sex);
	cout<<"\t\t输入员工的学历:";
	cin>>education;
	this->m_TmpWorker.SetEducation(education);
	cout<<"\t\t输入员工的电话:";
	cin>>telephone;
	this->m_TmpWorker.SetTelephone(telephone);

	//将员工信息添加到集合
	this->workerArray.push_back(this->m_TmpWorker);
	this->SaveInfoFile();

	
}

//展示员工信息
void WorkList::ShowWorker()
{
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<"\t\t==========================================================="<<endl;
	cout<<"\t\t||                    所有职工信息             \t\t||"<<endl;
	cout<<"\t\t==========================================================="<<endl;
	cout<<"\t\t姓名"<<"\t地址"<<"\t年龄"<<"\t工资"<<"\t工号"<<"\t性别"<<"\t学历"<<"\t电话"<<endl;
	for(int i=0;i<this->workerArray.size();i++)
	{
		cout<<"\t\t"<<this->workerArray.at(i).GetName()<<"\t"<<this->workerArray.at(i).GetAddress()<<"\t"<<this->workerArray.at(i).GetAge()
		<<"\t"<<this->workerArray.at(i).GetWage()<<"\t"<<this->workerArray.at(i).GetNumber()<<"\t"<<this->workerArray.at(i).GetSex()
		<<"\t"<<this->workerArray.at(i).GetEducation()<<"\t"<<this->workerArray.at(i).GetTelephone()<<endl;
	}
	cout<<""<<endl;
	cout<<""<<endl;
}

//搜索员工信息
void WorkList::FindWorker()
{
	cout<<""<<endl;
	cout<<""<<endl;
	string num;
	cout<<"\t\t输入你要查看的员工工号：";
	cin>>num;
	cout<<""<<endl;
	cout<<"\t\t==========================================================="<<endl;
	cout<<"\t\t||                    查看职工信息            \t\t||"<<endl;
	cout<<"\t\t==========================================================="<<endl;
	for(int i=0;i<this->workerArray.size();i++)
	{
		if(num == this->workerArray.at(i).GetNumber()){
			cout<<"\t\t姓名"<<"\t地址"<<"\t年龄"<<"\t工资"<<"\t工号"<<"\t性别"<<"\t学历"<<"\t电话"<<endl;
			cout<<"\t\t"<<this->workerArray.at(i).GetName()<<"\t"<<this->workerArray.at(i).GetAddress()<<"\t"<<this->workerArray.at(i).GetAge()
			<<"\t"<<this->workerArray.at(i).GetWage()<<"\t"<<this->workerArray.at(i).GetNumber()<<"\t"<<this->workerArray.at(i).GetSex()
			<<"\t"<<this->workerArray.at(i).GetEducation()<<"\t"<<this->workerArray.at(i).GetTelephone()<<endl;
		}
	}
	cout<<""<<endl;
	cout<<""<<endl;
}

// 删除员工信息
void WorkList::DeleteWorker(){
	cout<<""<<endl;
	cout<<""<<endl;
	string num;
	int flag =1;
	cout<<"\t\t输入你要删除的员工编号:";
	cin>>num;
	for(int i=0;i<this->workerArray.size();i++)
	{
		if(num == this->workerArray.at(i).GetNumber()){
			for(vector<Worker>::iterator iter=this->workerArray.begin(); iter!=this->workerArray.end();iter ++ )
			{
				if( iter->GetNumber() == num)
					 iter = this->workerArray.erase(iter);
			} 
		}
		flag++;
	}
	if(flag == this->workerArray.size()){
		cout<<"\t\t工号不存在！";
	}else{
		cout<<"\t\tsuccess";
	}
	cout<<""<<endl;
	cout<<""<<endl;
}

//修改员工信息
void WorkList::Modification(){
	cout<<""<<endl;
	cout<<""<<endl;
	string name;  // 姓名
	string address; // 地址
	int age;    // 年龄
	double wage; // 工资
	char sex; //性别
	string education;  // 学历
	string telephone;  // 电话
	string num;
	int flag =0;
	cout<<"\t\t输入你要修改的员工编号:";
	cin>>num;
	for(int i=0;i<this->workerArray.size();i++)
	{
		if(num == this->workerArray.at(i).GetNumber()){
			cout<<"\t\t=============================================="<<endl;
			cout<<"\t\t\t\t1-姓名:"<<this->workerArray.at(i).GetName()<<endl;
			cout<<"\t\t\t\t2-地址:"<<this->workerArray.at(i).GetAddress()<<endl;
			cout<<"\t\t\t\t3-年龄:"<<this->workerArray.at(i).GetAge()<<endl;
			cout<<"\t\t\t\t4-工资:"<<this->workerArray.at(i).GetWage()<<endl;
			cout<<"\t\t\t\t5-性别:"<<this->workerArray.at(i).GetSex()<<endl;
			cout<<"\t\t\t\t6-学历:"<<this->workerArray.at(i).GetEducation()<<endl;
			cout<<"\t\t\t\t7-电话:"<<this->workerArray.at(i).GetTelephone()<<endl;
			cout<<"\t\t=============================================="<<endl;
			cout<<"\t\t输入你要修改的编号：";
			cin>>flag;
			switch(flag){
				case 1:cout<<"\t\t输入新得名字：";cin>>name;this->workerArray.at(i).SetName(name);break;
				case 2:cout<<"\t\t输入新得地址：";cin>>address;this->workerArray.at(i).SetAddress(address);break;
				case 3:cout<<"\t\t输入新得年龄：";cin>>age;this->workerArray.at(i).SetAge(age);break;
				case 4:cout<<"\t\t输入新得工资：";cin>>wage;this->workerArray.at(i).SetWage(wage);break;
				case 5:cout<<"\t\t输入新得性别：";cin>>sex;this->workerArray.at(i).SetSex(sex);break;
				case 6:cout<<"\t\t输入新得学历：";cin>>education;this->workerArray.at(i).SetEducation(education);break;
				case 7:cout<<"\t\t输入新得电话：";cin>>telephone;this->workerArray.at(i).SetTelephone(telephone);break;
				default:cout<<"\t\t输入有误！"<<endl;
			}
		}
	}
	if(flag!=0){
		cout<<"\t\t\tsuccess"<<endl;
	}
	cout<<""<<endl;
	cout<<""<<endl;
}

//排序
void WorkList::SortWorker(){
	cout<<""<<endl;
	cout<<""<<endl;
	int flag;
	cout<<"\t\t\t<1-升序\t2-降序>";
	cin>>flag;
	switch(flag){
		case 1:this->UpSort();break;
		case 2:this->DownSort();break;
		default:cout<<"\t\t输入有误！"<<endl;
	}

}

 //自定义“小于”
bool comp2Number( Worker &a,  Worker &b){
	return a.GetNumber()<b.GetNumber();
 }

bool comp2Name( Worker &a,  Worker &b){
	return a.GetName()<b.GetName();
 }

bool comp2Wage( Worker &a,  Worker &b){
	return a.GetWage()<b.GetWage();
 }

 // 以升序排序
 void WorkList::UpSort(){
	 cout<<""<<endl;
	 cout<<""<<endl;
	 int flag;
	 cout<<"\t\t1-按姓名排序\n\t\t2-按工资排序\n\t\t3-按工号排序";
	 cin>>flag;
	 switch(flag){
		 case 1:sort(this->workerArray.begin(),this->workerArray.end(),comp2Name);break;
		 case 2:sort(this->workerArray.begin(),this->workerArray.end(),comp2Wage);break;
		 case 3:sort(this->workerArray.begin(),this->workerArray.end(),comp2Number);break;
	 }
	 this->ShowWorker();
 }


 //自定义“大于”
bool comp1Number( Worker &a,  Worker &b){
	return a.GetNumber()>b.GetNumber();
 }

bool comp1Name( Worker &a,  Worker &b){
	return a.GetName()>b.GetName();
 }

bool comp1Wage( Worker &a,  Worker &b){
	return a.GetWage()>b.GetWage();
 }

 // 以降序排序
 void WorkList::DownSort(){
	  cout<<""<<endl;
	 cout<<""<<endl;
	 int flag;
	 cout<<"\t\t1-按姓名排序\n\t\t2-按工资排序\n\t\t3-按工号排序";
	 cin>>flag;
	 switch(flag){
		 case 1:sort(this->workerArray.begin(),this->workerArray.end(),comp1Name);break;
		 case 2:sort(this->workerArray.begin(),this->workerArray.end(),comp1Wage);break;
		 case 3:sort(this->workerArray.begin(),this->workerArray.end(),comp1Number);break;
	 }
	 this->ShowWorker();
 }    

 // 读取文件信息到内存中  
void WorkList::ReadInfoFile()
{
	fstream ioFile("workerInfo.dat", ios::in | ios::out | ios::binary);
	if (!ioFile)
	{
		cerr << "open workerInfo.dat error!" << endl;
		abort();
	}
	ioFile.seekg(0,ios::end);
	streampos sp=ioFile.tellg();
	ioFile.seekg(0, ios::beg);
	size_t dataSize = sp.seekpos() / sizeof(Worker);

	for(int i=0;i<dataSize;i++) 
	{
		ioFile.read((char *)&m_TmpWorker,sizeof(Worker));
		workerArray.push_back(m_TmpWorker);
	}

}

// 保存内存信息到文件
void WorkList::SaveInfoFile()
{
	fstream ioFile("workerInfo.dat", ios::in | ios::out | ios::binary);
	if (!ioFile)
	{
		cerr << "open workerInfo.dat error!" << endl;
		abort();
	}
	for(int i=0;i<workerArray.size();i++)
	{
		ioFile.write((char *)&workerArray[i],sizeof(workerArray[i]));
	}
	ioFile.close();
}



//判断录入职工信息时工号是否重复
bool WorkList::getById(string num){
	for(int i=0;i<this->workerArray.size();i++)
	{
		if(num == this->workerArray.at(i).GetNumber())
		{
			return false;
		}
	}
	return true;
}