#include "pch.h"
#include "main.h"
#include "config.h"
#include "data.h"
#include "CC.h"
#include "assistant.h"
#include "slip_etc.h"
#include "delay.h"

static bool ifThreadRun = false;

//������Ҫ�߳�
void main::openMainThread()
{
	if (!ifThreadRun)
	{
		ifThreadRun = true;
		CC::run();
		Slip_etc::run();
		Assistant::run();
	}
}

//�ر������߳�
void main::closeAllThread()
{
	if (ifThreadRun)
	{
		ifThreadRun = false;
		CC::close();
		Slip_etc::close();
		Assistant::close();
	}
}

//���ð���ȫ����Ӧ

void main::run()
{
	Config::run();
	openMainThread();
}