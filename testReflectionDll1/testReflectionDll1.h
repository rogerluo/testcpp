// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� TESTREFLECTIONDLL1_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// TESTREFLECTIONDLL1_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef TESTREFLECTIONDLL1_EXPORTS
#define TESTREFLECTIONDLL1_API __declspec(dllexport)
#else
#define TESTREFLECTIONDLL1_API __declspec(dllimport)
#endif

// �����Ǵ� testReflectionDll1.dll ������
class TESTREFLECTIONDLL1_API CtestReflectionDll1 {
public:
	CtestReflectionDll1(void);
	// TODO: �ڴ�������ķ�����
};

extern TESTREFLECTIONDLL1_API int ntestReflectionDll1;

TESTREFLECTIONDLL1_API int fntestReflectionDll1(void);
