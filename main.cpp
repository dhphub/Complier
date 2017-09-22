#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

char *defTAG[] = {"int", "main", "void", "if", "char"};
char defChar[] = {'+','-','*','/','(',')','{','}','%',';',',','[',']',':','"','\'','~'};
char token[10];
int sum;

using namespace std;

int main(int argc,char** argv){
    char filename[100] = "test.c";

    ifstream input(filename);
    string line;

    for(int i=0; i<10; i++)
        token[i] = NULL;

    while(!std::getline(input, line)) {
        char temp;
        //string strForCheck;
        for(int i=0; i<line.size(); i++) {
            temp = line[i];
            if(temp == ' ') {
                continue;
            }
            int m=0;
            else if((temp>='A' && temp<='Z') || (temp>='a' && temp<='z')){
                int label = 10;
                while((temp>='0' && temp<='9') || (temp>='A' && temp<='Z') || (temp>='a' && temp<='z')) {
                token[m++] = temp;
                temp = line[i+1];
                }
                token[m++] = '\0';
                for(int j=0; j<5; j++) {
                    if(strcmp(token, defTAG[j]) == 0) {
                        label += 1;
                        break;
                    }
                }
            } else if(temp >= '0' && temp <= '9') {
                sum = 0;
                while(temp >= '0' && temp <= '9') {
                    sum = sum * 10 + temp - '0';
                    temp = line[i+1];
                }
                label = 9;
                if(sum >= 32767) {
                    label = -1;
                }
            } else switch(temp) {
            case "(":
            case ")":
                case
            }
        }
    }
}
