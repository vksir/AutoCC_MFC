#include "pch.h"
#include "framework.h"
#include "AutoCC_MFC.h"
#include "AutoCC_MFCDlg.h"
#include "afxdialogex.h"
#include "config.h"

//����combobox�����б�
int damageBoxPara[][2] = { {54, 162}, {52, 150}, {48, 130}, {45, 120}, {45, 110} };
//
LPCTSTR lstr = NULL;

//����Damage�༭��Ŀؼ�����
void CAutoCCMFCDlg::loadDamageEditUI()
{
	if (cc_Config.damageIndex <= 4)				//һ�������嵵
	{
		//����damage�����༭��Ϊֻ��
		m_Edit_DamageA.SetReadOnly(true);
		m_Edit_DamageB.SetReadOnly(true);
		//����damage�����༭����ʾ���

		//Ϊdamage�����༭��combobox�����б��е�ֵ
		setTextInt(m_Edit_DamageA, damageBoxPara[cc_Config.damageIndex][0]);
		setTextInt(m_Edit_DamageB, damageBoxPara[cc_Config.damageIndex][1]);
	}
	else {										//�Զ���
		//����damage�����༭��Ϊ�ɱ༭
		m_Edit_DamageA.SetReadOnly(false);
		m_Edit_DamageB.SetReadOnly(false);
		//Ϊdamage�����༭��cc_config�е�cc����ֵ
		setTextInt(m_Edit_DamageA, cc_Config.damage[0]);
		setTextInt(m_Edit_DamageB, cc_Config.damage[1]);
	}
}

//�������еĿؼ�����
void CAutoCCMFCDlg::loadAllUI()
{
	ifRespond = false;
	{
		//����damage_comboBox�Ĳ���
		m_ComboBox.SetCurSel(cc_Config.damageIndex);
		loadDamageEditUI();
		//����track��safe�༭��Ĳ���
		setTextInt(m_Edit_TrackA, cc_Config.track[0]);
		setTextInt(m_Edit_TrackB, cc_Config.track[1]);
		setTextInt(m_Edit_SafeA, cc_Config.safe[0]);
		setTextInt(m_Edit_SafeB, cc_Config.safe[1]);
	}
	//������Ӧ
	ifRespond = true;
}

//��frame�е����ݴ洢��config��
void CAutoCCMFCDlg::configLoad()
{
	cc_Config.damageIndex = m_ComboBox.GetCurSel();
	cc_Config.damage[0] = getTextInt(m_Edit_DamageA);
	cc_Config.damage[1] = getTextInt(m_Edit_DamageB);

	cc_Config.track[0] = getTextInt(m_Edit_TrackA);
	cc_Config.track[1] = getTextInt(m_Edit_TrackB);

	cc_Config.safe[0] = getTextInt(m_Edit_SafeA);
	cc_Config.safe[1] = getTextInt(m_Edit_SafeB);
}

//ΪCEdit�ؼ�����int���͵��ı�
void CAutoCCMFCDlg::setTextInt(CEdit &mE, int a)
{
	CString cstr;
	cstr.Format(_T("%d"), a);
	mE.SetWindowTextW(cstr);
}

//��CEdit�ؼ����ı���int���Ͷ�ȡ����
int CAutoCCMFCDlg::getTextInt(CEdit &mE)
{
	CString l = NULL;
	mE.GetWindowTextW(l);
	return _ttoi((LPCTSTR)l);
}