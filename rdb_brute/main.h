//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBStoredProc.hpp>
#include "m_thr.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TEdit *user;
    TEdit *pass;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TButton *btnStart;
    TMemo *Log;
    TButton *btnStop;
    TButton *btnClose;
    TIBDatabase *IBDb1;
    TIBTransaction *IBTa1;
    TIBStoredProc *IBSp1;
    TComboBox *db;
    void __fastcall btnCloseClick(TObject *Sender);
    void __fastcall btnStartClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btnStopClick(TObject *Sender);
private:	// User declarations
public:
    bool m_bStop;		// User declarations
    int m_pass[26];
    __fastcall TForm1(TComponent* Owner);
    void __fastcall LogIt(AnsiString text);
    TMyThread *mythread;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
