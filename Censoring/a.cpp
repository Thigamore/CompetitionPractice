#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("censor.in");
ofstream fout("censor.out");

int main() {
    string mag; fin >> mag;
    string censor; fin >> censor;
    /*
    int pos = 0;
    while(pos != mag.size()) {
        if(mag.at(pos) == censor.at(0)) {
            int ptr1 = pos;
            int ptr2 = 0;
        } else {
            pos++;
        }
    }
    */
   size_t pos = 0;
   pos = mag.find(censor);
   int start = 0;
   string out = mag;
   while(pos != string::npos) {
       out = out.substr(start, pos) + out.substr(pos+censor.size(), out.size() - 1);
       if((start-(int)censor.size()) >= 0) {
           start= start - (int)censor.size();
       } else {
           start = 0;
       }
       pos = out.find(censor);
   }
   fout << out;

}