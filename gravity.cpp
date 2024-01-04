#include <iostream>
#include <string>

using namespace std;

int main() {
    string suspiciousString;
    cin >> suspiciousString;

    int goodness = 0;

    int numCommands;
    cin >> numCommands;

    for (int i = 0; i < numCommands; ++i) {
        string command;
        cin >> command;

        if (command == "copy") {
            string key;
            int count;
            cin >> key >> count;
            
            for (int j = 0; j < count; ++j) {
                suspiciousString += key;
            }

            if (suspiciousString.length() > count) {
                suspiciousString = suspiciousString.substr(count);
            }
        } else if (command == "compare") {
            string key;
            cin >> key;

            if (suspiciousString == key) {
                goodness++;
            }
        } else if (command == "substr") {
            string key;
            int count;
            cin >> key >> count;

            size_t found = suspiciousString.find(key);

            if (found != string::npos && found + key.length() * count <= suspiciousString.length()) {
                goodness++;
            }
        } else if (command == "attach") {
            string key, str;
            int count;
            cin >> key >> count >> str;

            string attachedString = key + str;

            for (int j = 1; j < count; ++j) {
                attachedString += key + str;
            }

            if (suspiciousString.find(attachedString) != string::npos) {
                goodness++;
            }
        } else if (command == "length") {
            int count;
            cin >> count;

            if (suspiciousString.length() == count) {
                goodness++;
            }
        }
    }

    if (goodness >= numCommands / 2) {
        cout << "Eyval" << endl;
    } else {
        cout << "HeifShod" << endl;
    }

    return 0;
}
