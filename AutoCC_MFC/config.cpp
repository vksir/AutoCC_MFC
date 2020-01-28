#include "pch.h"
#include "config.h"
#include "data.h"
#include <fstream>

constexpr auto DAMAGE_INDEX = 2;
constexpr auto DAMAGE_A = 48;
constexpr auto DAMAGE_B = 130;
constexpr auto TRACK_A = 35;
constexpr auto TRACK_B = 200;
constexpr auto SAFE_A = 60;
constexpr auto SAFE_B = 200;

using std::ofstream;
using std::ifstream;
using std::ios;

//����ȫ�ֱ���
Config cc_Config;

Config::Config()
{
    setInitial();
}

//�����ļ���ʼ��
void Config::setInitial()
{
    damageIndex = DAMAGE_INDEX;
    damage[0] = DAMAGE_A;
    damage[1] = DAMAGE_B;
    track[0] = TRACK_A;
    track[1] = TRACK_B;
    safe[0] = SAFE_A;
    safe[1] = SAFE_B;
}

void Config::toParameter(Parameter &p)
{
    p.damage[0] = damage[0];
    p.damage[1] = damage[1];
    p.track[0] = track[0];
    p.track[1] = track[1];
    p.safe[0] = safe[0];
    p.safe[1] = safe[1];
}

//����������д���ļ�
void Config::fileWirte(Config p)
{
    // ��дģʽ���ļ�
    ofstream outfile;
    outfile.open("config.dat", ios::out | ios::binary);

    // ���ļ�д���û����������
    outfile.write((char*)&p, sizeof(p));

    // �رմ򿪵��ļ�
    outfile.close();
}
//���ļ��ж�ȡ��������
void Config::fileLoad()
{
    Config p;

    // �Զ�ģʽ���ļ�
    ifstream infile;
    infile.open("config.dat", ios::in | ios::binary); //�����ƶ���ʽ��

    //�Ƿ��ȡ�ɹ�
    if (infile) {
        //�ɹ���ȡ
        while (infile.read((char*)&p, sizeof(p))) { //һֱ�����ļ�����
            // int readedBytes = infile.gcount(); //���ղŶ��˶����ֽ�
        }
        cc_Config = p;

    }
    else {
        //��ȡʧ��
        cc_Config.setInitial();
        Config::fileWirte(cc_Config);
        Config::fileLoad();
    }

    // �رմ򿪵��ļ�
    infile.close();
}

void Config::run()
{
    Config::fileLoad();
    cc_Config.toParameter(cc_Parameter);
    data::loadAB(cc_Parameter.damage[0], cc_Parameter.damage[1]);
}

void Config::load()
{
    cc_Config.toParameter(cc_Parameter);
    data::loadAB(cc_Parameter.damage[0], cc_Parameter.damage[1]);
    Config::fileWirte(cc_Config);
}