#include <iostream>
#include <stdio.h>
using namespace std;
class ATM
{
public:
    int Id, All, max = 1000, min = 10;
    int Ten, Fifty, Hundred, Fhundred, Thousand;  
    void Initialization(int cId, int cTen, int cFifty, int cHundred, int cFhundred, int cThousand)
    {
        Id = cId;
        Ten = cTen; Fifty = cFifty; Hundred = cHundred; Fhundred = cFhundred; Thousand = cThousand;
        All = Ten*10 + Fifty*50 + Fhundred*500 + Thousand*1000;
    }
    void Input(int cTen, int cFifty, int cHundred, int cFhundred, int cThousand)
    {
        Ten = Ten + cTen; Fifty = Fifty + cFifty; Hundred = Hundred = cHundred; Fhundred = Fhundred + cFhundred; Thousand = Thousand + cThousand;
        All = All + cTen * 10 + cFifty * 50 + cFhundred * 500 + cThousand * 1000;
    }
    void Output(int cTen, int cFifty, int cHundred, int cFhundred, int cThousand)
    {
        Ten = Ten - cTen; Fifty = Fifty - cFifty; Hundred = Hundred - cHundred; Fhundred = Fhundred - cFhundred; Thousand = Thousand - cThousand;
        int cAll = cTen * 10 + cFifty * 50 + cHundred * 100 + cFhundred * 500 + cThousand * 1000;
        if (cAll < min || cAll > max || cAll > All)
            cout << "Error \n";
        All = All - cAll;
    }
};
int main()
{
    int I, T, F, H, FH, TH;
    ATM Cash;
    cout << "***ATM Initialization*** \n" << "ATM Id: " ;
    cin >> I;
    cout << "Number of Bills: Ten, Fifty, Hundred, Five Hundred, Thousand \n";
    cin >> T >> F >> H >> FH >> TH;
    Cash.Initialization(I,T,F,H,FH,TH);
Menu:
    cout << "*** MENU *** \n";
    cout <<"1. ATM Info \n" <<"2. Put Money \n" << "3. Withdraw Money \n" << "4. Exit \n";
    int D;  cin >> D;
    if (D == 2)
    {
        cout << "_PUT MONEY_ \n" << "Your Bills: Ten, Fifty, Hundred, Five Hundred, Thousand \n";
        cin >> T >> F >> H >> FH >> TH;
        Cash.Input(T, F, H, FH, TH);
        goto Menu;
    }
    if (D == 3)
    {
        cout << "_WITHDRAW MONEY_ \n" << "How Many Bills: Ten, Fifty, Hundred, Five Hundred, Thousand \n";
        cin >> T >> F >> H >> FH >> TH;
        Cash.Output(T, F, H, FH, TH);
        goto Menu;
    }
    if (D == 1)
    {
        cout << "_ATM INFO_ \n" << "ATM id: " << Cash.Id << '\n' << "Available Money: " << Cash.All << '\n';
        goto Menu;
    }
    if (D == 4)
    {
        cout << "Goodbye";
        exit(0);
    }
}
