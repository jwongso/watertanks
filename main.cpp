#include <iostream>
#include <stack>

using namespace std;

int solution(const string& street) {
    stack<char> houses;
    stack<char> ground;
    int res = 0;
    unsigned int i = 0;

    while (i < street.size()) {
        if (street[i] == 'H') {
            if (houses.empty()) {
                houses.push(street[i]);

                if (ground.size() == 1) {
                    // We have "-H". Check next
                    if (i + 1 < street.size()) {
                        if (street[i + 1] == '-') {
                            // We have "-H-"
                            ground.pop();
                        }
                        else {
                            // We have "-HH"
                            res++;
                            houses.pop();
                            ground.pop();
                        }
                    }
                    else {
                        // We have "-H" at the end of string
                        res++;
                        houses.pop();
                        ground.pop();
                    }
                }
            }
            else {
                // We had already "H-"
                if (houses.size() == 1 && ground.size() == 1) {
                    res++;
                    houses.pop();
                    ground.pop();
                }
                else {
                    return -1;
                }
            }
        }
        else {
            if (ground.empty()) {
                ground.push(street[i]);

                if (houses.size() == 1) {
                    // We had already "H-". Check next
                    if (i + 1 < street.size()) {
                        if (street[i + 1] == 'H') {
                            // We have the case "H-H"
                            res++;
                            i++;
                            houses.pop();
                            ground.pop();
                        }
                        else if (street[i + 1] == '-') {
                            // We have the case "H--"
                            res++;
                            houses.pop();
                            ground.pop();
                        }
                    }
                    else
                    {
                        // We have "H-" at the end of string
                        res++;
                        houses.pop();
                        ground.pop();
                    }
                }
            }
        }
        i++;
    }

    if (!houses.empty()) {
        return -1;
    }

    return res > 0 ? res : -1;
}

int main()
{
    string street = "-HH--H-H--H--";
    int res = solution(street);
    if (res > 0) {
        cout << "Needed watertank(s): " << res << endl;
    }
    else {
        cout << "Not possible to supply all houses on the street!" << endl;
    }
    return 0;
}
