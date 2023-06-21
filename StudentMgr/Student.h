#pragma once
#include"define.h"
using namespace std;
class Student 
{
private:
	char* name;
	int m_inum;
	int m_iKor;
	int m_iEng;
	int m_iMath;
	int m_iTotal;
	float m_fAve;

	

public:

    Student* Create();
	Student GetInfo();

	const char* GetName();
	int GetCount();
	int GetKor();
	int GetEng();
	int GetMath();
	int GetTotal();
	float GetAve();
	int GetNum();

	void SetName(char* sz_name);
	void SetNum();
	void SetKor(int num);
	void SetEng(int num);
	void SetMath(int num);
	void SetTotal(int num, int num2, int num3);
	void SetAve(int total);
	int total();
	float average(float total);

	

public:
	
	Student() 
		: m_inum(0)
		, m_iKor(0)
		, m_iEng(0)
		, m_iMath(0)
		, m_iTotal(0)
		, m_fAve(0.f)
	{}
	~Student();
};
