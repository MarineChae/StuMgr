#pragma once
#include<iostream>
#include<conio.h>
#include<random>
#include<time.h>
static int check = 0;
static int iNum = 0;
static int initCount = 0;
static char findname[4] = {};

#include"Student.h"
#include"Ect.h"
#include"LinkedList.h"


enum EnterData
{
	DATA_INITIALIZE = 0,
	DATA_OUTPUT = 1,
	DATA_SAVE = 2,
	DATA_ADD = 3,
	DATA_LOAD = 4,
	DATA_DELETE = 5,
	DATA_SEARCH = 6,
	DATA_MODIFIY = 7,
	DATA_SORT = 8,
	EXIT = 99
};


