#include<iostream>
#include <algorithm>
#include<vector>
#include<cpu-features.h>
#include<string>

using namespace std;

class Properties {
    public:
        Properties();
        void android_getCpu(int);
        string android_gotCpuFamily;
        vector<string> android_gotCpuFeatures{};
};

Properties::Properties() {
    cout << "Prebuiltive: Version 1.2.1" << endl
    << "---DEVELOPED BY MANAS RAWAT (CYOURCE---" << endl;
}

void Properties::android_getCpu(int n){

    string android_givenCpuFamilies[] = {
        "ARM",
        "X86",
        "MIPS",
        "ARM64",
        "X86_64",
        "MIPS64"
    };

    string android_givenCpuFeatures[] = {
        //ARM
        "VFPv2",
        "ARMv7",
        "VFPv3",
        "VFP_D32",
        "NEON",
        "VFP_FP16",
        "VFP_FMA",
        "NEON_FMA",
        "IDIV_ARM",
        "IDIV_THUMB2",
        "iWMMXt",
        "LDREX_STREX",
        //ARM64
        "FP",
        "ASIMD",
        "AES",
        "CRC32",
        "SHA1",
        "SHA2",
        "PMULL",
        //x86
        "SSSE3",
        "POPCNT",
        "MOVBE",
        //MIPS
        "R6",
        "MSA"
    };

    switch(n){
        case 0: {
            for (int i = 0; i <= 5; i++) {
                if (android_getCpuFamily() == i) {
                    android_gotCpuFamily = android_givenCpuFamilies[i];
                }
            }
        } break;
        case 1: {
            for (int j = 0; j < 4; j++) {
                if (android_getCpuFeatures() == j) {
                    android_gotCpuFeatures.push_back(android_givenCpuFeatures[j]);
                }
            }
        } break;
        default: break;
    }
}

int main() {

    string input;
    Properties props;
    getline(cin, input);

    if (input == "cpu family") {
        props.android_getCpu(0);
        cout << "CPU FAMILY: " + props.android_gotCpuFamily << endl;
    } else if (input == "cpu features") {
        props.android_getCpu(1);
        string v2s;
        v2s = accumulate(begin(props.android_gotCpuFeatures), end(props.android_gotCpuFeatures), v2s);
        cout << "CPU FEATURES: " + v2s << endl;
    } else {
        cout << "ERROR: Command not recognised" << endl;
    }

    return 0;
}

