//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnCloseClick(TObject *Sender)
{
    m_bStop = true;

    if( mythread )
    {
        mythread->Terminate();
        mythread->WaitFor();
    }

    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnStartClick(TObject *Sender)
{
    int i;

    for( i = 0; i < pass->Text.Length(); i++ )
    {
        m_pass[i] = pass->Text[i+1];
    }

    for( ; i < 25; i++ )
    {
        m_pass[i] = 0x1f;
    }


    LogIt( "--> starting... <--" );
    m_bStop = false;

    btnStart->Enabled = false;

    mythread = new TMyThread(false);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LogIt(AnsiString text)
{
    Log->Lines->Add( text );
}
void __fastcall TForm1::FormShow(TObject *Sender)
{
    for( int i = 0; i < 25; i++ )
    {
        m_pass[i] = 0x1f;
    }

    m_pass[25] = ( char )0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnStopClick(TObject *Sender)
{
    m_bStop = true;
}

//---------------------------------------------------------------------------


