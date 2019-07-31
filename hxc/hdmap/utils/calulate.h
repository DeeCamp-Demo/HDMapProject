//
// Created by catalina on 2019/7/31.
//
#include "string.h"
#include <iostream>
#include <vector>
#ifndef PROTO_TEST_CALULATE_H
#define PROTO_TEST_CALULATE_H
using namespace std;

namespace calulate {
    void dump(std::ostream &out, const std::vector<std::string> &v)
    {
        for(size_t i = 0; i < v.size(); ++i) {
            out << '\'' << v[ i ] << '\'' << ' ';
        }
        out << std::endl;
    }

    size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
    {
        size_t pos = txt.find( ch );
        size_t initialPos = 0;
        strs.clear();

        // Decompose statement
        while( pos != std::string::npos ) {
            strs.push_back( txt.substr( initialPos, pos - initialPos ) );
            initialPos = pos + 1;

            pos = txt.find( ch, initialPos );
        }

        // Add the last one
        strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

        return strs.size();
    }

    void extractFiguresFromStr2Vec(string str, vector<double> &vec){
        const char *s = str.c_str();
        const char *pstr;
        int i = 0, j = 0;
        int k, m;
        int e10;
        int digit;
        int ndigit = 0;
        pstr = &s[0];

        for (i = 0; *(pstr + i) != '\0'; i++){
            if ((*(pstr + i) >= '0') && (*(pstr + i) <= '9') || *(pstr + i)=='.')
                j++;
            else{
                if (j > 0){
                    string str;
                    for (k = j; k > 1; k--){
                        str.append(pstr + i  - k);
                    }
                    vec.push_back(atof(str.c_str()));
                    ndigit++;
                    j = 0;
                }
            }
        }
        if (j > 0){
            string str;
            for (k = j; k > 1; k--){
                str.append(pstr + i - k);
            }
            vec.push_back(atof(str.c_str()));
            ndigit++;
            j = 0;
        }
    }
    void extractFiguresFromStr2Vec(string str, vector<int> &vec){
        const char *s = str.c_str();
        const char *pstr;
        int i = 0, j = 0;
        int k, m;
        int e10;
        int digit;
        int ndigit = 0;
        pstr = &s[0];

        for (i = 0; *(pstr + i) != '\0'; i++){
            if ((*(pstr + i) >= '0') && (*(pstr + i) <= '9'))
                j++;
            else{
                if (j > 0){
                    digit = *(pstr + i - 1) - 48;
                    for (k = 1; k < j; k++){
                        e10 = 1;
                        for (m = 1; m <= k; m++)
                            e10 = e10 * 10;
                        digit = digit + (*(pstr + i - 1 - k) - 48)*e10;
                    }
                    vec.push_back(digit);
                    ndigit++;
                    j = 0;
                }
            }
        }
        if (j > 0){
            digit = *(pstr + i - 1) - 48;
            for (k = 1; k < j; k++){
                e10 = 1;
                for (m = 1; m <= k; m++)
                    e10 = e10 * 10;
                digit = digit + (*(pstr + i - 1 - k) - 48)*e10;
            }
            vec.push_back(digit);
            ndigit++;
            j = 0;
        }
    }

}
#endif //PROTO_TEST_CALULATE_H
