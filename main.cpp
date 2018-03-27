#include "QInt.h"
#include <fstream>

char operatorArray[10] = {'+', '-', '*', '/', '&', '|', '^', '~', '<', '>'};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(1){
        string a, b, c, d;
        bool flag = false;
        cin >> a >> b >> c;
        if (a == "") break;
        for (int i = 0; i < 10; i++)
            if (c[0] == operatorArray[i]){
                flag = true;
                break;
            }
        if (flag){
            cin >> d;
            QInt temp1, temp2, temp;
            if (a == "2"){
                temp1 = ConvertBinStringToQInt(b);
                temp2 = ConvertBinStringToQInt(d);
            } else
            if (a == "10"){
                temp1 = ConvertDecStringToQInt(b);
                temp2 = ConvertDecStringToQInt(d);
            } else {
                temp1 = ConvertHexStringToQInt(b);
                temp2 = ConvertHexStringToQInt(d);
            }
            if (c[0] == '+') temp = temp1 + temp2;
            if (c[0] == '-') temp = temp1 - temp2;
            if (c[0] == '*') temp = temp1 * temp2;
            if (c[0] == '/') temp = temp1 / temp2;
            if (c[0] == '&') temp = temp1 & temp2;
            if (c[0] == '|') temp = temp1 | temp2;
            if (c[0] == '^') temp = temp1 ^ temp2;
            if (c[0] == '~') temp = ~temp1;
            if (c[0] == '<') temp = temp1 << temp2.data[15];
            if (c[0] == '>') temp = temp1 >> temp2.data[15];
            if (a == "2")
                cout << ConvertQIntToBinString(temp);
            else
            if (a == "10")
                cout << ConvertQIntToDecString(temp);
            else
                cout << ConvertQIntToHexString(temp);
        } else {
            if (a == "2"){
                QInt temp = ConvertBinStringToQInt(c);
                if (b == "10")
                    cout << ConvertQIntToDecString(temp);
                else
                    cout << ConvertQIntToHexString(temp);
            } else
            if (a == "10"){
                QInt temp = ConvertDecStringToQInt(c);
                if (b == "2")
                    cout << ConvertQIntToBinString(temp);
                else
                    cout << ConvertQIntToHexString(temp);
            } else {
                QInt temp = ConvertHexStringToQInt(c);
                if (b == "2")
                    cout << ConvertQIntToBinString(temp);
                else
                    cout << ConvertQIntToDecString(temp);
            }
        }
        cout << endl;
    }
    return 0;
}
