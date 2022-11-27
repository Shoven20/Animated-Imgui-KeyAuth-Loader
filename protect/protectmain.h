#pragma once
#include <Windows.h>
#include <tchar.h>
#include <TlHelp32.h>
#include <thread>
#include <ntstatus.h>
#include "lazy.h"
#include "..\xorstr.hpp"
#pragma comment(lib, "ntdll.lib")
extern "C"
{
	NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN OldValue);
	NTSTATUS NTAPI NtRaiseHardError(LONG ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask, PULONG_PTR Parameters, ULONG ValidResponseOptions, PULONG Response);
}

///////////////////////////
 
void mainprotect(); 

///////////////////////////