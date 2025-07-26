#include "AniDialog.h"
#include "User.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CPrintToFileDlg : public CAniDialog
{
public:
	CPrintToFileDlg(CWnd* pParent = NULL);   
	virtual ~CPrintToFileDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_PRINTTOFILEDLG };

    COleDateTime GetTimeFrom(void) const;
    COleDateTime GetTimeTo(void) const;

    void SetTimeFrom(COleDateTime tm);
    void SetTimeTo(COleDateTime tm);

	void SetUser(CUser* pUser);
	CUser* GetUser(void) const;

protected:
	COleDateTime GetStartDate(void) const;
	COleDateTime GetEndDate(void) const;
	void FindExtremeDates(COleDateTime& rtmEarly, COleDateTime& rtmLate);

	COleDateTime GetCurStart(COleDateTime tmStart, int nTimePeriod, int nSpan);
	COleDateTime GetCurEnd(COleDateTime tmStart, int nTimePeriod, int nSpan);

	afx_msg void OnAllDatesClicked(void);
	afx_msg void OnBetweenDatesClicked(void);
	afx_msg void OnPrintToFileButtonClicked(void);

	afx_msg void OnFromDropDown(NMHDR* pNmHdr, LRESULT* pResult);
	afx_msg void OnToDropDown(NMHDR* pNmHdr, LRESULT* pResult);
	afx_msg void OnChangeFilename(void);

	virtual void DoDataExchange(CDataExchange* pDX); 

	bool PrintToFile(CString strFile, int nSpan, int nSize, COleDateTime tmStart, COleDateTime tmEnd, 
					 bool bPrintRun, bool bPrintBike, bool bPrintSwim, bool bPrintStrength);

	bool PrintWorkoutToFile(FILE* fp, CWorkout* pWorkout, bool bPrintRun, bool bPrintBike, bool bPrintSwim, bool bPrintStrength);
	CString PrintWorkoutToFile(CRunEZWorkout* pWorkout);
    CString PrintWorkoutToFile(CRunHardWorkout* pWorkout);
    CString PrintWorkoutToFile(CRunHillWorkout* pWorkout);
    CString PrintWorkoutToFile(CRunIntervalWorkout* pWorkout);
    CString PrintWorkoutToFile(CRunMiscWorkout* pWorkout);
    CString PrintWorkoutToFile(CRunNormalWorkout* pWorkout);
    CString PrintWorkoutToFile(CRunPoolWorkout* pWorkout);
    CString PrintWorkoutToFile(CRunTempoWorkout* pWorkout);
    CString PrintWorkoutToFile(CRunTreadmillWorkout* pWorkout);
    CString PrintWorkoutToFile(CBikeEZWorkout* pWorkout);
    CString PrintWorkoutToFile(CBikeHardWorkout* pWorkout);
    CString PrintWorkoutToFile(CBikeHillWorkout* pWorkout);
    CString PrintWorkoutToFile(CBikeIntervalWorkout* pWorkout);
    CString PrintWorkoutToFile(CBikeMiscWorkout* pWorkout);
    CString PrintWorkoutToFile(CBikeNormalWorkout* pWorkout);
    CString PrintWorkoutToFile(CBikeTrainerWorkout* pWorkout);
    CString PrintWorkoutToFile(CSwimDrillWorkout* pWorkout);
    CString PrintWorkoutToFile(CSwimEZWorkout* pWorkout);
    CString PrintWorkoutToFile(CSwimHardWorkout* pWorkout);
    CString PrintWorkoutToFile(CSwimIntervalWorkout* pWorkout);
    CString PrintWorkoutToFile(CSwimMiscWorkout* pWorkout);
    CString PrintWorkoutToFile(CSwimNormalWorkout* pWorkout);
    CString PrintWorkoutToFile(CSwimOpenWaterWorkout* pWorkout);
    CString PrintWorkoutToFile(CStrengthAbsWorkout* pWorkout);
    CString PrintWorkoutToFile(CStrengthMiscWorkout* pWorkout);
    CString PrintWorkoutToFile(CStrengthWeightsWorkout* pWorkout);
    CString PrintWorkoutToFile(CRaceRunWorkout* pWorkout);
    CString PrintWorkoutToFile(CRaceBikeWorkout* pWorkout);
    CString PrintWorkoutToFile(CRaceSwimWorkout* pWorkout);
    CString PrintWorkoutToFile(CRaceDuathlonWorkout* pWorkout);
    CString PrintWorkoutToFile(CRaceTriathlonWorkout* pWorkout);

    CString MakeText(CString strTag, int nVal, bool bTreatAsWind = false);
    CString MakeText(CString strTag, double dVal, bool bFormatAsTime = false);
    CString MakeText(CString strTag, COleDateTime tmVal);
	CString MakeText(CString strTag, CString strText);
	CString MakeText(CString strTag, bool bVal);
    CString MakeText(CString strTag, CCourseRun* pCourse);
    CString MakeText(CString strTag, CCourseBike* pCourse);
    CString MakeText(CString strTag, CCourseSwim* pCourse);
    CString MakeText(CString strTag, CCourseDuathlon* pCourse);
    CString MakeText(CString strTag, CCourseTriathlon* pCourse);
    CString MakeText(CString strTag, CLocationRun* pLocation);
    CString MakeText(CString strTag, CLocationBike* pLocation);
    CString MakeText(CString strTag, CLocationSwim* pLocation);
    CString MakeText(CString strTag, CLocationStrength* pLocation);
    CString MakeText(CString strTag, CShoesRun* pShoes);
    CString MakeText(CString strTag, CShoesBike* pShoes);
    CString MakeText(CString strTag, CBike* pBike);

	bool OpenEditor(CString strFile);

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CPrintToFileDlg)

    // data
	CUser* m_pUser;
    COleDateTime m_tmFrom;
    COleDateTime m_tmTo;
	CSkinProgress* m_pProgress;

	CStringFilterEdit m_edtFile;
};


BOOL PeekAndPump4(void);