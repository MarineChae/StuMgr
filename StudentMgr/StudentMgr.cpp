#define _CRT_SECURE_NO_WARNINGS
#include "define.h"




int main()
{


	

	bool running = true;
	srand(time(NULL));


	MainScreen();
	while (running)
	{


		printf("생성(0),출력(1),저장(2),추가(3),로드(4),삭제(5),검색(6),수정(7),정렬(8),종료(99) :");
		scanf("%d", &check);


		switch (check)
		{
		case DATA_INITIALIZE:

			g_pHead->init();

			break;

		case DATA_OUTPUT:
			MainScreen();
			g_pHead->Print();

			break;

		case DATA_SAVE:
			printf("덮어쓰기(1) 기존파일에 추가하기(2) : ");

			scanf("%d", &check);
			if (check == 1)
			{
				g_pHead->OverWriteData("StudendtList.dat");
				MainScreen();
				printf("덮어쓰기 완료!\n");

			}
			else if (check == 2)
			{
				g_pHead->SaveData("StudendtList.dat");
				MainScreen();
				printf("추가 저장 완료!\n");

			}
			else
			{
				MainScreen();
				printf("잘못 입력 하셨습니다.\n");
			}


			break;
		case DATA_ADD:

			printf("랜덤추가(1) 직접추가(2) : ");

			scanf("%d", &check);
			if (check == 1)
			{
				g_pHead->CreateData();
				if (initCount == 0)
					initCount++;
			}
			else
			{
				g_pHead->AddData();
				if (initCount == 0)
					initCount++;
			}


			MainScreen();
			printf("추가 되었습니다!\n");
			break;
		case DATA_LOAD:

			g_pHead->LoadData("StudendtList.dat");

			break;
		case DATA_DELETE:

			printf("전체삭제(1) 지정삭제(2) : ");
			scanf("%d", &check);
			if (check == 1)
			{
				g_pHead->DeleteAll();
			}
			else if (check == 2)
			{
				printf("삭제하려는 학생 이름을 입력 해 주세요. : ");
				scanf("%s", findname);
				g_pHead->DeleteStudent(g_pHead->Find(findname));
			}
			else
			{
				MainScreen();
				printf("잘못 입력 하셨습니다.\n");
			}

			break;

		case DATA_SEARCH:

			printf("검색하려는 학생 이름을 입력 해 주세요. : ");
			scanf("%s", findname);
			g_pHead->FindPrint(g_pHead->Find(findname));

			break;

		case DATA_MODIFIY:
			printf("수정하려는 학생 이름을 입력 해 주세요. : ");
			scanf("%s", findname);
			g_pHead->ModifyStudent(g_pHead->Find(findname));
			break;

		case DATA_SORT:


		/*	g_pHead->Sort();
			MainScreen();
			printf("정렬완료!\n");*/



			break;
		case EXIT:
			running = false;

			g_pHead->DeleteAll();
			MainScreen();
			printf("아무 버튼이나 누르면 프로그램을 종료합니다.\n");
			_getch();

			break;
		default:

			MainScreen();
			printf("잘못 입력하셨습니다.\n");
			break;
		}



	}

	return 0;
}

