//---------------------------------------------------------------------------

#ifndef m_thrH
#define m_thrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TMyThread : public TThread
{            
private:
protected:
    void __fastcall Execute();
public:
    __fastcall TMyThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
