#pragma once

#include "data.h"

class Config {
public:
    Config();
    void setInitial();
    void toParameter(Parameter &p);

    int damageIndex;
    int damage[2];
    int track[2];
    int safe[2];

    static void fileWirte(Config p);
    static void fileLoad();

    //�����ⲿ�ӿ�
    static void run();
    static void load();
};

//����ȫ�ֽ���������
extern Config cc_Config;