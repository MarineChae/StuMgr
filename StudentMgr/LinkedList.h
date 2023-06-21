#pragma once
#include "define.h"


template<typename T>
class LinkedList
{
protected:
	T Info;
	LinkedList* pPrev;
	LinkedList* pNext;

public:
	
	//void Link(T* A);
	void init();
	void CreateData();
	void SetNext();
	void SetNext(LinkedList<T>*Node);
	void SetPrev();
	void SetPrev(LinkedList<T>* Node);
	void SetInfo(T Tinfo);
	
	void Link(LinkedList<T>* TInfo);
	void Print();
	T GetInfo();
	void SaveData(const char* FileName);
	void OverWriteData(const char* FileName);
	void LoadData(const char* FileName);
	void DeleteAll();

	void DeleteData(T* FindData);
	LinkedList<T>* Find(const char* findname);
	void FindPrint(LinkedList<T>* FindData);
	void ModifyStudent(LinkedList<T>* FindData);
	void DeleteStudent(LinkedList<T>* FindData);
	void AddData();
	void Swap(T a, T b);
	void Sort();

public:
	

public:

	LinkedList()
		: Info()
		, pPrev(nullptr)
		, pNext(nullptr)
	{


	}
	~LinkedList()
	{

	}
	
};
static LinkedList<Student>* g_pHead=new LinkedList<Student>;

static LinkedList<Student>* g_pTail = new LinkedList<Student>;

template<typename T>
inline void LinkedList<T>::init()
{
	
	if(initCount==0)
	{
		for (int i = 0; i < 5; ++i)
		{
			CreateData();
		}
		
		MainScreen();
		printf("초기화 완료!\n");
	}
	else
	{
		MainScreen();
		printf("이미 정보가 존재합니다.\n");
	}
	




}

template<typename T>
inline void LinkedList<T>::CreateData()
{

	if (initCount == 0)
	{
		initCount++;
		g_pHead->SetNext(g_pTail);
		g_pTail->SetPrev(g_pHead);
	}
		Student* StudentInfo = new Student;
		StudentInfo->Create();
		

		LinkedList<Student>* Linker = new LinkedList<Student>;
		Linker->SetInfo(*StudentInfo);
		g_pHead->Link(Linker);

		


}

template<typename T>

void LinkedList<T>::SetNext()
{
	this->pNext = nullptr;

}

template<typename T>
inline void LinkedList<T>::SetNext(LinkedList<T>* Node)
{
	this->pNext = Node;

}

template<typename T>
void LinkedList<T>::SetPrev()
{
	this->pPrev = nullptr;

}

template<typename T>
inline void LinkedList<T>::SetPrev(LinkedList<T>* Node)
{
	this->pPrev = Node;
}

template<typename T>
void LinkedList<T>::SetInfo(T Tinfo)
{
	this->Info = Tinfo;
}


template<typename T>
inline void LinkedList<T>::Link(LinkedList<T>* TInfo)
{
	if (g_pHead->pNext == g_pTail)
	{
		g_pHead->pNext = TInfo;
		g_pTail->pPrev = TInfo;
		TInfo->pPrev = g_pHead;
		TInfo->pNext = g_pTail;
	}
	else
	{
		LinkedList<T> temp;
		temp.pPrev = g_pTail->pPrev;
		g_pTail->pPrev->pNext = TInfo;
		g_pTail->pPrev = TInfo;

		TInfo->pNext = g_pTail;
		TInfo->pPrev = temp.pPrev;

	}

}

template<typename T>
inline void LinkedList<T>::Print()
{

	LinkedList<T>* FindNode = g_pHead->pNext;
	if (FindNode == NULL||FindNode==g_pTail)
	{
		printf("정보가 입력되어있지 않습니다.\n");

	}
	else
	{
		printf("이름\t국어\t영어\t수학\t총점\t평균\n");
		while (FindNode != g_pTail)
		{
			T PrintNode = FindNode->GetInfo();
			cout << PrintNode.GetName() <<'\t';
			cout << PrintNode.GetKor() << '\t';
			cout << PrintNode.GetEng() << '\t';
			cout << PrintNode.GetMath() << '\t';
			cout << PrintNode.GetTotal() << '\t';
			cout.precision(4);
			cout << PrintNode.GetAve() << endl; 

			FindNode = FindNode->pNext;

		}
		
	}

}

template<typename T>
inline T LinkedList<T>::GetInfo()
{
	return  this->Info;
}

template<typename T>
inline void LinkedList<T>::SaveData(const char* FileName)
{

	LinkedList<T>* SaveData = g_pHead->pNext;
	FILE* fp = fopen(FileName, "ab+");
	while (SaveData != g_pTail)
	{
		
		fwrite(SaveData, 1, sizeof(T), fp);

		SaveData = SaveData->pNext;

	}
	fclose(fp);



}

template<typename T>
inline void LinkedList<T>::OverWriteData(const char* FileName)
{
	LinkedList<T>* SaveData = g_pHead->pNext;
	FILE* fp = fopen(FileName, "wb");
	while (SaveData != g_pTail)
	{
	
		fwrite(SaveData, 1, sizeof(T), fp);

		SaveData = SaveData->pNext;

	}
	fclose(fp);
}

template<typename T>
inline void LinkedList<T>::LoadData(const char* FileName)
{
	FILE* fp = fopen(FileName, "rb+");
	if (fp == NULL)
	{
		printf("파일이 존재하지 않습니다.\n");
	}
	else
	{
		while (1)
		{
			if (initCount == 0)
			{
				initCount++;
				g_pHead->SetNext(g_pTail);
				g_pTail->SetPrev(g_pHead);
			}
				
			LinkedList<T>* LoadStudent = new LinkedList<T>;

			fread(LoadStudent, 1, sizeof(T), fp);
			if (feof(fp))
			{
				break;
			}
			
			Link(LoadStudent);
			
		}

	}
	fclose(fp);
	MainScreen();
	printf("데이터를 성공적으로 불러왔습니다!\n");


}

template<typename T>
inline void LinkedList<T>::DeleteAll()
{

	if (g_pHead->pNext != g_pTail)
	{
		LinkedList<T>* DeleteStudent = g_pTail->pPrev;
		while (DeleteStudent != g_pHead)
		{
			LinkedList<T>* TempStudent = DeleteStudent->pPrev;
			delete(DeleteStudent);
			DeleteStudent = TempStudent;
		}
	}
	g_pHead->pNext = g_pTail;
	g_pTail->pPrev = g_pHead;
	initCount = 0;
	iNum = 0;
	MainScreen();
	printf("삭제 완료.\n");

}

template<typename T>
inline void LinkedList<T>::DeleteData(T* FindData)
{

	if (FindData != NULL)
	{

		T* FrontNode = FindData->pPrev;
		T* NextNode = FindData->pNext;
		if (FrontNode != NULL)
		{
			FrontNode->pNext = NextNode;
			NextNode->pPrev = FrontNode;
		}
		--iNum;
		delete(FindData);
		MainScreen();
		printf("삭제 완료.\n");
	}
	else
	{
		MainScreen();
		printf("이름을 찾을 수 없습니다.\n");
	}

}

template<typename T>
inline LinkedList<T>* LinkedList<T>::Find(const char* findname)
{
	LinkedList<T>* FindData = g_pHead->pNext;

	while (FindData != g_pTail && FindData!=NULL)
	{
		T TempInfo = FindData->GetInfo();
		if (strcmp(TempInfo.GetName(), findname) == 0)
		{
			return FindData;
		}
		else
		{
			FindData = FindData->pNext;
			TempInfo = FindData->GetInfo();
		}
	}

	return FindData;

}

template<typename T>
inline void LinkedList<T>::FindPrint(LinkedList<T>* FindData)
{
	if (FindData != g_pTail&&FindData!=NULL)
	{
		MainScreen();
		printf("이름\t국어\t영어\t수학\t총점\t평균\n");

		T PrintNode = FindData->GetInfo();
		cout << PrintNode.GetName() << '\t';
		cout << PrintNode.GetKor() << '\t';
		cout << PrintNode.GetEng() << '\t';
		cout << PrintNode.GetMath() << '\t';
		cout << PrintNode.GetTotal() << '\t';
		cout.precision(4);
		cout << PrintNode.GetAve() << endl;
	}
	else
	{
		MainScreen();
		printf("이름을 찾을 수 없습니다.\n");
	}
}

template<typename T>
inline void LinkedList<T>::ModifyStudent(LinkedList<T>* FindData)
{
	if (FindData != g_pTail)
	{
		T TempData = FindData->GetInfo();
		int Temp = 0;
		printf("국어 : ");
		scanf("%3d", &Temp);
		TempData.SetKor(Temp);
		printf("영어 : ");
		scanf("%3d", &Temp);
		TempData.SetEng(Temp);
		printf("수학 : ");
		scanf("%3d", &Temp);
		TempData.SetMath(Temp);
		TempData.SetTotal(TempData.GetKor(), TempData.GetEng(), TempData.GetMath());
		TempData.SetAve(TempData.GetTotal());

		FindData->SetInfo(TempData);
		MainScreen();
		printf("수정 완료!\n");
	}
	else
	{
		MainScreen();
		printf("이름을 찾을 수 없습니다.\n");

	}



}

template<typename T>
inline void LinkedList<T>::DeleteStudent(LinkedList<T>* FindData)
{
	if (FindData != NULL&& FindData!=g_pTail)
	{

		LinkedList < T>* FrontNode = FindData->pPrev;
		LinkedList < T>* NextNode = FindData->pNext;
		if (FrontNode != NULL)
		{
			FrontNode->pNext = NextNode;
			NextNode->pPrev = FrontNode;
		}
		iNum--;
		delete(FindData);
		MainScreen();
		printf("삭제 완료.\n");
	}
	else
	{
		MainScreen();
		printf("이름을 찾을 수 없습니다.\n");
	}

}

template<typename T>
inline void LinkedList<T>::AddData()
{
	if (initCount == 0)
	{
		initCount++;
		g_pHead->SetNext(g_pTail);
		g_pTail->SetPrev(g_pHead);
	}
	T* DatatInfo = new T;
	int temp = 0;
	char* name = new char[4];
	printf("이름: ");
	scanf("%s", name);
	DatatInfo->SetName(name);
	printf("국어 : ");
	scanf("%d", &temp);
	DatatInfo->SetKor(temp);
	printf("영어 : ");
	scanf("%d", &temp);
	DatatInfo->SetEng(temp);
	printf("수학 : ");
	scanf("%d", &temp);
	DatatInfo->SetMath(temp);
	DatatInfo->SetNum();
	DatatInfo->SetTotal(DatatInfo->GetKor(), DatatInfo->GetEng(), DatatInfo->GetMath());
	DatatInfo->SetAve(DatatInfo->GetTotal());

	LinkedList<Student>* Linker = new LinkedList<Student>;
	Linker->SetInfo(*DatatInfo);
	g_pHead->Link(Linker);




}

template<typename T>
inline void LinkedList<T>::Swap(T a, T b)
{
	

}

template<typename T>
inline void LinkedList<T>::Sort()
{
	T  a = g_pTail->pPrev->GetInfo();
	int LoopCount = a.GetNum();
	for (int i = 0; i < LoopCount; ++i)
	{
		
		

		for (int j = 0; j < LoopCount - i - 1; ++j)
		{
			





		}
	}

}


