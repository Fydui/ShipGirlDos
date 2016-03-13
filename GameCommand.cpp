#include "stdafx.h"
#include "GameCommand.h"

using namespace std;
using namespace Gsta;
//using namespace Gcom;



void Gcom::Start() 
{
	Gsta::GameStart();
}

void Gcom::Continue()
{
	cout << "����";
}

void Gcom::SGedit()
{
	//
}

void Gcom::Exit() 
{

	cout << "�ݰ�~�ǵû���Ŷ~" << endl;
	exit(0);
}
void Gcom::Help() 
{

	system("CLS");		
	string fi = "";		//�½�string�����ReadFile���������ı�
	fi = ReadFile("./StoryTXT/Help.txt");	
	vector<string>he;	//�½�vector�����Split���и�������ı�
	he = Split(fi, "#");
	
	int j = 2;			//�������ı��ּ��γ����� �����ı�������#��ʶ��
	for (int i = 0; i < j; i++) {

		cout << he.at(i) << endl;
		system("pause");
	}
}

void Gcom::Ret()
{
	cout << "����Ret����";

}

string Gcom::ReadFile(string name) { //��ȡ�ļ�����

	ifstream infile(name);			//���ļ�
	string word = "";				//ȫ���ı�
	string tmp;						//�ڶ��ĵ�ǰ��
	while (getline(infile,tmp)){
		word += tmp + "\n";
	}
	word = word.substr(0, word.length() - 2); //ɾ�����Ļ��з�
	return word;
}

vector<string> Gcom::Split(string o_str, string fenge)
{

	vector<string>str_list;
	int comma_n = 0;
	while (1) {

		string tmp_s = "";				//"����"�Ƿָ���
		const char* ccfengge = fenge.c_str();
		comma_n = o_str.find(ccfengge); //���ҷָ�����һ�γ��ֵ�λ��
		if (comma_n == -1) {			//û�ҵ��Ļ�

			str_list.push_back(o_str);  //��ʣ�µĶ�����ȥ
			break;
		}
		tmp_s = o_str.substr(0, comma_n);			//����һ�νض�
		o_str.erase(0, comma_n + fenge.length());	//����һ��Ĩȥ
		str_list.push_back(tmp_s);					//�ѽضϵ��ַ�����������
	}

	return str_list;
}
