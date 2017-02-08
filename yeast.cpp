#include "yeast.h"

Yeast::Yeast(WCHAR* Name)
{
    m_name = Name;
}

Yeast::Yeast(WCHAR* Name, LONG *Glucose) : Yeast(Name)
{
    m_glucose = Glucose;
    
    Initialize();
}

Yeast::~Yeast()
{
    if(m_yeastThread)
    {
        CloseHandle(m_yeastThread);
    }
}

VOID Yeast::Print()
{
    wcout << L"Yeast: " << m_name << endl;
}

DWORD WINAPI Yeast::Run(LPVOID Param)
{
    Yeast* This = (Yeast*)Param;
    return This->Run();
}

DWORD Yeast::Run()
{
    wcout << "Hello, world! (Thread: " << GetCurrentThreadId() << ")\n";
    
    if(*m_glucose > 0)
    {
        Glycolysis();
    }
    
    /*DWORD dwCount=0, dwWaitResult; 

    // Request ownership of mutex.

    while( dwCount < 20 )
    { 
        dwWaitResult = WaitForSingleObject( 
            ghMutex,    // handle to mutex
            INFINITE);  // no time-out interval
 
        switch (dwWaitResult) 
        {
            // The thread got ownership of the mutex
            case WAIT_OBJECT_0: 
                __try { 
                    // TODO: Write to the database
                    printf("Thread %d writing to database...\n", 
                            GetCurrentThreadId());
                    dwCount++;
                } 

                __finally { 
                    // Release ownership of the mutex object
                    if (! ReleaseMutex(ghMutex)) 
                    { 
                        // Handle error.
                    } 
                } 
                break; 

            // The thread got ownership of an abandoned mutex
            // The database is in an indeterminate state
            case WAIT_ABANDONED: 
                return FALSE; 
        }
    }*/
    return 0;
}

VOID Yeast::Glycolysis()
{
    while(*m_glucose > 0)
    {
        wcout << L"Decrementing glucose from " << *m_glucose;
        InterlockedDecrement(m_glucose);
        wcout << L" to " << *m_glucose << endl;
    }
    
    wcout << m_name << " is all out of sugar.\n";
}

VOID Yeast::Initialize()
{
    m_yeastThread = CreateThread(NULL,
                                 0,
                                 (LPTHREAD_START_ROUTINE)Run,
                                 this,
                                 0,
                                 &m_yeastId);
    
    if(m_yeastThread == NULL)
    {
        wcout << "CreateThread failed: " << GetLastError() << endl;
        m_isInitialized = FALSE;
    }

}