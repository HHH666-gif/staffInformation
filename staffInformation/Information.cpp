#include "Information.h"


// ������ʾ
void WorkList::ScreenShow()
{
	this->ReadInfoFile();
	int number,flag=1;
	while(flag==1){
		cout<<"\t\t=========================================================="<<endl;
		cout<<"\t\t||                    ְ������ϵͳ              \t||"<<endl;
		cout<<"\t\t=========================================================="<<endl;
		cout<<"\t\t||\t 1�����Ա����Ϣ\t  2��չʾ����Ա����Ϣ \t||"<<endl;
		cout<<"\t\t||\t 3������Ա����Ϣ\t  4��ɾ��Ա����Ϣ   \t||"<<endl;
		cout<<"\t\t||\t 5���޸�Ա����Ϣ\t  6������Ա����Ϣ   \t||"<<endl;
		cout<<"\t\t=========================================================="<<endl;
		cout<<"\t\t������Ҫִ�еĲ���:";
		cin>>number;
		switch(number)
		{
			// ���Ա����Ϣ
			case 1:this->AddWorker();break;
			//չʾ����Ա����Ϣ
			case 2:this->ShowWorker();break;
			// �鿴�뿴��Ա����Ϣ
			case 3:this->FindWorker();break;
			// ɾ��Ա����Ϣ
			case 4:this->DeleteWorker();break;
			//�޸�Ա����Ϣ
			case 5:this->Modification();break;
			//����
			case 6:this->SortWorker();break;
			default:cout<<"��������"<<endl;
		}
		cout<<"\t\t<1-����\t0-�˳�>"<<endl;
		cout<<"\t\t�Ƿ������";
		cin>>flag;
	}

}


// ���Ա����Ϣ
void WorkList::AddWorker()
{
	string name;  // ����
	string address; // ��ַ
	int age;    // ����
	double wage; // ����
	string num; // ����
	char sex; //�Ա�
	string education;  // ѧ��
	string telephone;  // �绰
	bool flag = true;
	cout<<"\t\t����Ա��������:";
	cin>>name;
	this->m_TmpWorker.SetName(name);
	cout<<"\t\t����Ա���ĵ�ַ:";
	cin>>address;
	this->m_TmpWorker.SetAddress(address);
	cout<<"\t\t����Ա��������:";
	cin>>age;
	this->m_TmpWorker.SetAge(age);
	cout<<"\t\t����Ա���Ĺ���:";
	cin>>wage;
	this->m_TmpWorker.SetWage(wage);

	while(flag)
	{
		cout<<"\t\t����Ա���Ĺ���:";
		cin>>num;
		//�жϹ����Ƿ��ظ�
		flag = this->getById(num);
		if(flag){
			flag = false;
		}else{
			cout<<"\t\tְ�������ظ�������������!"<<endl;
			flag = true;
		}
	}

	this->m_TmpWorker.SetNumber(num);
	cout<<"\t\t����Ա�����Ա�:";
	cin>>sex;
	this->m_TmpWorker.SetSex(sex);
	cout<<"\t\t����Ա����ѧ��:";
	cin>>education;
	this->m_TmpWorker.SetEducation(education);
	cout<<"\t\t����Ա���ĵ绰:";
	cin>>telephone;
	this->m_TmpWorker.SetTelephone(telephone);

	//��Ա����Ϣ��ӵ�����
	this->workerArray.push_back(this->m_TmpWorker);
	this->SaveInfoFile();

	
}

//չʾԱ����Ϣ
void WorkList::ShowWorker()
{
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<"\t\t==========================================================="<<endl;
	cout<<"\t\t||                    ����ְ����Ϣ             \t\t||"<<endl;
	cout<<"\t\t==========================================================="<<endl;
	cout<<"\t\t����"<<"\t��ַ"<<"\t����"<<"\t����"<<"\t����"<<"\t�Ա�"<<"\tѧ��"<<"\t�绰"<<endl;
	for(int i=0;i<this->workerArray.size();i++)
	{
		cout<<"\t\t"<<this->workerArray.at(i).GetName()<<"\t"<<this->workerArray.at(i).GetAddress()<<"\t"<<this->workerArray.at(i).GetAge()
		<<"\t"<<this->workerArray.at(i).GetWage()<<"\t"<<this->workerArray.at(i).GetNumber()<<"\t"<<this->workerArray.at(i).GetSex()
		<<"\t"<<this->workerArray.at(i).GetEducation()<<"\t"<<this->workerArray.at(i).GetTelephone()<<endl;
	}
	cout<<""<<endl;
	cout<<""<<endl;
}

//����Ա����Ϣ
void WorkList::FindWorker()
{
	cout<<""<<endl;
	cout<<""<<endl;
	string num;
	cout<<"\t\t������Ҫ�鿴��Ա�����ţ�";
	cin>>num;
	cout<<""<<endl;
	cout<<"\t\t==========================================================="<<endl;
	cout<<"\t\t||                    �鿴ְ����Ϣ            \t\t||"<<endl;
	cout<<"\t\t==========================================================="<<endl;
	for(int i=0;i<this->workerArray.size();i++)
	{
		if(num == this->workerArray.at(i).GetNumber()){
			cout<<"\t\t����"<<"\t��ַ"<<"\t����"<<"\t����"<<"\t����"<<"\t�Ա�"<<"\tѧ��"<<"\t�绰"<<endl;
			cout<<"\t\t"<<this->workerArray.at(i).GetName()<<"\t"<<this->workerArray.at(i).GetAddress()<<"\t"<<this->workerArray.at(i).GetAge()
			<<"\t"<<this->workerArray.at(i).GetWage()<<"\t"<<this->workerArray.at(i).GetNumber()<<"\t"<<this->workerArray.at(i).GetSex()
			<<"\t"<<this->workerArray.at(i).GetEducation()<<"\t"<<this->workerArray.at(i).GetTelephone()<<endl;
		}
	}
	cout<<""<<endl;
	cout<<""<<endl;
}

// ɾ��Ա����Ϣ
void WorkList::DeleteWorker(){
	cout<<""<<endl;
	cout<<""<<endl;
	string num;
	int flag =1;
	cout<<"\t\t������Ҫɾ����Ա�����:";
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
		cout<<"\t\t���Ų����ڣ�";
	}else{
		cout<<"\t\tsuccess";
	}
	cout<<""<<endl;
	cout<<""<<endl;
}

//�޸�Ա����Ϣ
void WorkList::Modification(){
	cout<<""<<endl;
	cout<<""<<endl;
	string name;  // ����
	string address; // ��ַ
	int age;    // ����
	double wage; // ����
	char sex; //�Ա�
	string education;  // ѧ��
	string telephone;  // �绰
	string num;
	int flag =0;
	cout<<"\t\t������Ҫ�޸ĵ�Ա�����:";
	cin>>num;
	for(int i=0;i<this->workerArray.size();i++)
	{
		if(num == this->workerArray.at(i).GetNumber()){
			cout<<"\t\t=============================================="<<endl;
			cout<<"\t\t\t\t1-����:"<<this->workerArray.at(i).GetName()<<endl;
			cout<<"\t\t\t\t2-��ַ:"<<this->workerArray.at(i).GetAddress()<<endl;
			cout<<"\t\t\t\t3-����:"<<this->workerArray.at(i).GetAge()<<endl;
			cout<<"\t\t\t\t4-����:"<<this->workerArray.at(i).GetWage()<<endl;
			cout<<"\t\t\t\t5-�Ա�:"<<this->workerArray.at(i).GetSex()<<endl;
			cout<<"\t\t\t\t6-ѧ��:"<<this->workerArray.at(i).GetEducation()<<endl;
			cout<<"\t\t\t\t7-�绰:"<<this->workerArray.at(i).GetTelephone()<<endl;
			cout<<"\t\t=============================================="<<endl;
			cout<<"\t\t������Ҫ�޸ĵı�ţ�";
			cin>>flag;
			switch(flag){
				case 1:cout<<"\t\t�����µ����֣�";cin>>name;this->workerArray.at(i).SetName(name);break;
				case 2:cout<<"\t\t�����µõ�ַ��";cin>>address;this->workerArray.at(i).SetAddress(address);break;
				case 3:cout<<"\t\t�����µ����䣺";cin>>age;this->workerArray.at(i).SetAge(age);break;
				case 4:cout<<"\t\t�����µù��ʣ�";cin>>wage;this->workerArray.at(i).SetWage(wage);break;
				case 5:cout<<"\t\t�����µ��Ա�";cin>>sex;this->workerArray.at(i).SetSex(sex);break;
				case 6:cout<<"\t\t�����µ�ѧ����";cin>>education;this->workerArray.at(i).SetEducation(education);break;
				case 7:cout<<"\t\t�����µõ绰��";cin>>telephone;this->workerArray.at(i).SetTelephone(telephone);break;
				default:cout<<"\t\t��������"<<endl;
			}
		}
	}
	if(flag!=0){
		cout<<"\t\t\tsuccess"<<endl;
	}
	cout<<""<<endl;
	cout<<""<<endl;
}

//����
void WorkList::SortWorker(){
	cout<<""<<endl;
	cout<<""<<endl;
	int flag;
	cout<<"\t\t\t<1-����\t2-����>";
	cin>>flag;
	switch(flag){
		case 1:this->UpSort();break;
		case 2:this->DownSort();break;
		default:cout<<"\t\t��������"<<endl;
	}

}

 //�Զ��塰С�ڡ�
bool comp2Number( Worker &a,  Worker &b){
	return a.GetNumber()<b.GetNumber();
 }

bool comp2Name( Worker &a,  Worker &b){
	return a.GetName()<b.GetName();
 }

bool comp2Wage( Worker &a,  Worker &b){
	return a.GetWage()<b.GetWage();
 }

 // ����������
 void WorkList::UpSort(){
	 cout<<""<<endl;
	 cout<<""<<endl;
	 int flag;
	 cout<<"\t\t1-����������\n\t\t2-����������\n\t\t3-����������";
	 cin>>flag;
	 switch(flag){
		 case 1:sort(this->workerArray.begin(),this->workerArray.end(),comp2Name);break;
		 case 2:sort(this->workerArray.begin(),this->workerArray.end(),comp2Wage);break;
		 case 3:sort(this->workerArray.begin(),this->workerArray.end(),comp2Number);break;
	 }
	 this->ShowWorker();
 }


 //�Զ��塰���ڡ�
bool comp1Number( Worker &a,  Worker &b){
	return a.GetNumber()>b.GetNumber();
 }

bool comp1Name( Worker &a,  Worker &b){
	return a.GetName()>b.GetName();
 }

bool comp1Wage( Worker &a,  Worker &b){
	return a.GetWage()>b.GetWage();
 }

 // �Խ�������
 void WorkList::DownSort(){
	  cout<<""<<endl;
	 cout<<""<<endl;
	 int flag;
	 cout<<"\t\t1-����������\n\t\t2-����������\n\t\t3-����������";
	 cin>>flag;
	 switch(flag){
		 case 1:sort(this->workerArray.begin(),this->workerArray.end(),comp1Name);break;
		 case 2:sort(this->workerArray.begin(),this->workerArray.end(),comp1Wage);break;
		 case 3:sort(this->workerArray.begin(),this->workerArray.end(),comp1Number);break;
	 }
	 this->ShowWorker();
 }    

 // ��ȡ�ļ���Ϣ���ڴ���  
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

// �����ڴ���Ϣ���ļ�
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



//�ж�¼��ְ����Ϣʱ�����Ƿ��ظ�
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