#include <catch.h>
#include <cell_world_tools/map_symbols.h>

using namespace std;
using namespace cell_world;
TEST_CASE("maps"){
    long a = 36;
    Map_symbol m;
    m.symbol = 9654;
//cout <<  "\033[3;" << 40 << ";" << 37 << "m" << m << "\033[0m" ;
//    cout << "\033[3;" << 41 << ";" << 36 << "mTexting\033[0m\t\t" << "HERRE" << endl;
//    cout << "\033[3;" << 42 << ";" << 35 << "mTexting\033[0m\t\t" << "HERRE" << endl;
//    cout << "\033[3;" << 43 << ";" << 34 << "mTexting\033[0m\t\t" << "HERRE" << endl;
//    cout << "\033[3;" << 44 << ";" << 33 << "mTexting\033[0m\t\t" << "HERRE" << endl;
//    cout << "\033[3;" << 45 << ";" << 32 << "mTexting\033[0m\t\t" << "HERRE" << endl;
//    cout << "\033[3;" << 46 << ";" << 31 << "mTexting\033[0m\t\t" << "HERRE" << endl;
//    cout << "\033[3;" << 47 << ";" << 30 << "mTexting\033[0m\t\t" << "HERRE" << endl;
    cout << "HERE " << m <<  m.back(Red).front(Yellow) << endl;
}