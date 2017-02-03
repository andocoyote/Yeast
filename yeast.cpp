#include "yeast.h"

Yeast::Yeast(WCHAR* Name)
{
    m_name = Name;
}

Yeast::Yeast(WCHAR* Name, LONG *Glucose) : Yeast(Name)
{
    m_glucose = Glucose;
}

void Yeast::Print()
{
    wcout << L"Yeast: " << m_name << endl;
}

void Yeast::Run()
{
    if(*m_glucose > 0)
    {
        Glycolysis();
    }
}

void Yeast::Glycolysis()
{
    wcout << L"Decrementing glucose from " << *m_glucose;
    InterlockedDecrement(m_glucose);
    wcout << L" to " << *m_glucose << endl;
}