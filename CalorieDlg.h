#include "AniDialog.h"

#pragma once


class CCalorieDlg : public CAniDialog
{
public:
	CCalorieDlg(CWnd* pParent = NULL);
	virtual ~CCalorieDlg();

	COleDateTime GetTimeFrom(void) const;
	COleDateTime GetTimeTo(void) const;
	void SetDates(COleDateTime tmFrom, COleDateTime tmTo);
	CUser* GetUser(void) const;
	void SetUser(CUser* pUser);

	enum { IDD = IDD_CALORIEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	
	virtual BOOL OnInitDialog(void);

    afx_msg void OnSelChange(void);

	double ComputeRunCalories(double dWeight, double dDist);
	double ComputeBikeCalories(double dWeight, double dDist, double dTime);
	double ComputeSwimCalories(double dWeight, double dDist, double dTime);
	double ComputeStrengthCalories(double dWeight, double dTime);

	DECLARE_MESSAGE_MAP()

	// data
	COleDateTime m_tmFrom;
	COleDateTime m_tmTo;
	CUser* m_pUser;
	WORKOUTARRAY m_arWorkouts;
};
