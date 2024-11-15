#include <Windows.h>
#include <winternl.h>
#include <ntstatus.h>
#include <stdio.h>

namespace HVM
{
    HANDLE processHeap = NULL;

    void InitVM()
    {
        processHeap = GetProcessHeap();
    }

    void* memcpy(void* dest, const void* src, size_t count)
    {
        unsigned char* d = (unsigned char*)dest;
        const unsigned char* s = (const unsigned char*)src;
        for (size_t i = 0; i < count; ++i)
        {
            d[i] = s[i];
        }
        return dest;
    }

    LPVOID VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect)
    {
        if (flAllocationType & MEM_COMMIT)
        {
            LPVOID heapAllocation = malloc(dwSize);
            if (heapAllocation != NULL)
            {
                //TODO: rewrite this to not use malloc and instead allocate a page of MEM_IMAGE section so that our allocate sections look more legit.
                return heapAllocation;
            }
        }
        return NULL;
    }

    BOOL VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType)
    {
        free(lpAddress);
        return TRUE;
    }
}