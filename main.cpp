#include <iostream>
#include <vector>

using namespace std;

int solution(const string& street) {
    bool house(false);
    bool space(false);
    int res = 0;
    unsigned int i = 0;

    while (i < street.size()) {
        if (street[i] == 'H') {
            if (!house) {
                house = true;

                if (space) {
                    // We have "-H". Check next
                    if (i + 1 < street.size()) {
                        if (street[i + 1] == '-') {
                            // We have "-H-"
                            space = false;
                        }
                        else {
                            // We have "-HH"
                            res++;
                            house = space = false;
                        }
                    }
                    else {
                        // We have "-H" at the end of string
                        res++;
                        house = space = false;
                    }
                }
            }
            else {
                // We had already "H-"
                if (house && space) {
                    res++;
                    house = space = false;
                }
                else {
                    return -1;
                }
            }
        }
        else {
            if (!space) {
                space = true;

                if (house) {
                    // We had already "H-". Check next
                    if (i + 1 < street.size()) {
                        if (street[i + 1] == 'H') {
                            // We have the case "H-H"
                            res++;
                            i++;
                            house = space = false;
                        }
                        else if (street[i + 1] == '-') {
                            // We have the case "H--"
                            res++;
                            house = space = false;
                        }
                    }
                    else
                    {
                        // We have "H-" at the end of string
                        res++;
                        house = space = false;
                    }
                }
            }
        }
        i++;
    }

    if (house) {
        return -1;
    }
    else if (!res)
    {
        // All spaces, threat as no error!
        return 0;
    }

    return res > 0 ? res : -1;
}

int main()
{
    vector<string> streets = {"-HH--H-H--H--",
                             "H-H-H-H-H-H",
                             "H-H-H-H-H",
                             "H-HH-HH-H",
                             "H-HH-H-H-H",
                             "H-H-HH-HH-H-H",
                             "H-HH",
                             "---------",
                             "----H-----",
                             "----H-H----",
                             "----H-HH----"};

    for( const auto& street : streets) {
        int res = solution(street);
        if (res >= 0) {
            cout << "Needed watertank(s): " << res << endl;
        }
        else {
            cout << "Not possible to supply all houses on the street!" << endl;
        }
    }

    return 0;
}
