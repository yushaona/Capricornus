// testConsole.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#pragma comment(lib,"advapi32.lib")
#pragma comment(lib,"psapi.lib")
#pragma comment(lib,"shell32.lib")
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"userenv.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "IPHLPAPI.lib")

#ifdef _DEBUG
#pragma comment(lib,"libuv_d.lib")
#else
#pragma comment(lib,"libuv.lib")
#endif

#include "uv.h"

int _tmain(int argc, _TCHAR* argv[])
{
	uv_loop_t *loop = (uv_loop_t *)malloc(sizeof(uv_loop_t));
	uv_loop_init(loop);

	printf("Now quitting.\n");
	uv_run(loop, UV_RUN_DEFAULT);

	uv_loop_close(loop);
	free(loop);
	getchar();
	return 0;
}

