#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct moose
{
    bool karl;
    int year;
    int strength;
    bool operator<(const moose& m) const {
        return year < m.year;
    }
    bool operator>(const moose& m) const {
        return strength > m.strength;
    }
};

struct tournament{
    int curr_year;
    moose last_winner;
    vector<moose> contestants;
    void build(int year, vector<moose> _contestants){
        curr_year = year;
        contestants = _contestants;
    }
    void contest(){
        moose strongest;
        strongest.strength = 0;
        int strongest_i;
        for(int i=0; i<contestants.size(); i++){
            moose m = contestants[i];
            if(m > strongest){
                strongest = m;
                strongest_i = i;
            }
        }
        last_winner = strongest;
        curr_year++;
        contestants.erase(contestants.begin()+strongest_i);
    }
};

moose build(bool karl = false){
    moose m;
    m.karl = karl;
    cin >> m.year;
    cin >> m.strength;
    return m;
}

int main(){

    int size, n;
    cin >> size;
    cin >> n;

    vector<moose> mooses;
    mooses.push_back(build(true));

    for(int i=0; i<n; i++){
        mooses.push_back(build());
    }

    sort(mooses.begin(), mooses.end());

    tournament t;

    vector<moose> contestants;
    int i = 0;
    while(i<size){
        contestants.push_back(mooses[i]);
        i++;
    }
    t.build(contestants[0].year, contestants);

    while(t.last_winner.karl != true){
        t.contest();
        if(i < mooses.size()){
            t.contestants.push_back(mooses[i]);
            i++;
        } else {
            t.curr_year = 0;
            break;
        }
    }

    cout << (t.curr_year != 0 ? to_string(t.curr_year-1) : "unknown") << endl;

    return 0;
}
