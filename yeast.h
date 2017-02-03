#include "precompiled.h"
#include <windows.h>
#include <iostream>
#include <memory>
#include <wchar.h>

using namespace std;

// 1 glucose = C6H12O6 = 2 ATP, 2 NADH, 2 pyruvate

class Yeast
{
public:
    Yeast(WCHAR* Name);
    Yeast(WCHAR* Name, LONG *Glucose);
    VOID Print();
    VOID Run();
    
private:

    VOID Glycolysis();
    
    WCHAR* m_name = nullptr;
    
    LONG m_ATP = 0;
    LONG m_NADH = 0;
    LONG m_pyruvate = 0;
    
    LONG *m_glucose = 0;
};

//unique_ptr<WCHAR[]>m_name = nullptr;
//m_name = unique_ptr<wchar_t[]>(new wchar_t[50](L"Yeast name"));