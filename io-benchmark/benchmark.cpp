#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> v(2000000);

////////////////////////////////////////////////////////////////////////////////

void cin1() {
    for (size_t i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
}

void cin2() {
    std::ios_base::sync_with_stdio(false);

    for (size_t i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
}

void cin3() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (size_t i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
}

void getline1() {
    string str;
    for (size_t i = 0; i < v.size(); i++) {
        getline(cin, str, ' ');
        v[i] = stoi(str);
    }
}

void scanf1() {
    for (size_t i = 0; i < v.size(); i++) {
        scanf("%i", &(v[i]));
    }
}

////////////////////////////////////////////////////////////////////////////////

void test(const string & name, void (*fn)()) {
    cout << name;

    long long avg = 0;
    for (int i = 0; i < 5; i++) {
        freopen("data.txt", "r", stdin);

        chrono::steady_clock::time_point begin, end;
        begin = chrono::steady_clock::now();
        fn();
        end = std::chrono::steady_clock::now();
        avg += chrono::duration_cast<chrono::microseconds>(end - begin).count();
        
        fclose(stdin);
    }

    cout << avg / 5 << "us\n";
}

int main() {
    test("1) scanf:                                   ", scanf1);
    test("2) out-of-the-box cin:                      ", cin1);
    test("3) getline:                                 ", getline1);
    test("4) sync_with_stdio(false) cin:              ", cin2);
    test("5) sync_with_stdio(false) + cin.tie(0) cin: ", cin3);
    
    cout << endl;
    
    return 0;
}