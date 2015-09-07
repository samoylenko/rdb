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
#include <IBQuery.hpp>
#include <IBStoredProc.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
    TEdit *edtUID;
    TButton *btnKick;
    TLabel *Label1;
    TIBDatabase *IBDatabase1;
    TIBTransaction *IBTransaction1;
    TIBQuery *IBQuery1;
    TIBQuery *IBQuery2;
    TIBStoredProc *IBStoredProc1;
    TLabel *Label2;
    void __fastcall btnKickClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
