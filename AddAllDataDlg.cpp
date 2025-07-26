#include "StdAfx.h"
#include <math.h>
#include "RunningLog.h"
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
#include "CourseRun.h"
#include "CourseBike.h"
#include "CourseSwim.h"
#include "CourseDuathlon.h"
#include "CourseTriathlon.h"
#include "LocationRun.h"
#include "LocationBike.h"
#include "LocationSwim.h"
#include "LocationStrength.h"
#include "ShoesRun.h"
#include "ShoesBike.h"
#include "Bike.h"
#include "User.h"
#include "Util.h"
#include "AniDialog.h"
#include "PPToolTip.h"
#include "AddAllDataDlg.h"


IMPLEMENT_DYNAMIC(CAddAllDataDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CAddAllDataDlg, CAniDialog)
    ON_BN_CLICKED(IDC_ADDRUNLOC, OnLocationRun)
    ON_BN_CLICKED(IDC_ADDBIKELOC, OnLocationBike)
    ON_BN_CLICKED(IDC_ADDSWIMLOC, OnLocationSwim)
    ON_BN_CLICKED(IDC_ADDSTRENGTHLOC, OnLocationStrength)
    ON_BN_CLICKED(IDC_ADDRUNCOURSE, OnCourseRun)
    ON_BN_CLICKED(IDC_ADDBIKECOURSE, OnCourseBike)
    ON_BN_CLICKED(IDC_ADDSWIMCOURSE, OnCourseSwim)
    ON_BN_CLICKED(IDC_ADDDUATHLONCOURSE, OnCourseDuathlon)
    ON_BN_CLICKED(IDC_ADDTRIATHLONCOURSE, OnCourseTriathlon)
    ON_BN_CLICKED(IDC_ADDRUNSHOES, OnShoesRun)
    ON_BN_CLICKED(IDC_ADDBIKESHOES, OnShoesBike)
    ON_BN_CLICKED(IDC_ADDBIKE, OnBike)
END_MESSAGE_MAP()


CAddAllDataDlg::CAddAllDataDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CAddAllDataDlg::IDD, pParent)
{
    SetModified(false);
}


CAddAllDataDlg::~CAddAllDataDlg()
{
}


void CAddAllDataDlg::OnOK(void)
{
    bool fResult = true;
    
    CAniDialog::OnOK();
}


BOOL CAddAllDataDlg::OnInitDialog(void)
{
    BOOL bRes = CAniDialog::OnInitDialog();
    
    m_ttpToolTip.Create(this);

	m_ttpToolTip.AddTool(GetDlgItem(IDC_ADDRUNLOC), _T("<b><ct=0x0000FF><al_c>Locations</b><br><ct=0x00AA00><hr=100%></ct><br>These are used to track where you run each day. <br>You can look at this information later via the day summary or the location summary. <br>These are mandatory by default, but you can change this behavior in the options dialog."), IDI_TTIPINFO);
	m_ttpToolTip.AddTool(GetDlgItem(IDC_ADDBIKELOC), _T("<b><ct=0x0000FF><al_c>Locations</b><br><ct=0x00AA00><hr=100%></ct><br>These are used to track where you ride each day. <br>You can look at this information later via the day summary or the location summary. <br>These are mandatory by default, but you can change this behavior in the options dialog."), IDI_TTIPINFO);
	m_ttpToolTip.AddTool(GetDlgItem(IDC_ADDSWIMLOC), _T("<b><ct=0x0000FF><al_c>Locations</b><br><ct=0x00AA00><hr=100%></ct><br>These are used to track where you swim each day. <br>You can look at this information later via the day summary or the location summary. <br>These are mandatory by default, but you can change this behavior in the options dialog."), IDI_TTIPINFO);
	m_ttpToolTip.AddTool(GetDlgItem(IDC_ADDSTRENGTHLOC), _T("<b><ct=0x0000FF><al_c>Locations</b><br><ct=0x00AA00><hr=100%></ct><br>These are used to track where you do strength work each day. <br>You can look at this information later via the day summary or the location summary. <br>These are mandatory by default, but you can change this behavior in the options dialog."), IDI_TTIPINFO);

	m_ttpToolTip.AddTool(GetDlgItem(IDC_ADDRUNCOURSE), _T("<b><ct=0x0000FF><al_c>Courses</b><br><ct=0x00AA00><hr=100%></ct><br>These are used to track data such as distance, personal records, and notes about the courses you race. <br>You can look at this information later via the day summary or the course summary. <br>These are mandatory by default, but you can change this behavior in the options dialog."), IDI_TTIPINFO);
	m_ttpToolTip.AddTool(GetDlgItem(IDC_ADDBIKECOURSE), _T("<b><ct=0x0000FF><al_c>Courses</b><br><ct=0x00AA00><hr=100%></ct><br>These are used to track data such as distance, personal records, and notes about the courses you race. <br>You can look at this information later via the day summary or the course summary. <br>These are mandatory by default, but you can change this behavior in the options dialog."), IDI_TTIPINFO);
	m_ttpToolTip.AddTool(GetDlgItem(IDC_ADDSWIMCOURSE), _T("<b><ct=0x0000FF><al_c>Courses</b><br><ct=0x00AA00><hr=100%></ct><br>These are used to track data such as distance, personal records, and notes about the courses you race. <br>You can look at this information later via the day summary or the course summary. <br>These are mandatory by default, but you can change this behavior in the options dialog."), IDI_TTIPINFO);
	m_ttpToolTip.AddTool(GetDlgItem(IDC_ADDDUATHLONCOURSE), _T("<b><ct=0x0000FF><al_c>Courses</b><br><ct=0x00AA00><hr=100%></ct><br>These are used to track data such as distance, personal records, and notes about the courses you race. <br>You can look at this information later via the day summary or the course summary. <br>These are mandatory by default, but you can change this behavior in the options dialog."), IDI_TTIPINFO);
	m_ttpToolTip.AddTool(GetDlgItem(IDC_ADDTRIATHLONCOURSE), _T("<b><ct=0x0000FF><al_c>Courses</b><br><ct=0x00AA00><hr=100%></ct><br>These are used to track data such as distance, personal records, and notes about the courses you race. <br>You can look at this information later via the day summary or the course summary. <br>These are mandatory by default, but you can change this behavior in the options dialog."), IDI_TTIPINFO);

	m_ttpToolTip.AddTool(GetDlgItem(IDC_ADDRUNSHOES), _T("<b><ct=0x0000FF><al_c>Shoes</b><br><ct=0x00AA00><hr=100%></ct><br>These are used to track data such as brand name, model, distance run, and dates run on a pair of shoes.<br>You can look at this information later via the day summary or the shoe summary. <br>These are mandatory by default, but you can change this behavior in the options dialog."), IDI_TTIPINFO);
	m_ttpToolTip.AddTool(GetDlgItem(IDC_ADDBIKESHOES), _T("<b><ct=0x0000FF><al_c>Shoes</b><br><ct=0x00AA00><hr=100%></ct><br>These are used to track data such as brand name, model, distance ridden, and dates ridden on a pair of shoes.<br>You can look at this information later via the day summary or the shoe summary. <br>These are mandatory by default, but you can change this behavior in the options dialog."), IDI_TTIPINFO);

	m_ttpToolTip.AddTool(GetDlgItem(IDC_ADDBIKE), _T("<b><ct=0x0000FF><al_c>Bike</b><br><ct=0x00AA00><hr=100%></ct><br>These are used to track data such as brand name, model, frame size, distance ridden, and dates ridden on a bike.<br>You can look at this information later via the day summary or the bike summary. <br>These are mandatory by default, but you can change this behavior in the options dialog."), IDI_TTIPINFO);

    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        LOCATIONRUNARRAY& rarLocationsRun = pUser->GetRefLocationRunArray();
        LOCATIONBIKEARRAY& rarLocationsBike = pUser->GetRefLocationBikeArray();
        LOCATIONSWIMARRAY& rarLocationsSwim = pUser->GetRefLocationSwimArray();
        LOCATIONSTRENGTHARRAY& rarLocationsStrength = pUser->GetRefLocationStrengthArray();
        COURSERUNARRAY& rarCoursesRun = pUser->GetRefCourseRunArray();
        COURSEBIKEARRAY& rarCoursesBike = pUser->GetRefCourseBikeArray();
        COURSESWIMARRAY& rarCoursesSwim = pUser->GetRefCourseSwimArray();
        COURSEDUATHLONARRAY& rarCoursesDuathlon = pUser->GetRefCourseDuathlonArray();
        COURSETRIATHLONARRAY& rarCoursesTriathlon = pUser->GetRefCourseTriathlonArray();
        SHOESRUNARRAY& rarShoesRun = pUser->GetRefShoesRunArray();
        SHOESBIKEARRAY& rarShoesBike = pUser->GetRefShoesBikeArray();
        BIKEARRAY& rarBikes = pUser->GetRefBikeArray();

        m_nOldLocRun = (int)rarLocationsRun.GetCount();
        m_nOldLocBike = (int)rarLocationsBike.GetCount();
        m_nOldLocSwim = (int)rarLocationsSwim.GetCount();
        m_nOldLocStrength = (int)rarLocationsStrength.GetCount();
        m_nOldCourseRun = (int)rarCoursesRun.GetCount();
        m_nOldCourseBike = (int)rarCoursesBike.GetCount();
        m_nOldCourseSwim = (int)rarCoursesSwim.GetCount();
        m_nOldCourseDuathlon = (int)rarCoursesDuathlon.GetCount();
        m_nOldCourseTriathlon = (int)rarCoursesTriathlon.GetCount();
        m_nOldShoesRun = (int)rarShoesRun.GetCount();
        m_nOldShoesBike = (int)rarShoesBike.GetCount();
        m_nOldBikes = (int)rarBikes.GetCount();
    }

    UpdateText();

    return bRes;
}


BOOL CAddAllDataDlg::PreTranslateMessage(MSG* pMsg)
{
    m_ttpToolTip.RelayEvent(pMsg);

    return CAniDialog::PreTranslateMessage(pMsg);
}


void CAddAllDataDlg::OnLocationRun(void)
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

    UpdateText();
}


void CAddAllDataDlg::OnLocationBike(void)
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
    
    UpdateText();
}


void CAddAllDataDlg::OnLocationSwim(void)
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
    
    UpdateText();
}


void CAddAllDataDlg::OnLocationStrength(void)
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
    
    UpdateText();
}


void CAddAllDataDlg::OnCourseRun(void)
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

    UpdateText();
}


void CAddAllDataDlg::OnCourseBike(void)
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

    UpdateText();
}


void CAddAllDataDlg::OnCourseSwim(void)
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

    UpdateText();
}


void CAddAllDataDlg::OnCourseDuathlon(void)
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

    UpdateText();
}


void CAddAllDataDlg::OnCourseTriathlon(void)
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

    UpdateText();
}


void CAddAllDataDlg::OnShoesRun(void)
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

    UpdateText();
}


void CAddAllDataDlg::OnShoesBike(void)
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

    UpdateText();
}


void CAddAllDataDlg::OnBike(void)
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

    UpdateText();
}


void CAddAllDataDlg::UpdateText(void)
{
    CUser* pUser = GetUser();

    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CAddAllDataDlg::UpdateText");
        return;
    }

    CString strTot = "Total: ";
    CString strSpaces = "      ";
    CString strAdded = "Added this time: ";

    LOCATIONRUNARRAY& rarLocationsRun = pUser->GetRefLocationRunArray();
    LOCATIONBIKEARRAY& rarLocationsBike = pUser->GetRefLocationBikeArray();
    LOCATIONSWIMARRAY& rarLocationsSwim = pUser->GetRefLocationSwimArray();
    LOCATIONSTRENGTHARRAY& rarLocationsStrength = pUser->GetRefLocationStrengthArray();
    COURSERUNARRAY& rarCoursesRun = pUser->GetRefCourseRunArray();
    COURSEBIKEARRAY& rarCoursesBike = pUser->GetRefCourseBikeArray();
    COURSESWIMARRAY& rarCoursesSwim = pUser->GetRefCourseSwimArray();
    COURSEDUATHLONARRAY& rarCoursesDuathlon = pUser->GetRefCourseDuathlonArray();
    COURSETRIATHLONARRAY& rarCoursesTriathlon = pUser->GetRefCourseTriathlonArray();
    SHOESRUNARRAY& rarShoesRun = pUser->GetRefShoesRunArray();
    SHOESBIKEARRAY& rarShoesBike = pUser->GetRefShoesBikeArray();
    BIKEARRAY& rarBikes = pUser->GetRefBikeArray();

    int nAddedLocRun = (int)rarLocationsRun.GetCount() - m_nOldLocRun;
    int nAddedLocBike = (int)rarLocationsBike.GetCount() - m_nOldLocBike;
    int nAddedLocSwim = (int)rarLocationsSwim.GetCount() - m_nOldLocSwim;
    int nAddedLocStrength = (int)rarLocationsStrength.GetCount() - m_nOldLocStrength;
    int nAddedCourseRun = (int)rarCoursesRun.GetCount() - m_nOldCourseRun;
    int nAddedCourseBike = (int)rarCoursesBike.GetCount() - m_nOldCourseBike;
    int nAddedCourseSwim = (int)rarCoursesSwim.GetCount() - m_nOldCourseSwim;
    int nAddedCourseDuathlon = (int)rarCoursesDuathlon.GetCount() - m_nOldCourseDuathlon;
    int nAddedCourseTriathlon = (int)rarCoursesTriathlon.GetCount() - m_nOldCourseTriathlon;
    int nAddedShoesRun = (int)rarShoesRun.GetCount() - m_nOldShoesRun;
    int nAddedShoesBike = (int)rarShoesBike.GetCount() - m_nOldShoesBike;
    int nAddedBikes = (int)rarBikes.GetCount() - m_nOldBikes;

    CString str;
    
    UpdateTextItem((int)rarLocationsRun.GetCount(), nAddedLocRun, IDT_ADDRUNLOCTEXT, IDT_ADDRUNLOCTEXT2);
    UpdateTextItem((int)rarLocationsBike.GetCount(), nAddedLocBike, IDT_ADDBIKELOCTEXT, IDT_ADDBIKELOCTEXT2);
    UpdateTextItem((int)rarLocationsSwim.GetCount(), nAddedLocSwim, IDT_ADDSWIMLOCTEXT, IDT_ADDSWIMLOCTEXT2);
    UpdateTextItem((int)rarLocationsStrength.GetCount(), nAddedLocStrength, IDT_ADDSTRENGTHLOCTEXT, IDT_ADDSTRENGTHLOCTEXT2);
    UpdateTextItem((int)rarCoursesRun.GetCount(), nAddedCourseRun, IDT_ADDRUNCOURSETEXT, IDT_ADDRUNCOURSETEXT2);
    UpdateTextItem((int)rarCoursesBike.GetCount(), nAddedCourseBike, IDT_ADDBIKECOURSETEXT, IDT_ADDBIKECOURSETEXT2);
    UpdateTextItem((int)rarCoursesSwim.GetCount(), nAddedCourseSwim, IDT_ADDSWIMCOURSETEXT, IDT_ADDSWIMCOURSETEXT2);
    UpdateTextItem((int)rarCoursesDuathlon.GetCount(), nAddedCourseDuathlon, IDT_ADDDUATHLONCOURSETEXT, IDT_ADDDUATHLONCOURSETEXT2);
    UpdateTextItem((int)rarCoursesTriathlon.GetCount(), nAddedCourseTriathlon, IDT_ADDTRIATHLONCOURSETEXT, IDT_ADDTRIATHLONCOURSETEXT2);
    UpdateTextItem((int)rarShoesRun.GetCount(), nAddedShoesRun, IDT_ADDRUNSHOESTEXT, IDT_ADDRUNSHOESTEXT2);
    UpdateTextItem((int)rarShoesBike.GetCount(), nAddedShoesBike, IDT_ADDBIKESHOESTEXT, IDT_ADDBIKESHOESTEXT2);
    UpdateTextItem((int)rarBikes.GetCount(), nAddedBikes, IDT_ADDBIKETEXT, IDT_ADDBIKETEXT2);
}


void CAddAllDataDlg::UpdateTextItem(int nTotal, int nAdded, int nID1, int nID2)
{
    CString str1;
    str1.Format("Total: %d", nTotal);
    CString str2;
    str2.Format("Added this time: %d", nAdded);

    SetDlgItemText(nID1, str1);
    SetDlgItemText(nID2, str2);
}


void CAddAllDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


bool CAddAllDataDlg::IsModified(void) const
{
    return m_bModified;
}


void CAddAllDataDlg::SetModified(bool bMod)
{
    m_bModified = bMod;
}


CUser* CAddAllDataDlg::GetUser(void) const
{
    return m_pUser;
}


void CAddAllDataDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}