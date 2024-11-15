#include <Windows.h>
#include <winternl.h>
#include <ntstatus.h>
#include <stdio.h>

namespace HVM
{
	void InitVM();

	void* memcpy(void* dest, const void* src, size_t count);

	LPVOID VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);

	BOOL VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
}