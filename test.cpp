

#include "stdafx.h"
#include <assert.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include "oolua/oolua.h"
#include "oolua/overloadhelper.h"


class TestOverLoad
{
public:
	TestOverLoad(){}
	~TestOverLoad(){}
	void OverLoadFunc()
	{
		printf("OverLoadFunc1");
	}
	void OverLoadFunc(std::string a)
	{
		printf("OverLoadFunc2 par:%s\n",a.data());
	}
	void OverLoadFunc(int a)
	{
		printf("OverLoadFunc3 par:%d\n",a);
	}
	void OverLoadFunc(int a, int b)
	{
		printf("OverLoadFunc4  par:%d,%d\n",a,b);
	}
	void OverLoadFunc(int a, int b,int c)
	{
		printf("OverLoadFunc5  par:%d,%d,%d\n", a, b,c);
	}
private:

};

OOLUA_PROXY(TestOverLoad)



OOLUA_MEM_FUNC_OVERLOADS(
OverLoadFunc,
OOLUA_MEM_FUNC_OVERLOAD(void, OverLoadFunc)
OOLUA_MEM_FUNC_OVERLOAD(void, OverLoadFunc, std::string)
OOLUA_MEM_FUNC_OVERLOAD(void, OverLoadFunc, int)
OOLUA_MEM_FUNC_OVERLOAD(void, OverLoadFunc, int,int)
OOLUA_MEM_FUNC_OVERLOAD(void, OverLoadFunc, int, int,int)
)
OOLUA_PROXY_END

OOLUA_EXPORT_FUNCTIONS(TestOverLoad, OverLoadFunc)
OOLUA_EXPORT_FUNCTIONS_CONST(TestOverLoad)

int _tmain(int argc, _TCHAR* argv[])
{
	OOLUA::Script scr;
	scr.register_class<TestOverLoad>();
	scr.run_chunk(
	"local a=TestOverLoad.new();\n"
	"a:OverLoadFunc()\n"
	"a:OverLoadFunc(1)\n"
	"a:OverLoadFunc(\"teststr\")\n"
	"a:OverLoadFunc(2,3)\n"
	"a:OverLoadFunc(4,5,6)\n"
		); 
  return 0;
}

