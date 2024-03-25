#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

#define lint long long int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases;

    cin >> cases;
    cin.ignore(9999, '\n');

    for (int i = 0; i < cases; i++) {
        std::string street;
        int num_addresses;
        std::string addresses_str;

        std::getline(std::cin, street);

        cout << street << endl;
        cin >> num_addresses >> addresses_str;
        cout << num_addresses << " " << addresses_str << endl;
        cin.ignore(9999, '\n');

        std::vector<int> digits(10, 0);
        int total_digits = 0;

        for (int z = 0; z < num_addresses;) {  // have we done all addresses for the street
            std::string input;
            std::getline(std::cin, input);

            if (input[0] == '+') {
                int increment;
                int start;
                int end;
                char junk;

                stringstream ss(input);
                ss >> junk;
                ss >> start;
                ss >> end;
                ss >> increment;
                for (int k = start; k <= end; k += increment) {
                    std::string string_version = std::to_string(k);
                    for (char c : string_version) {
                        int somthing = static_cast<int>(c - '0');
                        digits[somthing]++;
                        total_digits++;
                    }
                    z++;
                }
            } else {
                // cout << input << endl;
                // std::stoi(input);
                for (char c : input) {
                    int somthing = static_cast<int>(c - '0');
                    // cout << c << endl; //
                    digits[somthing]++;
                    total_digits++;
                }
                z++;
            }
        }
        for (int i = 0; i < 10; i++) {
            cout << "Make " << digits[i] << " digit " << i << endl;
        }

        // for(int i = 0; i < 10; i++){
        //     total_digits = total_digits + digits[i];
        // }
        cout << "In total " << total_digits << (total_digits == 1 ? " digit" : " digits") << endl;
    }
    return 0;
}