#include<iostream>
#include<cpu-features.h>
#include<string>

using namespace std;

class Properties {
    public:
        Properties();
        string android_getCpuFamilies(int);
};

Properties::Properties() {
    cout << "Prebuiltive: Version 1.2.1" << endl
    << "---DEVELOPED BY MANAS RAWAT (CYOURCE---" << endl;
}

string Properties::android_getCpuFamilies(int n){
    string android_givenCpuFamilies[] = {
        "ANDROID_CPU_FAMILY_ARM",
        "ANDROID_CPU_FAMILY_X86",
        "ANDROID_CPU_FAMILY_MIPS",
        "ANDROID_CPU_FAMILY_ARM64",
        "ANDROID_CPU_FAMILY_X86_64",
        "ANDROID_CPU_FAMILY_MIPS64"
    };

    switch(n){
        case 0: {
            for (int i = 0; i < 6; i++) {
                if (android_getCpuFamily() == i) {
                    return android_givenCpuFamilies[i];
                }
            }
        }
        default: break;
    }
    return "Error: Cannot identify CPU Family";
}

int main() {

    string input;
    Properties props;
    getline(cin, input);
    string cmds[] = {"cpu family"};

    if (input == cmds[0]) {
        cout << props.android_getCpuFamilies(0) << endl;
    }

    return 0;
}

