// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� TESTREFLECTIONDLL2_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// TESTREFLECTIONDLL2_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef TESTREFLECTIONDLL2_EXPORTS
#define TESTREFLECTIONDLL2_API __declspec(dllexport)
#else
#define TESTREFLECTIONDLL2_API __declspec(dllimport)
#endif

// �����Ǵ� testReflectionDll2.dll ������
class TESTREFLECTIONDLL2_API CtestReflectionDll2 {
public:
	CtestReflectionDll2(void);
	// TODO: �ڴ�������ķ�����
};

extern TESTREFLECTIONDLL2_API int ntestReflectionDll2;

TESTREFLECTIONDLL2_API int fntestReflectionDll2(void);
