#include "stdafx.h"

int num;

int main(){

	std::cin >> num;
	{
		relations a = relations{ num,num };
		init(a);
		print_data(a);
		system("pause");
	}
	system("pause");
    return 0;
}

