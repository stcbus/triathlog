#pragma once

class CUpcomingWorkout
{
public:
    CUpcomingWorkout(void);
    ~CUpcomingWorkout();

    COleDateTime GetDate(void) const;
    CString GetLineOne(void) const;
    CString GetLineTwo(void) const;
	CString GetLineThree(void) const;

    void SetDate(COleDateTime tm);
    void SetLineOne(CString str);
    void SetLineTwo(CString str);
	void SetLineThree(CString str);

protected:
    // data
    COleDateTime m_tmDay;
    CString m_strLine1;
    CString m_strLine2;
	CString m_strLine3;
};
