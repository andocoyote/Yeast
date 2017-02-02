#include "yeast.h"

Yeast::Yeast()
{
    m_name = unique_ptr<wchar_t[]>(new wchar_t[29](L"Saccharomyces cerevisiae"));
}

Yeast::Yeast(LONG volatile *Glucose) : Yeast()
{
    m_glucose = Glucose;
}

void Yeast::Print()
{
    wcout << L"Name: " << m_name.get() << endl;
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