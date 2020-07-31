#include <json_cpp.h>
#include <map_symbols.h>
#include <clocale>

using namespace std;
int main(){
    Map_symbols ms;
    cout << "Symbols loaded successfully" << endl;
    cout << "clear      : " << ms.clear << endl;
    cout << "occluded   : " << ms.occluded << endl;
    cout << "goal       : " << ms.goal << endl;
    cout << "North      : " << ms.N << endl;
    cout << "South      : " << ms.S << endl;
    cout << "East       : " << ms.E << endl;
    cout << "West       : " << ms.W << endl;
    cout << "North-East : " << ms.NE << endl;
    cout << "South-East : " << ms.SE << endl;
    cout << "North-West : " << ms.NW << endl;
    cout << "South-West : " << ms.SW << endl;
}