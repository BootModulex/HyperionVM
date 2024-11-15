#include <Windows.h>
#include <stdio.h>
#include "HyperionVM\HVM.hpp"

int main()
{
	HVM::InitVM();
	printf("=========HyperionVM=========\n");
	printf("Memory allocated at 0x%p\n", HVM::VirtualAlloc(NULL, 4096, MEM_COMMIT, PAGE_EXECUTE_READWRITE));
	system("pause");
}