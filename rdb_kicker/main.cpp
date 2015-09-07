//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnKickClick(TObject *Sender)
{
    try
    {
        StrToInt( edtUID->Text );
    }
    catch( ... )
    {
        return;
    }

    IBQuery1->ExecSQL();
    IBTransaction1->Commit();
    IBStoredProc1->ParamByName( "ID_USER" )->AsString = edtUID->Text;
    IBStoredProc1->ExecProc();
    IBQuery2->ExecSQL();
    IBTransaction1->Commit();
}
//---------------------------------------------------------------------------
