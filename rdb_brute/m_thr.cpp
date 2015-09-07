//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "m_thr.h"
#include "main.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TMyThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TMyThread::TMyThread(bool CreateSuspended)
    : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall TMyThread::Execute()
{
    AnsiString strPass;
    int i;

    try
    {
        Form1->IBSp1->ParamByName( "NAME_USER" )->AsString = Form1->user->Text;
        Form1->IBDb1->DatabaseName = Form1->db->Text;
        Form1->IBDb1->Open();

        if( Form1->IBDb1->TestConnected() )
        {
            while( ( !Form1->m_bStop )&&( Form1->m_pass[24] < 0x100 ) )
            {
                Form1->m_pass[0]++;
                if( Form1->m_pass[0] == 0x7f ) Form1->m_pass[0] = 0xc0;

                for( i = 1; i < 25; i++ )
                {
                    if( Form1->m_pass[i-1] > 0xff )
                    {
                        Form1->m_pass[i-1] = 0x20;
                        Form1->m_pass[i]++;
                        if( Form1->m_pass[i] == 0x7f ) Form1->m_pass[i] = 0xc0;
                    }
                }

                strPass = "";
                for( i = 0; i < 25; i++ )
                {
                    if( Form1->m_pass[i] > 0x1f ) strPass += ( char )Form1->m_pass[i];
                }

                Form1->pass->Text = strPass;
                Form1->IBSp1->ParamByName( "PASW_USER" )->AsString = strPass;

                if( Form1->IBDb1->TestConnected() )
                {
                    Form1->IBSp1->ExecProc();
                }
                else
                {
                    Form1->LogIt( "!!! Connection lost!" );
                    Form1->m_bStop = true;
                }

                if( Form1->IBSp1->ParamByName( "ID_USER" )->AsString != "" )
                {
                    Form1->LogIt( "user_name = " + Form1->IBSp1->ParamByName( "NAME_USER" )->AsString );
                    Form1->LogIt( "user_pass = " + Form1->IBSp1->ParamByName( "PASW_USER" )->AsString );
                    Form1->LogIt( "user_id   = " + Form1->IBSp1->ParamByName( "ID_USER" )->AsString );

                    Form1->m_bStop = true;
                }
            }

        }
        else
        {
            Form1->LogIt( "unable to connect!" );
        }
    }

    catch( ... )
    {
        Form1->LogIt( "!!! exception!" );
    }

    Form1->btnStart->Enabled = true;
    Form1->LogIt( "--> end <--" );
}
//---------------------------------------------------------------------------
