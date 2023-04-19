%:include <iostream>
const int i = 't' - 's';
const int ii = i - -i;
const int iii = ii - -ii;
const int iiii = iii - -iii;
const int iiiii = iiii - -iiii;
const int iiiiii = iiiii - -iiiii;
const int iiiiiii = iiiiii - -iiiiii;
const int iiiiiiii = iiiiiii - -iiiiiii;
const int iiiiiiiii = iiiiiiii - -iiiiiiii;
const int iiiiiiiiii = iiiiiiiii - -iiiiiiiii;
const int iiiiiiiiiii = iiiiiiiiii - -iiiiiiiiii;
const int iiiiiiiiiiii = iiiiiiiiiii - -iiiiiiiiiii;
const int iiiiiiiiiiiii = iiiiiiiiiiii - -iiiiiiiiiiii;
const int iiiiiiiiiiiiii = iiiiiiiiiiiii - -iiiiiiiiiiiii;
const int iiiiiiiiiiiiiii = iiiiiiiiiiiiii - -iiiiiiiiiiiiii;
const int iiiiiiiiiiiiiiii = iiiiiiiiiiiiiii - -iiiiiiiiiiiiiii;
const int iiiiiiiiiiiiiiiii = iiiiiiiiiiiiiiii - -iiiiiiiiiiiiiiii;
int n<:iiiiiiiiiiiiiii:>;
int nn;
int nnn;
int nnnn;
int nnnnn;
int nnnnnn;
int nnnnnnn;

int rr(int tt)
<%
    std::cin >> n<:tt:>; 
    nnn &= n<:tt:>;
    nnnnn ??'= n<:tt:>;
    nnnn = (nnnn & n<:tt:>) + (nnnn ??' n<:tt:>);
    return (tt < nnnnnn - i ? rr(tt - -i) : i);
%>

int rrr(int tt)
<%
    std::cout << n<:tt:> % n<:i - i:> << ' ';
    return (tt < nnnnnn - i ? rrr(tt - -i) : i);
%>

int r(int t)
<%
    std::cin >> nnnnnn;
    nnn = iiiiiiiiiiiiiiiii - i;
    nnnn = i - i;
    nnnnn = i - i;
    rr(i - i);
    std::cout << nnn << ' ' << nnnn << ' ' << nnnnn << std::endl;
    rrr(i - i);
    std::cout << std::endl;
    return (t > i? r(t-i) : i);
%>


int main()
<%
    std::cin >> nn >> nn;
    r(nn);
%>