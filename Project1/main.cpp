#include <iostream>
#include <windows.h>

using namespace std;

#define BUF_SIZE 1025
char szName[] = "NameOfMappingObject";    // �����ڴ������

int main()
{
	// ���������ļ����
	HANDLE hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // �����ļ����
		NULL,                    // Ĭ�ϰ�ȫ����
		PAGE_READWRITE,          // �ɶ���д
		0,                       // ��λ�ļ���С
		BUF_SIZE,                // ��λ�ļ���С
		szName                   // �����ڴ�����
	);

	// ӳ�仺������ͼ , �õ�ָ�����ڴ��ָ��
	char *pBuf = (char *)MapViewOfFile(
		hMapFile,            // �����ڴ�ľ��
		FILE_MAP_ALL_ACCESS, // �ɶ�д���
		0,
		0,
		BUF_SIZE
	);


	while (1)
	{
		cout << "input..." << endl;
		char szInfo[BUF_SIZE] = { 0 };

		gets_s(szInfo, 1025);  // ��ʵgets������ȫ
		strncpy(pBuf, szInfo, BUF_SIZE - 1);
		pBuf[BUF_SIZE - 1] = '\0';
	}
	// ����ļ�ӳ��
	UnmapViewOfFile(pBuf);
	//�ر��ڴ�ӳ���ļ�������
	CloseHandle(hMapFile);
	return 0;
}
