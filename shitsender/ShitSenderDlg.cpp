// ShitSenderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShitSender.h"
#include "ShitSenderDlg.h"

#include <winsock2.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BOOL	g_bStop;
UCHAR	g_shit[4096];
CString g_strTarget;
UINT	g_nPort;

UINT ShitThreadProc(LPVOID param)
{
    SOCKET s;
    LPHOSTENT hp;
    SOCKADDR_IN clnt_sin, srv_sin;

	WORD wVersionRequested = MAKEWORD( 2, 2 );;
	WSADATA wsaData;

	if( WSAStartup( wVersionRequested, &wsaData ) )
	{
//		MessageBox( ( HWND )param, "WSAStartup error!", "Error!", MB_OK | MB_ICONERROR );
		return 0;
	}

	s = socket (AF_INET, SOCK_STREAM, 0); 
	
	memset( &clnt_sin, 0, sizeof( clnt_sin ) ); 
	clnt_sin.sin_family				= AF_INET; 
	clnt_sin.sin_addr.S_un.S_addr	= INADDR_ANY; 
	clnt_sin.sin_port				= htons( 12345 ); 

	bind( s, ( struct sockaddr *)&clnt_sin, sizeof( clnt_sin ) );  

	memset( &srv_sin, 0, sizeof( srv_sin ) ); 

    if( isalpha( g_strTarget[0] ) )
	{
        hp = gethostbyname( g_strTarget );

		if( hp == NULL )
		{
//			MessageBox( ( HWND )param, "gethostbyname error!", "Error!", MB_OK | MB_ICONERROR );
			WSACleanup();
			closesocket( s );
            return 0;
        }

		memcpy ( &srv_sin.sin_addr, hp->h_addr, hp->h_length ); 
    }
	else 
	{
		srv_sin.sin_addr.S_un.S_addr = inet_addr( g_strTarget );
    } 
	srv_sin.sin_family	= AF_INET; 
	srv_sin.sin_port	= htons( g_nPort ); 

	if( connect( s, ( struct sockaddr *)&srv_sin, sizeof( srv_sin ) ) == SOCKET_ERROR )
	{
//		MessageBox( ( HWND )param, "Connection Error!", "Error!", MB_OK | MB_ICONERROR );
	}
	else
	{
		while( !g_bStop )
		{
			send( s, (char *)&g_shit, 4096, 0 );

			if( WSAGetLastError() )
			{
//				MessageBox( ( HWND )param, "Ubilas!", "dd", MB_OK );
				WSASetLastError( 0 );
				closesocket( s );
				WSACleanup();
				ShitThreadProc( param );
				return 0;
			}
		}
	}

	closesocket( s );
	WSACleanup();

	return 0;
}

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CShitSenderDlg dialog



CShitSenderDlg::CShitSenderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShitSenderDlg::IDD, pParent)
	, m_nThreads(35000)
	, Log(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShitSenderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, g_strTarget);
	DDX_Text(pDX, IDC_EDIT1, g_nPort);
	DDX_Text(pDX, IDC_EDIT2, m_nThreads);
	DDX_Text(pDX, IDC_EDIT4, Log);
}

BEGIN_MESSAGE_MAP(CShitSenderDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTNSTART, OnBnClickedBtnstart)
	ON_BN_CLICKED(IDC_BTNSTOP, OnBnClickedBtnstop)
END_MESSAGE_MAP()


// CShitSenderDlg message handlers

BOOL CShitSenderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	GetShit();
	g_nPort     = 3050;
	g_strTarget = "localhost";
	UpdateData( FALSE );
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShitSenderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShitSenderDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShitSenderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CShitSenderDlg::OnBnClickedBtnstart()
{
	g_bStop = FALSE;

	UpdateData( TRUE );
	Log = "Started";
	UpdateData( FALSE );

	HWND hWnd = GetSafeHwnd();

	for( UINT i = 0; i < m_nThreads; i++ )
	{
		AfxBeginThread( ShitThreadProc, hWnd, THREAD_PRIORITY_NORMAL, 4096 );
	}

}

void CShitSenderDlg::GetShit(void)
{
	srand( GetTickCount() );

	for( int i = 0; i < 4095; i++ )
	{
		g_shit[i] = rand() % 256;
	}
}

void CShitSenderDlg::OnBnClickedBtnstop()
{
	g_bStop = TRUE;

	Log = "Stopped";
	UpdateData( FALSE );
}
