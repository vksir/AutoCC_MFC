#include "pch.h"
#include "main.h"
#include "config.h"
#include "data.h"
#include "CC.h"
#include "assistant.h"
#include "slip_etc.h"
#include "delay.h"

//������Ҫ�߳�
void main::openMainThread()
{
	CC::run();
	Slip_etc::run();
	Assistant::run();
}

//�ر������߳�
void main::closeAllThread()
{
	CC::close();
	Slip_etc::close();
	Assistant::close();
}

//���ð���ȫ����Ӧ

void main::run()
{
	Config::run();
	openMainThread();
}