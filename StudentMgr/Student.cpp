#include "define.h"

Student* Student::Create()
{
	char* temp = new char[4];
	for (int i = 0; i < 4; ++i)
	{
		if (3 == i)
		{
			temp[i] = '\0';
		}
		else
		{
			temp[i] = 'A' + (rand() % 26);
		}
		
	}
	
	this->name = temp;
	this->SetNum();
	this->m_iKor = rand() % 101;
	this->m_iEng = rand() % 101;
	this->m_iMath = rand() % 101;
	this->m_iTotal = this->total();
	this->m_fAve = average((float)this->m_iTotal);
	


	return this;
}


const char* Student::GetName()
{
	
	return this->name;
}

int Student::GetCount()
{
	return this->m_inum;
}

Student Student::GetInfo()
{
	return *this;
}

int Student::GetKor()
{
	return this->m_iKor;
}

int Student::GetEng()
{
	return  this->m_iEng;
}

int Student::GetMath()
{
	return  this->m_iMath;
}

int Student::GetTotal()
{
	return  this->m_iTotal;
}

float Student::GetAve()
{
	return  this->m_fAve;
}

int Student::GetNum()
{
	return this->m_inum;
}

void Student::SetName(char* sz_name)
{
	this->name = sz_name;
}

void Student::SetNum()
{
	this->m_inum = iNum++;
}

void Student::SetKor(int num)
{
	this->m_iKor = num;
}

void Student::SetEng(int num)
{
	this->m_iEng = num;
}

void Student::SetMath(int num)
{
	this->m_iMath = num;
}

void Student::SetTotal(int num, int num2, int num3)
{
	this->m_iTotal = num + num2 + num3;
}

void Student::SetAve(int total)
{
	this->m_fAve = (float)total / 3;
}


int Student::total()
{
	return this->m_iKor + this->m_iEng + this->m_iMath;
}
float Student::average(float total)
{
	return total / 3;
}



Student::~Student()
{
	
}


