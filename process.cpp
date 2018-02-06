#include <windows.h>
#include <stdio.h>

void main( void ) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	//char* cmdLine="cmd /C dir";
	//������� �������� � �������������� ��������� ������
	ZeroMemory( &si, sizeof(si) );
	//��������� ������ ��� si � �� ������������� ������
	si.cb = sizeof(si);
	// ������������� ������� ���� ��������� STARTUPINFO
	ZeroMemory( &pi, sizeof(pi) );
	//��������� ������ ��� pi � �� ������������� ������
	// ����������� �������� �������
	if( !CreateProcess("C:\\Windows\\notepad.exe", //����������� ������
			   NULL, //cmdLine, // ��������� ������ �� ������������
			   NULL, // ���������� �������� �� �����������
			   NULL, // ���������� ������ �� �����������
			   FALSE,// �������� ����������� ������������� �������� �� �����������
			   HIGH_PRIORITY_CLASS, // �� ��������� ���� (����������� ����)
			   NULL, // ������������ ���������� ��������� ��������
			   NULL, // ������������ ������� ���������� ��������
			   &si,  // ��������� �� ��������� STARTUPINFO
			   &pi ) // ��������� �� ��������� PROCESS_INFORMATION
	) {
	printf("System error code: %i\n",GetLastError());
	}
	//�������� ��������� ��������� ��������
	WaitForSingleObject( pi.hProcess, INFINITE );
	// �������� ������������ �������� � ���������� ������
	CloseHandle( pi.hProcess );
	CloseHandle( pi.hThread );
}