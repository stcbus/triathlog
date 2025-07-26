#include "StdAfx.h"
#include "Math.h"
#include "RunningLog.h"
#include "RunningLogDoc.h"
#include "CalendarCtl.h"
#include "DlgHelper.h"
#include "Util.h"
#include "BtnST.h"
#include "PRRunDlg.h"
#include "PRBikeDlg.h"
#include "PRSwimDlg.h"
#include "PRDuathlonDlg.h"
#include "PRTriathlonDlg.h"
#include "AboutDlg.h"
#include "DaySummarySheet.h"
#include "GoToDayDlg.h"
#include "DMFRunSummaryDlg.h"
#include "DMFBikeSummaryDlg.h"
#include "DMFSwimSummaryDlg.h"
#include "DMFStrengthSummaryDlg.h"
#include "DMFMultiSummaryDlg.h"
#include "ShoeSummaryRunDlg.h"
#include "ShoeSummaryBikeDlg.h"
#include "BikeSummaryDlg.h"
#include "TrackPRDlg.h"
#include "CurrentNotesDlg.h"
#include "UpcomingRaceDlg.h"
#include "UpcomingWorkoutDlg.h"
#include "InjuryTrackerDlg.h"
#include "PaceCalcDlg.h"
#include "HelpDlg.h"
#include "GetDatesDlg.h"
#include "AddUserDlg.h"
#include "AddCourseRunDlg.h"
#include "AddCourseBikeDlg.h"
#include "AddCourseSwimDlg.h"
#include "AddCourseDuathlonDlg.h"
#include "AddCourseTriathlonDlg.h"
#include "AddLocationRunDlg.h"
#include "AddLocationBikeDlg.h"
#include "AddLocationSwimDlg.h"
#include "AddLocationStrengthDlg.h"
#include "AddShoesRunDlg.h"
#include "AddShoesBikeDlg.h"
#include "AddBikeDlg.h"
#include "EditUserDlg.h"
#include "OpenUserDlg.h"
#include "OptionsDlg.h"
#include "CalorieDlg.h"
#include "WorkoutStartDlg.h"
#include "RunWorkoutEZDlg.h"
#include "RunWorkoutNormalDlg.h"
#include "RunWorkoutHardDlg.h"
#include "RunWorkoutTempoDlg.h"
#include "RunWorkoutIntervalDlg.h"
#include "RunWorkoutHillDlg.h"
#include "RunWorkoutTreadmillDlg.h"
#include "RunWorkoutPoolDlg.h"
#include "RunWorkoutMiscDlg.h"
#include "BikeWorkoutEZDlg.h"
#include "BikeWorkoutNormalDlg.h"
#include "BikeWorkoutHardDlg.h"
#include "BikeWorkoutIntervalDlg.h"
#include "BikeWorkoutHillDlg.h"
#include "BikeWorkoutTrainerDlg.h"
#include "BikeWorkoutMiscDlg.h"
#include "BikeWorkoutMountainBikeDlg.h"
#include "BikeWorkoutTimeTrialDlg.h"
#include "SwimWorkoutEZDlg.h"
#include "SwimWorkoutNormalDlg.h"
#include "SwimWorkoutHardDlg.h"
#include "SwimWorkoutIntervalDlg.h"
#include "SwimWorkoutOpenWaterDlg.h"
#include "SwimWorkoutDrillsDlg.h"
#include "SwimWorkoutMiscDlg.h"
#include "StrengthWorkoutAbsDlg.h"
#include "StrengthWorkoutWeightsDlg.h"
#include "StrengthWorkoutMiscDlg.h"
#include "RaceWorkoutRunDlg.h"
#include "RaceWorkoutBikeDlg.h"
#include "RaceWorkoutSwimDlg.h"
#include "RaceWorkoutDuathlonDlg.h"
#include "RaceWorkoutTriathlonDlg.h"
#include "RunEZWorkout.h"
#include "RunNormalWorkout.h"
#include "RunHardWorkout.h"
#include "RunTempoWorkout.h"
#include "RunIntervalWorkout.h"
#include "RunHillWorkout.h"
#include "RunTreadmillWorkout.h"
#include "RunPoolWorkout.h"
#include "RunMiscWorkout.h"
#include "BikeEZWorkout.h"
#include "BikeNormalWorkout.h"
#include "BikeHardWorkout.h"
#include "BikeIntervalWorkout.h"
#include "BikeHillWorkout.h"
#include "BikeTrainerWorkout.h"
#include "BikeMiscWorkout.h"
#include "BikeMountainBikeWorkout.h"
#include "BikeTimeTrialWorkout.h"
#include "SwimEZWorkout.h"
#include "SwimNormalWorkout.h"
#include "SwimHardWorkout.h"
#include "SwimIntervalWorkout.h"
#include "SwimOpenWaterWorkout.h"
#include "SwimDrillWorkout.h"
#include "SwimMiscWorkout.h"
#include "StrengthAbsWorkout.h"
#include "StrengthWeightsWorkout.h"
#include "StrengthMiscWorkout.h"
#include "RaceRunWorkout.h"
#include "RaceBikeWorkout.h"
#include "RaceSwimWorkout.h"
#include "RaceDuathlonWorkout.h"
#include "RaceTriathlonWorkout.h"
#include "Course.h"
#include "CourseRun.h"
#include "CourseBike.h"
#include "CourseSwim.h"
#include "CourseDuathlon.h"
#include "CourseTriathlon.h"
#include "Location.h"
#include "LocationRun.h"
#include "LocationBike.h"
#include "LocationSwim.h"
#include "LocationStrength.h"
#include "UpcomingRace.h"
#include "UpcomingWorkout.h"
#include "ConverterDlg.h"
#include "ExpandWnd.h"
#include "SwimPRSummaryDlg.h"
#include "TrackPRSummaryDlg.h"
#include "SplashScreenEx.h"
#include "MenuXP.h"
#include "FormulaDlg.h"
#include "VersionConverterDlg.h"
#include "MemDC.h"
#include "LocationSummaryRunDlg.h"
#include "LocationSummaryBikeDlg.h"
#include "LocationSummarySwimDlg.h"
#include "LocationSummaryStrengthDlg.h"
#include "RaceSummaryRunDlg.h"
#include "RaceSummaryBikeDlg.h"
#include "RaceSummarySwimDlg.h"
#include "RaceSummaryDuathlonDlg.h"
#include "RaceSummaryTriathlonDlg.h"
#include "DeleteWorkoutDlg.h"
#include "AddAllDataDlg.h"
#include "PEChartDlg.h"
#include "SearchDlg.h"
#include "Hyperlink.h"
#include "XMLSerializer.h"
#include "PrintToFileDlg.h"
#include "RunningLogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TRIATHLOGDRAW_3  // second type of drawing

IMPLEMENT_DYNCREATE(CRunningLogView, CView)

IMPLEMENT_MENUXP(CRunningLogView, CView)

BEGIN_MESSAGE_MAP(CRunningLogView, CView)
    ON_MENUXP_MESSAGES()

    ON_COMMAND(ID_FILE_OPENUSER, OnFileOpenUser)
    ON_COMMAND(ID_FILE_SAVEUSER, OnFileSaveUser)
    ON_COMMAND(ID_FILE_CLOSEUSER, OnFileCloseUser)
    ON_COMMAND(ID_FILE_CONVERT1, OnFileConvert1)
    ON_COMMAND(ID_FILE_CONVERT3, OnFileConvert3)
	ON_COMMAND(ID_FILE_PRINTTOFILE, OnFilePrintToFile)
    ON_COMMAND(ID_APP_EXIT, OnFileExit)
    ON_COMMAND(ID_OPTIONS_GOTODAY, OnOptionsGoToDay)
    ON_COMMAND(ID_VIEW_DAYSUMMARY, OnViewDaySummary)
    ON_COMMAND(ID_VIEW_WEEKSUMMARYRUN, OnViewWeekSummaryRun)
    ON_COMMAND(ID_VIEW_MONTHSUMMARYRUN, OnViewMonthSummaryRun)
    ON_COMMAND(ID_VIEW_FULLSUMMARYRUN, OnViewFullSummaryRun)
    ON_COMMAND(ID_VIEW_CUSTOMSUMMARYRUN, OnViewCustomSummaryRun)
    ON_COMMAND(ID_VIEW_WEEKSUMMARYBIKE, OnViewWeekSummaryBike)
    ON_COMMAND(ID_VIEW_MONTHSUMMARYBIKE, OnViewMonthSummaryBike)
    ON_COMMAND(ID_VIEW_FULLSUMMARYBIKE, OnViewFullSummaryBike)
    ON_COMMAND(ID_VIEW_CUSTOMSUMMARYBIKE, OnViewCustomSummaryBike)
    ON_COMMAND(ID_VIEW_WEEKSUMMARYSWIM, OnViewWeekSummarySwim)
    ON_COMMAND(ID_VIEW_MONTHSUMMARYSWIM, OnViewMonthSummarySwim)
    ON_COMMAND(ID_VIEW_FULLSUMMARYSWIM, OnViewFullSummarySwim)
    ON_COMMAND(ID_VIEW_CUSTOMSUMMARYSWIM, OnViewCustomSummarySwim)
    ON_COMMAND(ID_VIEW_WEEKSUMMARYSTRENGTH, OnViewWeekSummaryStrength)
    ON_COMMAND(ID_VIEW_MONTHSUMMARYSTRENGTH, OnViewMonthSummaryStrength)
    ON_COMMAND(ID_VIEW_FULLSUMMARYSTRENGTH, OnViewFullSummaryStrength)
    ON_COMMAND(ID_VIEW_CUSTOMSUMMARYSTRENGTH, OnViewCustomSummaryStrength)
    ON_COMMAND(ID_VIEW_WEEKSUMMARYMULTI, OnViewWeekSummaryMulti)
    ON_COMMAND(ID_VIEW_MONTHSUMMARYMULTI, OnViewMonthSummaryMulti)
    ON_COMMAND(ID_VIEW_FULLSUMMARYMULTI, OnViewFullSummaryMulti)
    ON_COMMAND(ID_VIEW_CUSTOMSUMMARYMULTI, OnViewCustomSummaryMulti)
    ON_COMMAND(ID_VIEW_SHOESUMMARYRUN, OnViewShoeSummaryRun)
    ON_COMMAND(ID_VIEW_SHOESUMMARYBIKE, OnViewShoeSummaryBike)
    ON_COMMAND(ID_VIEW_BIKESUMMARY, OnViewBikeSummary)
    ON_COMMAND(ID_VIEW_CURRENTNOTES, OnViewCurrentNotes)
    ON_COMMAND(ID_VIEW_PRSRUN, OnViewPersonalRecordsRun)
    ON_COMMAND(ID_VIEW_PRSBIKE, OnViewPersonalRecordsBike)
    ON_COMMAND(ID_VIEW_PRSSWIM, OnViewPersonalRecordsSwim)
    ON_COMMAND(ID_VIEW_PRSDUATHLON, OnViewPersonalRecordsDuathlon)
    ON_COMMAND(ID_VIEW_PRSTRIATHLON, OnViewPersonalRecordsTriathlon)
    ON_COMMAND(ID_VIEW_POOLPRS, OnViewPoolPersonalRecords)
    ON_COMMAND(ID_VIEW_TRACKPRS, OnViewTrackPersonalRecords)
    ON_COMMAND(ID_VIEW_GRAPHLARGE, OnViewGraphLarge)
    ON_COMMAND(ID_VIEW_GRAPHMEDIUM, OnViewGraphMedium)
    ON_COMMAND(ID_VIEW_GRAPHSMALL, OnViewGraphSmall)
    ON_COMMAND(ID_VIEW_LOCATIONSUMMARYRUN, OnViewLocationSummaryRun)
    ON_COMMAND(ID_VIEW_LOCATIONSUMMARYBIKE, OnViewLocationSummaryBike)
    ON_COMMAND(ID_VIEW_LOCATIONSUMMARYSWIM, OnViewLocationSummarySwim)
    ON_COMMAND(ID_VIEW_LOCATIONSUMMARYSTRENGTH, OnViewLocationSummaryStrength)
    ON_COMMAND(ID_VIEW_RACESUMMARYRUN, OnViewRaceSummaryRun)
    ON_COMMAND(ID_VIEW_RACESUMMARYBIKE, OnViewRaceSummaryBike)
    ON_COMMAND(ID_VIEW_RACESUMMARYSWIM, OnViewRaceSummarySwim)
    ON_COMMAND(ID_VIEW_RACESUMMARYDUATHLON, OnViewRaceSummaryDuathlon)
    ON_COMMAND(ID_VIEW_RACESUMMARYTRIATHLON, OnViewRaceSummaryTriathlon)
	ON_COMMAND(ID_VIEW_INJURYTRACKER, OnViewInjuryTracker)
    ON_COMMAND(ID_MISC_PACECALC, OnMiscPaceCalc)
    ON_COMMAND(ID_MISC_DISTCONVERT, OnMiscDistConvert)
	ON_COMMAND(ID_MISC_CALORIES, OnMiscCalories)
	ON_COMMAND(ID_MISC_SEARCH, OnMiscSearch)
    ON_COMMAND(ID_HELP_HELPTOPICS, OnHelpHelpTopics)
	ON_COMMAND(ID_HELP_DONATE, OnHelpDonate)
    ON_COMMAND(ID_APP_ABOUT, OnHelpAbout)
	ON_COMMAND(ID_OPTIONS_EDITUSERINFO, OnOptionsEditUser)
    ON_COMMAND(ID_OPTIONS_USEROPTIONS, OnOptionsUserOptions)
    ON_COMMAND(ID_CHILDPREVMONTH, OnPrevMonth)
    ON_COMMAND(ID_CHILDNEXTMONTH, OnNextMonth)
    ON_COMMAND(ID_OPTIONS_ADDSHOESRUN, OnOptionsAddShoesRun)
    ON_COMMAND(ID_OPTIONS_ADDSHOESBIKE, OnOptionsAddShoesBike)
    ON_COMMAND(ID_OPTIONS_ADDCOURSERUN, OnOptionsAddCourseRun)
    ON_COMMAND(ID_OPTIONS_ADDCOURSEBIKE, OnOptionsAddCourseBike)
    ON_COMMAND(ID_OPTIONS_ADDCOURSESWIM, OnOptionsAddCourseSwim)
    ON_COMMAND(ID_OPTIONS_ADDCOURSEDUATHLON, OnOptionsAddCourseDuathlon)
    ON_COMMAND(ID_OPTIONS_ADDCOURSETRIATHLON, OnOptionsAddCourseTriathlon)
    ON_COMMAND(ID_OPTIONS_ADDLOCATIONRUN, OnOptionsAddLocationRun)
    ON_COMMAND(ID_OPTIONS_ADDLOCATIONBIKE, OnOptionsAddLocationBike)
    ON_COMMAND(ID_OPTIONS_ADDLOCATIONSWIM, OnOptionsAddLocationSwim)
    ON_COMMAND(ID_OPTIONS_ADDLOCATIONSTRENGTH, OnOptionsAddLocationStrength)
    ON_COMMAND(ID_OPTIONS_ADDWORKOUT, OnOptionsAddWorkout)
    ON_COMMAND(ID_OPTIONS_DELETEWORKOUT, OnOptionsDeleteWorkout)
    ON_COMMAND(ID_OPTIONS_DELETEUPCOMINGWORKOUT, OnOptionsDeleteUpcomingWorkout)
    ON_COMMAND(ID_OPTIONS_DELETEUPCOMINGRACE, OnOptionsDeleteUpcomingRace)
    ON_COMMAND(ID_OPTIONS_ADDUPCOMINGRACE, OnOptionsAddUpcomingRace)
    ON_COMMAND(ID_OPTIONS_ADDUPCOMINGWORKOUT, OnOptionsAddUpcomingWorkout)
    ON_COMMAND(ID_OPTIONS_ADDBIKE, OnOptionsAddBike)
    ON_COMMAND(ID_OPTIONS_ADDALLDATA, OnOptionsAddMultipleItems)

    ON_UPDATE_COMMAND_UI(ID_FILE_OPENUSER, OnUpdateOpenUser)
    ON_UPDATE_COMMAND_UI(ID_FILE_SAVEUSER, OnUpdateSaveUser)
    ON_UPDATE_COMMAND_UI(ID_FILE_CLOSEUSER, OnUpdateCloseUser)
    ON_UPDATE_COMMAND_UI(ID_FILE_CONVERT1, OnUpdateConvert1)
    ON_UPDATE_COMMAND_UI(ID_FILE_CONVERT3, OnUpdateConvert3)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINTTOFILE, OnUpdatePrintToFile)
	ON_UPDATE_COMMAND_UI(ID_OPTIONS_EDITUSERINFO, OnUpdateEditUser)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_USEROPTIONS, OnUpdateUserOptions)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDSHOESRUN, OnUpdateAddShoesRun)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDSHOESBIKE, OnUpdateAddShoesBike)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDBIKE, OnUpdateAddBike)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDALLDATA, OnUpdateAddMultipleItems)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDCOURSERUN, OnUpdateAddCourseRun)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDCOURSEBIKE, OnUpdateAddCourseBike)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDCOURSESWIM, OnUpdateAddCourseSwim)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDCOURSEDUATHLON, OnUpdateAddCourseDuathlon)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDCOURSETRIATHLON, OnUpdateAddCourseTriathlon)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDLOCATIONRUN, OnUpdateAddLocationRun)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDLOCATIONBIKE, OnUpdateAddLocationBike)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDLOCATIONSWIM, OnUpdateAddLocationSwim)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDLOCATIONSTRENGTH, OnUpdateAddLocationStrength)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDWORKOUT, OnUpdateAddWorkout)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_DELETEWORKOUT, OnUpdateDeleteWorkout)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_DELETEUPCOMINGWORKOUT, OnUpdateDeleteUpcomingWorkout)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_DELETEUPCOMINGRACE, OnUpdateDeleteUpcomingRace)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDUPCOMINGRACE, OnUpdateAddUpcomingRace)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_ADDUPCOMINGWORKOUT, OnUpdateAddUpcomingWorkout)
    ON_UPDATE_COMMAND_UI(ID_OPTIONS_GOTODAY, OnUpdateGoToDay)
    ON_UPDATE_COMMAND_UI(ID_VIEW_DAYSUMMARY, OnUpdateDaySummary)
    ON_UPDATE_COMMAND_UI(ID_VIEW_WEEKSUMMARYRUN, OnUpdateWeekSummaryRun)
    ON_UPDATE_COMMAND_UI(ID_VIEW_MONTHSUMMARYRUN, OnUpdateMonthSummaryRun)
    ON_UPDATE_COMMAND_UI(ID_VIEW_FULLSUMMARYRUN, OnUpdateFullSummaryRun)
    ON_UPDATE_COMMAND_UI(ID_VIEW_CUSTOMSUMMARYRUN, OnUpdateCustomSummaryRun)
    ON_UPDATE_COMMAND_UI(ID_VIEW_WEEKSUMMARYBIKE, OnUpdateWeekSummaryBike)
    ON_UPDATE_COMMAND_UI(ID_VIEW_MONTHSUMMARYBIKE, OnUpdateMonthSummaryBike)
    ON_UPDATE_COMMAND_UI(ID_VIEW_FULLSUMMARYBIKE, OnUpdateFullSummaryBike)
    ON_UPDATE_COMMAND_UI(ID_VIEW_CUSTOMSUMMARYBIKE, OnUpdateCustomSummaryBike)
    ON_UPDATE_COMMAND_UI(ID_VIEW_WEEKSUMMARYSWIM, OnUpdateWeekSummarySwim)
    ON_UPDATE_COMMAND_UI(ID_VIEW_MONTHSUMMARYSWIM, OnUpdateMonthSummarySwim)
    ON_UPDATE_COMMAND_UI(ID_VIEW_FULLSUMMARYSWIM, OnUpdateFullSummarySwim)
    ON_UPDATE_COMMAND_UI(ID_VIEW_CUSTOMSUMMARYSWIM, OnUpdateCustomSummarySwim)
    ON_UPDATE_COMMAND_UI(ID_VIEW_WEEKSUMMARYSTRENGTH, OnUpdateWeekSummaryStrength)
    ON_UPDATE_COMMAND_UI(ID_VIEW_MONTHSUMMARYSTRENGTH, OnUpdateMonthSummaryStrength)
    ON_UPDATE_COMMAND_UI(ID_VIEW_FULLSUMMARYSTRENGTH, OnUpdateFullSummaryStrength)
    ON_UPDATE_COMMAND_UI(ID_VIEW_CUSTOMSUMMARYSTRENGTH, OnUpdateCustomSummaryStrength)
    ON_UPDATE_COMMAND_UI(ID_VIEW_WEEKSUMMARYMULTI, OnUpdateWeekSummaryMulti)
    ON_UPDATE_COMMAND_UI(ID_VIEW_MONTHSUMMARYMULTI, OnUpdateMonthSummaryMulti)
    ON_UPDATE_COMMAND_UI(ID_VIEW_FULLSUMMARYMULTI, OnUpdateFullSummaryMulti)
    ON_UPDATE_COMMAND_UI(ID_VIEW_CUSTOMSUMMARYMULTI, OnUpdateCustomSummaryMulti)    
    ON_UPDATE_COMMAND_UI(ID_VIEW_SHOESUMMARYRUN, OnUpdateShoeSummaryRun)
    ON_UPDATE_COMMAND_UI(ID_VIEW_SHOESUMMARYBIKE, OnUpdateShoeSummaryBike)
    ON_UPDATE_COMMAND_UI(ID_VIEW_BIKESUMMARY, OnUpdateBikeSummary)
    ON_UPDATE_COMMAND_UI(ID_VIEW_CURRENTNOTES, OnUpdateCurrentNotes)
    ON_UPDATE_COMMAND_UI(ID_VIEW_PRSRUN, OnUpdatePersonalRecordsRun)
    ON_UPDATE_COMMAND_UI(ID_VIEW_PRSBIKE, OnUpdatePersonalRecordsBike)
    ON_UPDATE_COMMAND_UI(ID_VIEW_PRSSWIM, OnUpdatePersonalRecordsSwim)
    ON_UPDATE_COMMAND_UI(ID_VIEW_PRSDUATHLON, OnUpdatePersonalRecordsDuathlon)
    ON_UPDATE_COMMAND_UI(ID_VIEW_PRSTRIATHLON, OnUpdatePersonalRecordsTriathlon)
    ON_UPDATE_COMMAND_UI(ID_VIEW_POOLPRS, OnUpdatePoolPersonalRecords)
    ON_UPDATE_COMMAND_UI(ID_VIEW_TRACKPRS, OnUpdateTrackPersonalRecords)
    ON_UPDATE_COMMAND_UI(ID_VIEW_GRAPHLARGE, OnUpdateViewGraphLarge)
    ON_UPDATE_COMMAND_UI(ID_VIEW_GRAPHMEDIUM, OnUpdateViewGraphMedium)
    ON_UPDATE_COMMAND_UI(ID_VIEW_GRAPHSMALL, OnUpdateViewGraphSmall)
    ON_UPDATE_COMMAND_UI(ID_VIEW_LOCATIONSUMMARYRUN, OnUpdateLocationSummaryRun)
    ON_UPDATE_COMMAND_UI(ID_VIEW_LOCATIONSUMMARYBIKE, OnUpdateLocationSummaryBike)
    ON_UPDATE_COMMAND_UI(ID_VIEW_LOCATIONSUMMARYSWIM, OnUpdateLocationSummarySwim)
    ON_UPDATE_COMMAND_UI(ID_VIEW_LOCATIONSUMMARYSTRENGTH, OnUpdateLocationSummaryStrength)
    ON_UPDATE_COMMAND_UI(ID_VIEW_RACESUMMARYRUN, OnUpdateRaceSummaryRun)
    ON_UPDATE_COMMAND_UI(ID_VIEW_RACESUMMARYBIKE, OnUpdateRaceSummaryBike)
    ON_UPDATE_COMMAND_UI(ID_VIEW_RACESUMMARYSWIM, OnUpdateRaceSummarySwim)
    ON_UPDATE_COMMAND_UI(ID_VIEW_RACESUMMARYDUATHLON, OnUpdateRaceSummaryDuathlon)
    ON_UPDATE_COMMAND_UI(ID_VIEW_RACESUMMARYTRIATHLON, OnUpdateRaceSummaryTriathlon)
	ON_UPDATE_COMMAND_UI(ID_VIEW_INJURYTRACKER, OnUpdateInjuryTracker)
    ON_UPDATE_COMMAND_UI(ID_MISC_PACECALC, OnUpdatePaceCalc)
	ON_UPDATE_COMMAND_UI(ID_MISC_CALORIES, OnUpdateCalories)
	ON_UPDATE_COMMAND_UI(ID_MISC_SEARCH, OnUpdateSearch)
    ON_UPDATE_COMMAND_UI(ID_HELP_HELPTOPICS, OnUpdateHelpTopics)
	ON_UPDATE_COMMAND_UI(ID_HELP_DONATE, OnUpdateDonate)
    ON_UPDATE_COMMAND_UI(ID_APP_ABOUT, OnUpdateAbout)

    ON_WM_TIMER()
    ON_WM_KEYDOWN()
    ON_WM_LBUTTONDOWN()
    ON_WM_RBUTTONDOWN()
    ON_WM_LBUTTONDBLCLK()
    ON_WM_ERASEBKGND()
    ON_WM_SIZE()
    ON_WM_MBUTTONDOWN()
END_MESSAGE_MAP()


CRunningLogView::CRunningLogView()
{
    m_pCalendar = new CCalendarCtl(this);
    SetUserOpen(false);
    SetModified(false);
    SetLastMouseDay(-1);

    // may need to move
    m_pExpando = new CExpandWnd(this, m_pCalendar);

    m_pDCBmp = NULL;
    m_pBmpOld = NULL;

    m_pButtonNext = NULL;
    m_pButtonPrev = NULL;
}


CRunningLogView::~CRunningLogView()
{
    if(NULL != m_pCalendar)
    {
        delete m_pCalendar;
        m_pCalendar = NULL;
    }

    if(NULL != m_pButtonPrev)
    {
        delete m_pButtonPrev;
        m_pButtonPrev = NULL;
    }
    if(NULL != m_pButtonNext)
    {
        delete m_pButtonNext;
        m_pButtonNext = NULL;
    }
    if(NULL != m_pExpando)
    {
        delete m_pExpando;
        m_pExpando = NULL;
    }
    if(NULL != m_pDCBmp)
    {
        m_pDCBmp->SelectObject(m_pBmpOld);
        delete m_pDCBmp;
        m_pDCBmp = NULL;
    }
}


CRunningLogView* CRunningLogView::GetView(void)
{
    CRunningLogView* pRet = NULL;

    CWinApp* pApp = AfxGetApp();
    if(NULL != pApp)
    {
        CFrameWnd* pFrame = (CFrameWnd*)pApp->m_pMainWnd;
        if(NULL != pFrame)
        {
            CView* pView = pFrame->GetActiveView();
            if(NULL != pView)
            {
                if(pView->IsKindOf(RUNTIME_CLASS(CRunningLogView)))
                {
                    pRet = (CRunningLogView*)pView;
                }
            }
        }
    }

    return pRet;
}


BOOL CRunningLogView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}


#ifdef TRIATHLOGDRAW_1

void CRunningLogView::OnDraw(CDC* pDC)
{
	CRunningLogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

    if((NULL == m_pCalendar) || (NULL == pDC))
    {
        CUtil::Fatal("Can't draw calendar (reason: NULL) in CRunningLogView::OnDraw");
        return;
    }

    CRect rc;
    GetClientRect(&rc);

    CMemDC dcMem(pDC);

    CMemDC* pNewMemDC = new CMemDC(&dcMem);
    if(NULL != pNewMemDC)
    {
        pNewMemDC->SelectObject(&m_bmpGrad);
        delete pNewMemDC;
    }

    int nXLOffset;
    int nXROffset;
    int nYTOffset;
    int nYBOffset;
    GetOffsets(&nXLOffset, &nXROffset, &nYTOffset, &nYBOffset);

    m_pCalendar->DrawCalendar(&dcMem, CRect(nXLOffset, nYTOffset, rc.Width() - nXROffset, rc.Height() - nYBOffset));
 
    CSize szBox = m_pCalendar->GetBoxSize();
    int nMiddle = rc.Width() - (nXROffset / 2);

    CRect rcRectMonth(nMiddle - (szBox.cx / 2), (nYTOffset - szBox.cy) / 2, nMiddle + (szBox.cx / 2), (nYTOffset + szBox.cy) / 2);
    m_pCalendar->DrawMonthSummary(&dcMem, rcRectMonth);

    CRect rcRectWeek(nMiddle - (szBox.cx / 2), nYTOffset, nMiddle + (szBox.cx / 2), rc.Height() - nYBOffset);
    m_pCalendar->DrawWeekSummaries(&dcMem, rcRectWeek);

    CRect rcText(nXLOffset, 0, rc.Width() - nXROffset, nYTOffset);

    int nMode = dcMem.SetBkMode(TRANSPARENT);
    CFont* pfntOrig = dcMem.SelectObject(GetTitleFont());
    COLORREF crOrig = dcMem.SetTextColor(RGB(10, 10, 10));

    COleDateTime tmTime = GetCurrentDate();
    CString strText;
    strText.Format("%s %d", CUtil::MonthToString(tmTime.GetMonth()), tmTime.GetYear());

    COLORREF cr = dcMem.SetTextColor(::GetSysColor(COLOR_3DSHADOW));
    CRect rcNew = rcText + CPoint(1, 1);
    dcMem.DrawText(strText, &rcNew, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    dcMem.SetTextColor(RGB(220, 220, 220));
    CRect rcNew2 = rcText - CPoint(1, 1);
    dcMem.DrawText(strText, &rcNew2, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    dcMem.SetTextColor(cr);
    dcMem.DrawText(strText, &rcText, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    dcMem.SetBkMode(nMode);
    dcMem.SelectObject(pfntOrig);
    dcMem.SetTextColor(crOrig);

    SetWindowTitle();
}
#endif

#ifdef TRIATHLOGDRAW_2

void CRunningLogView::OnDraw(CDC* pDC)
{
	CRunningLogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

    if((NULL == m_pCalendar) || (NULL == pDC))
    {
        CUtil::Fatal("Can't draw calendar (reason: NULL) in CRunningLogView::OnDraw");
        return;
    }

    CRect rc;
    GetClientRect(&rc);


    CDC dc2;
    dc2.CreateCompatibleDC(pDC);
    CBitmap bmp;
    bmp.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
    CBitmap* pbmpOrig = dc2.SelectObject(&bmp);

    CDC dc3;
    dc3.CreateCompatibleDC(pDC);
    CBitmap* pbmpOrig2 = dc3.SelectObject(&m_bmpGrad);
 
    dc2.BitBlt(0, 0, rc.Width(), rc.Height(), &dc3, 0, 0, SRCCOPY);

    int nXLOffset;
    int nXROffset;
    int nYTOffset;
    int nYBOffset;
    GetOffsets(&nXLOffset, &nXROffset, &nYTOffset, &nYBOffset);

    m_pCalendar->DrawCalendar(&dc2, CRect(nXLOffset, nYTOffset, rc.Width() - nXROffset, rc.Height() - nYBOffset));
 
    CSize szBox = m_pCalendar->GetBoxSize();
    int nMiddle = rc.Width() - (nXROffset / 2);

    CRect rcRectMonth(nMiddle - (szBox.cx / 2), (nYTOffset - szBox.cy) / 2, nMiddle + (szBox.cx / 2), (nYTOffset + szBox.cy) / 2);
    m_pCalendar->DrawMonthSummary(&dc2, rcRectMonth);

    CRect rcRectWeek(nMiddle - (szBox.cx / 2), nYTOffset, nMiddle + (szBox.cx / 2), rc.Height() - nYBOffset);
    m_pCalendar->DrawWeekSummaries(&dc2, rcRectWeek);

    CRect rcText(nXLOffset, 0, rc.Width() - nXROffset, nYTOffset);

    int nMode = dc2.SetBkMode(TRANSPARENT);
    CFont* pfntOrig = dc2.SelectObject(GetTitleFont());
    COLORREF crOrig = dc2.SetTextColor(RGB(10, 10, 10));

    COleDateTime tmTime = GetCurrentDate();
    CString strText;
    strText.Format("%s %d", CUtil::MonthToString(tmTime.GetMonth()), tmTime.GetYear());

    COLORREF cr = dc2.SetTextColor(::GetSysColor(COLOR_3DSHADOW));
    CRect rcNew = rcText + CPoint(1, 1);
    dc2.DrawText(strText, &rcNew, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    dc2.SetTextColor(RGB(220, 220, 220));
    CRect rcNew2 = rcText - CPoint(1, 1);
    dc2.DrawText(strText, &rcNew2, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    dc2.SetTextColor(cr);
    dc2.DrawText(strText, &rcText, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    dc2.SetBkMode(nMode);
    dc2.SelectObject(pfntOrig);
    dc2.SetTextColor(crOrig);

    pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &dc2, 0, 0, SRCCOPY);

    dc2.SelectObject(pbmpOrig);
    dc3.SelectObject(pbmpOrig2);

    SetWindowTitle();
}
#endif


#ifdef TRIATHLOGDRAW_3

void CRunningLogView::OnDraw(CDC* pDC)
{
	CRunningLogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

    if((NULL == m_pCalendar) || (NULL == pDC))
    {
        CUtil::Fatal("Can't draw calendar (reason: NULL) in CRunningLogView::OnDraw");
        return;
    }

    CRect rc;
    GetClientRect(&rc);

    CMemDC dcMem(pDC);

    dcMem.BitBlt(0, 0, rc.Width(), rc.Height(), m_pDCBmp, 0, 0, SRCCOPY);

    int nXLOffset;
    int nXROffset;
    int nYTOffset;
    int nYBOffset;
    GetOffsets(&nXLOffset, &nXROffset, &nYTOffset, &nYBOffset);

    m_pCalendar->DrawCalendar(&dcMem, CRect(nXLOffset, nYTOffset, rc.Width() - nXROffset, rc.Height() - nYBOffset));
 
    CSize szBox = m_pCalendar->GetBoxSize();
    int nMiddle = rc.Width() - (nXROffset / 2);

    CRect rcRectMonth(nMiddle - (szBox.cx / 2), (nYTOffset - szBox.cy) / 2, nMiddle + (szBox.cx / 2), (nYTOffset + szBox.cy) / 2);
    m_pCalendar->DrawMonthSummary(&dcMem, rcRectMonth);

    CRect rcRectWeek(nMiddle - (szBox.cx / 2), nYTOffset, nMiddle + (szBox.cx / 2), rc.Height() - nYBOffset);
    m_pCalendar->DrawWeekSummaries(&dcMem, rcRectWeek);

    CRect rcText(nXLOffset, 0, rc.Width() - nXROffset, nYTOffset);

    int nMode = dcMem.SetBkMode(TRANSPARENT);
    CFont* pfntOrig = dcMem.SelectObject(GetTitleFont());
    COLORREF crOrig = dcMem.SetTextColor(RGB(10, 10, 10));

    COleDateTime tmTime = GetCurrentDate();
    CString strText;
    strText.Format("%s %d", CUtil::MonthToString(tmTime.GetMonth()), tmTime.GetYear());

    COLORREF cr = dcMem.SetTextColor(::GetSysColor(COLOR_3DSHADOW));
    CRect rcNew = rcText + CPoint(1, 1);
    dcMem.DrawText(strText, &rcNew, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    dcMem.SetTextColor(RGB(220, 220, 220));
    CRect rcNew2 = rcText - CPoint(1, 1);
    dcMem.DrawText(strText, &rcNew2, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    dcMem.SetTextColor(cr);
    dcMem.DrawText(strText, &rcText, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    dcMem.SetBkMode(nMode);
    dcMem.SelectObject(pfntOrig);
    dcMem.SetTextColor(crOrig);

//    dc3.SelectObject(pbmpOrig2);

    SetWindowTitle();
}
#endif

void CRunningLogView::OnInitialUpdate(void)
{
    CView::OnInitialUpdate();

    CMenuXP::SetXPLookNFeel(this);

    SetDoingContextMenu(false);

    CWnd* pWnd = AfxGetMainWnd();
    if(NULL != pWnd)
    {
        pWnd->ShowWindow(SW_HIDE);
    }

    SetWindowTitle();

    AfxEnableControlContainer();

    CRect rc;
    GetClientRect(&rc);
    MakeGradient(rc.Width(), rc.Height());

    int nXLOffset;
    int nXROffset;
    int nYTOffset;
    int nYBOffset;
    GetOffsets(&nXLOffset, &nXROffset, &nYTOffset, &nYBOffset);
    
    int nCalLength = rc.Width() - nXROffset - nXLOffset;

    CRect rcButton(nXLOffset + (nCalLength / 20), nYTOffset / 3, nXLOffset + (nCalLength / 5), 2 * nYTOffset / 3);
    m_pButtonPrev = new CButtonST;
    if(NULL != m_pButtonPrev)
    {
        m_pButtonPrev->Create("Last Month", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_ICON | BS_FLAT, rcButton, this, ID_CHILDPREVMONTH);
        m_pButtonPrev->SetFont(GetAnnotationFont());

        m_pButtonPrev->SetBitmaps(IDB_LEFTARROW, RGB(255, 0, 0), IDB_LEFTARROWGRAY, RGB(255, 255, 255));

        m_pButtonPrev->SetFlat(false);
        m_pButtonPrev->SetAlign(CButtonST::ST_ALIGN_HORIZ);

        SetButtonColors(m_pButtonPrev);
    }

    rcButton.OffsetRect(3 * nCalLength / 4, 0);
    m_pButtonNext = new CButtonST;
    if(NULL != m_pButtonNext)
    {
        m_pButtonNext->Create("Next Month", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_ICON | BS_FLAT, rcButton, this, ID_CHILDNEXTMONTH);
        m_pButtonNext->SetFont(GetAnnotationFont());

        m_pButtonNext->SetBitmaps(IDB_RIGHTARROW, RGB(255, 0, 0), IDB_RIGHTARROWGRAY, RGB(255, 255, 255));

        m_pButtonNext->SetFlat(false);
        m_pButtonNext->SetAlign(CButtonST::ST_ALIGN_HORIZ_RIGHT);

        SetButtonColors(m_pButtonNext);
    }

    AdjustTitleFontSize();

    COleDateTime tmCur = GetCurrentDate();
    COleDateTime tmFirst = CUtil::GetFirstVisibleDay(tmCur, GetFirstDayOfWeek());
    int nInitialHighlight = CUtil::GetNumberOfDaysLaterThan(tmCur, tmFirst) + 1;
    SetHighlightDay(nInitialHighlight);

    m_nTimerID = (int)SetTimer(TIMER1_ID, 1000, NULL);

    if(NULL != pWnd)
    {
        CRect rc(0, 0, 1000, 750);
        pWnd->MoveWindow(&rc);
        pWnd->CenterWindow(GetDesktopWindow());
    }
}


void CRunningLogView::OnTimer(UINT unID)
{
	CString strFileToOpen;

    if(TIMER1_ID == unID)
    {
        KillTimer(m_nTimerID);
        CView::OnTimer(unID);

        CSplashScreenEx* pSplashEx = NULL;

        CRunningLogApp* pApp = (CRunningLogApp*)AfxGetApp();
        if(NULL != pApp)
        {
            /*
            CSplashThread* pSplashThread = pApp->GetSplashThread();
            if(NULL != pSplashThread)
            {
                pSplashThread->HideSplash();
            }
            */
            pSplashEx = pApp->GetSplashEx();
            if(NULL != pSplashEx)
            {
                pSplashEx->SetText("Drawing...");
                Sleep(CUtil::GetSplashSleep());
            }

			strFileToOpen = pApp->GetFileToOpen();
        }

        CWnd* pWnd = AfxGetMainWnd();
        if(NULL != pWnd)
        {
            pWnd->ShowWindow(SW_SHOW);
        }

        if(NULL != pSplashEx)
        {
            pSplashEx->SetText("Creating Dialog...");
            Sleep(CUtil::GetSplashSleep());
            pSplashEx->Hide();
        }

		MakeOpenUserDialog(strFileToOpen);
    }
}


void CRunningLogView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    int nInc = 0;
    
    switch(nChar)
    {
    case VK_LEFT:
        {
            nInc = -1;
            break;
        }

    case VK_RIGHT:
        {
            nInc = 1;
            break;
        }

    case VK_UP:
        {
            nInc = -7;
            break;
        }
        
    case VK_DOWN:
        {
            nInc = 7;
            break;
        }

    case VK_RETURN:
        {
            if(MakeCorrectDialog())
            {
                InvalidateRect(NULL);
            }
            break;
        }

    default:
        {
            break;
        }
    }

    int nDay = GetHighlightDay();
    bool fDoNothing = false;

    int nWeeks = CUtil::GetNumWeeks(GetCurrentDate(), GetFirstDayOfWeek());
    if((nDay + nInc <= 0) || (nDay + nInc > 7 * nWeeks))
    {
        fDoNothing = true;
    }

    if((NO_SELECTION == nDay) || (0 == nInc) || (fDoNothing))
    {
        return;
    }

    CRect rcInvalidate = GetDayRect(nDay);
    rcInvalidate.InflateRect(1, 1);
    InvalidateRect(&rcInvalidate);

    SetHighlightDay(nDay + nInc);
    AdjustHighlightDay();

    rcInvalidate = GetDayRect(GetHighlightDay());
    rcInvalidate.InflateRect(1, 1);
    InvalidateRect(&rcInvalidate);
}

    
BOOL CRunningLogView::OnEraseBkgnd(CDC* pDC)
{
    if(NULL == pDC)
    {
        CUtil::Fatal("Bad parameter to CRunningLogView::OnEraseBkgnd");
        return false;
    }

    CRect rect;
    GetClientRect(&rect);

    CDC dc2;
    dc2.CreateCompatibleDC(pDC);
    CBitmap* pbmpOrig = dc2.SelectObject(&m_bmpGrad);

    pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dc2, 0, 0, SRCCOPY);
    dc2.SelectObject(pbmpOrig);

    return true;
}


void CRunningLogView::OnSize(UINT nType, int cx, int cy)
{
    CView::OnSize(nType, cx, cy);

    MakeGradient(cx, cy);

    int nXLOffset;
    int nXROffset;
    int nYTOffset;
    int nYBOffset;
    GetOffsets(&nXLOffset, &nXROffset, &nYTOffset, &nYBOffset);
    
    CRect rc;
    GetClientRect(&rc);
    int nCalLength = rc.Width() - nXROffset - nXLOffset;
    CRect rcButton(nXLOffset + (nCalLength / 20), nYTOffset / 3, nXLOffset + (nCalLength / 5), 2 * nYTOffset / 3);
    
    // don't allow the buttons to shrink smaller than their icons
    if(rcButton.Height() <= 40)
    {
        int n = 40 - rcButton.Height();
        int nExtraUp = (n % 2 == 1) ? 1 : 0;
        rcButton.top -= (n / 2) + nExtraUp;
        rcButton.bottom += (n / 2);
    }

    if(m_pButtonPrev)
    {
        m_pButtonPrev->MoveWindow(&rcButton);
    }

    rcButton.OffsetRect(3 * nCalLength / 4, 0);
    if(m_pButtonNext)
    {
        m_pButtonNext->MoveWindow(&rcButton);
    }

    AdjustTitleFontSize();
    Invalidate();
}


void CRunningLogView::OnLButtonDown(UINT nFlags, CPoint point)
{
    CRect rcInvalidate(0, 0, 0, 0);
    
    rcInvalidate = GetDayRect(GetHighlightDay());
    rcInvalidate.InflateRect(1, 1);
    InvalidateRect(&rcInvalidate);

    int nDay = HitTest(point);
    SetHighlightDay(nDay);

    rcInvalidate = GetDayRect(GetHighlightDay());
    rcInvalidate.InflateRect(1, 1);
    InvalidateRect(&rcInvalidate);
}


void CRunningLogView::OnMButtonDown(UINT nFlags, CPoint point)
{
    if(IsDoingContextMenu())
    {
        return;
    }

    CRect rcInvalidate(0, 0, 0, 0);

    rcInvalidate = GetDayRect(GetHighlightDay());
    rcInvalidate.InflateRect(1, 1);
    InvalidateRect(&rcInvalidate);

    int nDay = HitTest(point);
    SetHighlightDay(nDay);

    rcInvalidate = GetDayRect(GetHighlightDay());
    rcInvalidate.InflateRect(1, 1);
    InvalidateRect(&rcInvalidate);

    SetLastMouseDay(nDay);
    if(nDay < 40)
    {
        CRect rc = GetDayRect(nDay);
        COleDateTime tmCur = CUtil::GetFirstVisibleDay(GetCurrentDate(), GetFirstDayOfWeek());
        COleDateTime tmMouse = CUtil::OffsetDay(tmCur, nDay - 1);
        if(NULL != m_pExpando)
        {
            m_pExpando->Show(tmMouse, GetHighlightColor(), rc, rc.TopLeft(), 0, 3, 3);
        }
    }
}


void CRunningLogView::OnRButtonDown(UINT nFlags, CPoint point)
{
    CRect rcInvalidate(0, 0, 0, 0);
    
    rcInvalidate = GetDayRect(GetHighlightDay());
    rcInvalidate.InflateRect(1, 1);
    InvalidateRect(&rcInvalidate);

    int nDay = HitTest(point);
    SetHighlightDay(nDay);

    rcInvalidate = GetDayRect(GetHighlightDay());
    rcInvalidate.InflateRect(1, 1);
    InvalidateRect(&rcInvalidate);

    CMenu menu;
    menu.LoadMenu(IDR_CONTEXTMENU);
    CMenu* pPopupMenu = menu.GetSubMenu(0);
    ClientToScreen(&point);
    if(NULL != pPopupMenu)
    {
        MakeMenuReady(pPopupMenu);
        SetDoingContextMenu(true);
        pPopupMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
        SetDoingContextMenu(false);
    }
}


void CRunningLogView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    CRect rcInvalidate(0, 0, 0, 0);
    
    rcInvalidate = GetDayRect(GetHighlightDay());
    rcInvalidate.InflateRect(1, 1);
    InvalidateRect(&rcInvalidate);

    int nDay = HitTest(point);
    SetHighlightDay(nDay);

    rcInvalidate = GetDayRect(nDay);
    rcInvalidate.InflateRect(1, 1);
    InvalidateRect(&rcInvalidate);
    
    if(MakeCorrectDialog())
    {
        InvalidateRect(NULL);
    }
}


void CRunningLogView::DoRegistryData(bool fSave)
{
    CUser* pUser = GetUser();
    CRunningLogApp* pApp = (CRunningLogApp*)AfxGetApp();
    if((NULL == pUser) || (NULL == pApp))
    {
        return;
    }

    CString str = "TriathLog\\";
    str += pUser->GetFirstName();
    str += " ";
    str += pUser->GetLastName();
    CString strWidth = "Width";
    CString strHeight = "Height";

    if(fSave)
    {
        CRect rc;
        AfxGetMainWnd()->GetWindowRect(&rc);
        pApp->WriteProfileInt(str, strWidth, rc.Width());
        pApp->WriteProfileInt(str, strHeight, rc.Height());
    }
    else
    {
        int iWidth = pApp->GetProfileInt(str, strWidth, 1000);
        int iHeight = pApp->GetProfileInt(str, strHeight, 750);
        CRect rc(0, 0, iWidth, iHeight);
        CWnd* pWnd = AfxGetMainWnd();
        if(NULL != pWnd)
        {
            pWnd->ShowWindow(SW_HIDE);
            pWnd->MoveWindow(&rc);
            pWnd->CenterWindow(GetDesktopWindow());
            pWnd->ShowWindow(SW_SHOW);
        }
    }
}


void CRunningLogView::OnFileOpenUser(void)
{
	MakeOpenUserDialog();
}


void CRunningLogView::OnFileSaveUser(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CUtil::SaveXML(pUser);
        SetModified(false);
        DoRegistryData(true);
    }
}


void CRunningLogView::OnFileCloseUser(void)
{
    bool fClose = true;
    if(IsModified())
    {
        fClose = PromptToSave();
    }

    if(fClose)
    {
        SetUser(new CUser);
        SetModified(false);
        SetUserOpen(false);
     
        CRect rc;
        GetClientRect(&rc);
        MakeGradient(rc.Width(), rc.Height());
        SetButtonColors(m_pButtonPrev);
        SetButtonColors(m_pButtonNext);
        AdjustTitleFontSize();
        InvalidateRect(NULL);

        CWnd* pWnd = AfxGetMainWnd();
        if(NULL != pWnd)
        {
            pWnd->ShowWindow(SW_HIDE);
            CRect rc(0, 0, 1000, 750);
            pWnd->MoveWindow(&rc);
            pWnd->CenterWindow(GetDesktopWindow());
            pWnd->ShowWindow(SW_SHOW);
        }
    }

    SetWindowTitle();
}


void CRunningLogView::OnFileConvert1(void)
{
    CVersionConverterDlg dlg;
    dlg.DoModal();
}


void CRunningLogView::OnFileConvert3(void)
{
    CString strFilter = "RunningLog 3.x Files (*.xml)|*.xml||";
    CFileDialog dlg(true, ".xml", NULL, OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, strFilter, this); 
    if(IDOK == dlg.DoModal())
    {
        CString strFile = dlg.GetPathName();

		CXMLSerializer xmlReader;
		CUser* pUser = new CUser;
		bool fOpen = xmlReader.ReadFile(pUser, strFile);

		bool fSaved = CUtil::SaveXML(pUser);

		if((true == fOpen) && (true == fSaved))
		{
			CString str = "The conversion was successful!  The new file has been saved to the same directory as TriathLog with a .tlg extension, and will open momentarily";
			AfxMessageBox(str);

			// open the file up
			CString strOpen = CUtil::GetExeDirectory();
			strFile = strFile.Right(strFile.GetLength() - strFile.ReverseFind('\\') - 1);
			strFile = strFile.Left(strFile.GetLength() - 4);
			strFile += ".tlg";

			strOpen += strFile;

			MakeOpenUserDialog(strOpen);
		}
		else
		{
			AfxMessageBox("There was a problem with the file, and conversion was not successful");
		}

		if(NULL != pUser)
		{
			delete pUser;
		}
	}
}


void CRunningLogView::OnFilePrintToFile(void)
{
    COleDateTime tmCur = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());

	CPrintToFileDlg dlg;
	dlg.SetUser(GetUser());
	dlg.SetTimeFrom(tmCur);
	dlg.SetTimeTo(CUtil::OffsetDay(tmCur, 7));
	dlg.DoModal();
}


void CRunningLogView::OnFileExit(void)
{
    CWnd* pWnd = AfxGetMainWnd();
    if(NULL != pWnd)
    {
        pWnd->SendMessage(WM_CLOSE);
    }
}


void CRunningLogView::OnOptionsGoToDay(void)
{
    CGoToDayDlg dlg;
    dlg.SetDate(CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek()));

    if(IDOK == dlg.DoModal())
    {
        COleDateTime tm = dlg.GetDate();
        if(CUtil::IsDateValid(tm))
        {
            SetCurrentDate(tm);
            COleDateTime tmFirst = CUtil::GetFirstVisibleDay(CUtil::GetFirstOfMonth(tm), GetFirstDayOfWeek());

            SetHighlightDay(CUtil::GetNumberOfDaysLaterThan(tm, tmFirst) + 1);
            InvalidateRect(NULL);

            SetModified(true);
        }
    }
}


void CRunningLogView::OnViewDaySummary(void)
{
    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();

    COleDateTime tmStart;
    if((IsUserOpen()) && (CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay)))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());

		MakeDaySummarySheet(tmStart, GetUser(), this);
    }
}


void CRunningLogView::OnViewWeekSummaryRun(void)
{
    bool fDoDialog = false;

    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();
    int nWeeks = CUtil::GetNumWeeks(tmCur, nFirstDay);

    COleDateTime tmStart;
    if(CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
        while(tmStart.GetDayOfWeek() != GetFirstDayOfWeek())
        {
            tmStart = CUtil::SubtractDay(tmStart);
        }
        fDoDialog = true;
    }
    else if((nDay >= HIT_WEEKSUM1) && (nDay <= HIT_WEEKSUM1 + nWeeks - 1))
    {
        int nWeek = nDay - HIT_WEEKSUM1;
        tmStart = CUtil::OffsetDay(CUtil::GetFirstVisibleDay(tmCur, nFirstDay), 7 * nWeek);
        fDoDialog = true;
    }

    if(fDoDialog)
    {
        COleDateTime tmEnd = CUtil::OffsetDay(tmStart, 6);

        CDMFRunSummaryDlg dlg;
        dlg.SetTimeFrom(tmStart);
        dlg.SetTimeTo(tmEnd);
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewMonthSummaryRun(void)
{
    bool fDoDialog = false;

    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();
    int nWeeks = CUtil::GetNumWeeks(tmCur, nFirstDay);

    COleDateTime tmStart;
    if(CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
        fDoDialog = true;
    }

    else if((nDay >= HIT_WEEKSUM1) && (nDay <= HIT_WEEKSUM1 + nWeeks - 1))
    {
        tmStart = tmCur;
        fDoDialog = true;
    }

    else if(HIT_MONTHSUM == nDay)
    {
        tmStart = tmCur;
        fDoDialog = true;
    }
    
    if(fDoDialog)
    {
        COleDateTime tmFirst = CUtil::GetFirstOfMonth(tmStart);
        COleDateTime tmLast = CUtil::GetLastOfMonth(tmStart);

        CDMFRunSummaryDlg dlg;
        dlg.SetTimeFrom(tmFirst);
        dlg.SetTimeTo(tmLast);
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewFullSummaryRun(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        COleDateTime tmFirst = pUser->GetEarliestDay();
        COleDateTime tmLast = pUser->GetLatestDay();

        CDMFRunSummaryDlg dlg;
        dlg.SetTimeFrom(tmFirst);
        dlg.SetTimeTo(tmLast);
        dlg.SetUser(pUser);

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewCustomSummaryRun(void)
{
    COleDateTime tmCur = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());

    CGetDatesDlg dlgDates;
    dlgDates.SetTimeFrom(tmCur);
    dlgDates.SetTimeTo(tmCur);

    if(IDOK == dlgDates.DoModal())
    {
        CDMFRunSummaryDlg dlg;
        dlg.SetTimeFrom(dlgDates.GetTimeFrom());
        dlg.SetTimeTo(dlgDates.GetTimeTo());
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewWeekSummaryBike(void)
{
    bool fDoDialog = false;

    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();
    int nWeeks = CUtil::GetNumWeeks(tmCur, nFirstDay);

    COleDateTime tmStart;
    if(CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
        while(tmStart.GetDayOfWeek() != GetFirstDayOfWeek())
        {
            tmStart = CUtil::SubtractDay(tmStart);
        }
        fDoDialog = true;
    }
    else if((nDay >= HIT_WEEKSUM1) && (nDay <= HIT_WEEKSUM1 + nWeeks - 1))
    {
        int nWeek = nDay - HIT_WEEKSUM1;
        tmStart = CUtil::OffsetDay(CUtil::GetFirstVisibleDay(tmCur, nFirstDay), 7 * nWeek);
        fDoDialog = true;
    }

    if(fDoDialog)
    {
        COleDateTime tmEnd = CUtil::OffsetDay(tmStart, 6);

        CDMFBikeSummaryDlg dlg;
        dlg.SetTimeFrom(tmStart);
        dlg.SetTimeTo(tmEnd);
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewMonthSummaryBike(void)
{
    bool fDoDialog = false;

    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();
    int nWeeks = CUtil::GetNumWeeks(tmCur, nFirstDay);

    COleDateTime tmStart;
    if(CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
        fDoDialog = true;
    }

    else if((nDay >= HIT_WEEKSUM1) && (nDay <= HIT_WEEKSUM1 + nWeeks - 1))
    {
        tmStart = tmCur;
        fDoDialog = true;
    }

    else if(HIT_MONTHSUM == nDay)
    {
        tmStart = tmCur;
        fDoDialog = true;
    }
    
    if(fDoDialog)
    {
        COleDateTime tmFirst = CUtil::GetFirstOfMonth(tmStart);
        COleDateTime tmLast = CUtil::GetLastOfMonth(tmStart);

        CDMFBikeSummaryDlg dlg;
        dlg.SetTimeFrom(tmFirst);
        dlg.SetTimeTo(tmLast);
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewFullSummaryBike(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        COleDateTime tmFirst = pUser->GetEarliestDay();
        COleDateTime tmLast = pUser->GetLatestDay();

        CDMFBikeSummaryDlg dlg;
        dlg.SetTimeFrom(tmFirst);
        dlg.SetTimeTo(tmLast);
        dlg.SetUser(pUser);

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewCustomSummaryBike(void)
{
    COleDateTime tmCur = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());

    CGetDatesDlg dlgDates;
    dlgDates.SetTimeFrom(tmCur);
    dlgDates.SetTimeTo(tmCur);

    if(IDOK == dlgDates.DoModal())
    {
        CDMFBikeSummaryDlg dlg;
        dlg.SetTimeFrom(dlgDates.GetTimeFrom());
        dlg.SetTimeTo(dlgDates.GetTimeTo());
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewWeekSummarySwim(void)
{
    bool fDoDialog = false;

    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();
    int nWeeks = CUtil::GetNumWeeks(tmCur, nFirstDay);

    COleDateTime tmStart;
    if(CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
        while(tmStart.GetDayOfWeek() != GetFirstDayOfWeek())
        {
            tmStart = CUtil::SubtractDay(tmStart);
        }
        fDoDialog = true;
    }
    else if((nDay >= HIT_WEEKSUM1) && (nDay <= HIT_WEEKSUM1 + nWeeks - 1))
    {
        int nWeek = nDay - HIT_WEEKSUM1;
        tmStart = CUtil::OffsetDay(CUtil::GetFirstVisibleDay(tmCur, nFirstDay), 7 * nWeek);
        fDoDialog = true;
    }

    if(fDoDialog)
    {
        COleDateTime tmEnd = CUtil::OffsetDay(tmStart, 6);

        CDMFSwimSummaryDlg dlg;
        dlg.SetTimeFrom(tmStart);
        dlg.SetTimeTo(tmEnd);
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewMonthSummarySwim(void)
{
    bool fDoDialog = false;

    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();
    int nWeeks = CUtil::GetNumWeeks(tmCur, nFirstDay);

    COleDateTime tmStart;
    if(CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
        fDoDialog = true;
    }

    else if((nDay >= HIT_WEEKSUM1) && (nDay <= HIT_WEEKSUM1 + nWeeks - 1))
    {
        tmStart = tmCur;
        fDoDialog = true;
    }

    else if(HIT_MONTHSUM == nDay)
    {
        tmStart = tmCur;
        fDoDialog = true;
    }
    
    if(fDoDialog)
    {
        COleDateTime tmFirst = CUtil::GetFirstOfMonth(tmStart);
        COleDateTime tmLast = CUtil::GetLastOfMonth(tmStart);

        CDMFSwimSummaryDlg dlg;
        dlg.SetTimeFrom(tmFirst);
        dlg.SetTimeTo(tmLast);
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewFullSummarySwim(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        COleDateTime tmFirst = pUser->GetEarliestDay();
        COleDateTime tmLast = pUser->GetLatestDay();

        CDMFSwimSummaryDlg dlg;
        dlg.SetTimeFrom(tmFirst);
        dlg.SetTimeTo(tmLast);
        dlg.SetUser(pUser);

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewCustomSummarySwim(void)
{
    COleDateTime tmCur = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());

    CGetDatesDlg dlgDates;
    dlgDates.SetTimeFrom(tmCur);
    dlgDates.SetTimeTo(tmCur);

    if(IDOK == dlgDates.DoModal())
    {
        CDMFSwimSummaryDlg dlg;
        dlg.SetTimeFrom(dlgDates.GetTimeFrom());
        dlg.SetTimeTo(dlgDates.GetTimeTo());
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewWeekSummaryStrength(void)
{
    bool fDoDialog = false;

    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();
    int nWeeks = CUtil::GetNumWeeks(tmCur, nFirstDay);

    COleDateTime tmStart;
    if(CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
        while(tmStart.GetDayOfWeek() != GetFirstDayOfWeek())
        {
            tmStart = CUtil::SubtractDay(tmStart);
        }
        fDoDialog = true;
    }
    else if((nDay >= HIT_WEEKSUM1) && (nDay <= HIT_WEEKSUM1 + nWeeks - 1))
    {
        int nWeek = nDay - HIT_WEEKSUM1;
        tmStart = CUtil::OffsetDay(CUtil::GetFirstVisibleDay(tmCur, nFirstDay), 7 * nWeek);
        fDoDialog = true;
    }

    if(fDoDialog)
    {
        COleDateTime tmEnd = CUtil::OffsetDay(tmStart, 6);

        CDMFStrengthSummaryDlg dlg;
        dlg.SetTimeFrom(tmStart);
        dlg.SetTimeTo(tmEnd);
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewMonthSummaryStrength(void)
{
    bool fDoDialog = false;

    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();
    int nWeeks = CUtil::GetNumWeeks(tmCur, nFirstDay);

    COleDateTime tmStart;
    if(CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
        fDoDialog = true;
    }

    else if((nDay >= HIT_WEEKSUM1) && (nDay <= HIT_WEEKSUM1 + nWeeks - 1))
    {
        tmStart = tmCur;
        fDoDialog = true;
    }

    else if(HIT_MONTHSUM == nDay)
    {
        tmStart = tmCur;
        fDoDialog = true;
    }
    
    if(fDoDialog)
    {
        COleDateTime tmFirst = CUtil::GetFirstOfMonth(tmStart);
        COleDateTime tmLast = CUtil::GetLastOfMonth(tmStart);

        CDMFStrengthSummaryDlg dlg;
        dlg.SetTimeFrom(tmFirst);
        dlg.SetTimeTo(tmLast);
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewFullSummaryStrength(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        COleDateTime tmFirst = pUser->GetEarliestDay();
        COleDateTime tmLast = pUser->GetLatestDay();

        CDMFStrengthSummaryDlg dlg;
        dlg.SetTimeFrom(tmFirst);
        dlg.SetTimeTo(tmLast);
        dlg.SetUser(pUser);

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewCustomSummaryStrength(void)
{
    COleDateTime tmCur = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());

    CGetDatesDlg dlgDates;
    dlgDates.SetTimeFrom(tmCur);
    dlgDates.SetTimeTo(tmCur);

    if(IDOK == dlgDates.DoModal())
    {
        CDMFStrengthSummaryDlg dlg;
        dlg.SetTimeFrom(dlgDates.GetTimeFrom());
        dlg.SetTimeTo(dlgDates.GetTimeTo());
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewWeekSummaryMulti(void)
{
    bool fDoDialog = false;

    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();
    int nWeeks = CUtil::GetNumWeeks(tmCur, nFirstDay);

    COleDateTime tmStart;
    if(CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
        while(tmStart.GetDayOfWeek() != GetFirstDayOfWeek())
        {
            tmStart = CUtil::SubtractDay(tmStart);
        }
        fDoDialog = true;
    }
    else if((nDay >= HIT_WEEKSUM1) && (nDay <= HIT_WEEKSUM1 + nWeeks - 1))
    {
        int nWeek = nDay - HIT_WEEKSUM1;
        tmStart = CUtil::OffsetDay(CUtil::GetFirstVisibleDay(tmCur, nFirstDay), 7 * nWeek);
        fDoDialog = true;
    }

    if(fDoDialog)
    {
        COleDateTime tmEnd = CUtil::OffsetDay(tmStart, 6);

        CDMFMultiSummaryDlg dlg;
        dlg.SetTimeFrom(tmStart);
        dlg.SetTimeTo(tmEnd);
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewMonthSummaryMulti(void)
{
    bool fDoDialog = false;

    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();
    int nWeeks = CUtil::GetNumWeeks(tmCur, nFirstDay);

    COleDateTime tmStart;
    if(CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
        fDoDialog = true;
    }

    else if((nDay >= HIT_WEEKSUM1) && (nDay <= HIT_WEEKSUM1 + nWeeks - 1))
    {
        tmStart = tmCur;
        fDoDialog = true;
    }

    else if(HIT_MONTHSUM == nDay)
    {
        tmStart = tmCur;
        fDoDialog = true;
    }
    
    if(fDoDialog)
    {
        COleDateTime tmFirst = CUtil::GetFirstOfMonth(tmStart);
        COleDateTime tmLast = CUtil::GetLastOfMonth(tmStart);

        CDMFMultiSummaryDlg dlg;
        dlg.SetTimeFrom(tmFirst);
        dlg.SetTimeTo(tmLast);
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewFullSummaryMulti(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        COleDateTime tmFirst = pUser->GetEarliestDay();
        COleDateTime tmLast = pUser->GetLatestDay();

        CDMFMultiSummaryDlg dlg;
        dlg.SetTimeFrom(tmFirst);
        dlg.SetTimeTo(tmLast);
        dlg.SetUser(pUser);

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewCustomSummaryMulti(void)
{
    COleDateTime tmCur = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());

    CGetDatesDlg dlgDates;
    dlgDates.SetTimeFrom(tmCur);
    dlgDates.SetTimeTo(tmCur);

    if(IDOK == dlgDates.DoModal())
    {
        CDMFMultiSummaryDlg dlg;
        dlg.SetTimeFrom(dlgDates.GetTimeFrom());
        dlg.SetTimeTo(dlgDates.GetTimeTo());
        dlg.SetUser(GetUser());

        dlg.DoModal();
    }
}


void CRunningLogView::OnViewShoeSummaryRun(void)
{
    CShoeSummaryRunDlg dlg(this);
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewShoeSummaryBike(void)
{
    CShoeSummaryBikeDlg dlg(this);
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewBikeSummary(void)
{
    CBikeSummaryDlg dlg(this);
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewCurrentNotes(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CCurrentNotesDlg dlg;
        dlg.SetNotes(pUser->GetNotes());
        dlg.SetReadOnly(true);
        if(IDOK == dlg.DoModal())
        {
            pUser->SetNotes(dlg.GetNotes());
            SetModified(true);
        }
    }
}


void CRunningLogView::OnViewInjuryTracker(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CInjuryTrackerDlg dlg;
        dlg.SetUser(pUser);

		dlg.DoModal();
		SetModified(true);
    }
}


void CRunningLogView::OnViewPersonalRecordsRun(void)
{
    CPRRunDlg dlg;
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewPersonalRecordsBike(void)
{
    CPRBikeDlg dlg;
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewPersonalRecordsSwim(void)
{
    CPRSwimDlg dlg;
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewPersonalRecordsDuathlon(void)
{
    CPRDuathlonDlg dlg;
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewPersonalRecordsTriathlon(void)
{
    CPRTriathlonDlg dlg;
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewPoolPersonalRecords(void)
{
    CSwimPRSummaryDlg dlg;
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewTrackPersonalRecords(void)
{
    CTrackPRSummaryDlg dlg;
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewLocationSummaryRun(void)
{
    CLocationSummaryRunDlg dlg(this);
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewLocationSummaryBike(void)
{
    CLocationSummaryBikeDlg dlg(this);
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewLocationSummarySwim(void)
{
    CLocationSummarySwimDlg dlg(this);
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewLocationSummaryStrength(void)
{
    CLocationSummaryStrengthDlg dlg(this);
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewRaceSummaryRun(void)
{
    CRaceSummaryRunDlg dlg;
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewRaceSummaryBike(void)
{
    CRaceSummaryBikeDlg dlg;
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewRaceSummarySwim(void)
{
    CRaceSummarySwimDlg dlg;
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewRaceSummaryDuathlon(void)
{
    CRaceSummaryDuathlonDlg dlg;
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewRaceSummaryTriathlon(void)
{
    CRaceSummaryTriathlonDlg dlg;
    dlg.SetUser(GetUser());
    dlg.DoModal();
}


void CRunningLogView::OnViewGraphLarge(void)
{
	MakeGraphWindow(IDD_PECHARTLARGEDLG);
}


void CRunningLogView::OnViewGraphMedium(void)
{
    MakeGraphWindow(IDD_PECHARTMEDIUMDLG);
}


void CRunningLogView::OnViewGraphSmall(void)
{
    MakeGraphWindow(IDD_PECHARTSMALLDLG);
}


void CRunningLogView::MakeGraphWindow(int nID)
{
    COleDateTime tmCur = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
    
    if((IDD_PECHARTLARGEDLG != nID) && (IDD_PECHARTMEDIUMDLG != nID) && (IDD_PECHARTSMALLDLG != nID))
    {
        return;
    }

    CPEChartDlg* pdlgGraph = new CPEChartDlg(nID, this);
    if(NULL != pdlgGraph)
    {
        pdlgGraph->SetUser(GetUser());
        pdlgGraph->SetGraphTime(tmCur);
        pdlgGraph->Create(nID);
        pdlgGraph->ShowWindow(SW_SHOW);
    }
}


void CRunningLogView::OnMiscPaceCalc(void)
{
    CPaceCalcDlg dlg;
    dlg.DoModal();
}


void CRunningLogView::OnMiscCalories(void)
{
    COleDateTime tmCur = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());

	CGetDatesDlg dlgDates;
	dlgDates.SetTimeFrom(tmCur);
	dlgDates.SetTimeTo(tmCur);

    if(IDOK == dlgDates.DoModal())
	{
		CCalorieDlg dlg;
		dlg.SetDates(dlgDates.GetTimeFrom(), dlgDates.GetTimeTo());
		dlg.SetUser(GetUser());
		dlg.DoModal();
	}
}


void CRunningLogView::OnMiscSearch(void)
{
    COleDateTime tmCur = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());

	CSearchDlg dlg;
	dlg.SetTimeFrom(tmCur);
	dlg.SetTimeTo(CUtil::OffsetDay(tmCur, 7));
	dlg.SetUser(GetUser());

	dlg.DoModal();
}


void CRunningLogView::OnMiscDistConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CRunningLogView::OnHelpHelpTopics(void)
{
    CHelpDlg dlgHelp("Help Topics");
    dlgHelp.Initialize();
    dlgHelp.DoModal();
}


void CRunningLogView::OnHelpDonate(void)
{
	CString str = _T("https://www.paypal.com/xclick/business=weil%40fas.harvard.edu&item_name=TriathLog&no_shipping=1&cn=Optional+Note&tax=0&currency_code=USD");
	CHyperLink hLink;
	hLink.GotoURL(str, SW_SHOW);
}


void CRunningLogView::OnHelpAbout(void)
{
    CAboutDlg dlgAbout;
    dlgAbout.DoModal();
}


void CRunningLogView::OnUpdateOpenUser(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(!fOpen);
}


void CRunningLogView::OnUpdateSaveUser(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateCloseUser(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateConvert1(CCmdUI* pCmdUI)
{
	bool fClosed = !IsUserOpen();
    pCmdUI->Enable(fClosed);
}


void CRunningLogView::OnUpdateConvert3(CCmdUI* pCmdUI)
{
	bool fClosed = !IsUserOpen();
    pCmdUI->Enable(fClosed);
}


void CRunningLogView::OnUpdatePrintToFile(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateEditUser(CCmdUI* pCmdUI)
{
	bool fOpen = IsUserOpen();
	pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateUserOptions(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddMultipleItems(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddLocationRun(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddLocationBike(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddLocationSwim(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddLocationStrength(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddCourseRun(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddCourseBike(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddCourseSwim(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddCourseDuathlon(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddCourseTriathlon(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddShoesRun(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddShoesBike(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddBike(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateAddWorkout(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nFirstDay = GetFirstDayOfWeek();

    int nWeeks = CUtil::GetNumWeeks(tm, nFirstDay);

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fOpen = IsUserOpen();

    bool fTime = CUtil::IsHighlightDayADay(tm, n, nFirstDay);
    COleDateTime tmHighlight = CUtil::GetHighlightedDate(tm, n, nFirstDay);
    fTime &= !CUtil::IsLaterDayThan(tmHighlight, COleDateTime::GetCurrentTime());

    pCmdUI->Enable(fOpen && fDaySelected && fTime);
}


void CRunningLogView::OnUpdateDeleteWorkout(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nFirstDay = GetFirstDayOfWeek();

    int nWeeks = CUtil::GetNumWeeks(tm, nFirstDay);

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fOpen = IsUserOpen();

    bool fTime = CUtil::IsHighlightDayADay(tm, n, nFirstDay);
    COleDateTime tmHighlight = CUtil::GetHighlightedDate(tm, n, nFirstDay);
    fTime &= !CUtil::IsLaterDayThan(tmHighlight, COleDateTime::GetCurrentTime());

    pCmdUI->Enable(fOpen && fDaySelected && fTime);
}


void CRunningLogView::OnUpdateDeleteUpcomingWorkout(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nFirstDay = GetFirstDayOfWeek();

    int nWeeks = CUtil::GetNumWeeks(tm, nFirstDay);

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fOpen = IsUserOpen();

    bool fTime = CUtil::IsHighlightDayADay(tm, n, nFirstDay);
    COleDateTime tmHighlight = CUtil::GetHighlightedDate(tm, n, nFirstDay);
	COleDateTime tmNow = COleDateTime::GetCurrentTime();
	fTime &= (CUtil::IsLaterDayThan(tmHighlight, tmNow) || CUtil::IsSameDay(tmHighlight, tmNow));

    pCmdUI->Enable(fOpen && fDaySelected && fTime);
}


void CRunningLogView::OnUpdateDeleteUpcomingRace(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nFirstDay = GetFirstDayOfWeek();

    int nWeeks = CUtil::GetNumWeeks(tm, nFirstDay);

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fOpen = IsUserOpen();

    bool fTime = CUtil::IsHighlightDayADay(tm, n, nFirstDay);
    COleDateTime tmHighlight = CUtil::GetHighlightedDate(tm, n, nFirstDay);
	COleDateTime tmNow = COleDateTime::GetCurrentTime();
	fTime &= (CUtil::IsLaterDayThan(tmHighlight, tmNow) || CUtil::IsSameDay(tmHighlight, tmNow));

    pCmdUI->Enable(fOpen && fDaySelected && fTime);
}


void CRunningLogView::OnUpdateAddUpcomingRace(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nFirstDay = GetFirstDayOfWeek();

    int nWeeks = CUtil::GetNumWeeks(tm, nFirstDay);

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fOpen = IsUserOpen();

    bool fTime = CUtil::IsHighlightDayADay(tm, n, nFirstDay);
    COleDateTime tmHighlight = CUtil::GetHighlightedDate(tm, n, nFirstDay);
    fTime &= !CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), tmHighlight);

    pCmdUI->Enable(fOpen && fDaySelected && fTime);
}


void CRunningLogView::OnUpdateAddUpcomingWorkout(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nFirstDay = GetFirstDayOfWeek();

    int nWeeks = CUtil::GetNumWeeks(tm, nFirstDay);

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fOpen = IsUserOpen();

    bool fTime = CUtil::IsHighlightDayADay(tm, n, nFirstDay);
    COleDateTime tmHighlight = CUtil::GetHighlightedDate(tm, n, nFirstDay);
    fTime &= !CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), tmHighlight);

    pCmdUI->Enable(fOpen && fDaySelected && fTime);
}


void CRunningLogView::OnUpdateGoToDay(CCmdUI* pCmdUI)
{
    pCmdUI->Enable();
}


void CRunningLogView::OnUpdateDaySummary(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nWeeks = CUtil::GetNumWeeks(tm, GetFirstDayOfWeek());

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fOpen = IsUserOpen();

    pCmdUI->Enable(fOpen && fDaySelected);
}


void CRunningLogView::OnUpdateWeekSummaryRun(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nWeeks = CUtil::GetNumWeeks(tm, GetFirstDayOfWeek());

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fWeekSelected = ((n >= HIT_WEEKSUM1) && (n <= HIT_WEEKSUM1 + nWeeks - 1));
    bool fOpen = IsUserOpen();

    pCmdUI->Enable(fOpen && (fDaySelected || fWeekSelected));
}


void CRunningLogView::OnUpdateMonthSummaryRun(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nWeeks = CUtil::GetNumWeeks(tm, GetFirstDayOfWeek());

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fWeekSelected = ((n >= HIT_WEEKSUM1) && (n <= HIT_WEEKSUM1 + nWeeks - 1));
    bool fMonthSelected = (n == HIT_MONTHSUM);
    bool fOpen = IsUserOpen();

    pCmdUI->Enable(fOpen && (fDaySelected || fWeekSelected || fMonthSelected));
}


void CRunningLogView::OnUpdateFullSummaryRun(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateCustomSummaryRun(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateWeekSummaryBike(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nWeeks = CUtil::GetNumWeeks(tm, GetFirstDayOfWeek());

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fWeekSelected = ((n >= HIT_WEEKSUM1) && (n <= HIT_WEEKSUM1 + nWeeks - 1));
    bool fOpen = IsUserOpen();

    pCmdUI->Enable(fOpen && (fDaySelected || fWeekSelected));
}


void CRunningLogView::OnUpdateMonthSummaryBike(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nWeeks = CUtil::GetNumWeeks(tm, GetFirstDayOfWeek());

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fWeekSelected = ((n >= HIT_WEEKSUM1) && (n <= HIT_WEEKSUM1 + nWeeks - 1));
    bool fMonthSelected = (n == HIT_MONTHSUM);
    bool fOpen = IsUserOpen();

    pCmdUI->Enable(fOpen && (fDaySelected || fWeekSelected || fMonthSelected));
}


void CRunningLogView::OnUpdateCustomSummaryBike(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateFullSummaryBike(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateWeekSummarySwim(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nWeeks = CUtil::GetNumWeeks(tm, GetFirstDayOfWeek());

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fWeekSelected = ((n >= HIT_WEEKSUM1) && (n <= HIT_WEEKSUM1 + nWeeks - 1));
    bool fOpen = IsUserOpen();

    pCmdUI->Enable(fOpen && (fDaySelected || fWeekSelected));
}


void CRunningLogView::OnUpdateMonthSummarySwim(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nWeeks = CUtil::GetNumWeeks(tm, GetFirstDayOfWeek());

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fWeekSelected = ((n >= HIT_WEEKSUM1) && (n <= HIT_WEEKSUM1 + nWeeks - 1));
    bool fMonthSelected = (n == HIT_MONTHSUM);
    bool fOpen = IsUserOpen();

    pCmdUI->Enable(fOpen && (fDaySelected || fWeekSelected || fMonthSelected));
}


void CRunningLogView::OnUpdateFullSummarySwim(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateCustomSummarySwim(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateWeekSummaryStrength(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nWeeks = CUtil::GetNumWeeks(tm, GetFirstDayOfWeek());

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fWeekSelected = ((n >= HIT_WEEKSUM1) && (n <= HIT_WEEKSUM1 + nWeeks - 1));
    bool fOpen = IsUserOpen();

    pCmdUI->Enable(fOpen && (fDaySelected || fWeekSelected));
}


void CRunningLogView::OnUpdateMonthSummaryStrength(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nWeeks = CUtil::GetNumWeeks(tm, GetFirstDayOfWeek());

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fWeekSelected = ((n >= HIT_WEEKSUM1) && (n <= HIT_WEEKSUM1 + nWeeks - 1));
    bool fMonthSelected = (n == HIT_MONTHSUM);
    bool fOpen = IsUserOpen();

    pCmdUI->Enable(fOpen && (fDaySelected || fWeekSelected || fMonthSelected));
}


void CRunningLogView::OnUpdateFullSummaryStrength(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateCustomSummaryStrength(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateWeekSummaryMulti(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nWeeks = CUtil::GetNumWeeks(tm, GetFirstDayOfWeek());

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fWeekSelected = ((n >= HIT_WEEKSUM1) && (n <= HIT_WEEKSUM1 + nWeeks - 1));
    bool fOpen = IsUserOpen();

    pCmdUI->Enable(fOpen && (fDaySelected || fWeekSelected));
}


void CRunningLogView::OnUpdateMonthSummaryMulti(CCmdUI* pCmdUI)
{
    COleDateTime tm = GetCurrentDate();
    int nWeeks = CUtil::GetNumWeeks(tm, GetFirstDayOfWeek());

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fWeekSelected = ((n >= HIT_WEEKSUM1) && (n <= HIT_WEEKSUM1 + nWeeks - 1));
    bool fMonthSelected = (n == HIT_MONTHSUM);
    bool fOpen = IsUserOpen();

    pCmdUI->Enable(fOpen && (fDaySelected || fWeekSelected || fMonthSelected));
}


void CRunningLogView::OnUpdateFullSummaryMulti(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateCustomSummaryMulti(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateShoeSummaryRun(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateShoeSummaryBike(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateBikeSummary(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateLocationSummaryRun(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateLocationSummaryBike(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateLocationSummarySwim(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateLocationSummaryStrength(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateRaceSummaryRun(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateRaceSummaryBike(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateRaceSummarySwim(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateRaceSummaryDuathlon(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateRaceSummaryTriathlon(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateCurrentNotes(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateInjuryTracker(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdatePersonalRecordsRun(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdatePersonalRecordsBike(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdatePersonalRecordsSwim(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdatePersonalRecordsDuathlon(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdatePersonalRecordsTriathlon(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdatePoolPersonalRecords(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateTrackPersonalRecords(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateViewGraphLarge(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateViewGraphMedium(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateViewGraphSmall(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdatePaceCalc(CCmdUI* pCmdUI)
{
    pCmdUI->Enable();
}


void CRunningLogView::OnUpdateCalories(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateSearch(CCmdUI* pCmdUI)
{
    bool fOpen = IsUserOpen();
    pCmdUI->Enable(fOpen);
}


void CRunningLogView::OnUpdateHelpTopics(CCmdUI* pCmdUI)
{
    pCmdUI->Enable();
}

void CRunningLogView::OnUpdateDonate(CCmdUI* pCmdUI)
{
    pCmdUI->Enable();
}


void CRunningLogView::OnUpdateAbout(CCmdUI* pCmdUI)
{
    pCmdUI->Enable();
}


void CRunningLogView::OnOptionsEditUser(void)
{
	CEditUserDlg dlg;
	CUser* pUser = GetUser();

	if(NULL != pUser)
	{
		dlg.SetUser(pUser);
		if(IDOK == dlg.DoModal())
		{
			pUser->SetFirstName(dlg.GetFirstName());
			pUser->SetLastName(dlg.GetLastName());
			pUser->SetHeight(dlg.GetHeight());
			pUser->SetRestingHR(dlg.GetRestHR());
			pUser->SetSex(dlg.GetSex());
		}
	}

	SetWindowTitle();
}		


void CRunningLogView::OnOptionsUserOptions(void)
{
    COptionsDlg dlg("TriathLog Options");

    dlg.SetParentView(this);
    dlg.SetUser(GetUser());

    dlg.Initialize();
    
    dlg.DoModal();

    if(dlg.IsModified())
    {
        SetModified(true);
    }

    SetButtonColors(m_pButtonPrev);
    SetButtonColors(m_pButtonNext);

    CRect rcClient;
    GetClientRect(&rcClient);
    MakeGradient(rcClient.Width(), rcClient.Height());
    InvalidateRect(NULL);
}


void CRunningLogView::OptionsDlgNotifyApply(void)
{
    SetModified(true);

    SetButtonColors(m_pButtonPrev);
    SetButtonColors(m_pButtonNext);

    CRect rcClient;
    GetClientRect(&rcClient);
    MakeGradient(rcClient.Width(), rcClient.Height());
    InvalidateRect(NULL);
}


void CRunningLogView::OnPrevMonth(void)
{
    COleDateTime tm = CUtil::SubtractMonth(GetCurrentDate());
    if(CUtil::IsDateValid(tm))
    {
        SetCurrentDate(tm);
        AdjustHighlightDay();
        SetModified(true);
    }
    else
    {
        AfxMessageBox("Sorry, you cannot go any further forward.", MB_OK | MB_ICONSTOP);
    }

    InvalidateRect(NULL);
}


void CRunningLogView::OnNextMonth(void)
{
    COleDateTime tm = CUtil::AddMonth(GetCurrentDate());
    if(CUtil::IsDateValid(tm))
    {
        SetCurrentDate(tm);
        AdjustHighlightDay();
        SetModified(true);
    }
    else
    {
        AfxMessageBox("Sorry, you cannot go any further back.", MB_OK | MB_ICONSTOP);
    }

    InvalidateRect(NULL);
}


void CRunningLogView::OnOptionsAddCourseRun(void)
{
    CAddCourseRunDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        CCourseRun* pCourse = new CCourseRun;
        CUser* pUser = GetUser();
        if((NULL != pCourse) && (NULL != pUser))
        {
            pCourse->SetLength(dlg.GetLength());
            pCourse->SetPRSeconds(dlg.GetPRSeconds());
            pCourse->SetName(dlg.GetName());
            pCourse->SetNotes(dlg.GetNotes());
            pCourse->SetCity(dlg.GetCity());
            pCourse->SetState(dlg.GetState());

            pUser->AddCourseRun(pCourse);

            SetModified(true);
        }
    }
}


void CRunningLogView::OnOptionsAddCourseBike(void)
{
    CAddCourseBikeDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        CCourseBike* pCourse = new CCourseBike;
        CUser* pUser = GetUser();
        if((NULL != pCourse) && (NULL != pUser))
        {
            pCourse->SetLength(dlg.GetLength());
            pCourse->SetPRSeconds(dlg.GetPRSeconds());
            pCourse->SetName(dlg.GetName());
            pCourse->SetNotes(dlg.GetNotes());
            pCourse->SetCity(dlg.GetCity());
            pCourse->SetState(dlg.GetState());

            pUser->AddCourseBike(pCourse);

            SetModified(true);
        }
    }
}


void CRunningLogView::OnOptionsAddCourseSwim(void)
{
    CAddCourseSwimDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        CCourseSwim* pCourse = new CCourseSwim;
        CUser* pUser = GetUser();
        if((NULL != pCourse) && (NULL != pUser))
        {
            pCourse->SetLength(dlg.GetLength());
            pCourse->SetPRSeconds(dlg.GetPRSeconds());
            pCourse->SetName(dlg.GetName());
            pCourse->SetNotes(dlg.GetNotes());
            pCourse->SetCity(dlg.GetCity());
            pCourse->SetState(dlg.GetState());

            pUser->AddCourseSwim(pCourse);

            SetModified(true);
        }
    }
}


void CRunningLogView::OnOptionsAddCourseDuathlon(void)
{
    CAddCourseDuathlonDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        CCourseDuathlon* pCourse = new CCourseDuathlon;
        CUser* pUser = GetUser();
        if((NULL != pCourse) && (NULL != pUser))
        {
            pCourse->SetPRSeconds(dlg.GetOverallPRSeconds());
            pCourse->SetTransition1PRSeconds(dlg.GetTransition1PRSeconds());
            pCourse->SetTransition2PRSeconds(dlg.GetTransition2PRSeconds());
            pCourse->SetName(dlg.GetOverallNotes());
            pCourse->SetName(dlg.GetName());
            pCourse->SetCity(dlg.GetCity());
            pCourse->SetState(dlg.GetState());
            pCourse->SetLeg1Length(dlg.GetL1Length());
            pCourse->SetLeg1PRSeconds(dlg.GetL1PRSeconds());
            pCourse->SetLeg1Notes(dlg.GetL1Notes());            
            pCourse->SetLeg2Length(dlg.GetL2Length());
            pCourse->SetLeg2PRSeconds(dlg.GetL2PRSeconds());
            pCourse->SetLeg2Notes(dlg.GetL2Notes());
            pCourse->SetLeg3Length(dlg.GetL3Length());
            pCourse->SetLeg3PRSeconds(dlg.GetL3PRSeconds());
            pCourse->SetLeg3Notes(dlg.GetL3Notes());

            pUser->AddCourseDuathlon(pCourse);

            SetModified(true);
        }
    }
}


void CRunningLogView::OnOptionsAddCourseTriathlon(void)
{
    CAddCourseTriathlonDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        CCourseTriathlon* pCourse = new CCourseTriathlon;
        CUser* pUser = GetUser();
        if((NULL != pCourse) && (NULL != pUser))
        {
            pCourse->SetPRSeconds(dlg.GetOverallPRSeconds());
            pCourse->SetTransition1PRSeconds(dlg.GetTransition1PRSeconds());
            pCourse->SetTransition2PRSeconds(dlg.GetTransition2PRSeconds());
            pCourse->SetName(dlg.GetOverallNotes());
            pCourse->SetName(dlg.GetName());
            pCourse->SetCity(dlg.GetCity());
            pCourse->SetState(dlg.GetState());
            pCourse->SetLeg1Length(dlg.GetL1Length());
            pCourse->SetLeg1PRSeconds(dlg.GetL1PRSeconds());
            pCourse->SetLeg1Notes(dlg.GetL1Notes());            
            pCourse->SetLeg2Length(dlg.GetL2Length());
            pCourse->SetLeg2PRSeconds(dlg.GetL2PRSeconds());
            pCourse->SetLeg2Notes(dlg.GetL2Notes());
            pCourse->SetLeg3Length(dlg.GetL3Length());
            pCourse->SetLeg3PRSeconds(dlg.GetL3PRSeconds());
            pCourse->SetLeg3Notes(dlg.GetL3Notes());

            pUser->AddCourseTriathlon(pCourse);

            SetModified(true);
        }
    }
}


void CRunningLogView::OnOptionsAddMultipleItems(void)
{
    CAddAllDataDlg dlg;
    dlg.SetUser(GetUser());
    dlg.DoModal();

    if(dlg.IsModified())
    {
        SetModified(true);
    }
}


void CRunningLogView::OnOptionsAddLocationRun(void)
{
    CAddLocationRunDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        CLocationRun* pLoc = new CLocationRun;
        CUser* pUser = GetUser();
        if((NULL != pLoc) && (NULL != pUser))
        {
            pLoc->SetName(dlg.GetName());
            pLoc->SetNotes(dlg.GetNotes());
            pLoc->SetCity(dlg.GetCity());
            pLoc->SetState(dlg.GetState());

            pUser->AddLocationRun(pLoc);

            SetModified(true);
        }
    }
}


void CRunningLogView::OnOptionsAddLocationBike(void)
{
    CAddLocationBikeDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        CLocationBike* pLoc = new CLocationBike;
        CUser* pUser = GetUser();
        if((NULL != pLoc) && (NULL != pUser))
        {
            pLoc->SetName(dlg.GetName());
            pLoc->SetNotes(dlg.GetNotes());
            pLoc->SetCity(dlg.GetCity());
            pLoc->SetState(dlg.GetState());

            pUser->AddLocationBike(pLoc);

            SetModified(true);
        }
    }
}


void CRunningLogView::OnOptionsAddLocationSwim(void)
{
    CAddLocationSwimDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        CLocationSwim* pLoc = new CLocationSwim;
        CUser* pUser = GetUser();
        if((NULL != pLoc) && (NULL != pUser))
        {
            pLoc->SetName(dlg.GetName());
            pLoc->SetNotes(dlg.GetNotes());
            pLoc->SetCity(dlg.GetCity());
            pLoc->SetState(dlg.GetState());

            pUser->AddLocationSwim(pLoc);

            SetModified(true);
        }
    }
}


void CRunningLogView::OnOptionsAddLocationStrength(void)
{
    CAddLocationStrengthDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        CLocationStrength* pLoc = new CLocationStrength;
        CUser* pUser = GetUser();
        if((NULL != pLoc) && (NULL != pUser))
        {
            pLoc->SetName(dlg.GetName());
            pLoc->SetNotes(dlg.GetNotes());
            pLoc->SetCity(dlg.GetCity());
            pLoc->SetState(dlg.GetState());

            pUser->AddLocationStrength(pLoc);

            SetModified(true);
        }
    }
}


void CRunningLogView::OnOptionsAddShoesRun(void)
{
    CAddShoesRunDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        CShoesRun* pShoes = new CShoesRun;
        CUser* pUser = GetUser();
        if((NULL != pShoes) && (NULL != pUser))
        {
            pShoes->SetBrand(dlg.GetBrand());
            pShoes->SetType(dlg.GetType());
            pShoes->SetSize(dlg.GetSize());
            pShoes->SetFirstDay(dlg.GetFirstUse());
            pShoes->SetNotes(dlg.GetNotes());
            pShoes->SetRetired(false);

            pUser->AddShoesRun(pShoes);

            SetModified(true);
        }
    }
}


void CRunningLogView::OnOptionsAddShoesBike(void)
{
    CAddShoesBikeDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        CShoesBike* pShoes = new CShoesBike;
        CUser* pUser = GetUser();
        if((NULL != pShoes) && (NULL != pUser))
        {
            pShoes->SetBrand(dlg.GetBrand());
            pShoes->SetType(dlg.GetType());
            pShoes->SetSize(dlg.GetSize());
            pShoes->SetFirstDay(dlg.GetFirstUse());
            pShoes->SetNotes(dlg.GetNotes());
            pShoes->SetRetired(false);

            pUser->AddShoesBike(pShoes);

            SetModified(true);
        }
    }
}


void CRunningLogView::OnOptionsAddBike(void)
{
    CAddBikeDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        CBike* pBike = new CBike;
        CUser* pUser = GetUser();
        if((NULL != pBike) && (NULL != pUser))
        {
            pBike->SetBrand(dlg.GetBrand());
            pBike->SetType(dlg.GetType());
            pBike->SetSize(dlg.GetSize());
            pBike->SetFirstDay(dlg.GetFirstUse());
            pBike->SetNotes(dlg.GetNotes());
            pBike->SetRetired(false);
            
            pUser->AddBike(pBike);

            SetModified(true);
        }        
    }
}


void CRunningLogView::OnOptionsAddWorkout(void)
{
    MakeWorkoutDialog();
}


void CRunningLogView::OnOptionsDeleteWorkout(void)
{
    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();

    bool bChanged;

    COleDateTime tmStart;
    if(CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
        
        CDeleteWorkoutDlg dlg(this);

        CUser* pUser = GetUser();
        if(NULL != pUser)
        {
			bool fWorkouts = false;

            CDayLog* pDay = pUser->GetDayAt(tmStart);
            if(NULL != pDay)
            {
                fWorkouts = (0 != pDay->SumTotalWorkouts());
            }

			if(false == fWorkouts)
			{
                AfxMessageBox("Please select a day that has workouts to delete.");
                return;
            }

			dlg.SetDeleteType(CDeleteWorkoutDlg::EDeleteWorkout);
            dlg.SetDay(pDay);
			dlg.SetUser(pUser);
			dlg.SetDate(tmStart);
            dlg.DoModal();

            bChanged = dlg.GetChanged();
        }
    }

    if(bChanged)
    {
        SetModified(true);
    }

    InvalidateRect(NULL);
}


void CRunningLogView::OnOptionsDeleteUpcomingWorkout(void)
{
    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();

    bool bChanged;

    COleDateTime tmStart;
    if(CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
        
        CDeleteWorkoutDlg dlg(this);

        CUser* pUser = GetUser();
        if(NULL != pUser)
        {
			CDayLog* pDay = pUser->GetDayAt(tmStart);
			bool fUpcomingWorkouts = (true == MarkAsUpcomingWorkoutDay(tmStart));
	
			if(false == fUpcomingWorkouts)
			{
                AfxMessageBox("Please select a day that has planned workouts to delete.");
                return;
            }
			
			dlg.SetDeleteType(CDeleteWorkoutDlg::EDeleteUpcomingWorkout);
            dlg.SetDay(pDay);
			dlg.SetUser(pUser);
			dlg.SetDate(tmStart);
            dlg.DoModal();

            bChanged = dlg.GetChanged();
        }
    }

    if(bChanged)
    {
        SetModified(true);
    }

    InvalidateRect(NULL);
}


void CRunningLogView::OnOptionsDeleteUpcomingRace(void)
{
    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nFirstDay = GetFirstDayOfWeek();

    bool bChanged;

    COleDateTime tmStart;
    if(CUtil::IsHighlightDayADay(tmCur, nDay, nFirstDay))
    {
        tmStart = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());
        
        CDeleteWorkoutDlg dlg(this);

        CUser* pUser = GetUser();
        if(NULL != pUser)
        {
			CDayLog* pDay = pUser->GetDayAt(tmStart);
			bool fUpcomingRaces = (true == MarkAsUpcomingRaceDay(tmStart));
	
			if(false == fUpcomingRaces)
			{
                AfxMessageBox("Please select a day that has upcoming races to delete.");
                return;
            }
			
			dlg.SetDeleteType(CDeleteWorkoutDlg::EDeleteUpcomingRace);
            dlg.SetDay(pDay);
			dlg.SetUser(pUser);
			dlg.SetDate(tmStart);
            dlg.DoModal();

            bChanged = dlg.GetChanged();
        }
    }

    if(bChanged)
    {
        SetModified(true);
    }

    InvalidateRect(NULL);
}


void CRunningLogView::OnOptionsAddUpcomingRace(void)
{
    MakeUpcomingRaceDialog();
}
    

void CRunningLogView::OnOptionsAddUpcomingWorkout(void)
{
    MakeUpcomingWorkoutDialog();
}


bool CRunningLogView::PromptToSave(void)
{
    if(IsUserOpen())
    {
        int nRet = AfxMessageBox("Your records have changed.  Do you want to save them?",  MB_YESNOCANCEL);
        if(IDYES == nRet)
        {
            OnFileSaveUser();
            return true;
        }
        else if(IDNO == nRet)
        {
            return true;
        }
        else if(IDCANCEL == nRet)
        {
            return false;
        }
    }

    return true;
}


CString CRunningLogView::GetAnnotationRun(int nType, COleDateTime tmTime, bool& rfUpcomingRace, bool& rfUpcomingWorkout)
{
    rfUpcomingRace = false;
	rfUpcomingWorkout = false;
    CString strRet;
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        switch(nType)
        {
        case DAYTYPE_NORMAL:
        case DAYTYPE_GRAYED:
            {
                CDayLog* pDay = pUser->GetDayAt(tmTime);
                CUpcomingRace* pRace = pUser->GetUpcomingRaceAt(tmTime);
                CUpcomingWorkout* pWorkout = pUser->GetUpcomingWorkoutAt(tmTime);
                
                int nTotal = 0;

                if(NULL != pDay)
                {
                    strRet = "Run: ";
                    WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
                    for(int i = 0; i < rarWorkouts.GetCount(); i++)
                    {
                        CWorkout* pWorkout = rarWorkouts.GetAt(i);
                        if(NULL != pWorkout)
                        {
                            if(ACTIVITY_RUNNING == pWorkout->GetActivityType())
                            {
                                if(0 != nTotal)
                                {
                                    strRet += ", ";
                                    nTotal++;
                                }
                                strRet += pWorkout->GetDisplayName();

                                CString strDist;
                                if(BASED_ON_TIME == GetBaseTypeRun())
                                {
                                    double dSeconds = pWorkout->GetSeconds();
                                    if(CUtil::HasData(dSeconds))
                                    {
                                        strDist = CDlgHelper::FormatTimeNoDecimal(dSeconds / 60.0);
                                    }
                                }
                                else
                                {
                                    double dMiles = pWorkout->GetMiles();
                                    if(CUtil::HasData(dMiles))
                                    {
										strDist = FormatDecimals(pUser->GetRunDecimals(), dMiles);
                                    }
                                }
                                if(false == strDist.IsEmpty())
                                {
                                    strRet += " (";
                                    strRet += strDist;
                                    strRet += ")";
                                }
                                nTotal++;
                            }
                        }
                    }
                    if(nTotal == 0)
                    {
                        strRet = "";
                    }
                }
                else if((NULL != pRace) && (!CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), pRace->GetDate())))
                {
                    strRet = "Upcoming Race:";
                    rfUpcomingRace = true;
                }
				else if((NULL != pWorkout) && (!CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), pWorkout->GetDate())))
				{
					strRet = "Planned Workout:";
					rfUpcomingWorkout = true;
				}
                
                break;
            }

        case DAYTYPE_WEEKSUM:
            {
                strRet = "Run: ";
                CString str;
                int nWorkouts = pUser->SumWorkoutsRun(tmTime, 7);
                str.Format("%d, ", nWorkouts);
                strRet += str;
                double dMinutes = pUser->SumMinutesRun(tmTime, 7); 
                strRet += CDlgHelper::FormatTimeNoDecimal(dMinutes);
                double dMiles = pUser->SumMilesRun(tmTime, 7);
                str.Format("%.2lf", dMiles);
                strRet += ", ";
                strRet += str;
                break;
            }

        case DAYTYPE_MONTHSUM:
            {
                strRet = "Run: ";
                CString str;
                int nDays = CUtil::GetNumDaysInMonth(tmTime.GetYear(), tmTime.GetMonth());
                int nWorkouts = pUser->SumWorkoutsRun(tmTime, nDays);
                str.Format("%d, ", nWorkouts);
                strRet += str;
                double dMinutes = pUser->SumMinutesRun(tmTime, nDays); 
                strRet += CDlgHelper::FormatTimeNoDecimal(dMinutes);
                double dMiles = pUser->SumMilesRun(tmTime, nDays);
                str.Format("%.2lf", dMiles);
                strRet += ", ";
                strRet += str;
                break;
            }

        default:
            {
                break;
            }
        }
    }

    return strRet;
}


CString CRunningLogView::GetAnnotationBike(int nType, COleDateTime tmTime, bool& rfUpcomingRace, bool& rfUpcomingWorkout)
{
    rfUpcomingRace = false;
	rfUpcomingWorkout = false;
    CString strRet;
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        switch(nType)
        {
        case DAYTYPE_NORMAL:
        case DAYTYPE_GRAYED:
            {
                CDayLog* pDay = pUser->GetDayAt(tmTime);
                CUpcomingRace* pRace = pUser->GetUpcomingRaceAt(tmTime);
                CUpcomingWorkout* pWorkout = pUser->GetUpcomingWorkoutAt(tmTime);

                int nTotal = 0;

                if(NULL != pDay)
                {
                    strRet = "Bike: ";
                    WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
                    for(int i = 0; i < rarWorkouts.GetCount(); i++)
                    {
                        CWorkout* pWorkout = rarWorkouts.GetAt(i);
                        if(NULL != pWorkout)
                        {
                            if(ACTIVITY_BIKING == pWorkout->GetActivityType())
                            {
                                if(0 != nTotal)
                                {
                                    strRet += ", ";
                                    nTotal++;
                                }
                                strRet += pWorkout->GetDisplayName();

                                CString strDist;
                                if(BASED_ON_TIME == GetBaseTypeBike())
                                {
                                    double dSeconds = pWorkout->GetSeconds();
                                    if(CUtil::HasData(dSeconds))
                                    {
                                        strDist = CDlgHelper::FormatTimeNoDecimal(dSeconds / 60.0);
                                    }
                                }
                                else
                                {
                                    double dMiles = pWorkout->GetMiles();
                                    if(CUtil::HasData(dMiles))
                                    {
										strDist = FormatDecimals(pUser->GetBikeDecimals(), dMiles);
                                    }
                                }
                                if(false == strDist.IsEmpty())
                                {
                                    strRet += " (";
                                    strRet += strDist;
                                    strRet += ")";
                                }
                                nTotal++;
                            }
                        }
                    }

                    if(nTotal == 0)
                    {
                        strRet = "";
                    }
                }
                else if((NULL != pRace) && (!CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), pRace->GetDate())))
                {
                    strRet = pRace->GetLineOne();
                    rfUpcomingRace = true;
                }

                else if((NULL != pWorkout) && (!CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), pWorkout->GetDate())))
                {
                    strRet = pWorkout->GetLineOne();
                    rfUpcomingWorkout = true;
                }

                break;
            }

        case DAYTYPE_WEEKSUM:
            {
                strRet = "Bike: ";
                CString str;
                int nWorkouts = pUser->SumWorkoutsBike(tmTime, 7);
                str.Format("%d, ", nWorkouts);
                strRet += str;
                double dMinutes = pUser->SumMinutesBike(tmTime, 7); 
                strRet += CDlgHelper::FormatTimeNoDecimal(dMinutes);
                double dMiles = pUser->SumMilesBike(tmTime, 7);
                str.Format("%.2lf", dMiles);
                strRet += ", ";
                strRet += str;
                break;
            }

        case DAYTYPE_MONTHSUM:
            {
                strRet = "Bike: ";
                CString str;
                int nDays = CUtil::GetNumDaysInMonth(tmTime.GetYear(), tmTime.GetMonth());
                int nWorkouts = pUser->SumWorkoutsBike(tmTime, nDays);
                str.Format("%d, ", nWorkouts);
                strRet += str;
                double dMinutes = pUser->SumMinutesBike(tmTime, nDays); 
                strRet += CDlgHelper::FormatTimeNoDecimal(dMinutes);
                double dMiles = pUser->SumMilesBike(tmTime, nDays);
                str.Format("%.2lf", dMiles);
                strRet += ", ";
                strRet += str;
                break;
            }

        default:
            {
                break;
            }
        }
    }

    return strRet;
}


CString CRunningLogView::GetAnnotationSwim(int nType, COleDateTime tmTime, bool& rfUpcomingRace, bool& rfUpcomingWorkout)
{
    rfUpcomingRace = false;
	rfUpcomingWorkout = false;
    CString strRet;
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        switch(nType)
        {
        case DAYTYPE_NORMAL:
        case DAYTYPE_GRAYED:
            {
                CDayLog* pDay = pUser->GetDayAt(tmTime);
                CUpcomingRace* pRace = pUser->GetUpcomingRaceAt(tmTime);
                CUpcomingWorkout* pWorkout = pUser->GetUpcomingWorkoutAt(tmTime);

                int nTotal = 0;

                if(NULL != pDay)
                {
                    strRet = "Swim: ";
                    WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
                    for(int i = 0; i < rarWorkouts.GetCount(); i++)
                    {
                        CWorkout* pWorkout = rarWorkouts.GetAt(i);
                        if(NULL != pWorkout)
                        {
                            if(ACTIVITY_SWIMMING == pWorkout->GetActivityType())
                            {
                                if(0 != nTotal)
                                {
                                    strRet += ", ";
                                    nTotal++;
                                }
                                strRet += pWorkout->GetDisplayName();

                                CString strDist;
                                if(BASED_ON_TIME == GetBaseTypeSwim())
                                {
                                    double dSeconds = pWorkout->GetSeconds();
                                    if(CUtil::HasData(dSeconds))
                                    {
                                        strDist = CDlgHelper::FormatTimeNoDecimal(dSeconds / 60.0);
                                    }
                                }
                                else
                                {
                                    double dMiles = pWorkout->GetMiles();
                                    if(CUtil::HasData(dMiles))
                                    {
										strDist = FormatDecimals(pUser->GetSwimDecimals(), dMiles);
                                    }
                                }
                                if(false == strDist.IsEmpty())
                                {
                                    strRet += " (";
                                    strRet += strDist;
                                    strRet += ")";
                                }
                                nTotal++;
                            }
                        }
                    }

                    if(nTotal == 0)
                    {
                        strRet = "";
                    }
                }
                else if((NULL != pRace) && (!CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), pRace->GetDate())))
                {
                    strRet = pRace->GetLineTwo();
                    rfUpcomingRace = true;
                }
  
                else if((NULL != pWorkout) && (!CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), pWorkout->GetDate())))
                {
                    strRet = pWorkout->GetLineTwo();
                    rfUpcomingWorkout = true;
                }

                break;
            }

        case DAYTYPE_WEEKSUM:
            {
                strRet = "Swim: ";
                CString str;
                int nWorkouts = pUser->SumWorkoutsSwim(tmTime, 7);
                str.Format("%d, ", nWorkouts);
                strRet += str;
                double dMinutes = pUser->SumMinutesSwim(tmTime, 7); 
                strRet += CDlgHelper::FormatTimeNoDecimal(dMinutes);
                double dMiles = pUser->SumMilesSwim(tmTime, 7);
                str.Format("%.2lf", dMiles);
                strRet += ", ";
                strRet += str;
                break;
            }

        case DAYTYPE_MONTHSUM:
            {
                strRet = "Swim: ";
                CString str;
                int nDays = CUtil::GetNumDaysInMonth(tmTime.GetYear(), tmTime.GetMonth());
                int nWorkouts = pUser->SumWorkoutsSwim(tmTime, nDays);
                str.Format("%d, ", nWorkouts);
                strRet += str;
                double dMinutes = pUser->SumMinutesSwim(tmTime, nDays); 
                strRet += CDlgHelper::FormatTimeNoDecimal(dMinutes);
                double dMiles = pUser->SumMilesSwim(tmTime, nDays);
                str.Format("%.2lf", dMiles);
                strRet += ", ";
                strRet += str;
                break;
            }

        default:
            {
                break;
            }
        }
    }

    return strRet;
}



CString CRunningLogView::GetAnnotationStrength(int nType, COleDateTime tmTime, bool& rfUpcomingRace, bool& rfUpcomingWorkout)
{
	rfUpcomingRace = false;
	rfUpcomingWorkout = false;

    CString strRet;
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        switch(nType)
        {
        case DAYTYPE_NORMAL:
        case DAYTYPE_GRAYED:
            {
                CDayLog* pDay = pUser->GetDayAt(tmTime);
                CUpcomingRace* pRace = pUser->GetUpcomingRaceAt(tmTime);
                CUpcomingWorkout* pWorkout = pUser->GetUpcomingWorkoutAt(tmTime);

                int nTotal = 0;

                if(NULL != pDay)
                {
                    strRet = "Str: ";
                    WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
                    for(int i = 0; i < rarWorkouts.GetCount(); i++)
                    {
                        CWorkout* pWorkout = rarWorkouts.GetAt(i);
                        if(NULL != pWorkout)
                        {
                            if(ACTIVITY_STRENGTH == pWorkout->GetActivityType())
                            {
                                if(0 != nTotal)
                                {
                                    strRet += ", ";
                                    nTotal++;
                                }
                                strRet += pWorkout->GetDisplayName();

                                CString strDist;
                                double dSeconds = pWorkout->GetSeconds();
                                if(CUtil::HasData(dSeconds))
                                {
                                    strDist = CDlgHelper::FormatTimeNoDecimal(dSeconds / 60.0);
                                    strRet += " (";
                                    strRet += strDist;
                                    strRet += ")";
                                }
                                nTotal++;
                            }
                        }
                    }

					if(nTotal == 0)
					{
						strRet = "";
					}
                }


                else if((NULL != pRace) && (!CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), pRace->GetDate())))
                {
                    strRet = pRace->GetLineThree();
                    rfUpcomingRace = true;
                }
  
                else if((NULL != pWorkout) && (!CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), pWorkout->GetDate())))
                {
                    strRet = pWorkout->GetLineThree();
                    rfUpcomingWorkout = true;
                }
                
                break;
            }

        case DAYTYPE_WEEKSUM:
            {
                strRet = "Str: ";
                CString str;
                int nWorkouts = pUser->SumWorkoutsStrength(tmTime, 7);
                str.Format("%d, ", nWorkouts);
                strRet += str;
                double dMinutes = pUser->SumMinutesStrength(tmTime, 7); 
                strRet += CDlgHelper::FormatTimeNoDecimal(dMinutes);
                break;
            }

        case DAYTYPE_MONTHSUM:
            {
                strRet = "Str: ";
                CString str;
                int nDays = CUtil::GetNumDaysInMonth(tmTime.GetYear(), tmTime.GetMonth());
                int nWorkouts = pUser->SumWorkoutsStrength(tmTime, nDays);
                str.Format("%d, ", nWorkouts);
                strRet += str;
                double dMinutes = pUser->SumMinutesStrength(tmTime, nDays); 
                strRet += CDlgHelper::FormatTimeNoDecimal(dMinutes);
                break;
            }

        default:
            {
                break;
            }
        }
    }

    return strRet;
}


CString CRunningLogView::GetAnnotationRace(int nType, COleDateTime tmTime)
{
    CString strRet;
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        switch(nType)
        {
        case DAYTYPE_NORMAL:
        case DAYTYPE_GRAYED:
            {
                CDayLog* pDay = pUser->GetDayAt(tmTime);

                int nTotal = 0;

                if(NULL != pDay)
                {
                    strRet = "Race: ";
                    WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
                    for(int i = 0; i < rarWorkouts.GetCount(); i++)
                    {
                        CWorkout* pWorkout = rarWorkouts.GetAt(i);
                        if(NULL != pWorkout)
                        {
                            if(ACTIVITY_RACE == pWorkout->GetActivityType())
                            {
                                if(0 != nTotal)
                                {
                                    strRet += ", ";
                                    nTotal++;
                                }
                                strRet += pWorkout->GetDisplayName();
                                strRet += " (";
                                CString strDist; 

                                switch(pWorkout->GetType())
                                {
                                case RACETYPE_RUN:
                                    {
                                        if(BASED_ON_TIME == GetBaseTypeRun())
                                        {
                                            double dSeconds = pWorkout->GetSeconds();
                                            if(CUtil::HasData(dSeconds))
                                            {
                                                strDist = CDlgHelper::FormatTimeNoDecimal(dSeconds / 60.0);
                                            }
                                        }
                                        else
                                        {
                                            double dMiles = pWorkout->GetMiles();
                                            if(CUtil::HasData(dMiles))
                                            {
												strDist = FormatDecimals(pUser->GetRunDecimals(), dMiles);
                                            }
                                        }
                                        break;
                                    }

                                case RACETYPE_BIKE:
                                    {
                                        if(BASED_ON_TIME == GetBaseTypeBike())
                                        {
                                            double dSeconds = pWorkout->GetSeconds();
                                            if(CUtil::HasData(dSeconds))
                                            {
                                                strDist = CDlgHelper::FormatTimeNoDecimal(dSeconds / 60.0);
                                            }
                                        }
                                        else
                                        {
                                            double dMiles = pWorkout->GetMiles();
                                            if(CUtil::HasData(dMiles))
                                            {
												strDist = FormatDecimals(pUser->GetBikeDecimals(), dMiles);
                                            }
                                        }
                                        break;
                                    }

                                case RACETYPE_SWIM:
                                    {
                                        if(BASED_ON_TIME == GetBaseTypeSwim())
                                        {
                                            double dSeconds = pWorkout->GetSeconds();
                                            if(CUtil::HasData(dSeconds))
                                            {
                                                strDist = CDlgHelper::FormatTimeNoDecimal(dSeconds / 60.0);
                                            }
                                        }
                                        else
                                        {
                                            double dMiles = pWorkout->GetMiles();
                                            if(CUtil::HasData(dMiles))
                                            {
												strDist = FormatDecimals(pUser->GetSwimDecimals(), dMiles);
                                            }
                                        }
                                        break;
                                    }

                                case RACETYPE_DUATHLON:
                                    {
                                        if(BASED_ON_TIME == GetBaseTypeRun())
                                        {
                                            double dSeconds = pWorkout->GetLeg1Seconds();
                                            if(CUtil::HasData(dSeconds))
                                            {
                                                strDist = CDlgHelper::FormatTimeNoDecimal(dSeconds / 60.0);
                                            }
                                        }
                                        else
                                        {
                                            double dMiles = pWorkout->GetLeg1Miles();
                                            if(CUtil::HasData(dMiles))
                                            {
												strDist = FormatDecimals(pUser->GetRunDecimals(), dMiles);
											}
                                        }

                                        strDist += "/";

                                        if(BASED_ON_TIME == GetBaseTypeBike())
                                        {
                                            double dSeconds = pWorkout->GetLeg2Seconds();
                                            if(CUtil::HasData(dSeconds))
                                            {
                                                strDist += CDlgHelper::FormatTimeNoDecimal(dSeconds / 60.0);
                                            }
                                        }
                                        else
                                        {
                                            double dMiles = pWorkout->GetLeg2Miles();
                                            if(CUtil::HasData(dMiles))
                                            {
                                                CString str2;
												str2 = FormatDecimals(pUser->GetBikeDecimals(), dMiles);
                                                strDist += str2;
                                            }
                                        }

                                        strDist += "/";

                                        if(BASED_ON_TIME == GetBaseTypeRun())
                                        {
                                            double dSeconds = pWorkout->GetLeg3Seconds();
                                            if(CUtil::HasData(dSeconds))
                                            {
                                                strDist += CDlgHelper::FormatTimeNoDecimal(dSeconds / 60.0);
                                            }
                                        }
                                        else
                                        {
                                            double dMiles = pWorkout->GetLeg3Miles();
                                            if(CUtil::HasData(dMiles))
                                            {
                                                CString str2;
												str2 = FormatDecimals(pUser->GetRunDecimals(), dMiles);
                                                strDist += str2;
                                            }
                                        }
                                        break;
                                    }

                                case RACETYPE_TRIATHLON:
                                    {
                                        if(BASED_ON_TIME == GetBaseTypeSwim())
                                        {
                                            double dSeconds = pWorkout->GetLeg1Seconds();
                                            if(CUtil::HasData(dSeconds))
                                            {
                                                strDist = CDlgHelper::FormatTimeNoDecimal(dSeconds / 60.0);
                                            }
                                        }
                                        else
                                        {
                                            double dMiles = pWorkout->GetLeg1Miles();
                                            if(CUtil::HasData(dMiles))
                                            {
												strDist = FormatDecimals(pUser->GetSwimDecimals(), dMiles);
                                            }
                                        }

                                        strDist += "/";

                                        if(BASED_ON_TIME == GetBaseTypeBike())
                                        {
                                            double dSeconds = pWorkout->GetLeg2Seconds();
                                            if(CUtil::HasData(dSeconds))
                                            {
                                                strDist += CDlgHelper::FormatTimeNoDecimal(dSeconds / 60.0);
                                            }
                                        }
                                        else
                                        {
                                            double dMiles = pWorkout->GetLeg2Miles();
                                            if(CUtil::HasData(dMiles))
                                            {
                                                CString str2;
												str2 = FormatDecimals(pUser->GetBikeDecimals(), dMiles);
                                                strDist += str2;
                                            }
                                        }

                                        strDist += "/";

                                        if(BASED_ON_TIME == GetBaseTypeRun())
                                        {
                                            double dSeconds = pWorkout->GetLeg3Seconds();
                                            if(CUtil::HasData(dSeconds))
                                            {
                                                strDist += CDlgHelper::FormatTimeNoDecimal(dSeconds / 60.0);
                                            }
                                        }
                                        else
                                        {
                                            double dMiles = pWorkout->GetLeg3Miles();
                                            if(CUtil::HasData(dMiles))
                                            {
                                                CString str2;
												str2 = FormatDecimals(pUser->GetRunDecimals(), dMiles);
                                                strDist += str2;
                                            }
                                        }

                                        break;
                                    }
                                }

                                strRet += strDist;
                                strRet += ")";
                                nTotal++;
                            }
                        }
                    }
                }

                if(nTotal == 0)
                {
                    strRet = "";
                }

                break;
            }

        case DAYTYPE_WEEKSUM:
            {
                break;
            }

        case DAYTYPE_MONTHSUM:
            {
                break;
            }

        default:
            {
                break;
            }
        }
    }

    return strRet;
}


int CRunningLogView::HitTest(CPoint point) const
{
    if(NULL == m_pCalendar)
    {
        return NO_SELECTION;
    }

    CRect rc;
    GetClientRect(&rc);

    int nXLOffset;
    int nXROffset;
    int nYTOffset;
    int nYBOffset;
    GetOffsets(&nXLOffset, &nXROffset, &nYTOffset, &nYBOffset);

    CRect rcDays(nXLOffset, nYTOffset, rc.Width() - nXROffset, rc.Height() - nYBOffset);
    CSize szBox = m_pCalendar->GetBoxSize();
    int nMiddle = rc.Width() - (nXROffset / 2);
    CRect rcRectMonth(nMiddle - (szBox.cx / 2), (nYTOffset - szBox.cy) / 2, nMiddle + (szBox.cx / 2), (nYTOffset + szBox.cy) / 2);
    CRect rcRectWeek(nMiddle - (szBox.cx / 2), nYTOffset, nMiddle + (szBox.cx / 2), rc.Height() - nYBOffset);

    if(rcDays.PtInRect(point))
    {
        int nXOffset = m_pCalendar->GetMinWidthOffset();
        int nYOffset = m_pCalendar->GetMinHeightOffset();
        int nWidthOffset = nXOffset + ((rc.Width() % 7) / 2);

        int nWeeks = CUtil::GetNumWeeks(GetCurrentDate(), GetFirstDayOfWeek());

        CPoint ptTopLeft(rcDays.left + nWidthOffset, rcDays.top + nYOffset);

        COleDateTime tmCur = CUtil::GetFirstVisibleDay(GetCurrentDate(), GetFirstDayOfWeek());
        for(int j = 0; j < nWeeks; j++)
        {
            ptTopLeft.x = rcDays.left + nWidthOffset;

            for(int i = 0; i < 7; i++)
            {
                CRect rcRect(ptTopLeft.x, ptTopLeft.y, ptTopLeft.x + szBox.cx, ptTopLeft.y + szBox.cy);
                if(rcRect.PtInRect(point))
                {
                    return (7 * j + i + 1);
                }

                ptTopLeft.x += szBox.cx + m_pCalendar->GetHorzSpacing();
                tmCur = CUtil::AddDay(tmCur);
            }

            ptTopLeft.y += szBox.cy + m_pCalendar->GetVertSpacing();
        }
    }

    else if(rcRectMonth.PtInRect(point))
    {
        return HIT_MONTHSUM;
    }

    else if(rcRectWeek.PtInRect(point))
    {
        CRect rcDraw = rcRectWeek;

        rcDraw.top += m_pCalendar->GetMinHeightOffset();

        COleDateTime tmTime = CUtil::GetFirstOfMonth(GetCurrentDate());
        CPoint ptTopLeft(rcDraw.left, rcDraw.top);

        int nWeeks = CUtil::GetNumWeeks(tmTime, GetFirstDayOfWeek());
        for(int i = 0; i < nWeeks; i++)
        {
            tmTime = CUtil::OffsetDay(tmTime, 7);

            CRect rcRect(ptTopLeft.x, ptTopLeft.y, ptTopLeft.x + szBox.cx, ptTopLeft.y + szBox.cy);
            if(rcRect.PtInRect(point))
            {
                return (HIT_WEEKSUM1 + i);
            }
            ptTopLeft.y += szBox.cy + m_pCalendar->GetVertSpacing();
        }        
    }

    return NO_SELECTION;
}


void CRunningLogView::RedoUnits(int nDistRunUnitsOld, int nDistBikeUnitsOld, int nDistSwimUnitsOld,
                                int nHeightUnitsOld, int nWeightUnitsOld, int nTempUnitsOld)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->AdjustUnits(nDistRunUnitsOld, nDistBikeUnitsOld, nDistSwimUnitsOld, 
                           nHeightUnitsOld, nWeightUnitsOld, nTempUnitsOld);
    }
}


bool CRunningLogView::MakeCorrectDialog(void)
{
    COleDateTime tmCur = GetCurrentDate();

    int nDay = GetHighlightDay();
    int nStartDay = GetFirstDayOfWeek();

    bool fResult = false;

    if((IsUserOpen()) && (CUtil::IsHighlightDayADay(tmCur, nDay, nStartDay)))
    {
        COleDateTime tmHighlight = CUtil::GetHighlightedDate(tmCur, nDay, nStartDay);
        if(CUtil::IsLaterDayThan(tmHighlight, COleDateTime::GetCurrentTime()))
        {
            fResult = MakeUpcomingWorkoutDialog();
        }
        else
        {
            fResult = MakeWorkoutDialog();
        }
    }
    
    return fResult;
}


bool CRunningLogView::MakeUpcomingRaceDialog(void)
{
    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nStartDay = GetFirstDayOfWeek();

    bool fResult = false;

    if(CUtil::IsHighlightDayADay(tmCur, nDay, nStartDay))
    {
        CUpcomingRaceDlg dlg;
        COleDateTime tmHighlighted = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());

        dlg.SetDate(tmHighlighted);
        CUser* pUser = GetUser();

		if(NULL != pUser)
		{
			if((NULL != pUser->GetUpcomingRaceAt(tmHighlighted)) || (NULL != pUser->GetUpcomingWorkoutAt(tmHighlighted)))
			{
				AfxMessageBox("You can only enter one planned workout or upcoming race on each day.");
				return false;
			}

			if(IDOK == dlg.DoModal())
			{
				CUpcomingRace* pRace = new CUpcomingRace;
				if(NULL != pRace)
				{
					pRace->SetDate(dlg.GetDate());
					pRace->SetLineOne(dlg.GetLineOne());
					pRace->SetLineTwo(dlg.GetLineTwo());
					pRace->SetLineThree(dlg.GetLineThree());

					pUser->AddUpcomingRace(pRace);

					fResult = true;
				}
			}
		}
    }

    if(fResult)
    {
        InvalidateRect(NULL);
        SetModified(true);
    }

    return fResult;
}


bool CRunningLogView::MakeUpcomingWorkoutDialog(void)
{
    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nStartDay = GetFirstDayOfWeek();

	bool fResult = false;

    if(CUtil::IsHighlightDayADay(tmCur, nDay, nStartDay))
    {
        CUpcomingWorkoutDlg dlg;
        COleDateTime tmHighlighted = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());

        dlg.SetDate(tmHighlighted);
        CUser* pUser = GetUser();

		if(NULL != pUser)
		{
			if((NULL != pUser->GetUpcomingRaceAt(tmHighlighted)) || (NULL != pUser->GetUpcomingWorkoutAt(tmHighlighted)))
			{
				AfxMessageBox("You can only enter one planned workout or upcoming race on each day.");
				return false;
			}

			if(IDOK == dlg.DoModal())
			{
				CUpcomingWorkout* pWorkout = new CUpcomingWorkout;
				if(NULL != pWorkout)
				{
					pWorkout->SetDate(dlg.GetDate());
					pWorkout->SetLineOne(dlg.GetLineOne());
					pWorkout->SetLineTwo(dlg.GetLineTwo());
					pWorkout->SetLineThree(dlg.GetLineThree());

					pUser->AddUpcomingWorkout(pWorkout);

					fResult = true;
				}
			}
		}
    }

    if(fResult)
    {
        InvalidateRect(NULL);
        SetModified(true);
    }

    return fResult;
}


CString CRunningLogView::FormatDecimals(int nDecimals, double dVal)
{
	CString strRet;

	if(0 == nDecimals)
	{
		strRet.Format("%d", (int)dVal);
	}
	else if(1 == nDecimals)
	{
		strRet.Format("%.1lf", dVal);
	}
	else if(2 == nDecimals)
	{
		strRet.Format("%.2lf", dVal);
	}
	else if(3 == nDecimals)
	{
		strRet.Format("%.3lf", dVal);
	}
	else if(4 == nDecimals)
	{
		strRet.Format("%.4lf", dVal);
	}
	else if(5 == nDecimals)
	{
		strRet.Format("%.5lf", dVal);
	}

	return strRet;
}

	
bool CRunningLogView::GetDayData(COleDateTime tmCur, CWorkoutStartDlg& rdlgOld)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CDayLog* pDay = pUser->GetDayAt(tmCur);
        if(NULL != pDay)
        {
            int iTot = pDay->SumTotalWorkouts();
            if(iTot > 0)
            {
                CWorkout* pWorkout = pDay->GetRefWorkoutArray().ElementAt(iTot - 1);
                if(NULL != pWorkout)
                {
                    rdlgOld.SetWeight(pWorkout->GetWeight());
                    rdlgOld.SetPrevNightSleep(pWorkout->GetPrevNightSleep());
                    COleDateTime tmLast = pWorkout->GetTimeStart();

					COleDateTimeSpan tmSpan(0, 0, 5, (int)pWorkout->GetSeconds());

					COleDateTime tmNew = tmLast + tmSpan;

					// don't allow the estimated time to move into the next day
					if(tmNew.GetDay() != tmLast.GetDay())
					{
						tmNew = tmLast;
					}

					rdlgOld.SetTime(tmNew);
                    
                    rdlgOld.SetInjured(pWorkout->IsInjured());
					rdlgOld.SetSick(pWorkout->IsSick());
                    return true;
                }
            }
        }
    }
    
    return false;
}             


void CRunningLogView::MakeOpenUserDialog(CString strFile /* = "" */)
{
    InvalidateRect(NULL);

	if(true == strFile.IsEmpty())
	{
		COpenUserDlg dlg;
		if(IDOK == dlg.DoModal())
		{
			strFile = dlg.GetSelectedFile();
		}
		else
		{
			return;
		}
	}
	else
	{
		strFile = strFile.Right(strFile.GetLength() - strFile.ReverseFind('\\') - 1);
		strFile = strFile.Left(strFile.GetLength() - 4);
	}

	CUser* pUser = new CUser;
	if(NULL != pUser)
	{
		bool fOpen = CUtil::ReadXML(pUser, strFile);
		SetUserOpen(fOpen);

		if(!fOpen)
		{
			AfxMessageBox("There was a problem reading the file.");
			return;
		}

        SetUser(pUser);
        DoRegistryData(false);
    }

    CRect rc;
    GetClientRect(&rc);
    MakeGradient(rc.Width(), rc.Height());
    SetButtonColors(m_pButtonPrev);
    SetButtonColors(m_pButtonNext);
    AdjustTitleFontSize();
    SetWindowTitle();
    InvalidateRect(NULL);
}


bool CRunningLogView::MakeWorkoutDialog(void)
{
    COleDateTime tmCur = GetCurrentDate();
    int nDay = GetHighlightDay();
    int nStartDay = GetFirstDayOfWeek();

    bool fResult = false;

    if(CUtil::IsHighlightDayADay(tmCur, nDay, nStartDay))
    {
        CWorkoutStartDlg dlgStart;
        COleDateTime tmHighlighted = CUtil::GetHighlightedDate(GetCurrentDate(), GetHighlightDay(), GetFirstDayOfWeek());

        dlgStart.SetDate(tmHighlighted);
        bool fSet = GetDayData(tmHighlighted, dlgStart);
        dlgStart.SetPreset(fSet);

        CUser* pUser = GetUser();

        if((IDOK == dlgStart.DoModal()) && (NULL != pUser))
        {
            switch(dlgStart.GetActivityType())
            {
            case ACTIVITY_RUNNING:
                {
                    switch(dlgStart.GetWorkoutType())
                    {
                    case RUNTYPE_EZ:
                        {
                            CRunWorkoutEZDlg dlg(pUser->GetRefLocationRunArray(), pUser->GetRefShoesRunArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRunEZWorkout* pWorkout = new CRunEZWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationRun(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesRun(dlg.GetShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case RUNTYPE_NORMAL:
                        {
                            CRunWorkoutNormalDlg dlg(pUser->GetRefLocationRunArray(), pUser->GetRefShoesRunArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRunNormalWorkout* pWorkout = new CRunNormalWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
  									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetLocationRun(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesRun(dlg.GetShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }                    
                            break;   
                        }

                    case RUNTYPE_HARD:
                        {
                            CRunWorkoutHardDlg dlg(pUser->GetRefLocationRunArray(), pUser->GetRefShoesRunArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRunHardWorkout* pWorkout = new CRunHardWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetLocationRun(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesRun(dlg.GetShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }                    
                            break;   
                        }                    

                    case RUNTYPE_POOL:
                        {
                            CRunWorkoutPoolDlg dlg(pUser->GetRefLocationRunArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRunPoolWorkout* pWorkout = new CRunPoolWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetLocationRun(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case RUNTYPE_TEMPO:
                        {
                            CRunWorkoutTempoDlg dlg(pUser->GetRefLocationRunArray(), pUser->GetRefShoesRunArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRunTempoWorkout* pWorkout = new CRunTempoWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetLocationRun(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesRun(dlg.GetShoes());
                                    pWorkout->SetSpecialMiles(dlg.GetSpecialMiles());
                                    pWorkout->SetSpecialSeconds(dlg.GetSpecialSeconds());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case RUNTYPE_INTERVALS:
                        {
                            CRunWorkoutIntervalDlg dlg(pUser->GetRefLocationRunArray(), pUser->GetRefShoesRunArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRunIntervalWorkout* pWorkout = new CRunIntervalWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetLocationRun(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesRun(dlg.GetShoes());
                                    pWorkout->SetSpecialMiles(dlg.GetSpecialMiles());
                                    pWorkout->SetSpecialSeconds(dlg.GetSpecialSeconds());
                                    pWorkout->SetSpecialShoesRun(dlg.GetSpecialShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case RUNTYPE_HILLS:
                        {
                            CRunWorkoutHillDlg dlg(pUser->GetRefLocationRunArray(), pUser->GetRefShoesRunArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRunHillWorkout* pWorkout = new CRunHillWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetLocationRun(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesRun(dlg.GetShoes());
                                    pWorkout->SetSpecialMiles(dlg.GetSpecialMiles());
                                    pWorkout->SetSpecialSeconds(dlg.GetSpecialSeconds());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case RUNTYPE_TREADMILL:
                        {
                            CRunWorkoutTreadmillDlg dlg(pUser->GetRefLocationRunArray(), pUser->GetRefShoesRunArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRunTreadmillWorkout* pWorkout = new CRunTreadmillWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationRun(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetShoesRun(dlg.GetShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case RUNTYPE_OTHER:
                        {
                            CRunWorkoutMiscDlg dlg(pUser->GetRefLocationRunArray(), pUser->GetRefShoesRunArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRunMiscWorkout* pWorkout = new CRunMiscWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetCountedOnShoes(dlg.CountOnShoes());
                                    pWorkout->SetLocationRun(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesRun(dlg.GetShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    default:
                        {
                            break;
                        }
                    }

                    break;
                }

            case ACTIVITY_BIKING:
                {
                    switch(dlgStart.GetWorkoutType())
                    {
                    case BIKETYPE_EZ:
                        {
                            CBikeWorkoutEZDlg dlg(pUser->GetRefLocationBikeArray(), pUser->GetRefShoesBikeArray(), 
                                                  pUser->GetRefBikeArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CBikeEZWorkout* pWorkout = new CBikeEZWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationBike(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetBike(dlg.GetBike());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesBike(dlg.GetShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case BIKETYPE_NORMAL:
                        {
                            CBikeWorkoutNormalDlg dlg(pUser->GetRefLocationBikeArray(), pUser->GetRefShoesBikeArray(),
                                                      pUser->GetRefBikeArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CBikeNormalWorkout* pWorkout = new CBikeNormalWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationBike(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetBike(dlg.GetBike());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesBike(dlg.GetShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case BIKETYPE_HARD:
                        {
                            CBikeWorkoutHardDlg dlg(pUser->GetRefLocationBikeArray(), pUser->GetRefShoesBikeArray(),
                                                    pUser->GetRefBikeArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CBikeHardWorkout* pWorkout = new CBikeHardWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetLocationBike(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetBike(dlg.GetBike());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesBike(dlg.GetShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case BIKETYPE_INTERVALS:
                        {
                            CBikeWorkoutIntervalDlg dlg(pUser->GetRefLocationBikeArray(), pUser->GetRefShoesBikeArray(),
                                                        pUser->GetRefBikeArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CBikeIntervalWorkout* pWorkout = new CBikeIntervalWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationBike(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetBike(dlg.GetBike());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesBike(dlg.GetShoes());
                                    pWorkout->SetSpecialMiles(dlg.GetSpecialMiles());
                                    pWorkout->SetSpecialSeconds(dlg.GetSpecialSeconds());
                                    pWorkout->SetSpecialShoesBike(dlg.GetSpecialShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case BIKETYPE_HILLS:
                        {
                            CBikeWorkoutHillDlg dlg(pUser->GetRefLocationBikeArray(), pUser->GetRefShoesBikeArray(),
                                                    pUser->GetRefBikeArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CBikeHillWorkout* pWorkout = new CBikeHillWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationBike(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetBike(dlg.GetBike());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesBike(dlg.GetShoes());
                                    pWorkout->SetSpecialMiles(dlg.GetSpecialMiles());
                                    pWorkout->SetSpecialSeconds(dlg.GetSpecialSeconds());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case BIKETYPE_TRAINER:
                        {
                            CBikeWorkoutTrainerDlg dlg(pUser->GetRefLocationBikeArray(), pUser->GetRefShoesBikeArray(),
                                                       pUser->GetRefBikeArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CBikeTrainerWorkout* pWorkout = new CBikeTrainerWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationBike(dlg.GetLocation());
                                    pWorkout->SetBike(dlg.GetBike());
                                    pWorkout->SetCountedOnShoes(dlg.CountOnShoes());
                                    pWorkout->SetCountedOnBike(dlg.CountOnBike());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetShoesBike(dlg.GetShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case BIKETYPE_OTHER:
                        {
                            CBikeWorkoutMiscDlg dlg(pUser->GetRefLocationBikeArray(), pUser->GetRefShoesBikeArray(),
                                                    pUser->GetRefBikeArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CBikeMiscWorkout* pWorkout = new CBikeMiscWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetBike(dlg.GetBike());
                                    pWorkout->SetCountedOnShoes(dlg.CountOnShoes());
                                    pWorkout->SetCountedOnBike(dlg.CountOnBike());
                                    pWorkout->SetLocationBike(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesBike(dlg.GetShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

					 case BIKETYPE_MOUNTAINBIKE:
                        {
                            CBikeWorkoutMountainBikeDlg dlg(pUser->GetRefLocationBikeArray(), pUser->GetRefShoesBikeArray(), 
															pUser->GetRefBikeArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CBikeMountainBikeWorkout* pWorkout = new CBikeMountainBikeWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
 									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationBike(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetBike(dlg.GetBike());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesBike(dlg.GetShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case BIKETYPE_TIMETRIAL:
                        {
                            CBikeWorkoutTimeTrialDlg dlg(pUser->GetRefLocationBikeArray(), pUser->GetRefShoesBikeArray(),
                                                        pUser->GetRefBikeArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CBikeTimeTrialWorkout* pWorkout = new CBikeTimeTrialWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationBike(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetBike(dlg.GetBike());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesBike(dlg.GetShoes());
                                    pWorkout->SetSpecialMiles(dlg.GetSpecialMiles());
                                    pWorkout->SetSpecialSeconds(dlg.GetSpecialSeconds());
                                    pWorkout->SetSpecialShoesBike(dlg.GetSpecialShoes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                   default:
                        {
                            break;
                        }
                    }

                    break;
                }

			case ACTIVITY_SWIMMING:
				{
					switch(dlgStart.GetWorkoutType())
					{
                    case SWIMTYPE_EZ:
                        {
                            CSwimWorkoutEZDlg dlg(pUser->GetRefLocationSwimArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CSwimEZWorkout* pWorkout = new CSwimEZWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationSwim(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetChoppiness(dlg.GetChoppiness());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

					case SWIMTYPE_NORMAL:
                        {
                            CSwimWorkoutNormalDlg dlg(pUser->GetRefLocationSwimArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CSwimNormalWorkout* pWorkout = new CSwimNormalWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationSwim(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetChoppiness(dlg.GetChoppiness());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case SWIMTYPE_HARD:
                        {
                            CSwimWorkoutHardDlg dlg(pUser->GetRefLocationSwimArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CSwimHardWorkout* pWorkout = new CSwimHardWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationSwim(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetChoppiness(dlg.GetChoppiness());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case SWIMTYPE_DRILLS:
                        {
                            CSwimWorkoutDrillsDlg dlg(pUser->GetRefLocationSwimArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CSwimDrillWorkout* pWorkout = new CSwimDrillWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationSwim(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetChoppiness(dlg.GetChoppiness());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case SWIMTYPE_OTHER:
                        {
                            CSwimWorkoutMiscDlg dlg(pUser->GetRefLocationSwimArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CSwimMiscWorkout* pWorkout = new CSwimMiscWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationSwim(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetChoppiness(dlg.GetChoppiness());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case SWIMTYPE_OPENWATER:
                        {
                            CSwimWorkoutOpenWaterDlg dlg(pUser->GetRefLocationSwimArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CSwimOpenWaterWorkout* pWorkout = new CSwimOpenWaterWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationSwim(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetChoppiness(dlg.GetChoppiness());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case SWIMTYPE_INTERVALS:
                        {
                            CSwimWorkoutIntervalDlg dlg(pUser->GetRefLocationSwimArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CSwimIntervalWorkout* pWorkout = new CSwimIntervalWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationSwim(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetChoppiness(dlg.GetChoppiness());
                                    pWorkout->SetSpecialMiles(dlg.GetSpecialMiles());
                                    pWorkout->SetSpecialSeconds(dlg.GetSpecialSeconds());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    default:
                        {
                            break;
                        }
                    }
                    break;
                }

            case ACTIVITY_STRENGTH:
                {
                    switch(dlgStart.GetWorkoutType())
                    {
                    case STRENGTHTYPE_ABS:
                        {
                            CStrengthWorkoutAbsDlg dlg(pUser->GetRefLocationStrengthArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CStrengthAbsWorkout* pWorkout = new CStrengthAbsWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationStrength(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case STRENGTHTYPE_WEIGHTS:
                        {
                            CStrengthWorkoutWeightsDlg dlg(pUser->GetRefLocationStrengthArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CStrengthWeightsWorkout* pWorkout = new CStrengthWeightsWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationStrength(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case STRENGTHTYPE_OTHER:
                        {
                            CStrengthWorkoutMiscDlg dlg(pUser->GetRefLocationStrengthArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CStrengthMiscWorkout* pWorkout = new CStrengthMiscWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
 									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
									pWorkout->SetDisplayName(dlg.GetDispName());
                                    pWorkout->SetLocationStrength(dlg.GetLocation());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    default:
                        {
                            break;
                        }
                    }
                    break;
                }

            case ACTIVITY_RACE:
                {
                    switch(dlgStart.GetWorkoutType())
                    {
                    case RACETYPE_RUN:
                        {
                            CRaceWorkoutRunDlg dlg(pUser->GetRefCourseRunArray(), pUser->GetRefShoesRunArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRaceRunWorkout* pWorkout = new CRaceRunWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetCourseRun(dlg.GetCourse());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetDisplayName(dlg.GetDisplayName());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesRun(dlg.GetShoes());
                                    pWorkout->SetSpecialSeconds(dlg.GetSpecialSeconds());
                                    pWorkout->SetSpecialShoesRun(dlg.GetSpecialShoes());
                                    pWorkout->SetRacePosition(dlg.GetRacePosition());
                                    pWorkout->SetRaceNumber(dlg.GetRaceNumber());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case RACETYPE_BIKE:
                        {
                            CRaceWorkoutBikeDlg dlg(pUser->GetRefCourseBikeArray(), pUser->GetRefShoesBikeArray(), pUser->GetRefBikeArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRaceBikeWorkout* pWorkout = new CRaceBikeWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetCourseBike(dlg.GetCourse());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetDisplayName(dlg.GetDisplayName());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetBike(dlg.GetBike());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetWind(dlg.GetWind());
                                    pWorkout->SetShoesBike(dlg.GetShoes());
                                    pWorkout->SetSpecialSeconds(dlg.GetSpecialSeconds());
                                    pWorkout->SetSpecialShoesBike(dlg.GetSpecialShoes());
                                    pWorkout->SetRacePosition(dlg.GetRacePosition());
                                    pWorkout->SetRaceNumber(dlg.GetRaceNumber());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case RACETYPE_SWIM:
                        {
                            CRaceWorkoutSwimDlg dlg(pUser->GetRefCourseSwimArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRaceSwimWorkout* pWorkout = new CRaceSwimWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetCourseSwim(dlg.GetCourse());
                                    pWorkout->SetSeconds(dlg.GetSeconds());
                                    pWorkout->SetDisplayName(dlg.GetDisplayName());
                                    pWorkout->SetHR(dlg.GetHR());
                                    pWorkout->SetTemperature(dlg.GetTemperature());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetMiles(dlg.GetMiles());
                                    pWorkout->SetChoppiness(dlg.GetChoppiness());
                                    pWorkout->SetSpecialSeconds(dlg.GetSpecialSeconds());
                                    pWorkout->SetRacePosition(dlg.GetRacePosition());
                                    pWorkout->SetRaceNumber(dlg.GetRaceNumber());

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case RACETYPE_DUATHLON:
                        {
                            CRaceWorkoutDuathlonDlg dlg(pUser->GetRefCourseDuathlonArray(), pUser->GetRefShoesRunArray(),
                                                        pUser->GetRefShoesBikeArray(), pUser->GetRefBikeArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRaceDuathlonWorkout* pWorkout = new CRaceDuathlonWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetCourseDuathlon(dlg.GetCourseDuathlon());
                                    pWorkout->SetDisplayName(dlg.GetDisplayName());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetSeconds(dlg.GetOverallSeconds());
                                    pWorkout->SetTransition1Seconds(dlg.GetTransition1Seconds());
                                    pWorkout->SetTransition2Seconds(dlg.GetTransition2Seconds());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetRacePosition(dlg.GetRacePosition());
                                    pWorkout->SetRaceNumber(dlg.GetRaceNumber());
                                    pWorkout->SetLeg1Seconds(dlg.GetLeg1Seconds());
                                    pWorkout->SetLeg1Miles(dlg.GetLeg1Miles());
                                    pWorkout->SetLeg1Temperature(dlg.GetLeg1Temperature());
                                    pWorkout->SetLeg1HR(dlg.GetLeg1HR());
                                    pWorkout->SetLeg1Wind(dlg.GetLeg1Wind());
                                    pWorkout->SetLeg1Shoes(dlg.GetLeg1Shoes());
                                    pWorkout->SetLeg1RaceSeconds(dlg.GetLeg1RaceSeconds());
                                    pWorkout->SetLeg1RaceShoes(dlg.GetLeg1RaceShoes());
                                    pWorkout->SetLeg2Seconds(dlg.GetLeg2Seconds());
                                    pWorkout->SetLeg2Miles(dlg.GetLeg2Miles());
                                    pWorkout->SetLeg2Temperature(dlg.GetLeg2Temperature());
                                    pWorkout->SetLeg2HR(dlg.GetLeg2HR());
                                    pWorkout->SetLeg2Wind(dlg.GetLeg2Wind());
                                    pWorkout->SetBike(dlg.GetBike());
                                    pWorkout->SetLeg2Shoes(dlg.GetLeg2Shoes());
                                    pWorkout->SetLeg2RaceSeconds(dlg.GetLeg2RaceSeconds());
                                    pWorkout->SetLeg2RaceShoes(dlg.GetLeg2RaceShoes());
                                    pWorkout->SetLeg3Seconds(dlg.GetLeg3Seconds());
                                    pWorkout->SetLeg3Miles(dlg.GetLeg3Miles());
                                    pWorkout->SetLeg3Temperature(dlg.GetLeg3Temperature());
                                    pWorkout->SetLeg3HR(dlg.GetLeg3HR());
                                    pWorkout->SetLeg3Wind(dlg.GetLeg3Wind());
                                    pWorkout->SetLeg3Shoes(dlg.GetLeg3Shoes());
                                    pWorkout->SetLeg3RaceSeconds(dlg.GetLeg3RaceSeconds());
                                    pWorkout->SetLeg3RaceShoes(dlg.GetLeg3RaceShoes());

									pWorkout->SetOverallHR();
									pWorkout->SetOverallTemperature();

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }

                    case RACETYPE_TRIATHLON:
                        {
                            CRaceWorkoutTriathlonDlg dlg(pUser->GetRefCourseTriathlonArray(), pUser->GetRefShoesRunArray(),
                                                        pUser->GetRefShoesBikeArray(), pUser->GetRefBikeArray());
                            if(IDOK == dlg.DoModal())
                            {
                                CDayLog* pDay = pUser->GetDayAtCreate(tmHighlighted);
                                if(NULL == pDay)
                                {
                                    return false;
                                }

                                CRaceTriathlonWorkout* pWorkout = new CRaceTriathlonWorkout;
                                if(NULL != pWorkout)
                                {
                                    pWorkout->SetWeight(dlgStart.GetWeight());
                                    pWorkout->SetTimeStart(dlgStart.GetStartTime());
                                    pWorkout->SetPrevNightSleep(dlgStart.GetPrevNightSleep());
									pWorkout->SetDataFile(dlgStart.GetDataFile());
                                    pWorkout->SetInjured(dlgStart.IsInjured());
									pWorkout->SetSick(dlgStart.IsSick());
                                    pWorkout->SetCourseTriathlon(dlg.GetCourseTriathlon());
                                    pWorkout->SetDisplayName(dlg.GetDisplayName());
                                    pWorkout->SetLong(dlg.IsLong());
                                    pWorkout->SetSeconds(dlg.GetOverallSeconds());
                                    pWorkout->SetTransition1Seconds(dlg.GetTransition1Seconds());
                                    pWorkout->SetTransition2Seconds(dlg.GetTransition2Seconds());
                                    pWorkout->SetNotes(dlg.GetNotes());
                                    pWorkout->SetRacePosition(dlg.GetRacePosition());
                                    pWorkout->SetRaceNumber(dlg.GetRaceNumber());
                                    pWorkout->SetLeg1Seconds(dlg.GetLeg1Seconds());
                                    pWorkout->SetLeg1Miles(dlg.GetLeg1Miles());
                                    pWorkout->SetLeg1Temperature(dlg.GetLeg1Temperature());
                                    pWorkout->SetLeg1HR(dlg.GetLeg1HR());
                                    pWorkout->SetChoppiness(dlg.GetLeg1Choppiness());
                                    pWorkout->SetLeg1RaceSeconds(dlg.GetLeg1RaceSeconds());
                                    pWorkout->SetLeg2Seconds(dlg.GetLeg2Seconds());
                                    pWorkout->SetLeg2Miles(dlg.GetLeg2Miles());
                                    pWorkout->SetLeg2Temperature(dlg.GetLeg2Temperature());
                                    pWorkout->SetLeg2HR(dlg.GetLeg2HR());
                                    pWorkout->SetLeg2Wind(dlg.GetLeg2Wind());
                                    pWorkout->SetBike(dlg.GetBike());
                                    pWorkout->SetLeg2Shoes(dlg.GetLeg2Shoes());
                                    pWorkout->SetLeg2RaceSeconds(dlg.GetLeg2RaceSeconds());
                                    pWorkout->SetLeg2RaceShoes(dlg.GetLeg2RaceShoes());
                                    pWorkout->SetLeg3Seconds(dlg.GetLeg3Seconds());
                                    pWorkout->SetLeg3Miles(dlg.GetLeg3Miles());
                                    pWorkout->SetLeg3Temperature(dlg.GetLeg3Temperature());
                                    pWorkout->SetLeg3HR(dlg.GetLeg3HR());
                                    pWorkout->SetLeg3Wind(dlg.GetLeg3Wind());
                                    pWorkout->SetLeg3Shoes(dlg.GetLeg3Shoes());
                                    pWorkout->SetLeg3RaceSeconds(dlg.GetLeg3RaceSeconds());
                                    pWorkout->SetLeg3RaceShoes(dlg.GetLeg3RaceShoes());

									pWorkout->SetOverallHR();
									pWorkout->SetOverallTemperature();

                                    pDay->AddWorkout(pWorkout);
                                    fResult = true;
                                }
                            }
                            break;
                        }
                    }
                    break;
                }

            default:
                {
                    break;
                }
            }
        }
    }

    if(fResult)
    {
        InvalidateRect(NULL);
        SetModified(true);

        CUser* pUser = GetUser();
        if(NULL != pUser)
        {
            pUser->ReorderData();
        }
    }

    return fResult;
}


void CRunningLogView::MakeMenuReady(CMenu* pMenu)
{
    if(NULL == pMenu)
    {
        CUtil::Fatal("Bad parameter to CRunningLogView::MakeMenuReady");
        return;
    }

    COleDateTime tm = GetCurrentDate();
    int nFirstDay = GetFirstDayOfWeek();
    int nWeeks = CUtil::GetNumWeeks(tm, nFirstDay);

    int n = GetHighlightDay();
    bool fDaySelected = ((n >= 1) && (n <= 7 * nWeeks));
    bool fWeekSelected = ((n >= HIT_WEEKSUM1) && (n <= HIT_WEEKSUM1 + nWeeks - 1));
    bool fMonthSelected = (n == HIT_MONTHSUM);
    bool fUser = IsUserOpen();

    bool fTimeWorkout = CUtil::IsHighlightDayADay(tm, n, nFirstDay);
    bool fTimeRace = fTimeWorkout;
    COleDateTime tmHighlight = CUtil::GetHighlightedDate(tm, n, nFirstDay);
    fTimeWorkout &= !CUtil::IsLaterDayThan(tmHighlight, COleDateTime::GetCurrentTime());
    fTimeRace &= !CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), tmHighlight);

    CMenu* pSubMenu = pMenu->GetSubMenu(0);
    if(NULL != pSubMenu)
    {
        pSubMenu->EnableMenuItem(ID_OPTIONS_ADDWORKOUT, MF_BYCOMMAND | BoolToMenuID(fUser && fDaySelected && fTimeWorkout));
        pSubMenu->EnableMenuItem(ID_OPTIONS_ADDUPCOMINGRACE, MF_BYCOMMAND | BoolToMenuID(fUser && fDaySelected && fTimeRace));
        pSubMenu->EnableMenuItem(ID_OPTIONS_ADDUPCOMINGWORKOUT, MF_BYCOMMAND | BoolToMenuID(fUser && fDaySelected && fTimeRace));
    }

    pSubMenu = pMenu->GetSubMenu(1);
    if(NULL != pSubMenu)
    {
        pSubMenu->EnableMenuItem(ID_OPTIONS_DELETEWORKOUT, MF_BYCOMMAND | BoolToMenuID(fUser && fDaySelected && fTimeWorkout));
        pSubMenu->EnableMenuItem(ID_OPTIONS_DELETEUPCOMINGRACE, MF_BYCOMMAND | BoolToMenuID(fUser && fDaySelected && fTimeRace));
        pSubMenu->EnableMenuItem(ID_OPTIONS_DELETEUPCOMINGWORKOUT, MF_BYCOMMAND | BoolToMenuID(fUser && fDaySelected && fTimeRace));
    }

    pMenu->EnableMenuItem(ID_VIEW_DAYSUMMARY, MF_BYCOMMAND | BoolToMenuID(fUser && fDaySelected));
    pMenu->EnableMenuItem(ID_VIEW_CURRENTNOTES, MF_BYCOMMAND | BoolToMenuID(fUser));    
	pMenu->EnableMenuItem(ID_MISC_CALORIES, MF_BYCOMMAND | BoolToMenuID(fUser));
    pMenu->EnableMenuItem(ID_OPTIONS_GOTODAY, MF_BYCOMMAND | BoolToMenuID(true));
}


int CRunningLogView::BoolToMenuID(bool fEnable)
{
    if(fEnable)
    {
        return MF_ENABLED;
    }
    else
    {
        return (MF_DISABLED | MF_GRAYED);
    }
}


void CRunningLogView::SetWindowTitle(void)
{
    CString strText = "TriathLog";
    if(IsUserOpen())
    {
        CUser* pUser = GetUser();
        if(NULL != pUser)
        {
            strText += " - ";
            strText += pUser->GetFirstName();
            strText += " ";
            strText += pUser->GetLastName();
        }
    }

    AfxGetMainWnd()->SetWindowText(strText);
}


CRect CRunningLogView::GetDayRect(int nDay) const
{
    if((NULL == m_pCalendar) || (NO_SELECTION == nDay))
    {
        return CRect(0, 0, 0, 0);
    }

    CRect rc;
    GetClientRect(&rc);

    int nXLOffset;
    int nXROffset;
    int nYTOffset;
    int nYBOffset;
    GetOffsets(&nXLOffset, &nXROffset, &nYTOffset, &nYBOffset);

    CRect rcDays(nXLOffset, nYTOffset, rc.Width() - nXROffset, rc.Height() - nYBOffset);
    CSize szBox = m_pCalendar->GetBoxSize();
    int nMiddle = rc.Width() - (nXROffset / 2);
    CRect rcRectMonth(nMiddle - (szBox.cx / 2), (nYTOffset - szBox.cy) / 2, nMiddle + (szBox.cx / 2), (nYTOffset + szBox.cy) / 2);
    CRect rcRectWeek(nMiddle - (szBox.cx / 2), nYTOffset, nMiddle + (szBox.cx / 2), rc.Height() - nYBOffset);

    // test if it is in the days
    int nXOffset = m_pCalendar->GetMinWidthOffset();
    int nYOffset = m_pCalendar->GetMinHeightOffset();
    int nWidthOffset = nXOffset + ((rc.Width() % 7) / 2);

    int nWeeks = CUtil::GetNumWeeks(GetCurrentDate(), GetFirstDayOfWeek());

    CPoint ptTopLeft(rcDays.left + nWidthOffset, rcDays.top + nYOffset);

    COleDateTime tmCur = CUtil::GetFirstVisibleDay(GetCurrentDate(), GetFirstDayOfWeek());
    for(int j = 0; j < nWeeks; j++)
    {
        ptTopLeft.x = rcDays.left + nWidthOffset;

        for(int i = 0; i < 7; i++)
        {
            CRect rcRect(ptTopLeft.x, ptTopLeft.y, ptTopLeft.x + szBox.cx, ptTopLeft.y + szBox.cy);
            if((7 * j + i + 1) == nDay)
            {
                return rcRect;
            }

            ptTopLeft.x += szBox.cx + m_pCalendar->GetHorzSpacing();
            tmCur = CUtil::AddDay(tmCur);
        }

        ptTopLeft.y += szBox.cy + m_pCalendar->GetVertSpacing();
    }

    if(HIT_MONTHSUM == nDay)
    {
        return rcRectMonth;
    }

    // test if it is in the weeks
    else
    {
        CRect rcDraw = rcRectWeek;

        rcDraw.top += m_pCalendar->GetMinHeightOffset();

        COleDateTime tmTime = CUtil::GetFirstOfMonth(GetCurrentDate());
        CPoint ptTopLeft(rcDraw.left, rcDraw.top);

        int nWeeks = CUtil::GetNumWeeks(tmTime, GetFirstDayOfWeek());
        for(int i = 0; i < nWeeks; i++)
        {
            tmTime = CUtil::OffsetDay(tmTime, 7);

            CRect rcRect(ptTopLeft.x, ptTopLeft.y, ptTopLeft.x + szBox.cx, ptTopLeft.y + szBox.cy);
            if(HIT_WEEKSUM1 + i == nDay)
            {
                return rcRect;
            }
            ptTopLeft.y += szBox.cy + m_pCalendar->GetVertSpacing();
        }        
    }
    
    return CRect(0, 0, 0, 0);
}


void CRunningLogView::AdjustTitleFontSize(void)
{
    CFont* pFont = GetTitleFont();
    LOGFONT lf;
    if(NULL != pFont)
    {
        pFont->GetLogFont(&lf);
        pFont->DeleteObject();
    }
    else
    {
        pFont = new CFont;
    }

    CRect rc;
    GetClientRect(&rc);

    if(NULL != pFont)
    {
        lf.lfHeight = rc.Height() / 11;
        pFont->CreateFontIndirect(&lf);
        SetTitleFont(pFont);
    }
}


void CRunningLogView::MakeDaySummarySheet(COleDateTime tmStart, CUser* pUser, CWnd* pParent, bool bAllowSave /* = true */)
{
    CString str;
    str.Format("Day summary for %d/%d/%d", tmStart.GetMonth(), tmStart.GetDay(), tmStart.GetYear());
    CDaySummarySheet dlgSummary(str, bAllowSave, pParent);

    if(NULL != pUser)
    {
        CDayLog* pDay = pUser->GetDayAt(tmStart);
        if((NULL == pDay) || (0 == pDay->SumTotalWorkouts()))
        {
            AfxMessageBox("Please select a day that has information.");
            return;
        }

        dlgSummary.SetDay(pUser->GetDayAt(tmStart));
        dlgSummary.SetUser(pUser);
        dlgSummary.Initialize();
        dlgSummary.DoModal();
        if(dlgSummary.IsModified())
        {
            SetModified(true);
            Invalidate();
        }
    }
}


void CRunningLogView::AdjustHighlightDay(void)
{
    COleDateTime tmDate = GetCurrentDate();
    int nWeeks = CUtil::GetNumWeeks(tmDate, GetFirstDayOfWeek());

    int nDay = GetHighlightDay();

    // if it's a month summary or there is no selection, leave it alone
    if((HIT_MONTHSUM == nDay) || (NO_SELECTION == nDay))
    {
        return;
    }
    
    // if it's a week summary, make sure it isn't on a higher week than there is
    else if((HIT_WEEKSUM1 <= nDay) && (HIT_WEEKSUM6 >= nDay))
    {
        if(((HIT_WEEKSUM6 == nDay) || (HIT_WEEKSUM5 == nDay)) && (nDay - HIT_WEEKSUM1 + 1 > nWeeks))
        {
            nDay = HIT_WEEKSUM1 + nWeeks - 1;
        }
    }

    // else it's in the days.. move it back a week until it is on the calendar
    else
    {
        while(7 * nWeeks < nDay)
        {
            nDay--;
        }

        while(nDay < 1)
        {
            nDay++;
        }
    }

    SetHighlightDay(nDay);
}


bool CRunningLogView::IsHighlightDay(int nType, COleDateTime tmTime, int nWeek) const
{
    COleDateTime tmStart = CUtil::GetFirstVisibleDay(GetCurrentDate(), GetFirstDayOfWeek());
    int nDay = GetHighlightDay();

    if((DAYTYPE_NORMAL == nType) || (DAYTYPE_GRAYED == nType))
    {
        int nDaysAhead = CUtil::GetNumberOfDaysLaterThan(tmTime, tmStart);
        if(nDaysAhead + 1 == nDay)
        {
            return true;
        }
    }
    
    else if(DAYTYPE_MONTHSUM == nType)
    {
        if(HIT_MONTHSUM == nDay)
        {
            return true;
        }
    }

    else if(DAYTYPE_WEEKSUM == nType)
    {
        if(HIT_WEEKSUM1 + nWeek == nDay)
        {
            return true;
        }
    }

    return false;
}


bool CRunningLogView::IsInjuryDay(COleDateTime tmDay)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CDayLog* pDay = pUser->GetDayAt(tmDay);
        if(NULL != pDay)
        {
            return pDay->IsInjured();
        }
    }

    return false;
}


bool CRunningLogView::IsSickDay(COleDateTime tmDay)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CDayLog* pDay = pUser->GetDayAt(tmDay);
        if(NULL != pDay)
        {
            return pDay->IsSick();
        }
    }

    return false;
}


bool CRunningLogView::IsBrickDay(COleDateTime tmDay)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CDayLog* pDay = pUser->GetDayAt(tmDay);
        if(NULL != pDay)
        {
            return pDay->IsBrick();
        }
    }

    return false;
}


bool CRunningLogView::IsJambaDay(COleDateTime tmDay)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CDayLog* pDay = pUser->GetDayAt(tmDay);
        if(NULL != pDay)
        {
            return pDay->IsJamba();
        }
    }

    return false;
}


bool CRunningLogView::IsLongDay(COleDateTime tmDay)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CDayLog* pDay = pUser->GetDayAt(tmDay);
        if(NULL != pDay)
        {
            return pDay->IsLong();
        }
    }

    return false;
}


bool CRunningLogView::IsRaceDay(COleDateTime tmDay)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CDayLog* pDay = pUser->GetDayAt(tmDay);
        if(NULL != pDay)
        {
            return pDay->IsRaceDay();
        }
    }

    return false;
}


bool CRunningLogView::MarkAsUpcomingRaceDay(COleDateTime tmDay)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CDayLog* pDay = pUser->GetDayAt(tmDay);
        if(NULL == pDay) // pDay is NULL only if there are no workouts entered
        {
            CUpcomingRace* pRace = pUser->GetUpcomingRaceAt(tmDay);
            if(NULL != pRace)
            {
				if(CUtil::GetNumberOfDaysLaterThan(COleDateTime::GetCurrentTime(), tmDay) < 7)
				{
					return true;
				}
			}
        }
    }

    return false;
}


bool CRunningLogView::MarkAsUpcomingWorkoutDay(COleDateTime tmDay)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CDayLog* pDay = pUser->GetDayAt(tmDay);
        if(NULL == pDay) // pDay is NULL only if there are no workouts entered
        {
            CUpcomingWorkout* pWorkout = pUser->GetUpcomingWorkoutAt(tmDay);
            if(NULL != pWorkout)
            {
				if(CUtil::GetNumberOfDaysLaterThan(COleDateTime::GetCurrentTime(), tmDay) < 7)
				{
					return true;
				}
			}
        }
    }

    return false;
}


void CRunningLogView::SetButtonColors(CButtonST* pButton)
{
    if(NULL != pButton)
    {
        pButton->SetColor(CButtonST::BTNST_COLOR_BK_IN, GetButtonColor());
        pButton->SetColor(CButtonST::BTNST_COLOR_FG_IN, GetAnnotationTextColor());
        pButton->SetColor(CButtonST::BTNST_COLOR_BK_OUT, GetButtonColor());
        pButton->SetColor(CButtonST::BTNST_COLOR_FG_OUT, GetDayTextColor());
        pButton->SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, GetButtonColor());
        pButton->SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, GetAnnotationTextColor());
        pButton->SetFont(GetAnnotationFont());
    }
}


BOOL CRunningLogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRunningLogView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// add extra initialization before printing
}

void CRunningLogView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// add cleanup after printing
}


void CRunningLogView::GetOffsets(int* pXLOffset, int* pXROffset, int* pYTOffset, int* pYBOffset) const
{
    if((NULL == pXLOffset) || (NULL == pXROffset) || (NULL == pYTOffset) || (NULL == pYBOffset))
    {
        CUtil::Fatal("Bad parameter to CRunningLogView::GetOffsets");
        return;
    }

    CRect rc;
    GetClientRect(&rc);

    *pXLOffset = rc.Width() / 180;
    *pXROffset = 9 * rc.Width() / 64;
    *pYTOffset = rc.Height() / 5;
    *pYBOffset = rc.Height() / 65;
}


bool CRunningLogView::IsUserOpen(void) const
{
    return m_fUserOpen;
}


void CRunningLogView::SetUserOpen(bool fOpen)
{
    m_fUserOpen = fOpen;
}


bool CRunningLogView::IsModified(void) const
{
    return m_fModified;
}


void CRunningLogView::SetModified(bool fModified)
{
    m_fModified = fModified;
}


CUser* CRunningLogView::GetUser(void)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetUser");
        return NULL;
    }
     
    return pDoc->GetUser();
}


void CRunningLogView::SetUser(CUser* pUser)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::SetUser");
        return;
    }
     
    return pDoc->SetUser(pUser);
}


int CRunningLogView::GetLastMouseDay(void) const
{
    return m_nLastMouseDay;
}


void CRunningLogView::SetLastMouseDay(int nDay)
{
    m_nLastMouseDay = nDay;
}


int CRunningLogView::GetFirstDayOfWeek(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetFirstDayOfWeek");
        return MONDAY;
    }
     
    return pDoc->GetFirstDayOfWeek();
}


COleDateTime CRunningLogView::GetCurrentDate(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetCurrentDate");
        return COleDateTime::GetCurrentTime();
    }
     
    return pDoc->GetCurrentDate();
}


int CRunningLogView::GetHighlightDay(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetHighlightDay");
        return 0;
    }
             
    return pDoc->GetHighlightDay();
}


int CRunningLogView::GetBaseTypeRun(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetBaseTypeRun");
        return CUtil::GetDefaultBaseTypeRun();
    }
     
    return pDoc->GetBaseTypeRun();
}


int CRunningLogView::GetBaseTypeBike(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetBaseTypeBike");
        return CUtil::GetDefaultBaseTypeBike();
    }
     
    return pDoc->GetBaseTypeBike();
}


int CRunningLogView::GetBaseTypeSwim(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetBaseTypeSwim");
        return CUtil::GetDefaultBaseTypeSwim();
    }
     
    return pDoc->GetBaseTypeSwim();
}


bool CRunningLogView::DisplayInfoRun(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL user in CRunningLogView::DisplayInfoRun");
        return true;
    }
        
    return pDoc->DisplayInfoRun();
}


bool CRunningLogView::DisplayInfoBike(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL user in CRunningLogView::DisplayInfoBike");
        return true;
    }
        
    return pDoc->DisplayInfoBike();
}


bool CRunningLogView::DisplayInfoSwim(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL user in CRunningLogView::DisplayInfoSwim");
        return true;
    }
        
    return pDoc->DisplayInfoSwim();
}


bool CRunningLogView::DisplayInfoStrength(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL user in CRunningLogView::DisplayInfoStrength");
        return true;
    }
        
    return pDoc->DisplayInfoStrength();
}


bool CRunningLogView::DisplayInfoRace(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL user in CRunningLogView::DisplayInfoRace");
        return true;
    }
        
    return pDoc->DisplayInfoRace();
}


COLORREF CRunningLogView::GetBgColor(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetBgColor");
        return RGB(0, 0, 0);
    }
     
    return pDoc->GetBgColor();
}


COLORREF CRunningLogView::GetDayColor(int nType) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetDayColor");
        return RGB(0, 0, 0);
    }
    
    return pDoc->GetDayColor(nType);
}


COLORREF CRunningLogView::GetButtonColor(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetButtonColor");
        return RGB(0, 0, 0);
    }

    return pDoc->GetButtonColor();
}


COLORREF CRunningLogView::GetHighlightColor(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetHighlightColor");
        return RGB(0, 0, 0);
    }

    return pDoc->GetHighlightColor();
}


COLORREF CRunningLogView::GetShadowColor(bool bOne) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetShadowColor");
        return RGB(0, 0, 0);
    }
    
    return pDoc->GetShadowColor(bOne);
}

COLORREF CRunningLogView::GetGradientColor(bool bBegin) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetGradientBgColor");
        return RGB(0, 0, 0);
    }
    
    return pDoc->GetGradientColor(bBegin);
}


COLORREF CRunningLogView::GetHeadingTextColor(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetHeadingTextColor");
        return RGB(0, 0, 0);
    }
    
    return pDoc->GetHeadingTextColor();
}


COLORREF CRunningLogView::GetDayTextColor(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetDayTextColor");
        return RGB(0, 0, 0);
    }
    
    return pDoc->GetDayTextColor();
}


COLORREF CRunningLogView::GetAnnotationTextColor(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetAnnotationColor");
        return RGB(0, 0, 0);
    }
    
    return pDoc->GetAnnotationTextColor();
}


COLORREF CRunningLogView::GetRaceDayColor(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetRaceDayColor");
        return RGB(0, 0, 0);
    }
    
    return pDoc->GetRaceDayColor();
}


COLORREF CRunningLogView::GetUpcomingRaceDayColor(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetUpcomingRaceDayColor");
        return RGB(0, 0, 0);
    }
    
    return pDoc->GetUpcomingRaceDayColor();
}


COLORREF CRunningLogView::GetUpcomingWorkoutDayColor(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetUpcomingWorkoutDayColor");
        return RGB(0, 0, 0);
    }
    
    return pDoc->GetUpcomingWorkoutDayColor();
}


CFont* CRunningLogView::GetDayFont(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetDayFont");
        return NULL;
    }
    
    return pDoc->GetDayFont();
}


CFont* CRunningLogView::GetHeadingFont(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetHeadingFont");
        return NULL;
    }
    
    return pDoc->GetHeadingFont();
}


CFont* CRunningLogView::GetTitleFont(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetTitleFont");
        return NULL;
    }
       
    return pDoc->GetTitleFont();
}


CFont* CRunningLogView::GetAnnotationFont(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetAnnotationFont");
        return NULL;
    }
       
    return pDoc->GetAnnotationFont();
}


CFont* CRunningLogView::GetAnnotationFontBold(void) const
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL == pDoc)
    {
        CUtil::Fatal("NULL document in CRunningLogView::GetAnnotationFontBold");
        return NULL;
    }
       
    return pDoc->GetAnnotationFontBold();
}


void CRunningLogView::SetBaseTypeRun(int nType)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetBaseTypeRun(nType);
    }
}


void CRunningLogView::SetBaseTypeBike(int nType)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetBaseTypeBike(nType);
    }
}


void CRunningLogView::SetBaseTypeSwim(int nType)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetBaseTypeSwim(nType);
    }
}


void CRunningLogView::SetDisplayInfoRun(bool fDisp)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetDisplayInfoRun(fDisp);
    }
}    


void CRunningLogView::SetDisplayInfoBike(bool fDisp)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetDisplayInfoBike(fDisp);
    }
}    


void CRunningLogView::SetDisplayInfoSwim(bool fDisp)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetDisplayInfoSwim(fDisp);
    }
}    


void CRunningLogView::SetDisplayInfoStrength(bool fDisp)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetDisplayInfoStrength(fDisp);
    }
}    


void CRunningLogView::SetDisplayInfoRace(bool fDisp)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetDisplayInfoRace(fDisp);
    }
}    


void CRunningLogView::SetFirstDayOfWeek(int nDay)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetFirstDayOfWeek(nDay);
    }
}


void CRunningLogView::SetCurrentDate(COleDateTime tmCur)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetCurrentDate(tmCur);
    }
}


void CRunningLogView::SetHighlightDay(int nDay)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetHighlightDay(nDay);
    }
}


void CRunningLogView::SetBgColor(COLORREF cr)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetBgColor(cr);
    }
}


void CRunningLogView::SetDayColor(int nType, COLORREF cr)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetDayColor(nType, cr);
    }
}


void CRunningLogView::SetButtonColor(COLORREF cr)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetButtonColor(cr);
    }
}


void CRunningLogView::SetHighlightColor(COLORREF cr)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetHighlightColor(cr);
    }
}


void CRunningLogView::SetShadowColor(bool bOne, COLORREF cr)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetShadowColor(bOne, cr);
    }
}


void CRunningLogView::SetGradientColor(bool bBegin, COLORREF cr)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetGradientColor(bBegin, cr);
    }
}


void CRunningLogView::SetRaceDayColor(COLORREF cr)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetRaceDayColor(cr);
    }
}


void CRunningLogView::SetUpcomingRaceDayColor(COLORREF cr)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetUpcomingRaceDayColor(cr);
    }
}


void CRunningLogView::SetUpcomingWorkoutDayColor(COLORREF cr)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetUpcomingWorkoutDayColor(cr);
    }
}


void CRunningLogView::SetHeadingTextColor(COLORREF cr)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetHeadingTextColor(cr);
    }
}


void CRunningLogView::SetDayTextColor(COLORREF cr)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetDayTextColor(cr);
    }
}


void CRunningLogView::SetAnnotationTextColor(COLORREF cr)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetAnnotationTextColor(cr);
    }
}


void CRunningLogView::SetDayFont(CFont* pfnt)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetDayFont(pfnt);
    }
}


void CRunningLogView::SetHeadingFont(CFont* pfnt)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetHeadingFont(pfnt);
    }
}


void CRunningLogView::SetTitleFont(CFont* pfnt)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetTitleFont(pfnt);
    }
}


void CRunningLogView::SetAnnotationFont(CFont* pfnt)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetAnnotationFont(pfnt);
    }
}


void CRunningLogView::SetAnnotationFontBold(CFont* pfnt)
{
    CRunningLogDoc* pDoc = GetDocument();
    if(NULL != pDoc)
    {
        pDoc->SetAnnotationFontBold(pfnt);
    }
}


CSize CRunningLogView::GetLastSize(bool fFirst) const
{
    if(fFirst)
    {
        return m_aszWindow[0];
    }
    else
    {
        return m_aszWindow[1];
    }
}


void CRunningLogView::SetLastSize(bool fFirst, CSize sz)
{
    if(fFirst)
    {
        m_aszWindow[0] = sz;
    }
    else
    {
        m_aszWindow[1] = sz;
    }
}


void CRunningLogView::MakeGradient(int nWidth, int nHeight)
{
    CPaintDC dc(this);

    COLORREF crGradStart = GetGradientColor(true);
    COLORREF crGradEnd = GetGradientColor(false);

    int nR1 = GetRValue(crGradStart);
    int nG1 = GetGValue(crGradStart);
    int nB1 = GetBValue(crGradStart);
    int nR2 = GetRValue(crGradEnd);
    int nG2 = GetGValue(crGradEnd);
    int nB2 = GetBValue(crGradEnd);

    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    if(NULL != m_pDCBmp)
    {
        m_pDCBmp->SelectObject(m_pBmpOld);
        delete m_pDCBmp;
    }

    m_pDCBmp = new CDC();
    if(NULL == m_pDCBmp)
    {
        return;
    }

    m_pDCBmp->CreateCompatibleDC(&dc);

    if(m_bmpGrad.m_hObject)
    {
        m_bmpGrad.DeleteObject();
    }
    m_bmpGrad.CreateCompatibleBitmap(&dc, nWidth, nHeight);

    m_pBmpOld = m_pDCBmp->SelectObject(&m_bmpGrad);

    while((x1 < nWidth) && (y1 < nHeight))
    {
        if(y1 < nHeight - 1)
        {
            y1++;
        }
        else
        {
            x1++;
        }

        if(x2 < nWidth - 1)
        {
            x2++;
        }
        else
        {
            y2++;
        }

        int nRCur;
        int nGCur;
        int nBCur;
        int i = x1 + y1;
        nRCur = nR1 + (i * (nR2 - nR1) / (nWidth + nHeight));
        nGCur = nG1 + (i * (nG2 - nG1) / (nWidth + nHeight));
        nBCur = nB1 + (i * (nB2 - nB1) / (nWidth + nHeight));

        CPen pen(PS_SOLID, 1, RGB(nRCur, nGCur, nBCur));
        CPen *pOrigPen = m_pDCBmp->SelectObject(&pen); 

        m_pDCBmp->MoveTo(x1, y1);
        m_pDCBmp->LineTo(x2, y2);

        m_pDCBmp->SelectObject(pOrigPen);
    } 
}


void CRunningLogView::SetDoingContextMenu(bool bDoing)
{
    m_bDoingContextMenu = bDoing;
}


bool CRunningLogView::IsDoingContextMenu(void) const
{
    return m_bDoingContextMenu;
}


#ifdef _DEBUG
void CRunningLogView::AssertValid() const
{
	CView::AssertValid();
}


void CRunningLogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}


// non-debug version is inline
CRunningLogDoc* CRunningLogView::GetDocument() const 
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRunningLogDoc)));
	return (CRunningLogDoc*)m_pDocument;
}
#endif //_DEBUG