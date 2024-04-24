#include <iostream>
#include <string>

using namespace std;

struct moose
{
    int year;
    int strength;
};

moose* build(){
    moose* m = new moose();
    cin >> m->year;
    cin >> m->strength;
    return m;
}

int main(){

    int size;
    int n;

    cin >> size;
    cin >> n;

    moose* karl = build();
    vector<moose*> mooses;

    for(int i=0; i<n; i++){
        mooses.push_back(build());
    }

    

    return 0;
}