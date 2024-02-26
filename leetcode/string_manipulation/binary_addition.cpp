#include<bits/stdc++.h> 

using namespace std;

class Solution{
public:
    string addBinary(string a, string b){

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int slen, llen, i;
        int alen = a.length();
        int blen = b.length();

        string longer, res = "";

        if(alen < blen){
            longer = b;
            slen = alen;
            llen = blen;
        }
        else{
            longer = a;
            slen = blen;
            llen = alen;
        }

        bool carry = false;

        for(i = 0; i < slen; i++){

            if(carry == false){

                if(a[i]=='0' && b[i]=='0'){
                    res += '0';
                }
                else if(a[i]=='0' && b[i]=='1'){
                    res += '1';
                }
                else if(a[i]=='1' && b[i]=='0'){
                    res += '1';
                }
                else if(a[i]=='1' && b[i]=='1'){
                    res += '0';
                    carry = true;
                }

            }

            else{

                if(a[i]=='0' && b[i]=='0'){
                    res += '1';
                    carry = false;
                }
                else if(a[i]=='0' && b[i]=='1'){
                    res += '0';
                }
                else if(a[i]=='1' && b[i]=='0'){
                    res += '0';
                }
                else if(a[i]=='1' && b[i]=='1'){
                    res += '1';
                }

            }

        }

        while(i < llen){

            if(carry == false){
                if(longer[i] == '0'){
                    res += '0';
                }
                else{
                    res += '1';
                }
            }
            else{
                if(longer[i] == '0'){
                    res += '1';
                    carry = false;
                }
                else{
                    res += '0';
                }
            }

            ++i;

        }

        if(carry){
            res += '1';
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

int main(){

    Solution S;

    string a1 = "11", b1 = "1";
    string a2 = "1010", b2 = "1010";
    string a3 = "0101", b3 = "111";
    string a4 = "1", b4 = "111111";

    cout << S.addBinary(a1, b1) << endl;
    cout << S.addBinary(a2, b2) << endl;
    cout << S.addBinary(a3, b3) << endl;
    cout << S.addBinary(a4, b4) << endl;

    return 0;
}